#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define int long long
const int N = 666666  , inf = 1e18+10;
int a[N],b[N];
int n,m;
int cal(int K){
    int ans=inf;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=min(ans,K*a[i]+K*a[j]+b[i]+b[j]);
        }
    }
    return ans;
}
int solve(int l,int r){
    while(r - l > 10){
        int m1 = l+(r-l)/3,m2 = r - (r-l)/3;
        if(cal(m1) > cal(m2)) r = m2;
        else l = m1;
    }
    int ans = -inf;
    for(int i = l;i <= r;i++)
        ans = max(ans,cal(i));
    return ans;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int res=solve(1,m);
    cout<<res;
    return 0;
}
