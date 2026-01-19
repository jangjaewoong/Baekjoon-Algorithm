#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        int N, K;
        std::cin>>N>>K;
        int sum = 0;
        std::vector<int> arr(N);
        for(int i = 0; i<N; i++){
            std::cin>>arr[i];
            sum+=arr[i];
        }
        int aver = sum/N;
        int result = 0;
        for(int i = 0; i<N-K+1; i++){
            int tmp = 0;
            for(int j = i; j<i+K; j++){
                tmp+=arr[j];
            }
            if(tmp/K>=aver){
                result++;
            }
        }
        std::cout<<result<<"\n";
    }
    return 0;
}