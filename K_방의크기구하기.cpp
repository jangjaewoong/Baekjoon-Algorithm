#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){
        int m,n; // m이 가로 n이 세로 길이
        std::cin>>m>>n;
        std::vector<std::vector<char>> graph(n,std::vector<char>(m));
        std::vector<int> result;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ;j++){
                std::cin>>graph[i][j];
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m ;j++){
                if(graph[i][j]=='.'){
                    std::queue<std::pair<int,int>> Q;
                    std::pair<int,int> pos = std::make_pair(i,j);
                    Q.push(pos);
                    int sum = 1;
                    graph[i][j]='+';
                    while(!Q.empty()){
                        int tx = Q.front().second;
                        int ty = Q.front().first;
                        
                        Q.pop();
                        for(int k = 0; k<4; k++){
                            int x = tx+dx[k];
                            int y = ty+dy[k];
                            if(y>=0&&y<=n&&x>=0&&x<=m&&graph[y][x]=='.'){
                                std::pair<int,int> tmp = std::make_pair(y,x);
                                Q.push(tmp);
                                graph[y][x]='+';
                                sum++;
                            }
                        }
                    }
                    result.push_back(sum);
                }
            }
        }
        std::sort(result.begin(),result.end(),std::greater<int>());
        std::cout<<result.size()<<"\n";
        for(int i : result){
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
    }
}