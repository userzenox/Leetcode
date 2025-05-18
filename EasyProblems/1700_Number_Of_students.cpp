#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> s;
        queue<int> q;

        // Push students into queue
        for (int i = 0; i < students.size(); i++) {
            q.push(students[i]);
        }

        // Push sandwiches into stack in reverse order
        for (int i = sandwiches.size() - 1; i >= 0; i--) {
            s.push(sandwiches[i]);
        }

        int count = 0;

        while (!q.empty()) {
            if (q.front() == s.top()) {
                q.pop();
                s.pop();
                count = 0; // Reset the counter
            } else {
                int front = q.front();
                q.pop();
                q.push(front);
                count++;
                if (count == q.size()) {
                    return q.size(); // No one wants the sandwich at the top
                }
            }
        }

        return 0; // All students got sandwiches
    }
};

int main() {
    Solution sol;

    // Sample input
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    int result = sol.countStudents(students, sandwiches);
    cout << "Number of students who can't eat: " << result << endl;

    return 0;
}
