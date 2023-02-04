/*

思路：典型的状压dp，因为接的数很少，做这种题目的时候脑袋要清楚。
首先，分析所有后一个状态都可以不用接在前一个状态上。如果想要接在前一个状态，只有两种情况 1。当前的数没有被用过 2.上一个数和当前这个数相同。
通过这个分析列方程。
dp(i,j,k)：表示当前已经处理到第i位,当前状态为j(意思是当前已经取过数做的标记)，k为最后一个数。的方案数
转移方程看代码
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 2e3+100 ;
const int Mod = 998244353;
int n;
int dp[N][2000][11];
char str[N];
int arr[N];
signed main(){
    cin>>n>>(str+1);
    for(int i=1;i<=n;i++) arr[i]=str[i]-'A';
    //初始化
    for(int i=1;i<=n;i++) dp[i][(1<<arr[i])][arr[i]]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<10);j++){
            for(int k=0;k<10;k++){
                dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%Mod;
                if(arr[i+1]==k){
                    dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%Mod;
                }
                if((!((1<<arr[i+1])&j))){
                    dp[i+1][j|(1<<arr[i+1])][arr[i+1]]=(dp[i+1][j|(1<<arr[i+1])][arr[i+1]]+dp[i][j][k])%Mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<10);i++){
        for(int j=0;j<10;j++){
            if(i&(1<<j))
                ans=(ans+dp[n][i][j])%Mod;
        }
    }
    cout<<ans;
    return 0;
}

//dp[i][j][k]:当前已经处理到第i位，当前的集合为j(000000) ,且最后一位为k的方案数

/*

*/
