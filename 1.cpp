#include<iostream>
#include<string>
#include<cctype>
#include<vector>
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