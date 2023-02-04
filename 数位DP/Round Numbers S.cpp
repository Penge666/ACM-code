#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 66 ;
int a[N];
int dp[66][66][66][2][2];
int DP(int pos,int count1,int count0,int limit,int st){
    if(!pos){
        if(count0>=count1){
            return 1;
        }else{
            return 0;
        }
    }
    if(!limit&&st&&dp[pos][count1][count0][limit][st]!=-1){
        return dp[pos][count1][count0][limit][st];
    }
    int high=limit?a[pos]:1;
    int ans=0;
    for(int i=0;i<=high;i++){
        ans+=DP(pos-1,count1+(i==1?(st||i)*1:0),count0+(i==0?(st||i)*1:0),limit&&(i==high),st||i);
    }
    if(!limit&&st)
         dp[pos][count1][count0][limit][st]=ans;
    return ans;
}
int slove(int n){
    int len=0;
    while(n){
        a[++len]=n%2;
        n=n/2;
    }
    return DP(len,0,0,1,0);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int L,R;
    cin>>L>>R;
    cout<<slove(R)-slove(L-1);
    return 0;
}
