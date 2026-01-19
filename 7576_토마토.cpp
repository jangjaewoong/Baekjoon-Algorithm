#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, N;
    std::cin >> M >> N;

    std::vector<std::vector<int>> graph(N, std::vector<int>(M));
    std::queue<std::pair<int, int>> q;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cin >> graph[i][j];
            if (graph[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    int days = -1;

    while (!q.empty()) {
        int size = q.size(); 
        for (int i = 0; i < size; ++i) {
            auto [y, x] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                    if (graph[ny][nx] == 0) {
                        graph[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }
        }
        ++days;
    }

    for (const auto& row : graph) {
        for (int cell : row) {
            if (cell == 0) {
                std::cout << "-1\n";
                return 0;
            }
        }
    }

    std::cout << (days == -1 ? 0 : days) << "\n";

    return 0;
}
