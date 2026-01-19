#include <iostream>
#include <vector>
#include <utility>


std::pair<int,int> move(std::string str){
    if (str.size()==1){
        if(str=="R"){
            return {0,1};
        } else if(str=="L"){
            return {0,-1};
        } else if(str=="B"){
            return {1,0};
        } else if(str=="T"){
            return {-1,0};
        }
    }
    else{
        if (str[0]=='R'){
            if(str[1]=='T'){
                return {-1,1};
            } else {
                return {1,1};
            }
        }
        if (str[0] == 'L'){
            if(str[1]=='T'){
                return {-1,-1};
            } else{
                return {1,-1};
                }
            }
        } 
    
}



int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string king_pos;
    std::cin>>king_pos;
    int king_x = king_pos[0]-65;
    int king_y = 7-(king_pos[1]-'1');
    
    std::string stone_pos;
    std::cin>>stone_pos;
    int stone_x = stone_pos[0]-65;
    int stone_y = 7-(stone_pos[1]-'1');
    int T;
    std::cin>>T;
    for(int i = 0; i<T; i++){
        std::string order;
        std::cin>>order;
        std::pair<int,int> pos = move(order);
        if(king_x+pos.second<8 && king_x+pos.second>=0 &&king_y+pos.first<8 &&king_y+pos.first>=0){
            if((king_x+pos.second)==stone_x && (king_y+pos.first)==stone_y){
                if(stone_x+pos.second<8 && stone_x+pos.second>=0 &&stone_y+pos.first<8 &&stone_y+pos.first>=0){
                    stone_x += pos.second;
                    stone_y += pos.first;
                    king_x += pos.second;
                    king_y += pos.first;
                }
            } else {
                king_x += pos.second;
                king_y += pos.first;
            }
        }
    }
    king_y = 8-king_y;
    stone_y = 8-stone_y;
    std::string k_result = "";
    k_result+=king_x+'A';
    k_result+=king_y+'0';
    std::string s_result = "";
    s_result+=stone_x+'A';
    s_result+=stone_y+'0';

    std::cout<<k_result<<"\n";
    std::cout<<s_result<<"\n";
}