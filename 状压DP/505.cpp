/*
01����

Ҫ���޸����ٸ���ʹ������ż���Ӿ���1�ĸ���Ϊ������

n��mͬʱ����4��ô�޽⡣
����ֻ��Ҫ����n��3�������
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1000009 ;
string mp[N];
//dp[i][j]:�Ѿ��ں�ǰi�У����ҵ�ǰ�е�״̬��j����С��������
//dp[i][j]=dp[i-1][k]+���Ĵ���,dp[i][j]
int dp[N][1<<3];
int f[666][666];
int n,m;
int change(int row,int state){
    int sum=0;
    for(int i=0;i<n;i++){
        if((int)(mp[i][row]-'0')!=(state>>i&1))
            sum++;
    }
    return sum;
}
int a[666],b[666];
int check(int sta1,int sta2){
    for(int i=0;i<n;i++){
        a[i]=sta1>>i&1;
        b[i]=sta2>>i&1;
    }
    for(int i=1;i<n;i++){
        int sum=a[i]+a[i-1]+b[i]+b[i-1];
        if(sum%2==0)
            return 0;
    }
    return 1;
}
signed main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>mp[i];
    if(n>3&&m>3){
        cout<<"-1";
        return 0;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<(1<<n);i++){
        dp[0][i]=change(0,i);
        //cout<<i<<" "<<dp[0][i]<<" "<<'\n';
    }

    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++){
            f[i][j]=check(i,j);
        }
    }
    for(int k=1;k<m;k++){
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<(1<<n);j++){
                if(f[i][j]){
                    dp[k][i]=min(dp[k][i],dp[k-1][j]+change(k,i));
                }
            }
        }
    }
    int ans=9999999999999;
    for(int i=0;i<(1<<n);i++) ans=min(ans,dp[m-1][i]);
    cout<<ans;
    return 0;
}
