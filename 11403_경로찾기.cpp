#include <iostream>
#include <vector>
#include <map>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin>>N;
    std::map<int,std::vector<int>> graph;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int edge;
            std::cin>>edge;
            if(edge==1){
                graph[i].push_back(j);
            }
        }
    }
    std::vector<std::vector<bool>> isVisited(N,std::vector<bool>(N,false));
    std::queue<int> queue;
    for(int i = 0; i<N; i++){
        queue.push(i);
        while(!queue.empty()){
            int vertex = queue.front();
            queue.pop();
            for(int next : graph[vertex]){
                if(!isVisited[i][next]){
                    isVisited[i][next] = true;
                    queue.push(next);
                }
            }
        }    
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            std::cout<<(isVisited[i][j]?"1":"0")<<" ";
        }
        std::cout<<"\n";
    }
    
    return 0;
}