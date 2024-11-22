#include <bits/stdc++.h>
#define hpnzfi ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
using namespace std;

int suma(vector<ll>& array, ll i, ll j) {
    if ( i == 0 ) return array[j];
    return array[j] - array[i-1];
}

int main () {
    hpnzfi;
    ll n, x; 
    cin >> n >> x;
    vector<ll> array(n);

    for ( ll i = 0; i < n; i++) {
        cin >> array[i]; 
    }
    // Suma de prefijo
    ll sum = 0;
    for ( ll i = 1; i < n; i++) {
        array[i] += array[i-1];
    }
    ll i = 0;
    ll count = 0;
    for ( ll j = 0; j < n; j++) {
        if ( suma(array,i,j) < x) continue;
        if ( suma(array,i,j) == x) count++;
        if ( suma(array,i,j) > x) {
            i++;
            j--;
        }
    }
    cout << count << endl;
    return 0;
}
