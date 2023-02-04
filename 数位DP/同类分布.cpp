/*
现在关键的问题是：怎样记录dp状态？

这里st可达到1e18显然是不能作为dp转移的下标直接记录的

所以我们考虑取模

我们最理想的模数当然是把每次搜到最后得到的数字各个位数之和

但是我们发现在这个过程中sum是发生变化的

所以我们就应该以一个定值作为模数

那好，我们虽然不知道最后各位之和的结果，我们枚举总可以吧

我们只需要枚举所有的各位数字之和作为模数

最后判断sum和枚举的mod相等并且st%sum=0的数就是符合题意的答案
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 66;
int mod,a[N];
int dp[20][180][180][2];
int DP(int pos,int x,int y,int limit){
    if(!pos){
        if(x==mod&&y==0) return 1;else return 0;
    }
    if(!limit&&dp[pos][x][y][limit]!=-1)
        return dp[pos][x][y][limit];
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        ans+=DP(pos-1,x+i,(y*10+i)%mod,limit&&(i==high));
    }
    if(!limit)
        dp[pos][x][y][limit]=ans;
    return ans;
}
int slove(int n){
    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    int ans=0;
    for(mod=1;mod<=9*len;mod++){
        memset(dp,-1,sizeof(dp));
        ans+=DP(len,0,0,1);
    }
    return ans;
}
signed main(){
    int L,R;
    cin>>L>>R;
    cout<<slove(R)-slove(L-1);
    return 0;
}
