/*
设字符串为S。

设f[i][j]为要把从i到j（包括i和j）的字符串变为回文串的最少插入字符数。

怎么转移？ 有两种可能：

S[i] == S[j]说明串的两头相等，不需要多插入什么，只需要f[i][j] = f[i+1][j-1]就好了，i+1到 j-1 一段就是除两头外的最少插入字符数

S[i] != s[j] 说明串的两头不同，需要多插入1字符以保持串的回文性质，我们这次新插入的字符可能在最右边，也可能在最左边。所以需要f[i][j] = min(f[i+1][j], f[i][j-1]) + 1f
*/

#include<bits/stdc++.h>

using namespace std;
const int N = 1666;
int dp[N][N];
/*
dp(i,j):区间[i,j]变成回文串需要添加的最少字符
*/
char str[N];
int main(){
    scanf("%s",str+1);
    int L=strlen(str+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=L;i++){
        dp[i][i]=0;
        if(str[i]==str[i+1]) dp[i][i+1]=0;
        else dp[i][i+1]=1;
    }
    for(int len=3;len<=L;len++){
        for(int l=1;l+len-1<=L;l++){
            int r=l+len-1;
            if(str[l]==str[r]) dp[l][r]=dp[l+1][r-1];
            else dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
        }
    }
    cout<<dp[1][L];
    return 0;
}
