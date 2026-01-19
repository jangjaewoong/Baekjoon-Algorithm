#include <iostream>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin>>N;
    int arr[10001]={0};
    int dp[10001]={0};
    for(int i = 1; i<=N; i++){
        std::cin>>arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i = 3; i<=N; i++){
        dp[i] = std::max({dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i],dp[i-1]});
    }
    std::cout<<dp[N]<<"\n";
    
    return 0;
}