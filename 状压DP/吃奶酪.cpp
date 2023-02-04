/*
dp[i][j]：表示老鼠走到第 i个奶酪，且走过的二进制状态为 j 时，最短的距离。
接下来是三层循环，分别枚举所有可能的二进制状态、当前点所在的位置和能在当前状态下到达
当前点的位置。

在第二层循环中要判断一下 i 在当前二进制状态下是否已走过，如果根本没走过则不需要进行
接下来的计算，直接continue就可以。

在第三层运算中同样要判断当前点是否已走过，且当前点不与 i 点相同。
*/
#include<bits/stdc++.h>

using namespace std;

const int N =  66666 , mod = 1e8 , inf = 0x3f3f3f3f;
double dp[20][1<<16];//dp[i][j]:当前在i位置,且已经走过j状态的最小距离
double x[N],y[N];
double dis[666][666];
double F(int v,int w){//计算第v个和第w个奶酪之间的距离
  return sqrt((x[v]-x[w])*(x[v]-x[w])+(y[v]-y[w])*(y[v]-y[w]));//两点间距离公式
}
signed main(){
    memset(dp,127,sizeof(dp));
    int n;
    cin>>n;
    x[0]=0.0,y[0]=0.0;
    for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=F(i,j);
        }
    }
    for(int i=1;i<=n;i++) dp[i][(1<<(i-1))]=dis[i][0];
    for(int k=1;k<(1<<n);k++){
        for(int i=1;i<=n;i++){
            if(((1<<(i-1))&k)==0) continue;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if((k&(1<<(j-1)))==0) continue;
                dp[i][k]=min(dp[i][k],dp[j][k-(1<<(i-1))]+dis[i][j]);
            }
        }
    }
    double ans=dp[1][(1<<n)-1];
    for(int i=1;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
    printf("%.2lf\n",ans);
    return 0;
}
/*
//貌似这个样的DP好像更好理解
#include<bits/stdc++.h>

using namespace std;

const int N =  66666 , mod = 1e8 , inf = 0x3f3f3f3f;
double dp[20][1<<16];//dp[i][j]:当前在i位置,且已经走过j状态的最小距离
double x[N],y[N];
double dis[666][666];
double F(int v,int w){//计算第v个和第w个奶酪之间的距离
  return sqrt((x[v]-x[w])*(x[v]-x[w])+(y[v]-y[w])*(y[v]-y[w]));//两点间距离公式
}
signed main(){
    memset(dp,127,sizeof(dp));
    int n;
    cin>>n;
    x[0]=0.0,y[0]=0.0;
    for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=F(i,j);
        }
    }
    for(int i=1;i<=n;i++) dp[i][(1<<(i-1))]=dis[i][0];
    for(int k=1;k<(1<<n);k++){
        for(int i=1;i<=n;i++){
            //if(((1<<(i-1))&k)==0) continue;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                //if((k&(1<<(j-1)))==0) continue;
            //    dp[i][k]=min(dp[i][k],dp[j][k-(1<<(i-1))]+dis[i][j]);
                dp[j][k|(1<<(j-1))]=min(dp[i][k]+dis[i][j],dp[j][k|(1<<(j-1))]);
            }

        }
    }
    double ans=dp[1][(1<<n)-1];
    for(int i=1;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
    printf("%.2lf\n",ans);
    return 0;
}

*/
