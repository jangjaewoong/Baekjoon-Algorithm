#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin>>N;
    long long arr[N+1];
    if(N==1){
        std::cout<<"1\n";
        return 0;
    } else{
        arr[1]= 1;
        arr[2]= 2;
        for(int i=3; i<=N; i++){
            arr[i] = (arr[i-1]+arr[i-2])%10007;
        }
    }
    
    std::cout<<arr[N]<<"\n";
    return 0;
}