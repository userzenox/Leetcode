#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    using P = pair<int,int>;

    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<P>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt});  // reversed edge
        }

        priority_queue<P, vector<P>, greater<P>> pq;   // min-heap

        vector<int> result(n, INT_MAX);
        result[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1) {
                return result[n - 1];
            }

            for (auto &p : adj[node]) {
                int adjNode = p.first;
                int dist = p.second;

                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 3},
        {2, 3, 2}
    };

    int ans = sol.minCost(n, edges);
    cout << "Minimum Cost = " << ans << endl;

    return 0;
}
