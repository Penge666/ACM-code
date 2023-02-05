#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e5+100 ;

int n,l[N],r[N];
map<int,int> f;
int dp[N];// dp(i):表示覆盖i次的数量

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for(int i=1;i<=n;i++) f[l[i]]++,f[r[i]+1]--;
    map<int,int> ::iterator it=f.begin();
    int last=it->first;
    int cnt=0;
    for(it=f.begin();it!=f.end();it++){
        dp[cnt]+=(it->first-last);
        last=it->first;
        cnt+=it->second;
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
