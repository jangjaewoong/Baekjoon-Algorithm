#include <iostream>
#include <vector>
#include <utility>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, M;
    std::cin>>N>>M;
    std::vector<std::vector<int>> map(N,std::vector<int>(M,0));
    std::pair<int,int> start;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            std::cin>>map[i][j];
            if(map[i][j]==2){
                start = {i, j};
            }
        }
    }
    std::vector<std::vector<int>> result(N, std::vector<int>(M,0));
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    std::queue<std::pair<int,int>> queue;
    queue.push(start);
    int dist= 0;
    while(!queue.empty()){
        int size = queue.size();
        dist++;
        for(int t=0; t<size; t++){
                std::pair<int,int> p = queue.front();
                queue.pop();
                for(int k = 0; k<4; k++){
                    int newX = p.second+dx[k];
                    int newY = p.first+dy[k];
                    if(newX>=0 && newX<M && newY>=0 && newY<N && result[newY][newX]==0){
                        if(map[newY][newX]==1){
                            queue.push({newY,newX});
                            result[newY][newX] = dist;
                        }
                    }
                }
            }
        }
                            
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if((map[i][j]!=0&&map[i][j]!=2)&&result[i][j]==0){
                result[i][j] = -1;
            }
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<"\n";
    }   
    
    return 0;
}