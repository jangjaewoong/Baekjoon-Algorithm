#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int X;
    std::cin>>X;
    int count = 1;
    while(X>1){
        if(X%2==1) count+=1;
        X/=2;
    }
    std::cout<<count<<"\n";
    return 0;
}