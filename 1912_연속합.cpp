#include <iostream>
#include <algorithm>
#include <climits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N; 
    int arr[100001];
    int dp[100001];
    for(int i = 1; i<=N; i++){
        std::cin>>arr[i];
    }
    int result = INT_MIN;
    dp[0] = 0;
    for(int i = 1; i<=N; i++){
        dp[i] = std::max(dp[i-1]+arr[i],arr[i]);
        result = std::max(dp[i],result);
    }
    std::cout<<result<<"\n";
    
    return 0;
}