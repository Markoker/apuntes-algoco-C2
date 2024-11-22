#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
using namespace std;

struct Item{
    int value;
    int weight;
};

vector<int> knapsack (vector<Item>& items, ll n, ll C) {
    vector<vector<ll> > memo(n+1, vector<ll>(C+1, 0));
    for ( ll c = 0; c <= C; c++) {
        memo[0][c] = 0;
    }
    for (ll i = 1; i <= n; i++) {
        for ( ll c = 0; c <= C; c++) {
            if (items[i - 1].weight > c) {
                memo[i][c] = memo[i-1][c];
            } else {
                memo[i][c] = max(memo[i - 1][c], memo[i - 1][c - items[i - 1].weight] + items[i - 1].value);
            }
        } 
    }
    ll res =  memo[n][C];
    ll c = C;
    vector <int> indexes;
    for ( int i = n; i > 0 and res > 0; i--) {
        if (items[i-1].weight <= c and memo[i-1][c-items[i-1].weight] + items[i-1].value >= memo[i-1][c]) {
            indexes.push_back(i-1);
            c -= items[i-1].weight;
            res -= items[i-1].value;

        }
    }
    return indexes;
}

int main() {
    speed;
    vector<Item> items;
    ll cases = 30; 
    ll _value, _weight;
    while (cases--) {
        ll C, n;
        cin >> C >> n;
        for ( ll i = 0; i < n; i++) {
            cin >> _value >> _weight;
            Item item;  
            item.value = _value;
            item.weight = _weight;
            items.push_back(item);
        }   
        vector<int> solution = knapsack(items, n, C);
        ll size_solution = solution.size();
        cout << size_solution << endl;
        for (ll i = 0; i < size_solution; i++) {
            cout << solution[i] << " ";
        }
        cout << endl;
        items.clear();
    }
    return 0;
}

