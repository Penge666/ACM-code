/*
题目大意：
给一个字符串，每次可以删除一个可不连续回文子串，问最少删几次可以全部删完。

思路：
因为字符串长度最大16，所以可用二进制状态表示， 1表示选取这个字符，0不选，组成一个子串。
先预处理出所有状态，看这个状态是不是回文。
f[i]表示状态i最少几次可以全删完， 初始化f数组INF
f[i] = min{f[i], f[s]+1 } s是i的子集。
*/

#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

const int N = 1<<17;
char str[22];
int check[N];
int dp[N],n;//dp[i]:表示擦除状态i所需的最小次数
int slove(int state){
    char s[22];
    int len=0;
    for(int i=0;i<n;i++){
        if((1<<i)&state){
            s[len++]=str[i];
        }
    }
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1])
            return 0;
    }
    return 1;
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%s",str);
        n=strlen(str);
        int MAX=(1<<n);

        for(int i=0;i<=MAX;i++) dp[i]=n+10;
        check[0]=0;dp[0]=0;
        for(int i=1;i<MAX;i++){
            check[i]=slove(i);
        }
        for(int i=1;i<MAX;i++){
            for(int j=i;j!=0;j=(j-1)&i){
                if(check[j]){
                    dp[i]=min(dp[i],dp[i^j]+1);
                }
            }
        }

        printf("%d\n",dp[MAX-1]);
    }
    return 0;
}
/*
2
aa
*/
