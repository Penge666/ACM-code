#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
const int mod = 1e9+7;
const int maxn = 1e5+7;
using namespace std;
struct node{int to, w, next, cost; } edge[maxn];
int head[maxn], cnt;
int dis[maxn][15], vis[maxn][15];
int n, m, s, t, k;
struct Dijkstra
{
    void init()
    {
        memset(head,-1,sizeof(head));
        memset(dis,127,sizeof(dis));
        memset(vis,0,sizeof(vis));
        cnt = 0;
    }

    void add(int u,int v,int w)
    {
        edge[cnt].to = v;
        edge[cnt].w = w;
        edge[cnt].next = head[u];
        head[u] = cnt ++;
    }

    void dijkstra()
    {
        priority_queue <pii, vector<pii>, greater<pii> > q;
        dis[s][0] = 0;
        q.push({0, s});
        while(!q.empty())
        {
            int now = q.top().second; q.pop();
            int c = now / n; now %= n;
            if(vis[now][c]) continue;
            vis[now][c] = 1;
            for(int i = head[now]; i != -1; i = edge[i].next)
            {
                int v = edge[i].to;
                if(!vis[v][c] && dis[v][c] > dis[now][c] + edge[i].w)
                {
                    dis[v][c] = dis[now][c] + edge[i].w;
                    q.push({dis[v][c], v + c * n});
                }
            }
            if(c < k)
            {
                for(int i = head[now]; i != -1; i = edge[i].next)
                {
                    int v = edge[i].to;
                    if(!vis[v][c+1] && dis[v][c+1] > dis[now][c])
                    {
                        dis[v][c+1] = dis[now][c];
                        q.push({dis[v][c+1], v + (c + 1) * n});
                    }
                }
            }
        }
    }
}dj;

int main()
{
           scanf("%d%d", &n, &m);
        dj.init(); scanf("%d%d%d",&s,&t, &k);
        while(m--)
        {
            int u, v, w;
            scanf("%d%d%d",&u, &v, &w);
            dj.add(u, v, w);
            dj.add(v, u, w);
        }
        dj.dijkstra();
        int ans = inf;
        for(int i = 0; i <= k; i++)
            ans = min(ans, dis[t][i]);
        printf("%d\n", ans);
}
