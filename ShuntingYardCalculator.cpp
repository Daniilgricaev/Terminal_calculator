#include"ShuntingYardClass.hpp"


int main(){

    std::string demo;
    std::string example;
    std::string math_signs;
    std::vector<int>stack;

    std::cout<<"Enter your mathematical example : ";
    std::getline(std::cin ,demo);
    std::cout<<std::endl;
    for(char c:demo){
        if(c !=' '){
            example+=c;
        }
    }

    std::cout<<example;
    String_parser(example,math_signs,stack);
    Shunting_yard_alg(math_signs,stack);
    std::cout<<std::endl<<"Result :"<<stack[0]<<std::endl;
    return 0;
}