#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int step = 0;
        for(int i = 0; i < points.size() - 1; i++){
            
            // x,y — starting point; a,b — ending point
            int x = points[i][0];
            int y = points[i][1];

            int a = points[i+1][0];
            int b = points[i+1][1];

            while(x != a || y != b){
                
                if(x > a && y > b){
                    x--;
                    y--;
                    step++;
                }
                else if(x < a && y < b){
                    x++;
                    y++;
                    step++;
                }
                else if(x == a && y != b){
                    if(y > b){
                        y--;
                    } else {
                        y++;
                    }
                    step++;
                }
                else if(x != a && y == b){
                    if(x > a){
                        x--;
                    } else {
                        x++;
                    }
                    step++;
                }
                else if(x < a && y > b){
                    x++;
                    y--;
                    step++;
                }
                else if(x > a && y < b){
                    x--;
                    y++;
                    step++;
                }
            }
        }
        return step;
    }
};

int main() {
    // Example test input:
    vector<vector<int>> points = {{1,1}, {3,4}, {-1,0}};

    Solution sol;
    int result = sol.minTimeToVisitAllPoints(points);

    cout << "Minimum time to visit all points: " << result << endl;

    return 0;
}
