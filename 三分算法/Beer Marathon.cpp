/*
 n 个啤酒摊，在 x 轴上给出位置，现要求改变位置，每个相距 k，问最少的总移动距离。

求最值。可以用三分解决。简化思想


*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 6666666
int arr[N];
int ans;int n,m;
double check(int s){
    int ss=0;
    for(int i=1;i<=n;i++){
        ss+=(abs(s-arr[i]));
        s+=m;
    }
    ans=min(ans,ss);
    return ss;
}
void slove(int l,int r){
    for(int i=1;i<=100;i++){
        int mid=(l+r)/2;
        int mmid=(mid+r)/2;
        int t1=check(mid);
        int t2=check(mmid);
        if(t1>=t2){
            l=mid;
        }else{
            r=mmid;
        }
    }
}
signed main(){
    ans=999999999999999999;
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    sort(arr+1,arr+1+n);
    slove(-1000000000000,1000000000000);
    cout<<ans;
    return 0;
}
