#include <iostream>
#include <unordered_map>

bool isleap(int year){
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    

    int T;
    std::cin >> T;
    while(T--){
        std::unordered_map<int,int> map = {
        {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30},
        {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31}
        };
        int year, month;
        std::cin >> year >> month;
        int leap_year;
        int days;
        int start_day = 5;
        if(year == 1582){
            leap_year = 0;
        } else {
            leap_year = ((year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) - (395 - 15 + 3);
        }
        days = (year - 1582) * 365 + leap_year;
        for (int i = 1; i < month; i++){
            days += map[i];
        }
        if (isleap(year)){
            map[2]++;
            if(month>2){
                days++;
            }
        }
        start_day = (days % 7 + start_day) % 7;
        int count = ((start_day + map[month]) % 7 == 0 ? (start_day + map[month]) / 7 * 7 : ((start_day + map[month]) / 7 + 1) * 7);
        int index = 1;
        std::cout<<year<<" "<<month<<"\n";
        for (int i = 1; i <= count; i++){
            if(i > start_day && i <= map[month] + start_day){
                std::cout << index << " ";
                index++;
            } else {
                std::cout << "0 ";
            }
            if(i % 7 == 0){
                std::cout << "\n";
            }
        }
    }
    
    return 0;
}
