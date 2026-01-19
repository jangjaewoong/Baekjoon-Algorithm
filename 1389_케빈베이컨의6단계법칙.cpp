#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <limits>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> score(N+1, 0);
    
    std::map<int, std::set<int>> graph;
    for(int i = 0; i < M; i++){
        int a, b;
        std::cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    
    // 각 노드에서 BFS 수행
    for(int start = 1; start <= N; start++){
        std::queue<int> q;
        std::vector<bool> visited(N+1, false);
        
        q.push(start);
        visited[start] = true;
        
        int distance = 0;
        
        while(!q.empty()){
            int levelSize = q.size();  // 현재 depth의 노드 개수
            distance++;
            
            for(int i = 0; i < levelSize; i++){
                int current = q.front();
                q.pop();
                
                // 인접 노드들 탐색
                for(int next : graph[current]){
                    if(!visited[next]){
                        visited[next] = true;
                        score[start] += distance;
                        q.push(next);
                    }
                }
            }
        }
    }
    
    int min_Score = std::numeric_limits<int>::max();
    int bacon = 0;
    
    for(int i = 1; i <= N; i++){
        if(score[i] < min_Score){
            min_Score = score[i];
            bacon = i;
        }
    }
    
    std::cout << bacon << "\n";
    
    return 0;
}