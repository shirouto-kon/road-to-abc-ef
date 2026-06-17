#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998'244'353;


// find_target: index of t in sorted v, or -1.
// STL: std::lower_bound / std::binary_search — <algorithm>.
int find_target(const vector<ll>& v, ll t) {
    int lo = 0, hi = (int)v.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (v[mid] < t) lo = mid + 1;
        else if (v[mid] == t) return mid;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> arr {1, 3, 6, 9, 11};
    cout << find_target(arr, 6) << '\n';

}
