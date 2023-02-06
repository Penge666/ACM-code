/*

Floyd变形,dis[i][F(i)]=1,dis[i][G(i)]=1,dis[i][i]=0

最后求min(dis[F(A)][B],dis[G(A)][B])

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
    x%=233;
    return (x*x*x+x*x)%233;
}
int g(int x)
{
    x%=233;
    return (x*x*x-x*x)%233;
}
int dp[250][250];
signed main()
{
    for(int i=0;i<233;i++)
    {
        for(int j=0;j<233;j++)dp[i][j]=1e16;
        dp[i][f(i)]=1;
        dp[i][g(i)]=1;
        dp[i][i]=0;
    }
    for(int k=0;k<233;k++)
        for(int i=0;i<233;i++)
            for(int j=0;j<233;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    int t;
    int a,b;
    scanf("%lld",&t);
    while(t--)
    {
         int ans=1e16;
        scanf("%lld%lld",&a,&b);
        if(b>=233){
          if(a==b)ans=0;
          else ans=-1;}
        else if(a>=233)
        {
            ans=min(dp[f(a)][b]+1,ans);
            ans=min(dp[g(a)][b]+1,ans);
        }
        else ans=min(ans,dp[a][b]);
        if(ans==1e16)printf("-1\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
