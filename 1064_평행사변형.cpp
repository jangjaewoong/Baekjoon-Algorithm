#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    double x1,y1,x2,y2,x3,y3;
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
    
    double a1 = std::sqrt(std::pow(x1-x2,2)+std::pow(y1-y2,2));
    double a2 = std::sqrt(std::pow(x2-x3,2)+std::pow(y2-y3,2));
    double a3 = std::sqrt(std::pow(x3-x1,2)+std::pow(y3-y1,2));
    
    double S = 0.5 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    //행렬식 기반 넓이 유도(세점 이용)
    if(!S){
        std::cout<<"-1\n";
        return 0;
    }
    double case1 = 2*a1+2*a2;
    double case2 = 2*a2+2*a3;
    double case3 = 2*a3+2*a1;
    
    std::cout<<std::fixed<<std::setprecision(16)<<std::max({case1,case2,case3})-std::min({case1,case2,case3})<<"\n";
    
        
    return 0;
}