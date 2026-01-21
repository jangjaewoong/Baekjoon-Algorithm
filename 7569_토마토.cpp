#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int M,N,H;
    std::cin>>M>>N>>H;
    
    std::vector<std::vector<std::vector<int>>> graph(H,std::vector<std::vector<int>>(N,std::vector<int>(M,0)));
    std::vector<std::vector<std::vector<bool>>> isVisited(H,std::vector<std::vector<bool>>(N,std::vector<bool>(M,false)));
    std::vector<std::vector<int>> startQueue;
    for(int i = 0; i<H; i++){
        for(int j = 0; j<N; j++){
            for(int k = 0; k<M; k++){
                std::cin>>graph[i][j][k];
                if(graph[i][j][k]==1){
                    startQueue.push_back({i,j,k});
                }
            }
        }
    }
    
    int dx[6] = {1,-1,0,0,0,0};
    int dy[6] = {0,0,1,-1,0,0};
    int dh[6] = {0,0,0,0,1,-1};

    std::queue<std::vector<int>> queue;
    for(int i = 0; i<startQueue.size(); i++){
        queue.push(startQueue[i]);
    }
    int count = 0;
    while(!queue.empty()){
        int size = queue.size();
        for(int i = 0; i<size; i++){
            std::vector<int> index = queue.front();
            queue.pop();
            isVisited[index[0]][index[1]][index[2]] = true;
            for(int j = 0; j<6; j++){
                int newH = index[0]+dh[j];
                int newY = index[1]+dy[j];
                int newX = index[2]+dx[j];
                if(0<=newH&&newH<H&&0<=newX&&newX<M&&0<=newY&&newY<N){
                    if(!isVisited[newH][newY][newX]){
                        if(graph[newH][newY][newX]==0){
                            graph[newH][newY][newX]=1;
                            isVisited[newH][newY][newX] = true;
                            queue.push({newH,newY,newX});
                        }
                    }
                }
            }
        }
        count++;
    }
    
    for(int i = 0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k = 0; k<M; k++){
                if(graph[i][j][k]==0){
                    std::cout<<"-1\n";
                    return 0;
                }
            }
        }
    }

    std::cout<<count-1<<"\n";
    return 0;
}