#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
using namespace std;

int main () {
    ll n,x;
    cin >> n >> x;

    vector<ll> precio(n+1,0), paginas(n+1,0);
    for ( ll i = 1; i <= n; i++) {
        cin >> precio[i];
    }

    for ( ll i = 1; i <= n; i++) {
        cin >> paginas[i];
    }

    vector<vector<ll> > dp(n+1,vector<ll> (x+1,0));
    for ( ll i = 1; i <= n; i++) {
        for ( ll j = 1; j<=x; j++) {
            if ( precio[i] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-precio[i]] + paginas[i]); 
            }
        }
    }
    
    cout << dp[n][x] << endl;
    return 0;
}
