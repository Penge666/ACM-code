//思路：1.首先求最值，则必有最值，用三分。三分最小的楼房的高度。求最值

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int h[N];
int n,m;
int RES;
int check(int num){
    int res=0;
    for(int i=1;i<=n;i++){
        if(h[i]<num){
            res+=abs(h[i]-num)*abs(h[i]-num);
        }else if(h[i]>num+m){
            res+=abs(h[i]-num-m)*abs(h[i]-num-m);
        }
    }
    RES=min(RES,res);
    return res;
}
signed main(){
    cin>>n>>m;
    RES=99999999999999;
    for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
    int l=1;
    int ans=0;
    int r=1000000;
    while(l<r){
        int midl=(l+r)/2;
        int midr=(midl+r)/2;
        if(check(midl)<check(midr)){
            r=midr;
        }else if(check(midl)>check(midr)){
            l=midl;
        }else{

            break;
        }
    }
    cout<<RES;
    return 0;
}
