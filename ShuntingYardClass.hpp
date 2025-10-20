#ifndef SHUNTINGYARDCLASS_H

#define SHUNTINGYARDCLASS_H

#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
#include<vector>
#include<stdexcept>
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
        char get_higest_priorety(std::string math_signs){
            if(math_signs.empty()){
                std::cout<<"Stack is empty!"<<std::endl;
                return '\0';
            }
            if(math_signs.length()==1){
                std::invalid_argument("You can't divide by zero");
            }
            char higest = math_signs[0];
            for(size_t i = 0;i<math_signs.length();i++){
                if(ch[math_signs[i]]>ch[higest]){
                    higest = math_signs[i];
                }
            }
            return higest;
        }
};
void String_parser(std::string example,std::string& math_signs,std::vector<int>&stack);

void Shunting_yard_alg(std::string& math_signs,std::vector<int>&stack);

#endif