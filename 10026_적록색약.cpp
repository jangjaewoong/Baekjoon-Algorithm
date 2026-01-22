#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin>>N;
    std::vector<std::vector<char>> graph(N,std::vector<char>(N));

    for(size_t i = 0; i<N; i++){
        for(size_t j = 0; j<N; j++){
            std::cin>>graph[i][j];
        }
    }

    std::vector<std::vector<bool>> isBlindVisited(N,std::vector<bool>(N,false));
    std::vector<std::vector<bool>> isnonBlindVisited(N,std::vector<bool>(N,false));

    int nonRGcount = 0;
    int RGcount = 0;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for(size_t i = 0; i<N; i++){
        for(size_t j = 0; j<N; j++){
                bool isRGblindess = false;
            for(size_t k = 0; k<2; k++){
                std::queue<std::pair<int,int>> queue;
                queue.push({i,j});
                char curColor = graph[i][j];
                if(isRGblindess){
                    if(!isBlindVisited[i][j]){
                        isBlindVisited[i][j] = true;
                        while(!queue.empty()){
                            std::pair<int,int> pos = queue.front();
                            queue.pop();
                            for(size_t index = 0; index<4; index++){
                                int newX = pos.second+dx[index];
                                int newY = pos.first+dy[index];
                                if(0<=newX && newX<N && 0<=newY &&newY<N&&!isBlindVisited[newY][newX]){
                                    if(curColor != 'B' && graph[newY][newX] != 'B'){
                                        queue.push({newY,newX});
                                        isBlindVisited[newY][newX] = true;
                                    } else if(curColor == 'B' && graph[newY][newX]=='B'){
                                        queue.push({newY,newX});
                                        isBlindVisited[newY][newX] = true;
                                    }
                                }
                            }
                            
                        }
                        RGcount++;
                    }
                } else {
                    if(!isnonBlindVisited[i][j]){
                        isnonBlindVisited[i][j] = true;
                        while(!queue.empty()){
                            std::pair<int,int> pos = queue.front();
                            queue.pop();
                            for(size_t index = 0; index<4; index++){
                                int newX = pos.second+dx[index];
                                int newY = pos.first+dy[index];
                                if(0<=newX && newX<N && 0<=newY &&newY<N &&!isnonBlindVisited[newY][newX]){
                                    if(curColor == graph[newY][newX] ){
                                        queue.push({newY,newX});
                                        isnonBlindVisited[newY][newX] = true;
                                    }
                                }
                            }
                        }
                        nonRGcount++;
                    }
                }
                isRGblindess = true;
            }
        }
    }
    std::cout<<nonRGcount<<" "<<RGcount;
    
    return 0;
}