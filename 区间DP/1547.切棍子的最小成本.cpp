/*
https://leetcode-cn.com/problems/minimum-cost-to-cut-a-stick/
dp[l][r]:将第 l 段到第 r 段完全切开的最小花费
dp[l][r]=min(dp[l][k]+dp[k][r]+len,dp[l][r])

*/

const int N = 222;
int dp[N][N],cost[N];
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0),cuts.push_back(n);
        memset(cost,0,sizeof(cost));
        sort(cuts.begin(),cuts.end());
        for(int i=1;i<=cuts.size();i++) cost[i]=cuts[i-1];
        int m=cuts.size();
        for(int len=3;len<=m;len++){
            for(int l=1;l+len-1<=m;l++){
                int r=l+len-1;
                dp[l][r]=0x3f3f3f3f;
                for(int k=l+1;k<r;k++){
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+cost[r]-cost[l]);
                }
            }
        }
        return dp[1][m];
    }
};
/*


*/
