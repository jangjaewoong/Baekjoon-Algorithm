#include <iostream>
#include <queue>
#include <utility>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin>>T;

    while(T--){
        int M,N,K;
        std::cin>>M>>N>>K;
        std::vector<std::vector<int>> graph(N,std::vector<int>(M,0));
        for(int i = 0; i<K; i++){
            int r,c;
            std::cin>>c>>r;
            graph[r][c]=1;
        }
        int worm=0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int i =0; i<N;i++){
            for(int j = 0; j<M; j++){
                if(graph[i][j]==1){
                    worm++;
                    std::queue<std::pair<int,int>> Q;
                    Q.push({i,j});
                    graph[i][j]=0;
                    while(!Q.empty()){
                        auto [x,y] = Q.front();
                        Q.pop();
                        for(int k=0; k<4; k++){
                            int nx = x+dx[k];
                            int ny = y+dy[k];
                            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                                if(graph[nx][ny]==1){
                                    Q.push({nx,ny});
                                    graph[nx][ny]=0;
                                }
                            }
                        }
                    }
                }
            }
        
        
        }
        std::cout<<worm<<"\n";
    }
    return 0;
}