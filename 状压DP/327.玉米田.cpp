#include<bits/stdc++.h>

using namespace std;
#define int long long
const int mod = 1e8;
const int N = 1<<13;
int m,n;
int dp[16][N];
vector<int> state;//合法的状态数
vector<int> head[N];//head[a]表示a对应的放置集合状态可以转移到的集合状态。
int g[N];
int check(int x){
    for(int i=0;i<m-1;i++){
        if((x>>i&1)&&(x>>i+1&1))
            return 0;
    }
    return 1;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int t;
            cin>>t;
            g[i]+=!t*(1<<j);
        }
    }
    for(int i=0;i<(1<<m);i++){
        if(check(i)){
            state.push_back(i);
        }
    }
    for(int i=0;i<state.size();i++){
        for(int j=0;j<state.size();j++){
            int a=state[i],b=state[j];
            if(!(a&b)){
                head[i].push_back(j);
            }
        }
    }
    dp[0][0]=1;
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<state.size();j++){
            if(!(state[j]&g[i])){
                for(int k=0;k<head[j].size();k++){
                    dp[i][j]=(dp[i][j]+dp[i-1][head[j][k]])%mod;
                }
            }
        }
    }

    cout<<dp[n+1][0];
    return 0;
}
