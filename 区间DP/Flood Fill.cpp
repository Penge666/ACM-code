/*
区间dp
dp[l][r][0]表示l-r颜色为color_left，dp[l][r][1]表示l-r颜色为color_right.

那我们从长度为1的区间开始枚举

当前枚举到的区间是[l,r]且长度为len

所以可以向len+1的区间转移.

dp[l][r+1][1]可以由dp[l][r][0/1]转移而来
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 5009;

int n;
int dp[N][N][2];
int arr[N];
/*
dp(i,j,k):将区间[i,j]最终都涂成(k==0||k==1[左端点|右端点]的颜色)的最小代价
*/
signed main(){
    //memset(dp,0x3f,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)
         cin>>arr[i];

    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;

            dp[l][r][0]=min(dp[l+1][r][1]+(arr[l]!=arr[r]),dp[l+1][r][0]+(arr[l]!=arr[l+1]));
            dp[l][r][1]=min(dp[l][r-1][0]+(arr[l]!=arr[r]),dp[l][r-1][1]+(arr[r-1]!=arr[r]));
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1]);
    return 0;
}
