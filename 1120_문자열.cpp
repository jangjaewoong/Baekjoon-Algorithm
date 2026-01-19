#include <iostream>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string str1,str2;
    std::cin>>str1>>str2;
    if(str1.size()<str2.size()){
        std::string tmp = str2;
        str2 = str1;
        str1 = tmp;
    } else if(str1.size()==str2.size()){
        int tmp= 0;
        for(int i = 0 ; i<str1.size(); i++){
            if(str1[i]!=str2[i]){
                tmp++;
            }
        }
        std::cout<<tmp<<"\n";
        return 0;
    }

    int max_index = 0;
    int max_length = 0;
    for(int i = 0 ; i<str1.size()-str2.size()+1; i++){
        int tmp=0;
        for(int j = 0; j<str2.size();j++){
            if(str1[i+j]==str2[j]){
                tmp++;
            }
        }
        if(tmp>max_length){
            max_length = tmp;
            max_index = i;
        }
    }

    std::cout<<str2.size()-max_length<<"\n";

    return 0;
}