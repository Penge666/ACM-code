#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N =  4666666 ;
int f[N];
signed main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=0;i<=b;i++){
        f[i]++,f[i+a+1]--;
    }
    for(int i=0;i<=a+b;i++) f[i]+=f[i-1];
    int ans=0;
    for(int i=0;i<=a+b;i++){
        int l=max(i,0ll);
        int r=min(i+c,d);
        ans+=max(r-l+1,0ll)*f[i];
    }
    cout<<ans;
    return 0;
}
