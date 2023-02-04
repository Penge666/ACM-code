/*
��һ���Լ��������ģ�O(��_��)O����~
����dp [ l ] [ r ] Ϊ���е� l ������ r �����ŵ����ƥ����Ŀ
���ž�����ת�Ʒ���
����ö��[l,r-1]��r����ַ�����ƥ�䣬ö��������ֵ�����Բο�һ�´���

*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

#define N 333
int dp[N][N];
/*
dp(l,r):������ l ������ r ���������ƥ����
MAX
((()))
()()()
([]])
)[)(
([][][)
*/
char str[N];
signed main(){
    while(~scanf("%s",(str+1))){
        if(str[1]=='e') break;
        memset(dp,0,sizeof(dp));
        int n=strlen(str+1);
        for(int i=1;i<=n;i++){
            if(str[i]=='('&&str[i+1]==')') dp[i][i+1]=2;
            else if(str[i]=='['&&str[i+1]==']') dp[i][i+1]=2;
        }
        for(int len=3;len<=n;len++){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                for(int k=l;k<r;k++){
                    if(str[r]==')'&&str[k]=='(')
                        dp[l][r]=max(dp[l][r],dp[l][max(k-1,l)]+dp[min(k+1,r)][r-1]+2);
                    else if(str[r]==']'&&str[k]=='[')
                        dp[l][r]=max(dp[l][r],dp[l][max(k-1,l)]+dp[min(k+1,r)][r-1]+2);
                    else
                        dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
                }
            }
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<i<<" "<<j<<" "<<dp[i][j]<<'\n';
            }cout<<'\n';
        }*/
        cout<<dp[1][n]<<'\n';
    }
    return 0;
}
/*

[](][(])[)]()[)]

(][(])
*/
