#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T; 
    std::cin>>T;
    std::vector<long long int> dp(101,0);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4; i<=100; i++){
        dp[i]= dp[i-2]+dp[i-3];
    }

    while (T--){
        int n;
        std::cin>>n;
        std::cout<<dp[n]<<"\n";
    }
    return 0;
}