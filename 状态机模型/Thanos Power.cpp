#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 999999999999999;
int dp[N][6];
char str[N];
//dp[i][0]:表示已经处理到第i位,并且是+的情况
//dp[i][1]:表示已经处理到第i位,并且是-的情况
signed main(){
    cin>>(str+1);
    int n=strlen(str+1);
    dp[1][0]=(int)(str[1]-'0');
    dp[1][1]=10-(int)(str[1]-'0')+1;
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+(int)(str[i]-'0');
        dp[i][1]=min(dp[i-1][0]+10-(int)(str[i]-'0')+1,dp[i-1][1]+10-(int)(str[i]-'0')-1);
    }
    cout<<min(dp[n][0],dp[n][1]);
    return 0;
}
/*
75521

*/
