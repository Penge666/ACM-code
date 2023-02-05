#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 200010;
int n, m, cnt, tot;
int in[N], out[N], head[N], t[N], num[N];
struct node{
    int l, r, sum, lazy;
}tr[N<<2];
struct Edge{
    int to, nxt;
}edge[N];
void add(int a, int b)
{
    edge[cnt].to = b;
    edge[cnt].nxt = head[a];
    head[a] = cnt++;
}
void pushup(int m)
{
    tr[m].sum = tr[m<<1].sum + tr[m<<1|1].sum;
}
void pushdown(int m)
{
    if(tr[m].lazy)
    {
        tr[m<<1].lazy ^= 1;
        tr[m<<1|1].lazy ^= 1;
        tr[m<<1].sum = tr[m<<1].r - tr[m<<1].l + 1 - tr[m<<1].sum;
        tr[m<<1|1].sum = tr[m<<1|1].r - tr[m<<1|1].l + 1 - tr[m<<1|1].sum;
        tr[m].lazy = 0;
    }
}
void build(int m, int l, int r)
{
    tr[m].l = l;
    tr[m].r = r;
    tr[m].lazy = 0;
    if(l == r)
    {
        tr[m].sum = t[num[l]];
        return ;
    }
    int mid = (l + r) >> 1;
    build(m<<1, l, mid);
    build(m<<1|1, mid + 1, r);
    pushup(m);
}
void updata(int m, int l, int r)
{
    if(tr[m].l == l && tr[m].r == r)
    {
        tr[m].sum = r - l + 1 - tr[m].sum;
        tr[m].lazy ^= 1;
        return ;
    }
    pushdown(m);
    int mid = (tr[m].l + tr[m].r) >> 1;
    if(r <= mid) updata(m<<1, l, r);
    else if(l > mid) updata(m<<1|1, l, r);
    else
    {
        updata(m<<1, l, mid);
        updata(m<<1|1, mid + 1, r);
    }
    pushup(m);
}
int query(int m, int l, int r)
{
    if(tr[m].l == l && tr[m].r == r) return tr[m].sum;
    pushdown(m);
    int mid = (tr[m].l + tr[m].r) >> 1;
    if(r <= mid) return query(m<<1, l, r);
    else if(l > mid) return query(m<<1|1, l, r);
    else return query(m<<1, l, mid) + query(m<<1|1, mid + 1, r);
}
void dfs(int x)
{
    in[x] = ++tot;//第一次遇到
    num[tot] = x;//num[tot]=x表示在新的序列中，tot这个点是原先的x这个点
    for(int i = head[x]; i != -1; i = edge[i].nxt)
        dfs(edge[i].to);
    out[x] = tot;//最后一次遇到
}
int main()
{
    scanf("%d", &n);
    cnt = tot = 0;
    memset(head, -1, sizeof head);
    for(int i = 2; i <= n; i++)
    {
        int p;
        scanf("%d", &p);
        add(p, i);
    }
    for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
    dfs(1);
    build(1, 1, tot);
    scanf("%d", &m);
    char s[2];
    int x;
    while(m--)
    {
        scanf("%s %d", &s, &x);
        if(s[0] == 'g') printf("%d\n", query(1, in[x], out[x]));
        else updata(1, in[x], out[x]);
    }
    return 0;
}
