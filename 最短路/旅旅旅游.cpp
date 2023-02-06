#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
vector<pair<int,int>> G[N];
int n, m, f[N];
ll d1[N], dn[N];
int Find(int x) {
    if(x == f[x]) return x;
    return f[x] = Find(f[x]);
}
void dij(int x, ll d[]) {
    for(int i = 1; i <= n; i++) {
        d[i] = (x == i ? 0 : 1e18);
    }
    queue<int> qu;
    qu.push(x);
    while(!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for(auto it : G[u]) {
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                qu.push(v);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0, u, v, c; i < m; i++) {
        scanf("%d%d%d", &u, &v, &c);
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    dij(1, d1), dij(n, dn);
    if(d1[n] == 1e18) {
        printf("NO\n");
    }
    else {
        for(int i = 1; i <= n; i++) f[i] = i;
        for(int i = 1; i <= n; i++) {
            for(auto it : G[i]) {
                int v = it.first, w = it.second;
                if(d1[v] + dn[i] + w == d1[n] || dn[v] + d1[i] + w == d1[n]) continue;
                f[Find(i)] = Find(v);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(Find(i) == i) ans++;
        }
        printf("%s\n", ans == 1 ? "YES" : "NO");
    }
    return 0;
}
