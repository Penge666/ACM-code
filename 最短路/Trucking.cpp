//题意货车拉货，拉的货越多越好，但是车有货的重量上限，每条路也有货的重量上限，在货拉的多的前提下，求最短路程。
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define inf 9999999999
#define N 666666
int n,m;
int s,t,lim;
struct str{
    int x,y,z;
};
vector<str> v[N];
int dis[N];
int vis[N];
int spfa(int num){
    for(int i=1;i<=n+1;i++) dis[i]=inf,vis[i]=0;
    queue<int> q;
    dis[s]=0;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        vis[temp]=0;
        for(int i=0;i<v[temp].size();i++){
            int to=v[temp][i].x;
            if(v[temp][i].y>=num){
                if(dis[to]>dis[temp]+v[temp][i].z){
                    dis[to]=dis[temp]+v[temp][i].z;
                    if(!vis[to]){
                        vis[to]=1;
                        q.push(to);
                    }
                }
            }
        }
    }
    if(dis[t]>=inf) return 0;
    else dis[t];
}

void init(){
    for(int i=0;i<=n;i++) v[i].clear();
}
signed main(){
    int count=0;
    while(~scanf("%lld%lld",&n,&m)&&n&&m){
        init();
        for(int i=1;i<=m;i++){
            int a,b,c,d;
            scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
            if(c==-1) c=inf;
            v[a].push_back((str){b,c,d});
            v[b].push_back((str){a,c,d});
        }
        scanf("%lld%lld%lld",&s,&t,&lim);
        int l=0;
        int r=lim;
        int ans1=inf;int ans2=0;
        while(l<=r){
            int mid=(l+r)/2;
            int slove=spfa(mid);
            if(slove){
                l=mid+1;
                ans1=dis[t];
                ans2=mid;
            }else{
                r=mid-1;
            }
        }
        if(count) printf("\n");
        printf("Case %d:\n",++count);
        if(ans1==inf){
            printf("cannot reach destination\n");
        }else{
            printf("maximum height = %lld\n",ans2);
            printf("length of shortest route = %lld\n",ans1);
        }
    }
    return 0;
}
