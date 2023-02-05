//把黑边全部加入，白边按权值排序做一颗最大生成树即可，判断连完后是否是一整个连通块。

#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666666
#define mod 1000000007
int n,m,k;
int f[N];
map<int,int> mp;
struct edge{
    int u,v,w;
}black[N],white[N];
int getf(int v){
    if(v==f[v]) return f[v];
    else{
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
void init(){
    mp.clear();
    for(int i=0;i<=n;i++) f[i]=i;
}
bool cmp(edge a,edge b){

    return a.w>b.w;
}

signed main(){
    int T;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&m,&k);
        init();
        int a,b,c,d;
        int cnt1=0,cnt2=0;
        int ans=0;int add=0;
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
            if(d){
                white[cnt1].u=a;
                white[cnt1].v=b;
                white[cnt1++].w=c;
            }else{
                black[cnt2].u=a;
                black[cnt2].v=b;
                black[cnt2++].w=c;
                ans+=c;
                if(merge(a,b)){
                    add++;
                }
            }
        }
        sort(white,white+cnt1,cmp);
        for(int i=0;i<cnt1;i++){
            if(merge(white[i].u,white[i].v)){
                k--;
                mp[i]=1;
                ans+=white[i].w;
                add++;
            }
            if(!k) break;
        }
        /*cout<<add<<'\n';
        cout<<ans<<'\n';*/
        if(add<n-1){
            printf("-1\n");
            continue;
        }else{
            for(int i=0;i<cnt1;i++){
                if(!mp[i]){
                    k--;
                    mp[i]=1;
                    ans+=white[i].w;
                    add++;
                }
                if(!k) break;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
