#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string L, R;
    std::cin>>L>>R;
    
    if(L.size() != R.size()){
        std::cout<<"0\n";
        return 0;
    } 
  
    int min = 0;
    for(size_t i = 0; i<L.size(); i++){
        if(L[i]!=R[i]) break;
        if((L[i]==R[i])&&L[i]=='8') ++min;
    }
    std::cout<<min<<"\n";
    

    return 0;
}