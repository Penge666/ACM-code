/*
通过数据范围2000，很容易想到DP。我们可以设DP(i,j)表示区间【i,j】之间的答案（最小插值）。最后一次插值一定是加上MAX[I,J]-MIN[I,J]。通过这个点可以列出状态转移方程。min(DP(l+1,r),DP(l,r-1))+a[r]-a[l]（注意：区间[l,r]要排个序）

*/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define maxn 2009
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[maxn];
int n,m;
int dp[maxn][maxn];
int DP(int l,int r){
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=min(DP(l+1,r),DP(l,r-1))+a[r]-a[l];
    return dp[l][r];
}
signed main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    cout<<DP(1,n);
    return 0;
}
