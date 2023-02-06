/*
有N个点，点1为珍贵矿物的采矿区， 点N为加工厂，有M条双向连通的边连接这些点。走每条边的运输容量为C，运送时间为D。
他们要选择一条从1到N的路径运输， 这条路径的运输总时间要在T之内，在这个前提之下，要让这条路径的运输容量尽可能地大。
一条路径的运输容量取决与这条路径中的运输容量最小的那条边。
思路：
直接二分容量，check（最短路时间）

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define inf 999999999999
#define N 666666
int n,m,t;
struct str{
    int x,y,z;
};
int c[N];
vector<str> v[N];
int dis[N];
bool cmp(int a,int b){
    return a>b;
}
int slove(int num){
    for(int i=0;i<=n;i++) dis[i]=inf;
    queue<int> q;
    q.push(1);
    dis[1]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++){
            if(v[t][i].y>=num){
                if(dis[v[t][i].x]>dis[t]+v[t][i].z){
                    dis[v[t][i].x]=dis[t]+v[t][i].z;
                    q.push(v[t][i].x);
                }
            }
        }
    }
    return dis[n];
}
void init(){
    for(int i=1;i<=n;i++){
        v[i].clear();c[i]=0;
    }
}
signed main(){
    int _;
    cin>>_;
    while(_--){
        cin>>n>>m>>t;
        init();
        int maxn=0;
        int minx=inf;
        for(int i=1;i<=m;i++){
            int a,b,d;
            scanf("%lld%lld%lld%lld",&a,&b,&c[i],&d);
            v[a].push_back((str){b,c[i],d});
            v[b].push_back((str){a,c[i],d});
            maxn=max(maxn,c[i]);
            minx=min(minx,c[i]);
        }
        int l=minx;
        int r=maxn;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(slove(mid)<=t){
                l=mid+1;
                ans=mid;
            }else{
                r=mid-1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
