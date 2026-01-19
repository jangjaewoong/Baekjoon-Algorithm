#include <iostream>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    int arr[1001];
    for(int i = 1; i<=N; i++){
        std::cin>>arr[i];
    }
    int dp[1001];
    for(int i = 1; i<=N; i++){
        dp[i] = 1;
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }
    int result = *std::max_element(dp+1, dp+N+1);
    std::cout<<result<<"\n";

    

    return 0;
}