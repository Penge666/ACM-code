// 有M种不同颜色的线，给出这样的图，然后q个询问，问两点可以由多少种线连接。


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 99999999999
#define N 120
int arr[N];
int mp[N][N][N];
map<int,int> vis;
int sum;
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(!vis[c]) sum++;
         mp[a][b][c]=1;
         mp[b][a][c]=1;
         vis[c]=1;
    }
    for(int l=1;l<N;l++){
        if(!vis[l]) continue;
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(mp[i][k][l]&&mp[k][j][l]){
                        mp[i][j][l]=1;
                    }
                }
            }
        }
    }
    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        int s=0;
        for(int i=1;i<N;i++){
            if(mp[u][v][i]&&vis[i])
                 s++;
        }
        cout<<s<<'\n';
    }
    return 0;
}
