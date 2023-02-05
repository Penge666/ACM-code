#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 7;
const int M = MAXN * 100;
const int inf=1e9+100;
int n, q, tot;
int a[MAXN];
int T[MAXN], lson[M], rson[M], c[M];
int maxx[MAXN << 2], minn[MAXN << 2];

void pushup(int rt)
{
    maxx[rt] = max(maxx[rt << 1], maxx[rt << 1 | 1]);
    minn[rt] = min(minn[rt << 1], minn[rt << 1 | 1]);
}

void build1(int l, int r, int rt)
{
    if (l == r)
    {
        maxx[rt] = a[l];
        minn[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build1(l, mid, rt << 1);
    build1(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

int querymaxn(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r) return maxx[rt];
    int mid = (l + r) >> 1;
    int ret = 0;
    if (L <= mid) ret = max(ret, querymaxn(L, R, l, mid, rt << 1));
    if (R > mid) ret = max(ret, querymaxn(L, R, mid + 1, r, rt << 1 | 1));
    return ret;
}

int queryminn(int L, int R, int l, int r, int rt)
{
    if (L <= l && R >= r) return minn[rt];
    int mid = (l + r) >> 1;
    int ret = 0x3f3f3f3f;
    if (L <= mid) ret = min(ret, queryminn(L, R, l, mid, rt << 1));
    if (R > mid) ret = min(ret, queryminn(L, R, mid + 1, r, rt << 1 | 1));
    return ret;
}

int build(int l, int r) {
    int root = tot++;
    c[root] = 0;
    if (l != r) {
        int mid = (l + r) >> 1;
        lson[root] = build(l, mid);
        rson[root] = build(mid + 1, r);
    }
    return root;
}

int update(int root, int pos, int val) {
    int newroot = tot++, tmp = newroot;
    c[newroot] = c[root] + val;
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            lson[newroot] = tot++;
            rson[newroot] = rson[root];
            newroot = lson[newroot];
            root = lson[root];
            r = mid;
        } else {
            rson[newroot] = tot++;
            lson[newroot] = lson[root];
            newroot = rson[newroot];
            root = rson[root];
            l = mid + 1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}

int query(int root, int pos) {
    int ret = 0;
    int l = 1, r = n;
    while (pos < r) {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            r = mid;
            root = lson[root];
        } else {
            ret += c[lson[root]];
            root = rson[root];
            l = mid + 1;
        }
    }
    return ret + c[root];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(maxx, 0, sizeof(maxx));
        memset(T, 0, sizeof(T));
        memset(lson, 0, sizeof(lson));
        memset(rson, 0, sizeof(rson));
        memset(c, 0, sizeof(c));
        for(int i=0; i<(MAXN<<2); i++){
            minn[i]=0x3f3f3f3f;
        }
        scanf("%d%d", &n, &q);
        tot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        build1(1, n, 1);
        T[n + 1] = build(1, n);
        map<int, int> mp;
        for (int i = n; i >= 1; i--) {
            if (mp.find(a[i]) == mp.end()) {
                T[i] = update(T[i + 1], i, 1);
            } else {
                int tmp = update(T[i + 1], mp[a[i]], -1);
                T[i] = update(tmp, i, 1);
            }
            mp[a[i]] = i;
        }
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            //cout << querymaxn(l, r, 1, n, 1) << endl;
            //cout << queryminn(l, r, 1, n, 1) << endl;
            if (querymaxn(l, r, 1, n, 1) - queryminn(l, r, 1, n, 1) + 1 == query(T[l], r)) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
