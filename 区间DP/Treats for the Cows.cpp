/*
��Ŀ����
������N�����ֵ�����,v1v2��vn,ÿ�ο���ȡ������˻������Ҷ˵����֣���������������ȡ��������� i ��ȡ������Ϊ vi ,��ɻ�� i*vi �ļ�ֵ������ι滮ȡ��˳�򣬲���ʹ��ֵ������������ֵ�͡�

˼·

����ÿ��ֻ��ȡ����˻������Ҷ˵����֣����ж���һ������ vi��vj,ֻ����ȡ vi ���� vj�󣬲��ܿ������м�����֡������������裬���֪����ȡ�� vi+1��vj �� vi��vj-1�����������������������ֵ�����ֵ����ô���ǾͿ������ vi��vj ���е�����ֵ(���������״̬ת����)���ɴˣ����ǿ���ȷ������˼·���ǽ����仮��ΪС���䣬ֱ��ֻ��һ��Ԫ��ʱ���������������ֵ(���ڵ� i ��Ԫ�ؿ����ǵ�1~n��ȡ�����ǵ�ǰֻ����һ��Ԫ��ʱ��Ȼ�ǵ�n��ȡ����ʣ�����ֵΪvalue[i] * n)��Ȼ�󲻶Ϻϲ���������ȡ�������ֵ��ֱ�����串���������С�
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
dp(i,j):��������� i ȡ������ j ����õ�����ֵ
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
