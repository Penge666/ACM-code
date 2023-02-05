/*
如果我们枚举每一条删的边，那么就变成了两个联通块不同数的个数之和。

我们可以发现删边的时候，其实是去掉一个子树。

又因为子树在dfs序上面是连续的，所以我们可以转化为序列操作。

然后去掉一个子树的时候，另一个区间不是连续的，怎么办呢？我们可以把dfs序复制一遍，放到后面，然后就变成连续的了。
*/
#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>

using namespace std;

const int N=1e6+7;
int n,m;
vector<int> g[2*N];
int w[N];
//**************主席树
struct Node{
    int l,r;
    int cnt;
}tr[N*40];
int root[N],idx;
int build(int l,int r){
    int p=++idx;
    tr[p].cnt=0;
    if(l==r) return p;
    int mid=(l+r)/2;
    tr[p].l=build(l,mid),tr[p].r=build(mid+1,r);
    return p;
}
int insert(int l,int r,int p,int pos,int val){
    int q=++idx;
    tr[q]=tr[p];
    if(l==r){
        tr[q].cnt+=val;
        return q;
    }
    int mid=(l+r)/2;
    if(pos<=mid) tr[q].l=insert(l,mid,tr[p].l,pos,val);
    else tr[q].r=insert(mid+1,r,tr[p].r,pos,val);
    tr[q].cnt=tr[tr[q].l].cnt+tr[tr[q].r].cnt;
    return q;
}
int query(int l,int r,int x,int L,int R){
    if(L<=l&&r<=R){
        return tr[x].cnt;
    }
    int mid=(l+r)/2;
    if(R<=mid) return query(l,mid,tr[x].l,L,R);
    else if(L>mid) return query(mid+1,r,tr[x].r,L,R);
    else return query(l,mid,tr[x].l,L,mid)+query(mid+1,r,tr[x].r,mid+1,R);
}
//**************dfs序
int in[N],out[N],num[N];
int tot;
void dfs(int x){
    in[x]=++tot;
    num[tot]=x;
    for(int i=0;i<g[x].size();i++) dfs(g[x][i]);
    out[x]=tot;
}
int vis[N];

void init(){
    idx=0;
    for(int i=0;i<=n+1;i++){
        g[i].clear();
        root[i]=0;
    }
    tot=0;
}
signed main(){
    while(~scanf("%d",&n)){
        init();int x;
        for(int i=2;i<=n;i++){
            scanf("%d",&x);
            g[x].push_back(i);
        }
        for(int i=1;i<=n;i++) scanf("%d",&w[i]),vis[w[i]]=0;
        dfs(1);
        for(int i=1;i<=n;i++) num[i+n]=num[i];
        int m=2*n;
        root[0]=build(1,m);
        for(int i=1;i<=m;i++){
            if(!vis[w[num[i]]]){
                root[i]=insert(1,m,root[i-1],i,1);
            }else{
                int temp=0;
                temp=insert(1,m,root[i-1],vis[w[num[i]]],-1);
                root[i]=insert(1,m,temp,i,1);
            }
            vis[w[num[i]]]=i;
        }
        int ans=0;
        for(int i=2;i<=n;i++){//[in[i],out[i]][]
            int res=query(1,m,root[out[i]],in[i],out[i])+query(1,m,root[in[i]+n-1],out[i]+1,in[i]+n-1);
            ans=max(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}
