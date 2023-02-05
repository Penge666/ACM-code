/*
三分模板一套。

求上述公式的最大值

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int a,b,n;
int res=0;
int cal(int x){
    int t=floor(a*x/b)-a*floor(x/b);res=max(res,t);
    return t;
}
void solve(int l,int r){
    while(r - l > 10){
        int m1 = l+(r-l)/3,m2 = r - (r-l)/3;
        if(cal(m1) > cal(m2)) r = m2;
        else l = m1;
    }
    int ans = 0;
    for(int i = l;i <= r;i++)
        ans = max(ans,cal(i));
    ans=max(ans,res);
    printf("%lld\n",ans);
}
signed main(){
    res=0;
    cin>>a>>b>>n;
    int l=0,r=n;
    solve(0,n);
    return 0;
}
