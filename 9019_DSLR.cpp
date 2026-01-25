#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int D(int n) { return (n * 2) % 10000; }
int S(int n) { return (n + 9999) % 10000; }
int L(int n) { return (n % 1000) * 10 + n / 1000; }
int R(int n) { return (n % 10) * 1000 + n / 10; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    std::cin >> T;
    
    while(T--) {
        int start, target;
        std::cin >> start >> target;
        
        std::vector<bool> visited(10000, false);
        std::vector<std::pair<int, char>> parent(10000, {-1, ' '});
        
        std::queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if(cur == target) break;
            
   
            int next = D(cur);
            if(!visited[next]) {
                visited[next] = true;
                parent[next] = {cur, 'D'};  
                q.push(next);
            }
  
 
            next = S(cur);
            if(!visited[next]) {
                visited[next] = true;
                parent[next] = {cur, 'S'};
                q.push(next);
            }
            

            next = L(cur);
            if(!visited[next]) {
                visited[next] = true;
                parent[next] = {cur, 'L'};
                q.push(next);
            }
            
   
            next = R(cur);
            if(!visited[next]) {
                visited[next] = true;
                parent[next] = {cur, 'R'};
                q.push(next);
            }
        }
        

        std::string path = "";
        int cur = target;
        
        while(cur != start) {
            path += parent[cur].second;  
            cur = parent[cur].first;     
        }
        

        std::reverse(path.begin(), path.end());
        
        std::cout << path << "\n";
    }
    
    return 0;
}