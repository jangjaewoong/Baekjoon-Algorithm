#include <iostream>
#include <queue>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin>>N;
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    while(N--){
        int num;
        std::cin>>num;
        if(pq.empty()&&num==0){
            std::cout<<"0\n";
        } else if(!pq.empty()&&num==0){
            std::cout<<pq.top()<<"\n";
            pq.pop();
        } else {
            pq.push(num);
        }
    }

    
    return 0;
}