#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
using namespace std;



int main () {
    ll n, x; 
    cin >> n >> x;

    vector<ll> coins(n,0); 
    vector<ll> hpnzfi(x+1,LLONG_MAX);

    for ( ll i = 0; i < n; i++) {
        cin >> coins[i]; 
    }

    hpnzfi[0] = 0;

    for ( ll i = 1; i <= x; i++) {
        for ( auto coin: coins) {
            if ( i - coin < 0 || hpnzfi[i-coin] == LLONG_MAX) continue;
            hpnzfi[i] = min(hpnzfi[i],hpnzfi[i-coin] + 1);
        }
    }
    
    if ( hpnzfi[x] == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << hpnzfi[x] << endl;

    return 0;
}
