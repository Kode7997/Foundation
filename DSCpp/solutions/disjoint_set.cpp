// Disjoint Set with path compression and union by rank
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) : parent(n), rank(n,0) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return;
        if (rank[xr] < rank[yr]) parent[xr] = yr;
        else if (rank[xr] > rank[yr]) parent[yr] = xr;
        else { parent[yr] = xr; rank[xr]++; }
    }
};

int main() {
    DisjointSet ds(5);
    ds.unite(0,1); ds.unite(1,2);
    cout << (ds.find(0) == ds.find(2)) << endl;
    cout << (ds.find(0) == ds.find(3)) << endl;
    return 0;
}
