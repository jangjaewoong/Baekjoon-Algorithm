#include <iostream>

int getPrimeFactor(int N){
    int num = 0;
    while(N%2==0){
        N/=2;
        ++num;
    }
    for(int i = 3; i*i<=N; i+=2){
        while(N%i==0){
            N/=i;
            ++num;
        }
    }
    if(N!=1) ++num;
    return num;
}

bool isPrime(int N){
    if(N==1) return false;
    if(N==2) return true;
    if(N%2==0) return false;
    for(int i = 3; i*i<=N; i+=2){
        if(N%i==0) return false;
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int A,B;
    std::cin>>A>>B;
    int num = 0;
    for(int i = A; i<=B; i++){
        int N = getPrimeFactor(i);
        if(isPrime(N)) ++num;
    }
    std::cout<<num<<"\n";
    return 0;
}