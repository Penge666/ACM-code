// ’€∞Î√∂æŸ£¨∆ΩÃØ∏¥‘”∂»°£


#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 66 , M = 1<<21 ;
struct str{
    int w,val;
}st1[M],st2[M];
int n,m,t,arr[N];
int cnt1=0,cnt2=0;
bool cmp(str A,str B){
    if(A.w!=B.w){
        return A.w<B.w;
    }else{
        return A.val>B.val;
    }
}
int slove(int num){
    int l=1,r=cnt2;
    int pos=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(st2[mid].w<=num){
            l=mid+1;
            pos=mid;
        }else{
            r=mid-1;
        }
    }
    if(pos==-1) return 0;
    else return st2[pos].val;
}
signed main(){
    cin>>n>>t;
    for(int i=0;i<n;i++) cin>>arr[i];
    m=n/2;
//    cout<<m<<'\n';
    for(int i=0;i<(1<<m);i++){
        int sum=0;
        for(int j=0;j<m;j++){
            if((i>>j)&1){
                sum+=arr[j];
            }
        }
        st1[++cnt1].w=sum;st1[cnt1].val=sum;
    }
    for(int i=0;i<(1<<(n-m));i++){
        int sum=0;
        for(int j=0;j<(n-m);j++){
            if((i>>j)&1){
                sum+=arr[j+m];
            }
        }
        st2[++cnt2].w=sum;st2[cnt2].val=sum;
    }
    sort(st2+1,st2+1+cnt2,cmp);
    for(int i=1;i<=cnt2;i++) st2[i].val=max(st2[i].val,st2[i-1].val);
    int ans=0;
    //for(int i=1;i<=cnt1;i++) cout<<st1[i].w<<'\n';
    for(int i=1;i<=cnt1;i++){
        int tot=0;
        if(st1[i].val<=t)
            tot+=st1[i].val;
        int tmp=slove(t-st1[i].w);
        if(tmp+tot<=t)
            tot+=tmp;
        ans=max(ans,tot);
    }
    cout<<ans;
    return 0;
}
