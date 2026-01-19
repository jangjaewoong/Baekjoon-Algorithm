#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N,K;
    std::cin >> N >> K;

    bool visited[100001]={false};
    std::queue<int> q;
    int days = 0;
    q.push(N);
    while (!q.empty()) {
        int size = q.size(); 
        for (int i = 0; i < size; ++i) {
            int cur = q.front(); q.pop();
            if(cur==K){
                std::cout<<days<<"\n";
                return 0; 
                }
            int next_pos[3] = {cur*2, cur+1,cur-1};
            for(int j = 0; j<3; j++){
                int next = next_pos[j];
                if(next>=0&&next<100001&&!visited[next]){
                    q.push(next);
                    visited[next]= true;
                    }
                }
            }
            ++days;
        }
        return 0;
}


    