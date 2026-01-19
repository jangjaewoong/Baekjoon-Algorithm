#include <iostream>
#include <vector>
#include <algorithm> 

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);

        long long int sum = 1;
        int count2 = 0, count5 = 0;

        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
            int x = arr[i];

            while (x % 2 == 0) {
                ++count2;
                x /= 2;
            }
            while (x % 5 == 0) {
                ++count5;
                x /= 5;
            }

            sum *= x;
            while (sum % 10 == 0) sum /= 10;
            sum %= 1000000000; 
        }

        int zero = std::min(count2, count5);

        for (int i = 0; i < count2 - zero; ++i) {
            sum *= 2;
            while (sum % 10 == 0) sum /= 10;
            sum %= 1000000000;
        }

        for (int i = 0; i < count5 - zero; ++i) {
            sum *= 5;
            while (sum % 10 == 0) sum /= 10;
            sum %= 1000000000;
        }

        std::cout << sum % 10 << " " << zero << "\n";
    }

    return 0;
}
