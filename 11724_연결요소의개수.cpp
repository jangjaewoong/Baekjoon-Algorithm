#include <iostream>
#include <vector>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N,M;
    std::cin>>N>>M;
    int answer = 0;
    std::vector<int> graph[1001];
    bool visit[1001];
    int u,v;
    for(int i = 0 ; i<M; i++){
        std::cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::queue<int> q;
    for(int i = 1; i<N+1; i++){
        if(visit[i]) continue;
        q.push(i);
        visit[i] = true;
        while(!q.empty()){
            int index = q.front();
            q.pop();
            for(int j = 0; j<graph[index].size(); j++){
                if(visit[graph[index][j]]) continue;
                visit[graph[index][j]] = true;
                q.push(graph[index][j]);
            }
        }
        answer++;
    }
       
        
        
    
    std::cout<<answer<<"\n";
    return 0;
}