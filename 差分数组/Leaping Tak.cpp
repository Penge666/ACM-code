/*
���⣺����һ������n��k������,S��ʾ��������Ĳ��ļ���,��Ŀǰ��1,ÿ�ο��ԴӼ�����ѡ��һ�����������ƶ�,���ж����ַ�����1�ߵ�n.
���:���Ǵ�1��ʼ����,dp[i]��ʾ�ߵ�Ŀǰ�ߵ�i�ķ�����,��ȥ����ÿһ������,��dp[i]��������[i+l[j],i+r[j]]�еĵ�,�������������ǿ����ò����O(n)�����г���.

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , mod = 998244353;
int n,k,l[N],r[N];
int dp[N];
signed main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>l[i]>>r[i];
    dp[1]=1;dp[2]=-1;
    for(int i=1;i<=n;i++){
        dp[i]=(dp[i]+dp[i-1]+mod)%mod;
        for(int j=1;j<=k;j++){
            dp[i+l[j]]+=dp[i];
            dp[i+r[j]+1]-=dp[i];
            dp[i+l[j]]=(dp[i+l[j]]+mod)%mod;
            dp[i+r[j]+1]=(dp[i+r[j]+1]+mod)%mod;
        }
    }
    cout<<dp[n];
    return 0;
}
