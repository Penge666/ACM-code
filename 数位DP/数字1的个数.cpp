const int N = 66;
int a[N];
int dp[N][N][N];
class Solution {
public:
    int DP(int pos,int count,int limit){
        if(!pos) return count;
        if(!limit&&dp[pos][count][limit]!=-1)
            return dp[pos][count][limit];
        int high=limit?a[pos]:9;
        int sum=0;
        for(int i=0;i<=high;i++){
            sum+=DP(pos-1,count+(i==1),limit&&(i==a[pos]));
        }
        if(!limit) dp[pos][count][limit]=sum;
        return sum;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        int len=0;
        while(n){
            a[++len]=n%10;
            n/=10;
        }
        return DP(len,0,1);
    }
};
