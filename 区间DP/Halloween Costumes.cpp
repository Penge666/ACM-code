/*
题意：有n天，每天穿特定的衣服，可以同时穿几件衣服，但是最外面的那件衣服必须是特定的那件，当脱掉一件衣服后，该衣服就视为不干净，不能再穿，问经过这n天，至少需要多少件衣服。

题解：区间dp，dp [i] [j] 表示区间 i ~ j 最少需要的衣服，初始化，dp [i] [j] = dp [i] [j-1] + 1, 初始化理解很简单。然后，再在区间   [ i，j-1 )  中找是否有某一天 ( k ) 衣服和第 j 天的衣服一样，若一样 dp [i] [j] = min( dp [i] [j] , dp [i] [k] + dp [k+1] [j-1] )，该dp方程的意思是，第k天穿上该衣服后，后来几天都不脱第k天的那件衣服，直到第j天，脱掉其他的衣服露出第k天的那件衣服，从而满足第j天特定衣服的条件，最终便容易得到该dp方程。


*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
const int N = 666 ;
int dp[N][N];
int arr[N];
/*

*/
signed main(){
    int T;
    int cnt=1;
    scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof(dp));
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<=n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                if(arr[r-1]==arr[r]) dp[l][r]=dp[l][r-1];
                else dp[l][r]=dp[l][r-1]+1;
                for(int k=l;k<r;k++){
                    if(arr[k]==arr[r])
                        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r-1]);
                }
            }
        }
        printf("Case %d: %d\n",cnt++,dp[1][n]);
    }

    return 0;
}
/*
再一次刷到这题，一点心得
这题的关键在于dp[i][j]: 表示在区间i-j之间需要穿的最小的数量
重点是：dp[i][j]表示当前至少穿着第j件衣服。
这样，我们就能用
if(arr[r]==arr[k]) 
  dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]-1);
else
   dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
   
   
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

#define pb push_back

#define int long long

const int N = 633 , inf = 6666666 ;
//dp[i][j]: 表示在区间i-j之间需要穿的最小的数量 重点：表示当前至少穿第j件衣服
//(arr[r] == arr[k]) dp[i][j] = max(dp[i][j] , dp[i][k] + dp[k+1][r] -1 )
int n;
int arr[N];
int dp[N][N];
signed main(){
    int T=1;
    int cnt=1;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i],dp[i][i]=1;

        for(int len=2;len<=n;len++){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                dp[l][r]=inf;
                for(int k=l;k<r;k++){
                    if(arr[r]==arr[k])
                        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]-1);
                    else
                        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);

                }
            }
        }
         printf("Case %lld: %lld\n",cnt++,dp[1][n]);
    }
    return 0;
}
/*
((()))
状压：
1.枚举Len
2.枚举左端点 （左端点 右端点）
3.枚举左端点和右端点中间的数

dp[i][j]: 表示在区间i-j之间需要穿的最小的数量

if()
    DP[l][r]=DP[l][k]+DP[k][r]+
    for(int len=2;len<=n;len++){  //枚举长度
        for(int i=1;i+len-1<=n;i++){ //枚举区间左端点
            int j=i+len-1;
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }




*/
*/
