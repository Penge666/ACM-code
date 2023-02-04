/*
����dp[i][j]��ʾ����[i,j]����С�÷�

һ��ʼ�����ȳ�ʼ���ó���Ϊ��������ֵ�Ƕ��٣�����ֱ����

Ȼ��ʼö�����䳤��Ϊ4������������[i,j]
ö�������ڵ�һ����k��Ϊ���һ��ȡ�����������������Ѿ�ȡ���ˣ�ֻʣi,k,j(i<k<j)��

״̬ת�Ʒ���Ϊ

dp[i][j]=dp[i][k]+dp[k][j]+a[i]*a[k]*a[j]
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long  ll;
const int N = 666;
int n;
int dp[N][N];
int arr[N];
/*
dp(i,j):��ʾ������[i,j]�������պ���ʽ�ϲ�ʹ�����ս�ʣͷβ����С����
*/
signed main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++)
        dp[i][i+2]=arr[i]*arr[i+1]*arr[i+2];
    for(int len=4;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            dp[l][r]=1e8;
            for(int k=l+1;k<r;k++){
                dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+arr[l]*arr[r]*arr[k]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
