#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Henry = 1
int dfs(vector<set<int>> & edges, int i) {
    int ans = 0;

    for (int dest : edges[i]) {
        // Cant follow himself and Henry is not following them yet
        if (dest != 1 && edges[0].find(dest) == edges[0].end() && edges[1].find(dest) == edges[1].end()) {
            edges[0].insert(dest);
            ++ans;
        }
    }

    return ans;
}

int main() {
    int ans = 0;
    int n, m;
    cin >> n >> m;

    vector<set<int>> edges(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].insert(v);
    }

    vector<bool>

    for (int i : edges[1]) {
        ans += dfs(edges, i);
    }

    cout << ans << endl;

    return 0;
}
