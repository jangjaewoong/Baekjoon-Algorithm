#include <iostream>

#define MOD 1000000000
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin>>N;
    long long int dp[101][10] = {0};
    for(int i = 1; i<10; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i<=N; i++){
        for(int j = 0; j<10; j++){
            if(j==0){
                dp[i][j] = dp[i-1][1]%MOD;
            } else if(j==9){
                dp[i][j] = dp[i-1][8]%MOD;
            } else {
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%MOD;
            }
        }
    }
    long long int result = 0;
    for(int i = 0; i<10; i++){
        result = (result+dp[N][i])%MOD;
    }
    std::cout<<result<<"\n";
}