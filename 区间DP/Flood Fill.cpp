/*
����dp
dp[l][r][0]��ʾl-r��ɫΪcolor_left��dp[l][r][1]��ʾl-r��ɫΪcolor_right.

�����Ǵӳ���Ϊ1�����俪ʼö��

��ǰö�ٵ���������[l,r]�ҳ���Ϊlen

���Կ�����len+1������ת��.

dp[l][r+1][1]������dp[l][r][0/1]ת�ƶ���
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 5009;

int n;
int dp[N][N][2];
int arr[N];
/*
dp(i,j,k):������[i,j]���ն�Ϳ��(k==0||k==1[��˵�|�Ҷ˵�]����ɫ)����С����
*/
signed main(){
    //memset(dp,0x3f,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)
         cin>>arr[i];

    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;

            dp[l][r][0]=min(dp[l+1][r][1]+(arr[l]!=arr[r]),dp[l+1][r][0]+(arr[l]!=arr[l+1]));
            dp[l][r][1]=min(dp[l][r-1][0]+(arr[l]!=arr[r]),dp[l][r-1][1]+(arr[r-1]!=arr[r]));
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1]);
    return 0;
}
