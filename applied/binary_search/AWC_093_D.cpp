#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998'244'353;

//upsolved
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> hs(n+3);
    vector<vector<ll>> es(n+3);
    for(int i = 1; i <= n; ++i) cin >> hs[i];
    while(m--) {
        ll u, v; cin >> u >> v;
        es[u].push_back(v); es[v].push_back(u);
    }

    //-
    vector<ll> copy(hs.begin()+1, hs.begin()+n+1);
    sort(copy.begin(), copy.end());
    
    ll lo = 0, hi = (ll)copy.size()-1, res = -1;
    while(lo <= hi) {
        ll mid = lo + (hi - lo) / 2;

        //*pitfall: start node already too high -> infeasible, skip the rest
        if(hs[1] > copy[mid]) {
            lo = mid + 1;
            continue;
        }

        queue<ll> bfs; vector<ll> dist(n+3, -1);
        bfs.push(1); dist[1] = 1;
        while(!bfs.empty()) {
            ll now = bfs.front();
            bfs.pop();

            for(size_t i = 0; i < es[now].size(); ++i) {
                ll next = es[now][i];
                // if(dist[next] > k) continue;
                if(dist[next] != -1) continue;
                if(hs[next] > copy[mid]) continue;
                bfs.push(next);
                dist[next] = dist[now] + 1;
            }
        }//end bfs

        if(dist[n] != -1 && dist[n] <= k) {
            res = copy[mid];
            hi = mid - 1;
            continue;
        }

        lo = mid + 1;
    }

    cout << res;
}
