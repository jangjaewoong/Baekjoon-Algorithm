#include <iostream>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N,M,B;
    std::cin>>N>>M>>B;
    long long int sum = 0;
    for(int i = 0; i<N*M;i++){
        int val;
        std::cin>>val;
        sum+=val;
    }
    long long int high_block = 0;
    long long int low_block = 0;
    int unit = N*M;
    while(high_block<sum){
        high_block+=unit;
    }
    low_block=high_block-unit;
    long long int time = 0;
    if(B>=high_block-sum&&high_block-sum<=(sum-low_block)*2){
        time = high_block - sum;
        sum = high_block;
    } else{
        time = (sum - low_block)*2;
        sum = low_block;
    }
    
    std::cout<<time<<" "<<sum/unit<<"\n";
    


    return 0;
}