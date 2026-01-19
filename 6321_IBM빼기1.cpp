#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;

    for(int i = 0; i<T; i++){
        std::string str;
        std::cin>>str;
        std::string result = "";
        for(size_t j = 0 ; j<str.size(); j++){
            if(str[j]=='Z'){
                result+='A';
            } else{
                result+=str[j]+1;
            }
            
        }
        std::cout<<"String #"<<i+1<<"\n";
        std::cout<<result<<"\n";
        if(i!=T-1){
            std::cout<<"\n";
        }
    }
    return 0;
}