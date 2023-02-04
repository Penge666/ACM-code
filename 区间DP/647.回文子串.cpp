// 区间DP+容斥思想


const int N = 1009 ;
int dp[N][N];
char str[N];
int f[N][N];
class Solution {
public:

    int countSubstrings(string s){
        memset(dp,0,sizeof(dp));
        memset(f,0,sizeof(f));
        int n=s.size();
        for(int i=1;i<=n;i++) str[i]=s[i-1];
        for(int i=1;i<=n;i++) dp[i][i]=1,f[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                dp[l][r]=dp[l][r-1]+dp[l+1][r]-dp[l+1][r-1];
                if(str[l]==str[r]&&f[l+1][r-1]||(str[l]==str[r]&&len==2)){
                    f[l][r]=1;
                }
                dp[l][r]+=f[l][r];
            }
        }
        return dp[1][n];
    }
};
