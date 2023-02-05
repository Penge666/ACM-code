/*
题解：bitset<N>a[i]维护ai能到的点集，保证dag图，先拓扑，倒序更新前驱，输出个数即可
复杂度O(n*(n+m)/64) 
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 60000
queue<int> q;
int in[N];
int n,m;
vector<int> e[N];
vector<int> v;
bitset<N> f[N];
signed main(){;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        in[y]++;
    }
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);

    while(!q.empty()){
        int u=q.front();
        v.push_back(u);
        q.pop();
        for(int i=0;i<e[u].size();i++){
            in[e[u][i]]--;
            if(in[e[u][i]]==0) q.push(e[u][i]);
        }
    }

    for(int i=v.size()-1;i>=0;i--){
        int u=v[i];
        f[u][u]=1;
        for(int j=0;j<e[u].size();j++){
            f[u]|=f[e[u][j]];
        }
    }    //cout<<"==";
    for(int i=1;i<=n;i++) printf("%lld\n",f[i].count());
    return 0;
}
