#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<char>> castle(N, std::vector<char>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            std::cin >> castle[i][j];

    int row_need = 0;
    for (int i = 0; i < N; ++i) {
        bool has_guard = false;
        for (int j = 0; j < M; ++j) {
            if (castle[i][j] == 'X') {
                has_guard = true;
                break;
            }
        }
        if (!has_guard) row_need++;
    }

    int col_need = 0;
    for (int j = 0; j < M; ++j) {
        bool has_guard = false;
        for (int i = 0; i < N; ++i) {
            if (castle[i][j] == 'X') {
                has_guard = true;
                break;
            }
        }
        if (!has_guard) col_need++;
    }

    std::cout << std::max(row_need, col_need) << "\n";
    return 0;
}
