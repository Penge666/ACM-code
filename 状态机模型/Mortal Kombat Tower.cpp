/*
状态表示：dp[i][j][k]:当前已经打到第i关,并且当前是j号选手进行作战且已经连续打了K次。
感性的进行状态转移即可

*/
#include<bits/stdc++.h>

using namespace std;


const int N = 266666 , inf = 0x3f3f3f3f;
int n,arr[N];
int dp[N][3][3];
signed main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=2;j++)
                for(int k=0;k<=2;k++)
                    dp[i][j][k]=inf;
        if(arr[1]==1) dp[1][1][1]=1;else dp[1][1][1]=0;
        for(int i=2;i<=n;i++){
            dp[i][1][1]=min(dp[i][1][1],min(dp[i-1][2][1],dp[i-1][2][2])+(int)(arr[i]==1*1ll));
            dp[i][1][2]=min(dp[i][1][2],dp[i-1][1][1]+(int)(arr[i]==1*1ll));
            dp[i][2][1]=min(dp[i][2][1],min(dp[i-1][1][1],dp[i-1][1][2]));
            dp[i][2][2]=min(dp[i][2][2],dp[i-1][2][1]);
        }
        int ans=dp[n][1][1];
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                ans=min(ans,dp[n][i][j]);
        printf("%d\n",ans);
    }
    return 0;
}
/*
dp[i][0]:当前已经打到第i关,并且当前0/1进行攻击
*/
