/*
按照数位DP分析步骤： 假设我们当前枚举到第i位，且第i位上的数字是x，那么现在对于答案的第i位数字j来说，可以填两类数字：

1.j取0~x-1
那么res += f[i+1][j];

2.j取x
last记录x，再枚举下一位

f数组
f[i][j] 表示一共有i位，且最高位数字为j的不降数的个数
状态转移： 因为最高位已经固定，所以假设第i-1位是k，根据不降数定义k>=j,所以
*/
#include<bits/stdc++.h>

using namespace std;

const int N=15;

int f[N][N];
/*
总共 i 位，最高位为 j 的合法方案数

*/
void init(){
    for(int i=0;i<10;i++) f[1][i]=1;

    for(int i=2;i<N;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++)
                f[i][j]+=f[i-1][k];
        }
    }
}

int dp(int n){
    if(!n) return 1;

    vector<int> nums;
    while(n) nums.push_back(n%10),n/=10;

    int res=0;
    int last=0;//保存前一位的值
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        for(int j=last;j<x;j++) res+=f[i+1][j];
        if(x<last) break;
        last=x;
        if(!i) res++;
    }
    return res;
}
int main(){
    init();

    int l,r;
    while( cin >> l >> r ){
        cout << dp(r) - dp(l-1) << endl;
    }
    return 0;
}
