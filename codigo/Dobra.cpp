#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
using namespace std;


string s;
vector<int> posibilidades(101,1);
ll int ans = 0;

bool isValid(){
    bool hasL = false; bool esVocal = true;
    int count = 0;
    for ( char &c : s) {
        if ( c == 'L' ) hasL = true;

        if ( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') { // Caso con vocal
                if ( esVocal ) {
                    count++;
                } else {
                    count = 1;
                    esVocal = true;
                }
        } else { //Caso de una consonante
            if ( esVocal ) {
                esVocal = false;
                count = 1;
            } else {
                count++;
            }
        }
        if ( count >= 3 ) return false;
    
    }  
    return hasL; 
}

void solve(int i) {

    if ( i == s.length()) {
        if (isValid()) {
            ll int count = 1;
            for ( int j = 0; j < s.size(); j++) {
                count *= posibilidades[j];
            }
            ans += count;
        }
        return;
    }
    
    if ( s[i] != '_' ) {
        solve(i+1);
    } else {
        // Se intenta con 'L'
        s[i] = 'L';
        solve(i+1);

        //Consonante
        s[i] = 'B';
        posibilidades[i] = 20;
        solve(i+1);

        //Vocal
        s[i] = 'A';
        posibilidades[i] = 5;
        solve(i+1);

        s[i] = '_';
        posibilidades[i] = 1;
    }
}


int main () {
    speed;

    cin >> s;
    solve(0);
    cout << ans;

    return 0;
}