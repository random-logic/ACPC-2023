#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size(), ans = 0;

    for (int i = 1; i < n - 3; ++i) {
        if (s.substr(i, 3) == "cow") {
            if ((i < 3 || s.substr(i - 3, 3) != "cow") && s.substr(i + 3, 3) != "cow") {
                ++ans;
            }
        }
    }

    cout << ans;

    return 0;
}
