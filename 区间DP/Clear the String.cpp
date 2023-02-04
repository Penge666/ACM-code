/*
���⣺����һ����s��ÿ�ο��Ի���1�Ĵ���ɾȥһ���Ӵ���Ҫ���Ӵ���ÿһλΪͬһ���ַ�����ɾȥ����������С���ۡ�

//dp[l,r]����ʾ������l,r���ַ���ɾ������С����
//dp[l,r]=min(dp[l,r],dp[l,k]+dp[k+1,r]+(str[r]!=str[l]) ���״̬ת�Ʒ���Ϲ�µġ�QAQ
*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 9999999999999;
int n;
char str[N];
int dp[666][666];
//dp[l,r]����ʾ������l,r���ַ���ɾ������С����
//dp[l,r]=min(dp[l,r],dp[l,k]+dp[k+1,r]+(str[r]!=str[l])
signed main(){
    cin>>n>>(str+1);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int i=2;i<=n;i++){
        if(str[i-1]!=str[i]) dp[i-1][i]=2;
        else dp[i-1][i]=1;
    }
    for(int len=3;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            for(int k=l;k<r;k++){
                if(str[l]!=str[r]){
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
                }else{
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]-1);
                }
            }
        //    cout<<l<<" "<<r<<" "<<dp[l][r]<<'\n';
        }
    }
    cout<<dp[1][n];
    return 0;
    
}

/*
//�ⷨ2�����仯 
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 666666 , inf = 9999999999999;
int n;
char str[N];
int dp[666][666];
//dp[l,r]����ʾ������l,r���ַ���ɾ������С����
//dp[l,r]=min(dp[l,r],dp[l,k]+dp[k+1,r]+(str[r]!=str[l])
int DP(int L,int R){
    if(dp[L][R]!=-1) return dp[L][R];
    if(L==R) return 1;
    if(str[L]==str[R]) return DP(L+1,R);
    int ans=inf;
    for(int k=L;k<R;k++){
        ans=min(ans,DP(L,k)+DP(k+1,R));
    }
    return dp[L][R]=ans;
}
signed main(){
    cin>>n>>(str+1);
    memset(dp,-1,sizeof(dp));
    cout<<DP(1,n);
    return 0;
}
*/
