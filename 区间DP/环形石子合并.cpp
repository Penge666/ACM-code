#include<bits/stdc++.h>

using namespace std;

const int N = 333;

int n;
int sum[N];
int f[N][N];
/*
f(i,j):将第 i 堆石子合并到第 j 堆的合法方案数

*/
int arr[N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],sum[i]=sum[i-1]+arr[i];

    for(int len=2;len<=n;len++){  //枚举长度
        for(int i=1;i+len-1<=n;i++){ //枚举区间左端点
            int j=i+len-1;
            f[i][j]=1e8;
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    cout<<f[1][n];
    return 0;
}