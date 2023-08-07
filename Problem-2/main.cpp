#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v(2, vector<int>(2));

    int ans = 0;

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            cin >> v[i][j];
            ans = max(ans, v[i][j]);
        }


    string dir = "up";

    // Check left right
    if (v[0][0] == v[0][1] && v[0][0] * 2 > ans) {
        ans = 2*v[0][0];
        dir = "left";
    }
    if (v[1][0] == v[1][1] && v[1][0] * 2 > ans) {
        ans = 2*v[1][0];
        dir = "left";
    }

    // Check up down
    if (v[0][0] == v[1][0] && v[0][0] * 2 > ans) {
        ans = 2*v[0][0];
        dir = "up";
    }
    if (v[0][1] == v[1][1] && v[0][1] * 2 > ans) {
        ans = 2*v[1][0];
        dir = "up";
    }

    cout << ans << endl;
    cout << dir << endl;

    return 0;
}
