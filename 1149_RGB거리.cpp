#include <iostream>
#include <algorithm>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin>>N;
    int house[1001][3];
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    int cost[3];
    for(int i = 1; i<=N; i++){
        std::cin>>cost[0]>>cost[1]>>cost[2];
        house[i][0] = std::min(house[i-1][1], house[i-1][2])+cost[0];
        house[i][1] = std::min(house[i-1][0], house[i-1][2])+cost[1];
        house[i][2] = std::min(house[i-1][1], house[i-1][0])+cost[2];
    }
    std::cout<<std::min(house[N][2],std::min(house[N][0],house[N][1]));
    return 0;
}