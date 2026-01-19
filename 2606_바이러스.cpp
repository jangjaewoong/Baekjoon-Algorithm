#include <iostream>
#include <vector>
#include <queue>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int V,E;
    std::cin>>V>>E;
    std::vector<std::vector<int>> graph(V+1);
    std::vector<bool> isvisited(V+1,false);
    for(int i = 0; i<E; i++){
        int a,b;
        std::cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    std::queue<int> Q;
    Q.push(1);
    int sum=0;
    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        if(isvisited[node]) continue;
        isvisited[node]=true;
        sum++;
        for(int i : graph[node]){
            if(!isvisited[i]){
                Q.push(i);
            }
        }
    }

    std::cout<<sum-1<<"\n";
    return 0;
}