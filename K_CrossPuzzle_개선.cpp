#include <iostream>
#include <vector>
#include <string>

const int dx[8] = {-1, -1,  0, 1, 1,  1,  0, -1}; 
const int dy[8] = { 0,  1,  1, 1, 0, -1, -1, -1};

int findDirection(int s_row, int s_col, int m, int n, const std::string& word, const std::vector<std::vector<char>>& graph) {
    int length = word.size();

    for (int dir = 0; dir < 8; ++dir) {
        int end_row = s_row + dx[dir] * (length - 1);
        int end_col = s_col + dy[dir] * (length - 1);

        if (end_row < 0 || end_row >= m || end_col < 0 || end_col >= n)
            continue;

        bool match = true;
        for (int i = 0; i < length; ++i) {
            int nx = s_row + dx[dir] * i;
            int ny = s_col + dy[dir] * i;
            if (graph[nx][ny] != word[i]) {
                match = false;
                break;
            }
        }

        if (match) return dir;
    }

    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T;
    std::cin >> T;

    while (T--) {
        int m, n;
        std::cin >> m >> n;

        std::vector<std::vector<char>> graph(m, std::vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> graph[i][j];
            }
        }

        int word_n;
        std::cin >> word_n;
        std::vector<std::string> words(word_n);
        for (int i = 0; i < word_n; ++i) {
            std::cin >> words[i];
        }

        for (const auto& word : words) {
            int result = -1;
            int result_row = -1;
            int result_col = -1;

            for (int i = 0; i < m && result == -1; ++i) {
                for (int j = 0; j < n && result == -1; ++j) {
                    if (graph[i][j] == word[0]) {
                        int dir = findDirection(i, j, m, n, word, graph);
                        if (dir != -1) {
                            result = dir;
                            result_row = i;
                            result_col = j;
                        }
                    }
                }
            }

            if (result == -1) {
                std::cout << "-1\n";
            } else {
                std::cout << result_row + 1 << " " << result_col + 1 << " " << result << "\n";
            }
        }
    }

    return 0;
}
