#include <bits/stdc++.h>
using namespace std;

void applyMessageEvent(vector<string> &event,
                       vector<int> &mentionCount,
                       vector<int> &offlineTime) {
    int timestamp = stoi(event[1]);

    vector<string> ids;
    stringstream ss(event[2]);
    string token;

    // Split mentions_string into tokens by whitespace
    while (ss >> token) {
        ids.push_back(token);
    }

    // Process all IDs
    for (string id : ids) {
        if (id == "ALL") {
            for (int i = 0; i < (int)mentionCount.size(); i++) {
                mentionCount[i]++;
            }
        } else if (id == "HERE") {
            for (int i = 0; i < (int)mentionCount.size(); i++) {
                if (offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp) {
                    mentionCount[i]++;
                }
            }
        } else {
            // id is like "id0", "id1", ...
            int userId = stoi(id.substr(2));
            mentionCount[userId]++;
        }
    }
}

vector<int> countMentions(int numberOfUsers,
                          vector<vector<string>> &events) {
    vector<int> mentionCount(numberOfUsers, 0);
    vector<int> offlineTime(numberOfUsers, 0);

    // Sort by timestamp; if equal, OFFLINE must come before MESSAGE
    auto cmp = [](vector<string> &a, vector<string> &b) {
        int t1 = stoi(a[1]);
        int t2 = stoi(b[1]);
        if (t1 == t2) {
            // "OFFLINE" should come before "MESSAGE"
            // Comparing first char is enough: 'O' > 'M'
            return a[0][0] > b[0][0];
        }
        return t1 < t2;
    };

    sort(events.begin(), events.end(), cmp);

    for (auto &event : events) {
        if (event[0] == "MESSAGE") {
            applyMessageEvent(event, mentionCount, offlineTime);
        } else if (event[0] == "OFFLINE") {
            int timestamp = stoi(event[1]);
            int id = stoi(event[2]);      // here OFFLINE has raw user id
            offlineTime[id] = timestamp;
        }
    }

    return mentionCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    // Example input format:
    // n m
    // then m lines, each:
    // for MESSAGE: MESSAGE timestamp mentions_string
    // for OFFLINE: OFFLINE timestamp userId
    //
    // You can adapt this part to LeetCode-style driver code.
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<string>> events;
    events.reserve(m);

    for (int i = 0; i < m; i++) {
        string type;
        cin >> type;
        if (type == "MESSAGE") {
            string timestamp;
            cin >> timestamp;
            // read the rest of the line as mentions_string
            string rest;
            getline(cin, rest);          // includes leading space
            if (!rest.empty() && rest[0] == ' ')
                rest.erase(rest.begin()); // remove leading space
            events.push_back({type, timestamp, rest});
        } else { // OFFLINE
            string timestamp, id;
            cin >> timestamp >> id;
            events.push_back({type, timestamp, id});
        }
    }

    vector<int> ans = countMentions(n, events);

    // Print result
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
