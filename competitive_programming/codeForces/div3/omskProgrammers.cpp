#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<map>
using namespace std;

using ll = long long;

void dfs(ll v, ll cost, ll x, map<ll,ll>& dist)
{
    if(dist.count(v) && dist[v] <= cost)
        return;

    dist[v] = cost;

    if(v == 0)
        return;

    dfs(v / x, cost + 1, x, dist);

    ll add = (x - v % x) % x;
    dfs((v + add) / x, cost + add + 1, x, dist);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--)
    {
        ll a, b, x;
        cin >> a >> b >> x;

        map<ll,ll> A, B;

        dfs(a, 0, x, A);
        dfs(b, 0, x, B);

        ll ans = (ll)4e18;

        for(auto [va, ca] : A)
        {
            for(auto [vb, cb] : B)
            {
                ll meet = max(va, vb);

                ans = min(
                    ans,
                    ca + (meet - va)
                       + cb + (meet - vb)
                );
            }
        }

        cout << ans << '\n';
    }

    return 0;
}