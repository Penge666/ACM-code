/*
ͨ�����ݷ�Χ2000���������뵽DP�����ǿ�����DP(i,j)��ʾ���䡾i,j��֮��Ĵ𰸣���С��ֵ�������һ�β�ֵһ���Ǽ���MAX[I,J]-MIN[I,J]��ͨ�����������г�״̬ת�Ʒ��̡�min(DP(l+1,r),DP(l,r-1))+a[r]-a[l]��ע�⣺����[l,r]Ҫ�Ÿ���

*/
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define maxn 2009
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[maxn];
int n,m;
int dp[maxn][maxn];
int DP(int l,int r){
    if(l==r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=min(DP(l+1,r),DP(l,r-1))+a[r]-a[l];
    return dp[l][r];
}
signed main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    cout<<DP(1,n);
    return 0;
}
