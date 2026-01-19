#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin>>T;
    int a, b;
    for (int i = 0; i<T; i++){
        std::cin>>a>>b;
        int result = 1;
        while(b--){
            result = ((a%10)*(result%10))%10;
        }
        if(result){
            std::cout<<"10\n";
        } else{
            std::cout<<result<<"\n";
        }
    }
    return 0;
}