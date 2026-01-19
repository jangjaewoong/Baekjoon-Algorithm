#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    while(T--){
        int price_n, coupon;
        std::cin>>price_n>>coupon;
        std::unordered_map<int,std::vector<int>> map;
        std::vector<int> price_value(price_n);
        int sum =0;
        while(price_n--){
            int item;
            std::cin>>item;
            std::vector<int> tmp(item+1);
            for(int i = 1; i<=item; i++){
                std::cin>>tmp[i];
            }
            int price;
            std::cin>>price;
            price_value.push_back(price);
            map[price]=tmp;
        }
        std::vector<int> myBag(coupon+1);
        for(int i = 1 ; i<=coupon ; i++){
            std::cin>>myBag[i];
        }
        for(int i =0; i<price_value.size(); i++){
            while(true){
                int pass = true;
                for(int j = 1; i<=map[price_value[i]].size();j++){
                    if(myBag[j]-map[price_value[i]][j]<0){
                        pass=false;
                        break;
                    }
                    
                }
               
            }
        }

    }
    return 0;
}