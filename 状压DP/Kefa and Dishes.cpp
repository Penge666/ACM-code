/*
题意：有n个菜，每个菜只能吃一次，最多吃m个，每盘菜都有一个快乐值，吃菜的先后顺序也会增加快乐值。
题解：
dp[s,i]:已经吃了状态s的菜，且前一盘吃i盘
dp[s|(1<<j)][j]=min(dp[s][i]+(mp[i][j]+arr[j]),dp[s|(1<<j)][j]);
*/
/*
dp[s,i]:已经吃了状态s的菜，且前一盘吃i盘
dp[s|(1<<j)][j]=min(dp[s][i]+(mp[i][j]+arr[j]),dp[s|(1<<j)][j]);
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 20 , M = 1<<20;
int n,m,k;
int mp[N][N];
int dp[M][N];
int v[N];
int count(int state){
    int sum=0;
    for(int i=0;i<n;i++){
        if((1<<i)&state) sum++;
     }
    return sum;
}
signed main(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<k;i++){
        int x,y,z;
        cin>>x>>y>>z;x--,y--;
        mp[x][y]=z;
    }
    int ans=0;
    for(int i=0;i<n;i++) dp[1<<i][i]=v[i];
    for(int s=0;s<(1<<n);s++){
        if(count(s)>m) continue;
        for(int i=0;i<n;i++){
            if(!(s&(1<<i))) continue;
            for(int j=0;j<n;j++){
                if((s&(1<<j))) continue;
                dp[s|(1<<j)][j]=max(dp[s|(1<<j)][j],dp[s][i]+mp[i][j]+v[j]);
                //if(count((s|(1<<j)))<=m)
                //    ans=max(ans,dp[s|(1<<j)][j]);
            }
        }
    }
    for(int i=0;i<(1<<n);i++){
        if(count(i)==m){
            for(int j=0;j<n;j++) ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}
