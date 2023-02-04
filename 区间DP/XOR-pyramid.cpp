/*
ͨ������ͼƬ����Ŀ������֪��ĳ�������ڵ�ֵ�ĵ���ʽΪf[l,r]=f[l+1,r] xor f[l,r?1]
��ͨ���������ʽ���Խ�������dp�������������dp[i][i]Ϊ���䳤��Ϊ1��ֵ��Ȼ��ͨ
��ö�ٳ����Լ���˵�����������fֵ�����⿪һ��ans[i][j]����¼[i, j]����Ĵ𰸣���
ѯ�ʵ�ʱ��O(1)�ش�
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 5555;
int n,q;
int arr[N];
int dp[N][N];
int f[N][N];
/*
dp(i,j):��ʾ����[i,j]����ʾ�����ֵ
*/
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        dp[i][i]=arr[i];
        f[i][i]=arr[i];
    }

    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            f[l][r]=f[l][r-1]^f[l+1][r];
            dp[l][r]=max(max(dp[l][r],f[l][r]),max(dp[l][r-1],dp[l+1][r]));
        }
    }
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        cout<<dp[L][R]<<'\n';
    }
    return 0;
}
