#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ll = long long;
using namespace std;

int main () {
    string input;
    cin >> input; 
    int n = input.length();
    int ways = 0; 
    sort(input.begin(),input.end());
    vector<string> memo;
    do {
        ways++;
        memo.push_back(input);
    } while(next_permutation(input.begin(),input.end()));

    cout << ways << endl;
    for ( auto word: memo) {
        cout << word << endl;
    }
    return 0;
}
