#include <iostream>
#include <unordered_set>
#include <string>

int numJewelsInStones(const std::string& jewels, const std::string& stones) {
    std::unordered_set<char> jewelSet(jewels.begin(), jewels.end());
    int count = 0;
    for (char stone : stones) {
        if (jewelSet.count(stone)) {
            ++count;
        }
    }
    return count;
}

int main() {
    std::string jewels = "aA";
    std::string stones = "aAAbbbb";
    std::cout << "Number of jewels in stones: " << numJewelsInStones(jewels, stones) << std::endl;
    return 0;
}
