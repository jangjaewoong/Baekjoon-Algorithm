#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, V;
    std::cin >> N >> M >> V;
    
    std::vector<std::vector<int>> graph(N+1);
    for(int i=0 ; i<M; i++){
        int a,b;
        std::cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i<=N; i++){
        std::sort(graph[i].begin(),graph[i].end());
    }

    std::vector<bool> dfsVisited(N+1,false);
    std::stack<int> S;
    S.push(V);

    while(!S.empty()){
        int node = S.top();
        S.pop();
        if(dfsVisited[node]) continue;
        dfsVisited[node] = true;
        std::cout<<node<<" ";

        for(auto it = graph[node].rbegin(); it !=graph[node].rend(); ++it){
            if(!dfsVisited[*it]){
                S.push(*it);
            }
        }
    }
    std::cout<<"\n";

    std::vector<bool> bfsVisited(N+1, false);
    std::queue<int> Q;
    Q.push(V);

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        if(bfsVisited[node]) continue;
        bfsVisited[node] = true;
        std::cout<<node<<" ";

        for(int i : graph[node]){
            if(!bfsVisited[i]){
                Q.push(i);
            }
        }
    }

    std::cout<<"\n";
    
    return 0;
}
