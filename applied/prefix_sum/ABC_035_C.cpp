#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998'244'353;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    //
    ll n, q; cin >> n >> q;
    vector<ll> diff(n+3);
    while(q--) {
        ll l, r; cin >> l >> r;
        diff[l] += 1;
        diff[r+1] -= 1;
    }
    ll cur = 0;
    for(int i = 1; i <= n; ++i) {
        cur += diff[i];
        cout << (cur % 2 == 0 ? 0 : 1); 
    }
    cout << '\n';
}
