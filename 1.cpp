#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>

class shuting_yard{
    private:
        std::map<char,int> ch;
    public:
        shuting_yard(){
            ch = {
            {'(', 0},
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'^', 3}
        };
        }
        char get_char(std::string rpn){
            if(rpn.empty()){
                std::cout<<"Stack is empty!"<<std::endl;
                return '\0';
            }
            if(rpn.length()==1){
                return rpn[0];
            }
            for(int i = 0;i<rpn.length()-1;i++){
                for(int j = i+1;j<rpn.length();j++){
                    if(ch[rpn[i]]>=ch[rpn[j]]){
                        return rpn[i];
                    }else{
                        return rpn[j];
                    }
                }
            }
        }
};


void Dijekstra_Shuting_Yard(std::string example){
    std::string rpn;
    std::vector<int>stack;
    int i = 0;
    while(example[i]!='\0'){
        if(isdigit(example[i])){
            int digit = example[i] -'0';
            stack.push_back(digit);
        }else{
            rpn.push_back(example[i]);
        }
        i++;
    }
    std::cout<<std::endl;
    for(int i =0;i<rpn.size();i++){
        std::cout<<rpn[i];
    }
    std::cout<<std::endl;
    for(int i = 0;i<stack.size();i++){
        std::cout<<stack[i];
    }
}
int main(){

    std::string demo;
    std::string example;
    std::cout<<"Enter your mathematical example"<<std::endl;
    std::getline(std::cin ,demo);
    for(char c:demo){
        if(c !=' '){
            example+=c;
        }
    }
    std::cout<<example;
    Dijekstra_Shuting_Yard(example);

    return 0;
}