/*
��һ������n ��� 1-n �����飬 m�������� ÿ�β���ѡ�� [L,R] ��һ�Σ� q����ѯ��ÿ�β�ѯ��[L,R] �ϸ��������ڣ����˼��� ��
����: ���� [1,1] [2,2] [1,2] , [1,6] ��ѯ[1 2] �õ�3

*/

/*
��һ������n ��� 1-n �����飬 m�������� ÿ�β���ѡ�� [L,R] ��һ�Σ� q����ѯ��
ÿ�β�ѯ��[L,R] �ϸ��������ڣ����˼��� ��
����: ���� [1,1] [2,2] [1,2] , [1,6] ��ѯ[1 2] �õ�3
*/

#include<bits/stdc++.h>

using namespace std;
#define int long long
#define N 666
int n,m,q;
int dp[N][N],mp[N][N]={0};
/*
dp(i,j): ���� [i,j] ���ǵ������������
���ǵ�Ҫ��l+1��r-1�����l����r����
dp(l,r)+=dp(l,r-1)+dp(l+1,r)-dp(l-1,r-1)
*/
signed main(){
    cin>>n>>m>>q;
    int l,r;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        mp[l][r]++;
    }
    for(int i=1;i<=n;i++) dp[i][i]=mp[i][i];//��ʼ��
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            dp[l][r]=mp[l][r]+dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1];
        }
    }
    while(q--){
        cin>>l>>r;
        cout<<dp[l][r]<<'\n';
    }
    return 0;
}
