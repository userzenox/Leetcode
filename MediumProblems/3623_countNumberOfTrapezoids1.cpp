#include <bits/stdc++.h>
using namespace std;

long long countTrapezoids(vector<vector<int>>& points) {

    unordered_map<int, int> mp; // y -> count

    // Count how many points exist for each y-coordinate
    for (auto &point : points) {
        int y = point[1];
        mp[y]++;
    }

    long long result = 0;  // total number of trapezoids
    long long prevHorizontalLines = 0; 

    // Iterate through each distinct y-level
    for (auto &it : mp) {
        int count = it.second;

        // Number of horizontal line pairs from points on this y-level
        long long horizontalLines = 1LL * count * (count - 1) / 2; // nC2

        // Each new level can form trapezoids with previous levels
        result += horizontalLines * prevHorizontalLines;

        prevHorizontalLines += horizontalLines;
    }

    return result;
}

int main() {
    vector<vector<int>> points = {{1,1}, {2,1}, {5,1}, {0,2}, {3,2}, {6,2}};
    cout << countTrapezoids(points) << endl;
    return 0;
}
