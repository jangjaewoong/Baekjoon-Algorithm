#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> dp(100001,100001);
    int N,K;
    std::cin>>N>>K;
    int curr = N;
    dp[curr]= 0;
    if(curr!=0&&curr*2<100001){
        dp[curr*2]=1;
    } 
    if(curr+1<100001){
        dp[curr+1]=1;
    }
    if(curr-1>=0){
        dp[curr-1]=1;
    }

    for(int i = N; i<=K; i++){
        if(i-1>=0&&dp[i-1]!=-1){
            dp[i]= std::min(dp[i-1]+1,dp[i]);
        }
        if(i%2==0&&dp[i/2]!=-1){
            dp[i] = std::min(dp[i/2]+1,dp[i]);
        }
      
    }

    std::cout<<dp[K]<<"\n";

    return 0;
}