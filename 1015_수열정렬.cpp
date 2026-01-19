#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> A(N);
    std::vector<int> P(N);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end()); 
    for (int newIndex = 0; newIndex < N; newIndex++) {
        int originalIndex = A[newIndex].second;
        P[originalIndex] = newIndex;
    }

    for (int i = 0; i < N; i++) {
        std::cout << P[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
