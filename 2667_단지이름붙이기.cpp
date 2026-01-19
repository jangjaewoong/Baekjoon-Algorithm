#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin>>N;
    std::vector<std::vector<char>> graph(N,std::vector<char>(N));
    for(int i = 0; i<N; i++){
        std::string str;
        std::cin>>str;
        for(int j = 0; j<N; j++){
            graph[i][j]= str[j];
        }
    }
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    std::vector<int> sum;
    for(int i=0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(graph[i][j]=='1'){
                std::queue<std::pair<int,int>> Q;
                Q.push({i,j});
                int count = 0;
                graph[i][j]='x';
                while(!Q.empty()){
                    auto [x,y] = Q.front();
                    Q.pop();
                    for(int i =0 ; i<4; i++){
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        if(nx>=0&&nx<N&&ny>=0&&ny<N){
                            if(graph[nx][ny]=='1'){
                                Q.push({nx,ny});
                                count++;
                                graph[nx][ny]='x';
                            }
                        }
                    }
                }
                sum.push_back(count+1);
            }
        }
    }

    std::sort(sum.begin(),sum.end());
    std::cout<<sum.size()<<"\n";
    for(int i : sum){
        std::cout<<i<<"\n";
    }
    return 0;
}