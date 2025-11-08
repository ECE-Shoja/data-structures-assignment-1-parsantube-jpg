#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    explicit UnionFind(const int array_size) {
        parent.resize(array_size);
        rank.resize(array_size, 0);
        for (int i = 0; i < array_size; i++) parent[i] = i;
    }
    int find(const int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_function(const int x, const int y) {
        const int root_x = find(x);
        const int root_y = find(y);
        if (root_x == root_y) return;

        if (rank[root_x] < rank[root_y]) parent[root_x] = root_y;
        else if (rank[root_x] > rank[root_y]) parent[root_y] = root_x;
        else {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }
    bool root(const int x, const int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind a1(n);
    vector<string> state;
    string line;
    int x, y;
    while (m--) {
        cin >> line >> x >> y;
        x--;
        y--;
        if (line == "+") {
            a1.union_function(x, y);
        } else if (line == "?") {
            state.emplace_back(a1.root(x, y) ? "YES" : "NO");
        }
    }
    for (const auto& i : state) {
        cout<<i<<endl;
    }
    return 0;
}
