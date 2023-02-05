// ¶þ·Ö+²î·Ö


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define  N 1666666
int n,m;
int arr[N];
struct str{
    int d,s,t;
}st[N];
int f[N];
int check(int num){
    memset(f,0,sizeof(f));
    for(int i=1;i<=num;i++){
        f[st[i].s]+=st[i].d;
        f[st[i].t+1]-=st[i].d;
    }
    for(int i=1;i<=n;i++)
        f[i]+=f[i-1];
    for(int i=1;i<=n;i++){
        if(f[i]>arr[i]){
            return 1;
        }
    }
    return 0;
}
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
    for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&st[i].d,&st[i].s,&st[i].t);
    int l=1;
    int r=m;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    if(ans==-1){
        cout<<"0";
    }else{
        cout<<"-1"<<'\n';
        cout<<ans;
    }
    return 0;
}
