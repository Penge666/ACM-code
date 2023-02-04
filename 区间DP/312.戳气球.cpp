/*
思路：dp[l][r]:表示将区间[l,r]上的气球都戳破所获得的最大价值。
这是枚举一个k,k在[l+1,r-1]的区间。这里k意味着在区间[l,r]上k个气球最后戳破。
值得注意的是，这题区间是开区间

*/

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
/*
*/
