#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998'244'353;


// Wood cutting (a.k.a. log cutting): cut every log into pieces of length x.
// Find the largest x such that the total number of pieces is at least k.
// Classic monotonic binary-search-on-the-answer problem.

ll k;
vector<ll> trees;

// check: with cut length x, are there at least k pieces? Monotonic (true -> false as x grows).
bool check(ll x) {
    ll cnt = 0;
    for (auto& e : trees) {
        cnt += e / x;
        if (cnt >= k) return true;
    }
    return cnt >= k;
}

// min_true_x: largest x where check is true.
// STL: std::partition_point — <algorithm>.
ll min_true_x(ll lo, ll hi) {
    ll ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n >> k;
    trees.resize(n + 3);
    for (int i = 1; i <= n; ++i) cin >> trees[i];

    sort(trees.begin(), trees.end());
    cout << min_true_x(1, trees.back());

}
