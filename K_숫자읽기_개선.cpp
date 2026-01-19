#include <iostream>
#include <vector>
#include <string>
#include <array>

std::array<std::string, 20> underTwenty = {
    "", "One_", "Two_", "Three_", "Four_", "Five_", "Six_", "Seven_", "Eight_", "Nine_",
    "Ten_", "Eleven_", "Twelve_", "Thirteen_", "Fourteen_", "Fifteen_", "Sixteen_", "Seventeen_", "Eighteen_", "Nineteen_"
};

std::array<std::string, 10> tens = {
    "", "", "Twenty_", "Thirty_", "Forty_", "Fifty_", "Sixty_", "Seventy_", "Eighty_", "Ninety_"
};

std::vector<std::string> units = {"", "Thousand_", "Million_", "Billion_"};

std::string convertThreeDigits(const std::string& num) {
    int n = std::stoi(num);
    if (n == 0) return "";

    std::string result;
    if (n >= 100) {
        result += underTwenty[n / 100] + "Hundred_";
        n %= 100;
    }
    if (n >= 20) {
        result += tens[n / 10] + underTwenty[n % 10];
    } else {
        result += underTwenty[n];
    }
    return result;
}

// 숫자 문자열 전체를 영어로 변환
std::string numberToWords(const std::string& numStr) {
    std::string num = numStr;
    // 0 처리
    if (num == "0") return "Zero";

    // 뒤에서부터 3자리씩 끊기
    std::vector<std::string> groups;
    while (!num.empty()) {
        int len = num.size();
        std::string group = num.substr(len >= 3 ? len - 3 : 0, len >= 3 ? 3 : len);
        groups.push_back(group);
        if (len <= 3) break;
        num.erase(len - 3);
    }

    // 각 그룹 변환
    std::string result;
    for (int i = groups.size() - 1; i >= 0; --i) {
        std::string word = convertThreeDigits(groups[i]);
        if (!word.empty()) {
            result += word + units[i];
        }
    }

    // 마지막 '_' 제거
    if (!result.empty() && result.back() == '_') result.pop_back();
    return result;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        std::string num;
        std::cin >> num;
        std::cout << numberToWords(num) << "\n";
    }
}
