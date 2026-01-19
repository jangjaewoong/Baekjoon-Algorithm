#include <iostream>
#include <cmath>
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    while(T--){
        int x1,y1,r1,x2,y2,r2;
        std::cin>>x1>>y1>>r1>>x2>>y2>>r2;
        
        double d = sqrt(pow(x1 - x2 , 2) + pow(y1-y2,2));

        if(d==0 && r1==r2){
            std::cout<<-1<<"\n";
        } else if(d==0 || d>r1+r2 || d<abs(r1-r2)){
            std::cout<<0<<"\n";
        } else if(d==r1+r2 || d== abs(r1-r2)){
            std::cout<<1<<"\n";
        } else{
            std::cout<<2<<"\n";
        }
       
    }
    return 0;
}