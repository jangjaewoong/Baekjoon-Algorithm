#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M; 
    std::cin>>N>>M;
    std::vector<std::vector<char>> graph(N,std::vector<char>(M));
    for(int i = 0; i<N; i++){
        std::string str;
        std::cin>>str;
        for(int j = 0; j<M; j++){
            graph[i][j]=str[j];
        }
    }
    std::queue<std::pair<int,int>> Q;
    std::vector<std::vector<int>> dist(N,std::vector<int>(M,0));
    Q.push({0,0});
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    dist[0][0] = 1;

    while(!Q.empty()){
        auto [x,y] = Q.front();
        Q.pop();
        for(int i = 0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(graph[nx][ny]=='1'&&dist[nx][ny]==0){
                    Q.push({nx,ny});
                    dist[nx][ny]=dist[x][y]+1;
                }
            }
        }

    }

    std::cout<<dist[N-1][M-1]<<"\n";
    return 0;
}
