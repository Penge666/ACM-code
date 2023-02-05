#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int f[N],arr[N];
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n,k;
        scanf("%lld%lld",&n,&k);

        for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
        for(int i=1;i<=n/2;i++){
            int minx=min(arr[i],arr[n-i+1]);
            int maxn=max(arr[i],arr[n-i+1]);
            int sum=arr[i]+arr[n-i+1];
            f[2]+=2;
            f[2*k+1]-=2;
            f[sum]--;
            f[sum+1]++;
            f[minx+1]--;
            f[maxn+k+1]++;
        }
        int ans=f[2];
        for(int i=3;i<=2*k;i++){
            f[i]+=f[i-1];
            ans=min(ans,f[i]);
        }
        cout<<ans<<'\n';
        for(int i=0;i<=2*k+1;i++) arr[i]=0,f[i]=0;
    }
    return 0;
}
