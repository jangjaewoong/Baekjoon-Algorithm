#include <iostream>

int pow(int exp, int quo){
    int result = 1;
    for(int i = 0; i<quo; i++){
        result *= exp;
    }
    return result;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N,K;
    std::cin>>N>>K;
    
    int result = 0;
    while(true){
        int count = 0;
        int temp = N;
        while(temp>0){
            if(temp%2==1) count++;
            temp/=2;
        }
        if(count<=K) break;
        
        int plus = N & -N;
        N+=plus;
        result+=plus;
    }
    std::cout<<result<<"\n";
    return 0;
}