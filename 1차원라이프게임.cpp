#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    while (T--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> cell(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> cell[i];
        }

        for (int t = 0; t < k; ++t) {
            std::vector<int> next = cell;
            for (int i = 0; i < n; ++i) {
                int neighbors = 0;
                if (i > 0) neighbors += cell[i - 1];
                if (i < n - 1) neighbors += cell[i + 1];

                if (neighbors < 3 && cell[i] > 0) {
                    next[i]--;
                } else if (neighbors > 7 && cell[i] > 0) {
                    next[i]--;
                } else if (neighbors >= 4 && neighbors <= 7 && cell[i] < 9) {
                    next[i]++;
                }

            }
            cell = next;
        }

        for (int i = 0; i < n; ++i) {
            std::cout << cell[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
