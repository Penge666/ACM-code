#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 5;
const ll INF = 1e18;
struct node {
    ll x,d;
    node() {}
    node(ll a,ll b) {
        x=a;
        d=b;
    }
    bool operator < (const node & a) const {
        if(d == a.d) return x<a.x;
        else return d > a.d;
    }
};
vector<node> eg[maxn];
ll dis[maxn], n, a[maxn], b[maxn], c[maxn], d[maxn];;
vector<int>ff[maxn];

int main() {
    for(int i = 1;i <= (int)2e5; i++)
        for(int j = i;j <= (int)2e5; j += i)
            ff[j].pb(i);
    cin >> n;
    for(int i = 1; i <= n; i++)
        scanf("%d%d%d%d",a+i, b+i, c+i, d+i);
    for(int i = 1; i <= n; i++){
        eg[i].pb(node(d[i],a[d[i]]));
        for(int j = 0;j < ff[c[i]].size(); j++)
            if(i + ff[c[i]][j] <= n)
                eg[i].pb(node(i + ff[c[i]][j], a[i + ff[c[i]][j]] + b[i]));
    }

    for(int i = 0; i <= n; i++) dis[i] = INF;
    dis[1] = 0;
    priority_queue<node> q;
    q.push(node(1,dis[1]));
    while(!q.empty()) {
        node x = q.top();
        q.pop();
        for(int i = 0; i < eg[x.x].size(); i++) {
            node y = eg[x.x][i];
            if(dis[y.x] > x.d + y.d) {
                dis[y.x] = x.d + y.d;
                q.push(node(y.x, dis[y.x]));
            }
        }
    }
    printf("%lld\n",dis[n] + a[1]);
}
