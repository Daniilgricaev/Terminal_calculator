#include"ShuntingYardClass.hpp"

void String_parser(std::string example,std::string& math_signs,std::vector<int>&stack){
    shunting_yard yard;
    size_t i = 0;

    while(example[i]!='\0'){
        if(isdigit(example[i])){
            int digit = 0;
            while(i<example.length() && isdigit(example[i])){
                digit = digit * 10 +(example[i]-'0');
                i++;
            }
            stack.push_back(digit);
        }   
        else{
            math_signs.push_back(example[i]);
            i++;
        }
    }
    // std::cout<<std::endl;
    // for(int i =0;i<math_signs.size();i++){
    //     std::cout<<math_signs[i];
    // }
    // std::cout<<std::endl;
    // for(int i = 0;i<stack.size();i++){
    //     std::cout<<stack[i];
    // }
}
void Shunting_yard_alg(std::string& math_signs,std::vector<int>&stack){
    shunting_yard yard;

    auto perform_operation = [](int a,int b,char operation)->int{
        switch(operation){
            case '+':return a+b;
            case '-':return a-b;
            case '*':return a*b;
            case '/':
                if(b == 0){
                    std::cout<<"  Next time, don't use division by zero, it's a huge mistake!!!  "<<std::endl;
                    return b/a;
                }else{
                    return a/b;
                };
            case '^':return pow(a,b);
            default:return 0;
        }
    };

    while(!math_signs.empty()){
        char operation = yard.get_higest_priorety(math_signs);
        size_t operation_pos = -1;
        for(size_t i =0;i<math_signs.length();i++){
            if(math_signs[i]==operation){
                operation_pos = i;
                break;
            }
        }
        int left = stack[operation_pos];
        int right = stack[operation_pos+1];
        int result = perform_operation(left,right,operation);

        stack[operation_pos] = result;

        for(size_t i = operation_pos+1;i<stack.size()-1;i++){
            stack[i]=stack[i + 1];
        }
        stack.pop_back();
        for(size_t i = operation_pos;i<math_signs.length()-1;i++){
            math_signs[i]=math_signs[i+1];
        }
        math_signs.pop_back();
    }
    
}