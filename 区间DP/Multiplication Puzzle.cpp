/*
定义dp[i][j]表示区间[i,j]的最小得分

一开始可以先初始化好长度为三的区间值是多少，可以直接算

然后开始枚举区间长度为4到更长的区间[i,j]
枚举区间内的一个点k作为最后一次取的数（即其他数都已经取走了，只剩i,k,j(i<k<j)）

状态转移方程为

dp[i][j]=dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long  ll;
const int N = 666;
int n;
int dp[N][N];
int arr[N];
/*
dp(i,j):表示将区间[i,j]的数按照合理方式合并使得最终仅剩头尾的最小花费
*/
signed main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++)
        dp[i][i+2]=arr[i]*arr[i+1]*arr[i+2];
    for(int len=4;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            dp[l][r]=1e8;
            for(int k=l+1;k<r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+arr[l]*arr[r]*arr[k]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
