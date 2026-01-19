#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        std::string str;
        std::cin>>str;
        bool isdigit = false;
        int sum = 0;
        for(int i = 0; i<str.size(); i++){
            if(str[i]>='0'&&str[i]<='9'){
                isdigit = true;
            } else{
                if(isdigit){
                    sum++;
                    isdigit = false;
                }
            }
        }
        if(isdigit){
            sum++;
        }
        std::cout<<sum<<"\n";
    }
    return 0;
}