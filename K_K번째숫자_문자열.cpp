#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string prefix="";
    for(int i =1; i<185270; i++){
        prefix+=std::to_string(i);
    }

    int T;
    std::cin>>T;
    while(T--){
        int K;
        std::cin>>K;
        std::cout<<prefix[K-1]<<"\n";
    }
    return 0;
}