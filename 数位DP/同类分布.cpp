/*
���ڹؼ��������ǣ�������¼dp״̬��

����st�ɴﵽ1e18��Ȼ�ǲ�����Ϊdpת�Ƶ��±�ֱ�Ӽ�¼��

�������ǿ���ȡģ

�����������ģ����Ȼ�ǰ�ÿ���ѵ����õ������ָ���λ��֮��

�������Ƿ��������������sum�Ƿ����仯��

�������Ǿ�Ӧ����һ����ֵ��Ϊģ��

�Ǻã�������Ȼ��֪������λ֮�͵Ľ��������ö���ܿ��԰�

����ֻ��Ҫö�����еĸ�λ����֮����Ϊģ��

����ж�sum��ö�ٵ�mod��Ȳ���st%sum=0�������Ƿ�������Ĵ�
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 66;
int mod,a[N];
int dp[20][180][180][2];
int DP(int pos,int x,int y,int limit){
    if(!pos){
        if(x==mod&&y==0) return 1;else return 0;
    }
    if(!limit&&dp[pos][x][y][limit]!=-1)
        return dp[pos][x][y][limit];
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        ans+=DP(pos-1,x+i,(y*10+i)%mod,limit&&(i==high));
    }
    if(!limit)
        dp[pos][x][y][limit]=ans;
    return ans;
}
int slove(int n){
    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    int ans=0;
    for(mod=1;mod<=9*len;mod++){
        memset(dp,-1,sizeof(dp));
        ans+=DP(len,0,0,1);
    }
    return ans;
}
signed main(){
    int L,R;
    cin>>L>>R;
    cout<<slove(R)-slove(L-1);
    return 0;
}
