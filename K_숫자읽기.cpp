#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<char, std::string> onesMap = {
        {'0', ""},
        {'1', "One_"},
        {'2', "Two_"},
        {'3', "Three_"},
        {'4', "Four_"},
        {'5', "Five_"},
        {'6', "Six_"},
        {'7', "Seven_"},
        {'8', "Eight_"},
        {'9', "Nine_"}
    };

std::unordered_map<char, std::string> tensMap = {
        {'0', ""},
        {'2', "Twenty_"},
        {'3', "Thirty_"},
        {'4', "Forty_"},
        {'5', "Fifty_"},
        {'6', "Sixty_"},
        {'7', "Seventy_"},
        {'8', "Eighty_"},
        {'9', "Ninety_"}
    };

std::unordered_map<std::string, std::string> numberMap = {
        {"10", "Ten_"},
        {"11", "Eleven_"},
        {"12", "Twelve_"},
        {"13", "Thirteen_"},
        {"14", "Fourteen_"},
        {"15", "Fifteen_"},
        {"16", "Sixteen_"},
        {"17", "Seventeen_"},
        {"18", "Eighteen_"},
        {"19", "Nineteen_"},
};


    

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int T;
    std::cin>>T;
    std::string arr[3] = {"Thousand_", "Million_", "Billion_"};
    while(T--){
        std::string num;
        std::cin>>num;
        std::vector<std::string> vec;
        int div = 0;
        std::string tmp="";
        std::string result ="";
        for(int i = num.size()-1; i>=0; i--){
            tmp = num[i]+tmp;
            div++;
            if(div==3){
                vec.push_back(tmp);
                div = 0;
                tmp = "";
            }
        }
        if(tmp!=""){
            vec.push_back(tmp);
        }

        for(int i = vec.size()-1; i>=0; i--){
            tmp="";
            if(vec[i]=="000") continue;
            if(vec[i].size()==3 && vec[i][0]!='0'){
                tmp += onesMap[vec[i][0]]+"Hundred_";
            }
            if(vec[i].size()>=2){
                if(vec[i][vec[i].size()-2]=='1'){;
                    std::string key = "";
                    key.push_back(vec[i][vec[i].size()-2]);
                    key.push_back(vec[i][vec[i].size()-1]);
                    tmp+=numberMap[key];
                } else {
                    tmp+=tensMap[vec[i][vec[i].size()-2]]+onesMap[vec[i][vec[i].size()-1]];
                }
            } else{
                tmp+=onesMap[vec[i][vec[i].size()-1]];
            }
            if(i-1>=0){
                tmp+=arr[i-1];
            }
            result+=tmp;
            
        }
        result.pop_back();
        std::cout<<result<<"\n";
    }
    
}