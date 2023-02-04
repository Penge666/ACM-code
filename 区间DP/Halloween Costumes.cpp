/*
���⣺��n�죬ÿ�촩�ض����·�������ͬʱ�������·���������������Ǽ��·��������ض����Ǽ������ѵ�һ���·��󣬸��·�����Ϊ���ɾ��������ٴ����ʾ�����n�죬������Ҫ���ټ��·���

��⣺����dp��dp [i] [j] ��ʾ���� i ~ j ������Ҫ���·�����ʼ����dp [i] [j] = dp [i] [j-1] + 1, ��ʼ�����ܼ򵥡�Ȼ����������   [ i��j-1 )  �����Ƿ���ĳһ�� ( k ) �·��͵� j ����·�һ������һ�� dp [i] [j] = min( dp [i] [j] , dp [i] [k] + dp [k+1] [j-1] )����dp���̵���˼�ǣ���k�촩�ϸ��·��󣬺������춼���ѵ�k����Ǽ��·���ֱ����j�죬�ѵ��������·�¶����k����Ǽ��·����Ӷ������j���ض��·������������ձ����׵õ���dp���̡�


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
const int N = 666 ;
int dp[N][N];
int arr[N];
/*

*/
signed main(){
    int T;
    int cnt=1;
    scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof(dp));
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<=n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                if(arr[r-1]==arr[r]) dp[l][r]=dp[l][r-1];
                else dp[l][r]=dp[l][r-1]+1;
                for(int k=l;k<r;k++){
                    if(arr[k]==arr[r])
                        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r-1]);
                }
            }
        }
        printf("Case %d: %d\n",cnt++,dp[1][n]);
    }

    return 0;
}
/*
��һ��ˢ�����⣬һ���ĵ�
����Ĺؼ�����dp[i][j]: ��ʾ������i-j֮����Ҫ������С������
�ص��ǣ�dp[i][j]��ʾ��ǰ���ٴ��ŵ�j���·���
���������Ǿ�����
if(arr[r]==arr[k]) 
  dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]-1);
else
   dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
   
   
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;

#define pb push_back

#define int long long

const int N = 633 , inf = 6666666 ;
//dp[i][j]: ��ʾ������i-j֮����Ҫ������С������ �ص㣺��ʾ��ǰ���ٴ���j���·�
//(arr[r] == arr[k]) dp[i][j] = max(dp[i][j] , dp[i][k] + dp[k+1][r] -1 )
int n;
int arr[N];
int dp[N][N];
signed main(){
    int T=1;
    int cnt=1;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i],dp[i][i]=1;

        for(int len=2;len<=n;len++){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                dp[l][r]=inf;
                for(int k=l;k<r;k++){
                    if(arr[r]==arr[k])
                        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]-1);
                    else
                        dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);

                }
            }
        }
         printf("Case %lld: %lld\n",cnt++,dp[1][n]);
    }
    return 0;
}
/*
((()))
״ѹ��
1.ö��Len
2.ö����˵� ����˵� �Ҷ˵㣩
3.ö����˵���Ҷ˵��м����

dp[i][j]: ��ʾ������i-j֮����Ҫ������С������

if()
    DP[l][r]=DP[l][k]+DP[k][r]+
    for(int len=2;len<=n;len++){  //ö�ٳ���
        for(int i=1;i+len-1<=n;i++){ //ö��������˵�
            int j=i+len-1;
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }




*/
*/
