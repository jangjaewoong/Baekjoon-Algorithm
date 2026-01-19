#include <iostream>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    bool graph[101][101] = {false};
    int doubled=0;
    int T = 4;
    while(T--){
        int x1,x2,y1,y2;
        std::cin>>x1;
        std::cin>>y1;
        std::cin>>x2;
        std::cin>>y2;
        for(int i = y1; i<y2; i++){
            for(int j = x1; j<x2; j++){
                if(!graph[i][j]){
                    graph[i][j]=true;
                    doubled+=1;
                }
            }
        }
    }
    std::cout<<doubled<<"\n";
    return 0;
}