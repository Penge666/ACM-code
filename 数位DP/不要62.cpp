/*
还是相同的套路，假设数字num当前枚举到第i位，且第i位数字是x，那么对于答案的第i位来说，假设是j，有两种填法：

1.0~x-1
我们用last表示num中第i位的高一位数字，那么根据题意，j不能是4 且 当last是6的时候j不能为2，这两种情况在枚举的时候特判一下即可
然后，累加到答案中，res += f[i+1][j]

2.x
那么这一位就不用处理了，更新一下last即可，last = x
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 12;

int f[N][10];

void init(){
    for(int i = 0; i<=9; i++) f[1][i] = !(i==4);

    for(int i = 2; i<N; i++)
        for(int j = 0; j<=9; j++){
            if(j == 4) continue;
            for(int k = 0; k<=9; k++){
                if(k == 4 || (j==6 && k==2)) continue;
                f[i][j] += f[i-1][k];
            }
        }

}

int dp(int n){
    if(!n) return 1;  //最好特判一下，否则进到下面可能出问题
    int res = 0, last = 0;  //last表示num高一位的数字是多少

    vector<int> a;
    while(n) a.push_back(n%10),n/=10;

    int len = a.size()-1;
    for(int i = len; i>=0; i--){
        int x = a[i];
        for(int j = 0; j<x; j++){
            if(j == 4 || (last == 6 && j == 2)) continue;
            res += f[i+1][j];
        }
        if(x == 4 || (last == 6 && x == 2)) break;  //特判一下，不满足题意直接break
        last = x;
        if(!i) res ++;
    }
    return res;
}
int main()
{
    init();
    int l,r;
    while(cin>>l>>r){
        if(l==0 && r==0) break;
        cout<<dp(r)-dp(l-1)<<endl;
    }
    return 0;
}
/*
// 记忆化搜索

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 66 ;
int a[N];
int dp[N][N][N];
int DP(int pos,int pre,int limit){
    //cout<<pos<<" "<<pre<<" "<<limit<<'\n';
    if(!pos) return 1;
    if(dp[pos][pre][limit]!=-1&&!limit) return dp[pos][pre][limit];
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        if(i==4||pre==6&&i==2) continue;
        ans+=DP(pos-1,i,limit&&i==high);
    }
    if(!limit) dp[pos][pre][limit]=ans;
    return ans;
}
int slove(int n){

    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    return DP(len,0,1);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int L,R;
    while(scanf("%lld%lld",&L,&R)&&(L+R)){
        printf("%lld\n",slove(R)-slove(L-1));
    }
    return 0;
}
/*
99 1000000
*/
*/
