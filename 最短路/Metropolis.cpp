//思路：把每个大都会设为起点，跑一遍最短路。在跑最短路的时候，假设有一个大都会A，它不能更新一个非大都会B点，就说明这个B到另一个大都会C很近，用dis[u] + dis[B] + w[u][B]更新A点的答案。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200010;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int p[maxn], from[maxn]; // from[i]记录点i是由哪个源点扩展的
ll dist[maxn], ans[maxn];
bool vis[maxn];
int n, m, k;

struct Node
{
    int v;
    ll c;
    Node(int _v, ll _c): v(_v), c(_c) {}
    bool operator < (const Node & r) const
    {
        return c > r.c;
    }
};

struct Edge
{
    int to;
    ll w;
    Edge(int _to, ll _w): to(_to), w(_w) {}
};

vector <Edge> edge[maxn];

void addedge(int u, int v, ll w)
{
    edge[u].push_back(Edge(v, w));
}

void dijkstra() // 最短路
{
    for (int i = 0; i <= n; ++i)
    {
        vis[i] = false;
        dist[i] = inf;
        ans[i] = inf;
    }
    priority_queue <Node> Q;
    for (int i = 0; i < k; ++i)
    {
        dist[p[i]] = 0;
        Q.push(Node(p[i], dist[p[i]]));
    }
    while (!Q.empty())
    {
        Node tmp = Q.top();
        Q.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < edge[u].size(); ++i)
        {
            int v = edge[u][i].to;
            ll cost = edge[u][i].w;
            if (dist[v] > dist[u] + cost) // 更新最短路
            {
                dist[v] = dist[u] + cost;
                Q.push(Node(v, dist[v]));
                from[v] = from[u];
            }
            else if (from[v] != from[u]) // u和v由不同源点扩展，则更新答案
            {
                ans[from[u]] = min(ans[from[u]], dist[u] + dist[v] + cost);
                ans[from[v]] = min(ans[from[v]], dist[v] + dist[u] + cost);
            }
        }
    }
}

int main()
{
    memset(from, 0, sizeof from);
    for (int i = 0; i <= n; ++i)
        edge[i].clear();
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &p[i]);
        from[p[i]] = p[i];
    }
    int u, v;
    ll w;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%lld", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    dijkstra();
    printf("%lld", ans[p[0]]);
    for (int i = 1; i < k; ++i)
        printf(" %lld", ans[p[i]]);
    printf("\n");
    return 0;
}
