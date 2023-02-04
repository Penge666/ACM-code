/*
题目大意
给定右N个数字的序列,v1v2…vn,每次可以取出最左端或者最右端的数字，将序列所有数字取出。假设第 i 次取出数字为 vi ,则可获得 i*vi 的价值，问如何规划取数顺序，才能使价值和最大，输出最大价值和。

思路

由于每次只能取最左端或者最右端的数字，所有对于一个序列 vi…vj,只能先取 vi 或者 vj后，才能考虑其中间的数字。不妨做个假设，如果知道了取出 vi+1…vj 和 vi…vj-1这两个子序列中序所有数字的最大价值，那么我们就可以求出 vi…vj 序列的最大价值(求解在下述状态转移中)。由此，我们可以确定大致思路就是将区间划分为小区间，直至只有一个元素时，求出该区间的最大值(对于第 i 个元素可能是第1~n次取，但是当前只考虑一个元素时显然是第n次取最合适，即价值为value[i] * n)，然后不断合并扩大区间取区间最大值，直至区间覆盖整个序列。
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
const int N = 6666 ;
int dp[N][N];
int arr[N];
/*
dp(i,j):代表从区间 i 取到区间 j 所获得的最大价值
*/
signed main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            dp[l][r]=max(dp[l][r],max(dp[l+1][r]+(n-(r-l+1)+1)*arr[l],dp[l][r-1]+(n-(r-l+1)+1)*arr[r]));
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}
