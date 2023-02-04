//dp[l,r]:区间[l,r]上最长的回文子序列的长度 MAX
const int N = 6666;
int arr[N];
int dp[N][N];
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        memset(dp,0,sizeof(dp));
        int cnt=0;arr[++cnt]=1;
        for(int i=0;i<nums.size();i++) arr[++cnt]=nums[i];
        arr[++cnt]=1;
        for(int i=2;i<cnt;i++) dp[i-1][i+1]=arr[i]*arr[i-1]*arr[i+1];
        for(int len=4;len<=cnt;len++){
            for(int l=1;l+len-1<=cnt;l++){
                int r=l+len-1;
                for(int k=l+1;k<r;k++){
                    dp[l][r]=max(dp[l][r],dp[l][k]+arr[l]*arr[k]*arr[r]+dp[k][r]);
                }
            }
        }
        return dp[1][cnt];
    }
};
