/*
转移方程为：dp[S|(1<<(j-1))][(k*10+a[j])%d]+=dp[S][k]但是这样写是错误的，因为
没有考虑重复的排列，记了个临时数组b[i]b[i]，表示当前要填的数字i有没有被填过，这样就可
以避免一个位置放相同元素的情况了
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 11 , M = 1<<11 ;
int dp[M][1009];//dp[s,i]：在状态s下余数为i的方案数
map<int,int> vis;
int a[N];
signed main(){
    int T;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        string s;int d;
        cin>>s>>d;
        int n=s.size();
        for(int i=0;i<n;i++) a[i]=(int)(s[i]-'0');
        //for(int i=0;i<n;i++) cout<<a[i]<<" ";
        dp[0][0]=1;
        for(int s=0;s<(1<<n);s++){
            vis.clear();
            for(int i=0;i<n;i++){
                if(!((1<<i)&s)){
                    if(!vis[a[i]]){
                        vis[a[i]]=1;
                        for(int j=0;j<d;j++){
                            dp[s|(1<<i)][(10*j+a[i])%d]+=dp[s][j];
                        }
                    }
                }
            }
        }
        cout<<dp[(1<<n)-1][0]<<'\n';
    }
    return 0;
}
