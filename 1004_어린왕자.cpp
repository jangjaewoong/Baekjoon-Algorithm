#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin>>T;
    while(T--){ 
        int b_x,b_y,e_x,e_y;
        std::cin>>b_x>>b_y>>e_x>>e_y;
        int n;
        std::cin>>n;
        int value = 0;
        for(int i = 0; i<n; i++){
            int x,y,r;
            std::cin>>x>>y>>r;
            int dis_b = (x-b_x)*(x-b_x)+(y-b_y)*(y-b_y);
            int dis_e = (x-e_x)*(x-e_x)+(y-e_y)*(y-e_y);
            if(dis_b<r*r&&dis_e<r*r){
                continue;
            } 
            if(dis_b<r*r){
                value++;
            }
            if(dis_e<r*r){
                value++;
            }
        }
        std::cout<<value<<"\n";
    }
    return 0;
}