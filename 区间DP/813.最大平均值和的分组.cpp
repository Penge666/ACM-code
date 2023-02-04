/*
假的区间DPQAQ
DP[I,K]:将前 I 个数分为 K 组的最大价值
DP[I,K]=DP[I-J][K-1]+(sum[i]-sum[]/num)
*/
const int N = 666 ;
double dp[N][N],sum[N];
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        memset(sum,0.0,sizeof(sum));
        memset(dp,0.0,sizeof(dp));
        sum[1]=A[0];
        int n=A.size();
        for(int i=2;i<=n;i++) sum[i]=sum[i-1]+A[i-1];
        for(int i=1;i<=n;i++) dp[i][1]=sum[i]*1.0/i;
        for(int k=2;k<=K;k++){
            for(int i=k;i<=n;i++){
                for(int j=k-1;j<i;j++){
                    dp[i][k]=max(dp[i][k],dp[j][k-1]+(sum[i]-sum[j])*1.0/(i-j));
                }
            }
        }
        return dp[n][K];
    }
};
/*
DP[I,K]:将前 I 个数分为 K 组的最大价值
DP[I,K]=DP[I-J][K-1]+(sum[i]-sum[]/num)
*/
