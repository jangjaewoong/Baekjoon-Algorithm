#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::map<std::pair<int,int>, char> map;
    int N,M;
    std::cin>>N>>M;
    for(int i = 0; i<M; i++){
        int a, b;
        char c;
        std::cin>>a>>b>>c;
        map[{a,b}]=c;
    }

    std::vector<std::pair<std::pair<int, int>, char>> vec(map.begin(), map.end());
    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        if (a.first.second != b.first.second)
            return a.first.second < b.first.second;
        return a.first.first < b.first.first;
    });

    for (const auto& [key, value] : vec) {
        std::cout << value;
    }
   
    std::cout<<"\n";
       
}