#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin>>N;
    int dp[1001] = {0};
    for(int i = 0; i<N; i++){
        int value;
        std::cin>>value;
        int max = 0;
        for(int j = 0; j<value; j++){
            if(dp[j]>max) max = dp[j];
        }
        dp[value] = max+1;
    }
    int result = 0;
    for(int i = 0; i<1001; i++){
        if(dp[i]>result){
            result = dp[i];
        }
    }
    std::cout<<result<<"\n";
    return 0;
}