#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P; // freq, element

    int findTopKSum(unordered_map<int, int>& mp, int x) {
        // min-heap
        priority_queue<P, vector<P>, greater<P>> pq;

        for(auto &it : mp) { // O(k * log(k))
            pq.push({it.second, it.first});
            if(pq.size() > x) {
                pq.pop(); // remove smallest element from the top
            }
        }

        int sum = 0;
        while(!pq.empty()) {
            auto [freq, val] = pq.top();
            pq.pop();

            sum += freq * val;
        }

        return sum;
    }
    
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> result;
        
        int i = 0;
        int j = 0;

        while(j < n) {
            mp[nums[j]]++;

            if(j - i + 1 == k) {
                result.push_back(findTopKSum(mp, x));

                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2, 1, 3, 3, 2};
    int k = 4;
    int x = 2;

    vector<int> res = sol.findXSum(nums, k, x);
    for(int sum : res) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
