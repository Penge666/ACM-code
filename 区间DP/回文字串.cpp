/*
���ַ���ΪS��

��f[i][j]ΪҪ�Ѵ�i��j������i��j�����ַ�����Ϊ���Ĵ������ٲ����ַ�����

��ôת�ƣ� �����ֿ��ܣ�

S[i] == S[j]˵��������ͷ��ȣ�����Ҫ�����ʲô��ֻ��Ҫf[i][j] = f[i+1][j-1]�ͺ��ˣ�i+1�� j-1 һ�ξ��ǳ���ͷ������ٲ����ַ���

S[i] != s[j] ˵��������ͷ��ͬ����Ҫ�����1�ַ��Ա��ִ��Ļ������ʣ���������²�����ַ����������ұߣ�Ҳ����������ߡ�������Ҫf[i][j] = min(f[i+1][j], f[i][j-1]) + 1f
*/

#include<bits/stdc++.h>

using namespace std;
const int N = 1666;
int dp[N][N];
/*
dp(i,j):����[i,j]��ɻ��Ĵ���Ҫ��ӵ������ַ�
*/
char str[N];
int main(){
    scanf("%s",str+1);
    int L=strlen(str+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=L;i++){
        dp[i][i]=0;
        if(str[i]==str[i+1]) dp[i][i+1]=0;
        else dp[i][i+1]=1;
    }
    for(int len=3;len<=L;len++){
        for(int l=1;l+len-1<=L;l++){
            int r=l+len-1;
            if(str[l]==str[r]) dp[l][r]=dp[l+1][r-1];
            else dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
        }
    }
    cout<<dp[1][L];
    return 0;
}
