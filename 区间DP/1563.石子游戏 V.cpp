// º«“‰ªØ’Êœ„



const int N = 666;
int n,dp[N][N],sum[N];
class Solution {
public:
    int DP(int l,int r){
        if(dp[l][r]!=-1) return dp[l][r];
        if(l==r) return 0;
        int val=-1;
        for(int i=l;i<r;i++){
            int s1=sum[i]-sum[l-1];
            int s2=sum[r]-sum[i];
            if(s1==s2){
                val=max(val,max(s2+DP(i+1,r),s1+DP(l,i)));
            }else if(s1>s2){
                val=max(val,s2+DP(i+1,r));
            }else if(s1<s2){
                val=max(val,s1+DP(l,i));
            }
        }
        return dp[l][r]=val;
    }
    int stoneGameV(vector<int>& stoneValue) {
        if(stoneValue.size()==1) return 0;
        int n=stoneValue.size();
        memset(dp,-1,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+stoneValue[i-1];
        }
        int ans=DP(1,n);
        return ans;
    }
};
