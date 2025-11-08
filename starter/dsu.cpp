#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
     if (v != parent[v]) parent[v] = findSet(parent[v]);
        return parent[v];
}

void unionSet(int a, int b) {
    const int root_x = findSet(a);
        const int root_y = findSet(b);
        if (root_x == root_y) return;

        if (sz[root_x] < sz[root_y]) parent[root_x] = root_y;
        else if (sz[root_x] > sz[root_y]) parent[root_y] = root_x;
        else {
            parent[root_y] = root_x;
            sz[root_x]++;
        }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
