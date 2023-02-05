#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int mp[6666][6666];
int f[N];
int n,m,k;
struct str{
    int u,v,w;
}st[N];
int getf(int v){
    if(v==f[v]){
        return f[v];
    }else{
        f[v]=getf(f[v]);
        return f[v];
    }
}
int merge(int u,int v){
    int t1=getf(u);
    int t2=getf(v);
    if(t1!=t2){
        f[t2]=t1;
        return 1;
    }
    return 0;
}
bool cmp(str a,str b){
    return a.w>b.w;
}
signed main(){
    int cnt=0;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&st[i].u,&st[i].v,&st[i].w);
    int ans=0;
    sort(st+1,st+m+1,cmp);
    for(int i=1,j=1;i<=m&&j<=k;i++){
        if(merge(st[i].u,st[i].v)){
            ans+=st[i].w;j++;
        }
    }
    cout<<ans;
    return 0;
}
