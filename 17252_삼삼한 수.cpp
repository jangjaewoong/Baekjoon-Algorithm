#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int L;
    std::cin>>L;
    if(L==0){
        std::cout<<"NO\n";
        return 0;
    }
    while(true){
        if(L==1){
            std::cout<<"YES\n";
            break;
        }
        if(L%3>1){
            std::cout<<"NO\n";
            break;
        } else {
            L /= 3;
        }
        
    }
    return 0;
}