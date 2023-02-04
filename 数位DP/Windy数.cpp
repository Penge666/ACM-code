/*
假设我们当前枚举到第i位(设共有n位)，且第i位上的数字为x，那么对于答案中第i位数字j来说，有两类：

1.0~x-1 (如果第i位是最高位，这里是1~x-1)
括号中提到的1~x-1后面会解释 ,我们用last记录上一位的数字，然后枚举j，如果abs(j-last) >= 2 就累加答案，res += f[i+1][j];

2.x
不需要枚举j，last = x,再枚举之后的数位即可

上述做完之后，由于上面的答案都是n位的，对于数位个数低于n的，再累加到答案中就行了
*/

#include<bits/stdc++.h>

using namespace std;

const int  N  = 11;
int f[N][N];
/*
f(i,j) ；总共 i 位 ，最高位为 j 的合法方案数
*/
void init(){
    for(int i=0;i<=9;i++) f[1][i]=1;

    for(int i=2;i<N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                if(abs(j-k)>=2)
                    f[i][j]+=f[i-1][k];
            }
        }
    }
}
int dp(int n){
    if(!n) return 0;

    vector<int> nums;
    while(n) nums.push_back(n%10),n/=10;

    int res=0;
    int last=-10;
    //处理 n 位的情况
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        for(int j=(i==nums.size()-1);j<x;j++){
            if(abs(j-last)>=2)
            res+=f[i+1][j];
        }
        if(abs(last-x)>=2) last=x;
        else break;

        if(!i) res++;
    }
    //处理n-1的情况 [处理有前导 0 的情况]
    for(int i=1;i<nums.size();i++){
        for(int j=1;j<=9;j++)
            res+=f[i][j];
    }
    return res;
}
int main(){
    init();

    int l,r;
    cin>>l>>r;
    cout<<dp(r) - dp(l-1)<<endl;
    return 0;
}
/*

// 记忆化搜索

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 15 ;
int a[N];
int dp[N][N][N][N];
int DP(int pos,int pre,int lead,int limit){
    if(!pos) return 1;
    if(!lead&&!limit&&dp[pos][pre][lead][limit]!=-1)
        return dp[pos][pre][lead][limit];
    int high=limit?a[pos]:9;
    int sum=0;
    for(int i=0;i<=high;i++){
        if(abs(pre-i)<2) continue;
        if(lead&&!i) sum+=DP(pos-1,100,1,limit&&(i==high));
        else sum+=DP(pos-1,i,0,limit&&(i==high));
    }
    if(!lead&&!limit)
        dp[pos][pre][lead][limit]=sum;
    return sum;
}
int slove(int n){
    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    return DP(len,100,1,1);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int L,R;
    cin>>L>>R;
    cout<<slove(R)-slove(L-1);
    return 0;
}
*/
