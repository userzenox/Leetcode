#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkcode(const string& s) {
        if (s.empty()) return false;

        for (char c : s) {
            if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9') ||
                c == '_') {
                continue;
            }
            return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

        int n = code.size();
        vector<pair<int, string>> ans;

        map<string, int> priority = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        for (int i = 0; i < n; i++) {
            bool c1 = checkcode(code[i]);
            bool c2 = (priority.count(businessLine[i]) > 0);
            bool c3 = isActive[i];

            if (c1 && c2 && c3) {
                ans.push_back({priority[businessLine[i]], code[i]});
            }
        }

        // Sort by priority first, then by coupon code automatically
        sort(ans.begin(), ans.end());

        vector<string> result;
        for (auto& p : ans) {
            result.push_back(p.second);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<string> code = {
        "m", "A", "B", "P", "J", "P", "u", "w", "4", "J", "C", "9"
    };

    vector<string> businessLine = {
        "electronics", "invalid", "invalid", "pharmacy",
        "invalid", "electronics", "restaurant", "grocery",
        "restaurant", "pharmacy", "pharmacy", "pharmacy"
    };

    vector<bool> isActive = {
        true, true, false, true, false, true,
        true, false, false, false, true, false
    };

    vector<string> result = sol.validateCoupons(code, businessLine, isActive);

    cout << "Valid Coupons:\n";
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
