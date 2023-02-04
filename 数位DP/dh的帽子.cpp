#include<bits/stdc++.h>

using namespace std;
#define int long long
int a[33],b[33];
int dp[66][2][2][2][2][2][2];
int DP(int pos,int limit1,int limit2,int limit3,int ismin1,int ismin2,int ismin3){
    if(pos==-1) return 1;
    if(!limit1&&!limit2&&!limit3&&dp[pos][limit1][limit2][limit3][ismin1][ismin2][ismin3]!=-1)
        return dp[pos][limit1][limit2][limit3][ismin1][ismin2][ismin3];
    int high1=limit1?a[pos]:1;
    int high2=limit2?a[pos]:1;
    int high3=limit3?a[pos]:1;
    int low1=ismin1?b[pos]:0;
    int low2=ismin2?b[pos]:0;
    int low3=ismin3?b[pos]:0;
    int ans=0;
    for(int i=low1;i<=high1;i++){
        for(int j=low2;j<=high2;j++){
            for(int k=low3;k<=high3;k++){
                if((i^j^k)==(i|j|k))
                    ans=ans+DP(pos-1,(i==high1)&&limit1,(j==high2)&&limit2,(k==high3)&&limit3,(i==low1)&&ismin1,(j==low2)&&ismin2,(k==low3)&&ismin3);
            }
        }
    }
    if(!limit1&&!limit2&&!limit3)
    dp[pos][limit1][limit2][limit3][ismin1][ismin2][ismin3]=ans;
    return ans;
}
int slove(int L,int R){
    for(int i=0;i<=30;i++){
        if((1<<i)&R) a[i]=1;else a[i]=0;
        if((1<<i)&L) b[i]=1;else b[i]=0;
    }
    return DP(30,1,1,1,1,1,1);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int L,R;
    cin>>L>>R;
    cout<<slove(L,R);
    return 0;
}
