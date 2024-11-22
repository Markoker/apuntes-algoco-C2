#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
using namespace std;

struct union_find {
  vector<int> e;
  union_find(int n) { e.assign(n, -1); }
  int findSet (int x) { 
    return (e[x] < 0 ? x : e[x] = findSet(e[x]));
  }
  bool sameSet (int x, int y) { return findSet(x) == findSet(y); }
  int size (int x) { return -e[findSet(x)]; }
  bool unionSet (int x, int y) {
    x = findSet(x), y = findSet(y);
    if (x == y) return 0;
    if (e[x] > e[y]) swap(x, y);
    e[x] += e[y], e[y] = x;
    return 1;
  }
};
struct edge{
    ll from,to,weight;
};
int main() {
    speed;
    ll n,m; 
    // n ciudades y m caminos
    cin >> n >>m;
    vector<edge>roads(m);
    for (ll i = 0; i < m; i++) {
        ll from, to , weight;
        cin >> from >> to >> weight;

        roads[i] = {from, to, weight};

    }
    sort ( roads.begin(), roads.end(), [](edge a, edge b) {
        return a.weight < b.weight;
    });

    ll edges = 0;
    ll ans = 0;
    union_find dsu(n+1);

    for ( edge e: roads) {
        if ( dsu.sameSet(e.from, e.to)) continue;
        dsu.unionSet(e.from, e.to);
        edges++;
        ans += e.weight;
    }
    
    // La cantidad de aristas es V -1 ( A =  V-1)
    if ( edges == n - 1 ){
        cout << ans << endl;
        return 0;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
