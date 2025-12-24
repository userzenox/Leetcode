#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int n : apple) {
            totalApples += n;
        }
        
        // Sort capacity in descending order (largest first)
        sort(capacity.begin(), capacity.end(), [](int a, int b) {
            return a > b;
        });
        
        int currentCapacity = 0;
        int boxCount = 0;
        
        // Greedily pick largest boxes until capacity >= totalApples
        for (int cap : capacity) {
            if (currentCapacity >= totalApples) {
                return boxCount;
            }
            currentCapacity += cap;
            boxCount++;
        }
        
        return boxCount;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: [1,2,3] apples, [1,2] capacities
    vector<int> apple1 = {1, 2, 3};
    vector<int> capacity1 = {1, 2};
    cout << "Test 1: " << sol.minimumBoxes(apple1, capacity1) 
         << " (Expected: 3)" << endl;  // 6 apples need all 3 boxes
    
    // Test Case 2: [3,5] apples, [4,5,7] capacities  
    vector<int> apple2 = {3, 5};
    vector<int> capacity2 = {4, 5, 7};
    cout << "Test 2: " << sol.minimumBoxes(apple2, capacity2) 
         << " (Expected: 2)" << endl;  // 8 apples fit in 7+5=12
    
    // Test Case 3: [1,2] apples, [3] capacity
    vector<int> apple3 = {1, 2};
    vector<int> capacity3 = {3};
    cout << "Test 3: " << sol.minimumBoxes(apple3, capacity3) 
         << " (Expected: 1)" << endl;  // 3 apples fit in 3
    
    // Test Case 4: Large input
    vector<int> apple4 = {5,5,5,5,5,5,5};
    vector<int> capacity4 = {6,7,8,9,10};
    cout << "Test 4: " << sol.minimumBoxes(apple4, capacity4) 
         << " (Expected: 4)" << endl;  // 35 apples need 10+9+8+7=34
        
    return 0;
}
