#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int mp[6666][6666];
int f[N];
int n,m;
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
        f[max(t1,t2)]=min(t1,t2);
        return 1;
    }
    return 0;
}
bool cmp(str a,str b){
    return a.w<b.w;
}
signed main(){
    int cnt=0;
    scanf("%lld%lld",&m,&n);
    for(int i=1;i<=max(n,m);i++) f[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&mp[i][j]);
            if(mp[i][j]){
                st[cnt].u=i;
                st[cnt].v=j;
                st[cnt++].w=mp[i][j];
            }

        }
    }
    int ans=0;
    sort(st,st+cnt,cmp);
    for(int i=0;i<cnt;i++){
        if(merge(st[i].u,st[i].v)){
            ans+=st[i].w;
        }
    }for(int i=1;i<=n;i++)
        if(i==f[i]) ans+=m;
    cout<<ans;
    return 0;
}
