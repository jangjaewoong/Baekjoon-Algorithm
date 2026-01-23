#include <iostream>
#include <vector>
#include <utility>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N,M;
    std::cin>>N>>M;
    std::vector<int> map(101);
    std::vector<bool> isVisited(101);
    while(N--){
        int start, end;
        std::cin>>start>>end;
        map[start]=end;
    }
    while(M--){
        int start, end;
        std::cin>>start>>end;
        map[start] = end;
    }
    std::queue<std::pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()){
        int loc = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i = 1 ; i<=6; i++){
            int next = loc + i;
            if(next == 100){
                std::cout<<cnt+1;
                return 0;
            } else if(next < 100){
                while(map[next]!=0){
                    next = map[next];
                }
                if(!isVisited[next]){
                    q.push({next,cnt+1});
                    isVisited[next] = true;
                }
            }
        }
    }
    
    
    return 0;
}