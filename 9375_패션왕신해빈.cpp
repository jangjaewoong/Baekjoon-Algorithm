#include <iostream>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;
        std::unordered_map<std::string, int> wear;

        for (int i = 0; i < n; i++) {
            std::string cloth, tag;
            std::cin >> cloth >> tag;
            wear[tag]++;
        }

        int total = 1;
        for (auto it = wear.begin(); it != wear.end(); ++it) {
            total *= (it->second + 1); 
        }

        std::cout << total - 1 << "\n"; 
    }

    return 0;
}
