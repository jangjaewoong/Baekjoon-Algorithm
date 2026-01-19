#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin>>N;
    long long dp[N+1];
    if(N==1){
        std::cout<<"1\n";
        return 0;
    } else{
        dp[1] = 1;
        dp[2] = 3;
        for(int i=3; i<=N; i++){
            dp[i]= (dp[i-1]+2*dp[i-2])%10007;
        }
    }
    
    std::cout<<dp[N]<<"\n";
    return 0;
}