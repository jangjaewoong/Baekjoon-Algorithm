#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N,M;
    std::cin>>N>>M;
    std::vector<int> package(M);
    std::vector<int> one(M);
    
    for(int i = 0; i<M; i++){
        std::cin>>package[i];
        std::cin>>one[i];
    }
    
    std::sort(package.begin(),package.end());
    std::sort(one.begin(),one.end());
    
    
    if(package[0]>=one[0]*6){
        std::cout<<one[0]*N<<"\n";
    } else {
        int sum = 0;
        int pack = (N%6!=0 ? N/6+1 : N);
        sum += (N/6)*package[0];
        N = N%6;
        sum += N*one[0];
        sum = std::min(pack*package[0],sum);
        std::cout<<sum<<"\n";
    }
    
    return 0;
}