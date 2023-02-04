/*
dp[i][j]：表示当前走到第 i个点位置，且走过的二进制状态为 j 时，最短的距离。

*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 17
#define inf 0x3f3f3f3f
int Map[maxn][maxn],dp[maxn][1<<maxn|1],n;

void floyd()
{
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(Map[i][j]>Map[i][k]+Map[k][j])
                    Map[i][j]=Map[i][k]+Map[k][j];
}


int main()
{
    int T,x,y,z,i,j,k,m;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(Map,inf,sizeof(Map));
        for(i=0;i<m;++i){
            scanf("%d%d%d",&x,&y,&z);
            if(z<Map[x][y]) Map[x][y]=Map[y][x]=z;
        }

        floyd();
        memset(dp,inf,sizeof(dp));
        dp[1][1]=0;
        for(i=1;i<(1<<n);++i)   //依次枚举各种状态
            for(j=1;j<=n;++j)
            {
                if(i&(1<<(j-1)))   //枚举该状态下访问的顶点
                {
                    for(k=1;k<=n;++k)   //枚举访问的其它顶点
                        if(i&(1<<(k-1))&&j!=k)
                            dp[j][i]=min(dp[j][i],dp[k][i^(1<<(j-1))]+Map[k][j]);
                }
            }

        int ans=inf;
        for(i=2;i<=n;++i) ans=min(ans,dp[i][(1<<n)-1]+Map[i][1]);
        printf("%d\n",n==1?0:ans);
    }
    return 0;
}
