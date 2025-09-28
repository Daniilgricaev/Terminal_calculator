#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>

class shunting_yard{
    private:
        std::map<char,int> ch;
    public:
        shunting_yard(){
            ch = {
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3}
        };
        }
        char get_higest_priorety(std::string rpn){
            if(rpn.empty()){
                std::cout<<"Stack is empty!"<<std::endl;
                return '\0';
            }
            if(rpn.length()==1){
                return rpn[0];
            }
            char higest = rpn[0];
            for(int i = 0;i<rpn.length();i++){
                if(ch[rpn[i]]>ch[higest]){
                    higest = rpn[i];
                }
            }
            return higest;
        }
};
void String_parser(std::string example,std::string rpn,std::vector<int>stack){
    shunting_yard yard;
    int i = 0,j=0;

    while(example[i]!='\0'){
        if(isdigit(example[i])){
            int digit = example[i] -'0';
            stack.push_back(digit);
        }else{
            rpn.push_back(example[i]);
        }
        i++;
    }
    // std::cout<<std::endl;
    // for(int i =0;i<rpn.size();i++){
    //     std::cout<<rpn[i];
    // }
    // std::cout<<std::endl;
    // for(int i = 0;i<stack.size();i++){
    //     std::cout<<stack[i];
    // }
}
void Shunting_yard_alg(std::string& rpn,std::vector<int>& stack){
    shunting_yard yard;

    auto perform_operation = [](int a,int b,char operation)->int{
        switch(operation){
            case '+':return a+b;
            case '-':return a-b;
            case '*':return a*b;
            case '/':return a/b;
            default:return 0;
        }
    };

    while(!rpn.empty()){
        char operation = yard.get_higest_priorety(rpn);
        size_t operation_pos = -1;
        for(int i =0;i<rpn.length();i++){
            if(rpn[i]==operation){
                operation_pos = i;
                break;
            }
        }
        int left = stack[operation_pos];
        int right = stack[operation_pos+1];
        int result = perform_operation(left,right,operation);

        stack[operation_pos] = result;

        for(int i = operation_pos+1;i<stack.size()-1;i++){
            stack[i]=stack[i + 1];
        }
        stack.pop_back();
        for(int i = operation_pos;i<rpn.length()-1;i++){
            rpn[i]=rpn[i+1];
        }
        rpn.pop_back();
    }
    
}
int main(){

    std::string demo;
    std::string example;
    std::string rpn;
    std::vector<int>stack;

    std::cout<<"Enter your mathematical example"<<std::endl;
    std::getline(std::cin ,demo);

    for(char c:demo){
        if(c !=' '){
            example+=c;
        }
    }

    std::cout<<example;
    String_parser(example,rpn,stack);
    Shunting_yard_alg(rpn,stack);
    std::cout<<"Result :"<<stack[0]<<std::endl;
    return 0;
}