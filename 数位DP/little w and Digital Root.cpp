#include<bits/stdc++.h>

using namespace std;
#define int long long
int j,a[66];
int dp[22][6666][2][12];
int vis[66];
int judge(int num){
    if(num<10) return num;
    while(1){
        int sum=0;
        int cnt=1;
        while(num){
            sum+=(num%10)*cnt++;num/=10;
        }
        if(sum<10) return sum;else num=sum;
    }
}
int DP(int pos,int sum,int limit){
    if(!pos) return j==judge(sum)?1:0;
    if(!limit&&dp[pos][sum][limit][j]!=-1)
        return dp[pos][sum][limit][j];
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        ans+=DP(pos-1,sum+i*pos,limit&&(i==high));
    }
    if(!limit)
        dp[pos][sum][limit][j]=ans;
    return ans;
}
int slove(int n){
    int len=0;
    while(n){
        a[++len]=n%10;
        n/=10;
    }
    return DP(len,0,1);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int T;
    cin>>T;
    int cnt=1;
    while(T--){
        int L,R;
        scanf("%lld%lld",&L,&R);
        printf("Case #%lld: ",cnt++);
        for(j=1;j<=9;j++){

            int res=slove(R)-slove(L-1);
            if(j==1) printf("%lld",res);else printf(" %lld",res);
        }
        printf("\n");
    }
    return 0;
}
