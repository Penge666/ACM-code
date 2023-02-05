#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+100 ;
int n,cost,a[N],b[N],c[N];
int dp[N];//dp[i]:表示覆盖次数为i的数量
map<int,int> f;
signed main(){
    cin>>n>>cost;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++){
        f[a[i]]+=c[i];
        f[b[i]+1]-=c[i];
    }
    int ans=0;
    int cnt=0;
    map<int,int>::iterator it=f.begin();
    int last=it->first;
    for(it=f.begin();it!=f.end();it++){
        ans+=min(cost,cnt)*(it->first-last);
        last=it->first;
        cnt+=it->second;
    }
    cout<<ans;
    return 0;
}
