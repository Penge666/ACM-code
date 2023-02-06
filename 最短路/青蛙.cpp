#include<bits/stdc++.h>
using namespace std;

#define int long long
int vis[666666],dis[666666];
map<int,int> mp;
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    queue<int> q;
    q.push(0);
    vis[0]=1;
    dis[0]=0;
    while(!q.empty()){
        int t=q.front();q.pop();
        if(t==n){
            cout<<dis[n];return 0;
        }

        if(mp[t]&&!vis[mp[t]]){
            vis[mp[t]]=1;
            q.push(mp[t]);
            dis[mp[t]]=dis[t]+1;
        }
        if(!vis[t+1]){
            q.push(t+1);
            dis[t+1]=dis[t]+1;
            vis[t+1]=1;
        }
        if(!vis[t-1]){
            q.push(t-1);
            dis[t-1]=dis[t]+1;
            vis[t-1]=1;
        }

    }
    return 0;
}
