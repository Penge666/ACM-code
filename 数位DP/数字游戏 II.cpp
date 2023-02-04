/*
在几道数位Dp题目练习过后，这类题目重点在于找到左边那一类如何直接计算
对于这一题来说，假设我们当前枚举到的第i位，且第i位上的数字是x，那么对于答案中的第i位数字j来说，可以填两类数：

1.0~x-1
我们用last表示到当前为止，前面数位上的数字之和，对此，当前第i位数字为j，前面数字之和为last，那么
后i位(包括j这一位)数字之和sum与last的关系就是(last+sum)%N == 0,那么sum%N的结果等价于(-last)%N,
所以res += f[i+1][j][(-last%N)]; (后面会提到f数组的处理)
2.x
如果j填x，那么不用枚举了，last += x，再枚举下一位即可
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 11, M = 110;

int P;
int f[N][N][M];
/*
f(i,j,k):总共 i 位，最高位为 j ，所有数字加和mod P ==k 的方案数
*/
int mod(int x,int y){
    return (x%y+y)%y;
}
void init(){
    memset(f,0,sizeof(f));
    for(int i=0;i<=9;i++) f[1][i][i%P]=1;
    for(int i=2;i<N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<P;k++){
                for(int x=0;x<=9;x++)
                    f[i][j][k]+=f[i-1][x][mod(k-j,P)];
            }
        }
    }
    return ;
}
int dp(int n){
    if(!n) return 1;

    vector<int> nums;
    while(n) nums.push_back(n%10),n/=10;

    int res=0;
    int last=0;

    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        for(int j=0;j<x;j++){
            res+=f[i+1][j][mod(-last,P)];
        }
        last+=x;
        if(!i&&last%P==0) res++;
    }
    return res;
}
signed main(){
    int l,r;
    while(cin>>l>>r>>P){
        init();
        cout<<dp(r) - dp(l-1)<<'\n';
    }
    return 0;
}
