#include<bits/stdc++.h>

using namespace std;

const int N = 1666;
int n,m;
vector<int> g[N];
int in[N];
queue<int> q;
int mp[N][N];
signed main(){

    cin>>n>>m;
    //memset(ans,0,sizeof(ans));
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        in[b]++;
    }
    for(int i=1;i<=n;i++){
        if(!in[i]) q.push(i);
    }
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=0;i<g[t].size();i++){
            int to=g[t][i];
            in[to]--;
            for(int j=1;j<=n;j++){
                if(!mp[to][j]) mp[to][j]=mp[t][j];
            }
            mp[to][t]=1;
            if(!in[to]){
                q.push(to);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++) sum+=mp[i][j];
        cout<<sum<<'\n';
    }
    return 0;
}
/*
3 3
1 3
1 2
2 3

*/
