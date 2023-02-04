#include<bits/stdc++.h>

using namespace std;
const int N = 109 , M = 1<< 11 ;
int n,m;
int dp[N][M][M];
vector<int> state;
int g[1010];
int cnt[M];
/*
dp[i][j][k]:
已经摆完了前 i 行,且第 i 行的状态是 j , 第 i - 1 行的状态是 k 所能摆放的最大数量
*/
int check(int state){
    for(int i=0;i<m;i++){
        if((state>>i)&1){
            if(((state>>(i+1))&1)||((state>>(i+2))&1)) return 0;
        }
    }
    return 1;
}
int count(int state){
    int sum=0;
    for(int i=0;i<m;i++) sum+=(state>>i)&1;
    return sum;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            if(ch=='H') g[i]=g[i]+(1<<j);
        }
    }
    for(int i=0;i<(1<<m);i++){
        if(check(i)){
            state.push_back(i);
            cnt[i]=count(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<state.size();j++){
            for(int k=0;k<state.size();k++){
                for(int u=0;u<state.size();u++){
                    int a=state[j];//第 i 行的状态
                    int b=state[k];//第 i-1 行的状态
                    int c=state[u];//第 i-2 行的状态
                    if(a&b|b&c|a&c) continue;
                    if(g[i]&a|g[i-1]&b) continue;
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][u]+cnt[a]);
                }
            }
        }
    }
    int res=0;
    for(int i=0;i<state.size();i++)
        for(int j=0;j<state.size();j++)
            res=max(res,dp[n][i][j]);
    cout<<res;
    return 0;
}
