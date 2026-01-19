#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin>>T;
    while(T--){
        int p[4];
        int q[4];
        for(int i = 0; i<4; i++){
            std::cin>>p[i];
        }
        for(int i = 0; i<4; i++){
            std::cin>>q[i];
        }
        bool graph[p[3]>q[3]?p[3]+1:q[3]+1][p[2]>q[2]?p[2]+1:q[2]+1] = {false};
        int area_sum=0;
        int doubled=0;
        for(int i=p[1]; i<p[3]; i++){
            for(int j=p[0]; j<p[2];j++){
                graph[i][j]=true;
                area_sum++;
            }
        }
        int d1[2]={-1,-1};
        int d2[2]={-1,-1};
        for(int i=q[1]; i<q[3]; i++){
            for(int j=q[0]; j<q[2];j++){
                if(graph[i][j]==true){
                    if(d1[0]==-1&&d1[1]==-1){
                        d1[0]=j;
                        d1[1]=i;
                    }
                    d2[0] =j;
                    d2[1] = i;
                    doubled++;
                } else {
                    graph[i][j]=true;
                    area_sum++;
                }
            }
        }
        int peri;
        if(doubled>0){
            peri = 2*(p[3]-p[1]+p[2]-p[0])+2*(q[3]-q[1]+q[2]-q[0])-2*(d2[1]+1-d1[1]+d2[0]+1-d1[0]);
        } else{
            peri = 2*(p[3]-p[1]+p[2]-p[0])+2*(q[3]-q[1]+q[2]-q[0]);
        }
        std::cout<<area_sum<<" "<<peri<<"\n";
    }
    return 0;
}
