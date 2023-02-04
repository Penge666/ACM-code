// 1.直接爆搜，爆搜解决最小分组问题

#include<bits/stdc++.h>

using namespace std;
const int N = 22;
int ans,n,m,arr[N];
int g[N];//分组数

//u:当前用了多少个数  cnt：当前分成了多少组
void dfs(int u,int cnt){
    if(cnt>=ans) return ;
    if(u==n){
        ans = cnt;
        return ;
    }
    for(int i=0;i<cnt;i++){
        if(g[i]+arr[u+1]<=m){
            g[i]+=arr[u+1];
            dfs(u+1,cnt);
            g[i]-=arr[u+1];
        }
    }
    g[cnt]+=arr[u+1];
    dfs(u+1,cnt+1);
    g[cnt]-=arr[u+1];
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    ans=n;
    dfs(0,0);//用了多少个数，分了多少组
    cout<<ans;
    return 0;
}

//状压DP


//dp[i]就代表当前状态为i时最小的乘电梯次数
//dw[i]就代表当前状态为i时剩余的空间
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 20 , M = 1<<21 , inf = 0x3f3f3f3f;
int n,m,w[N];
int dp[M];
int dw[M];//状态s下可以放的最大价值
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>w[i];
    dp[0]=1,dw[0]=m;
    for(int s=0;s<(1<<n);s++){
        for(int j=0;j<n;j++){
            if((1<<j)&s) continue;
            if(dw[s]>=w[j]){
                dp[s|(1<<j)]=dp[s];
                dw[s|(1<<j)]=max(dw[s|(1<<j)],dw[s]-w[j]);
            }else{
                dp[s|(1<<j)]=dp[s]+1;
                dw[s|(1<<j)]=max(dw[s|(1<<j)],m-w[j]);
            }
        }
    }
    cout<<dp[(1<<n)-1];
    return 0;
}
