#include<bits/stdc++.h>

using namespace std;
#define int long long

const int N = 15;
int a[N],j;
int dp[N][2][2][20];
int DP(int pos,int sta,int limit,int count){
    if(!pos){return count;}
    if(!limit&&!sta&&dp[pos][sta][limit][count]!=-1)
        return dp[pos][sta][limit][count];
    int ans=0;
    int high=limit?a[pos]:9;
    for(int i=0;i<=high;i++){
        ans+=DP(pos-1,(!i)&&sta,limit&&(i==high),count+(i>0||sta==0)*(i==j));
    }
    if(!limit&&!sta)  dp[pos][sta][limit][count]=ans;
    return ans;
}
int slove(int n){
    memset(dp,-1,sizeof(dp));
    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    return DP(len,1,1,0);
}
signed main(){
    int L,R;
    cin>>L>>R;
    for(j=0;j<=9;j++){

        cout<<slove(R)-slove(L-1)<<" ";
    }
    return 0;
}

/*
//2021.11.24����

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 666 ;
int dp[N][2][2][20];
int a[N];
int p;
class Solution {
public:
    //sta:��ʾǰ��0  1:��ʾ��ǰ��0  0:��ʾû��ǰ��0
    //limit:��ʾ��ǰλ���Ƿ񵽴���λ���Ͻ�
    //count:�����������������10^count�� (countָ����ָ���ϵ���)
    int DP(int pos,int sta,int limit,int count){
        if(!pos) return count;
        if(!limit&&sta&&dp[pos][sta][limit][count]!=-1)
            return dp[pos][sta][limit][count];
        int high=limit?a[pos]:9;
        int tot=0;
        for(int i=0;i<=high;i++){
            tot+=DP(pos-1,i||sta,limit&&(i==high),count+(sta||i)*(i==p));
        }
        if(!limit&&sta)
            dp[pos][sta][limit][count]=tot;
        return tot;
    }
    int Count(int n) {
        memset(dp,-1,sizeof(dp));
           int len=0;
        int m=n;
        while(m){
            a[++len]=m%10,m/=10;
        }
        return DP(len,0,1,0);
    }
}S;
signed main(){
    int L,R;
    cin>>L>>R;
    for(int i=0;i<=9;i++){
        p=i;
        cout<<S.Count(R)-S.Count(L-1)<<" ";
    }
    return 0;
}
*/
