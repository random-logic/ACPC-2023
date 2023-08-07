#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<long long> dp(4001, -1);

long long f(int k) {
    if (dp[k] > -1)
        return dp[k];

    if (k == 1 || k == 2)
        return dp[k] = 26;

    if (k % 2)
        return dp[k] = 26 * f(k / 2);
    else
        return dp[k] = f(k / 2);
}

int main() {
    int k;
    cin >> k;

    cout << f(k) << endl;
}
