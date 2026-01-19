#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<int>> graph(N,std::vector<int>(M));
    for(int i = 0; i<N; i++){
        std::string str;
        std::cin>>str;
        for(int j = 0; j<M; j++){
            graph[i][j] = str[j]-'0';
        }
    }
    int y = 0;
    int x = 0;
    int length = std::min(N,M)-1;
    int max = 1;
    while(length>0){
        if(x+length<M&&y+length<N){
            if(graph[y][x]==graph[y+length][x+length]&&graph[y+length][x]==graph[y][x+length]&&graph[y][x]==graph[y+length][x]){
                max= length+1;    
                break;
            }
        } else if(x+length>=M&&y+length>=N){
            length--;
            y=0;
            x=-1;
        } else if(x+length>=M){
            y++;
            x=-1;
        }
        x++;
    }
    std::cout<<max*max<<"\n";
}