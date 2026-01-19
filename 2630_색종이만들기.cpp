#include <iostream>
#include <vector>
#include <utility>



std::pair<int,int> RecurPaper(std::pair<int,int> start, int dist, std::vector<std::vector<int>>& graph ){
    int blue_num = 0;
    int white_num = 0;
    if(dist==1){
        if(graph[start.first][start.second]==1){
            return {++blue_num,white_num};
        } else {
            return {blue_num,++white_num};
        }
    }
    bool isBluePass = true;
    bool isWhitePass = true;
    for(int i = start.first; i<(start.first+dist) ; i++){
        for(int j = start.second; j<(start.second+dist); j++){
            if(graph[i][j] == 0){
                isBluePass = false;
                break;
            }
        }
    }
    for(int i = start.first; i<(start.first+dist) ; i++){
        for(int j = start.second; j<(start.second+dist); j++){
            if(graph[i][j] == 1){
                isWhitePass = false;
                break;
            }
        }
    }

    
    dist /=2;
    std::pair<int,int> start1 = {start.first,start.second};
    std::pair<int,int> start2 = {start.first,start.second+dist};
    std::pair<int,int> start3 = {start.first+dist,start.second};
    std::pair<int,int> start4 = {start.first+dist,start.second+dist};
    
    if(!isBluePass&&!isWhitePass){
        std::pair<int,int> a = RecurPaper(start1, dist, graph);
        std::pair<int,int> b = RecurPaper(start2, dist, graph);
        std::pair<int,int> c = RecurPaper(start3, dist, graph);
        std::pair<int,int> d = RecurPaper(start4, dist, graph);
        blue_num = {a.first+b.first+c.first+d.first};
        white_num = {a.second+b.second+c.second+d.second};
    } else if(isBluePass){
        blue_num+=1;
    } else if(isWhitePass){
        white_num+=1;
    }
   
    return {blue_num,white_num};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; 
    std::cin>>N;
    std::vector<std::vector<int>> graph(N,std::vector<int>(N));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            int n;
            std::cin>>n;
            graph[i][j] = n;
        }
    }
    std::pair<int,int> start={0,0};
    std::pair<int,int> res = RecurPaper(start,N,graph);
    std::cout<<res.second<<"\n";
    std::cout<<res.first<<"\n";
    
    return 0;
}