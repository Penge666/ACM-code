#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 6666
#define inf 9999999999
int mp[N][N];
signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i==j)
                mp[i][j]=0;
            else
                mp[i][j]=inf;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a][b]=c;
        mp[b][a]=c;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(mp[i][j]+mp[j][k]<mp[i][k])
                    mp[i][k]=mp[i][j]+mp[j][k];


    cout<<mp[1][n];
    return 0;
}
