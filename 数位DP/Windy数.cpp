/*
�������ǵ�ǰö�ٵ���iλ(�蹲��nλ)���ҵ�iλ�ϵ�����Ϊx����ô���ڴ��е�iλ����j��˵�������ࣺ

1.0~x-1 (�����iλ�����λ��������1~x-1)
�������ᵽ��1~x-1�������� ,������last��¼��һλ�����֣�Ȼ��ö��j�����abs(j-last) >= 2 ���ۼӴ𰸣�res += f[i+1][j];

2.x
����Ҫö��j��last = x,��ö��֮�����λ����

��������֮����������Ĵ𰸶���nλ�ģ�������λ��������n�ģ����ۼӵ����о�����
*/

#include<bits/stdc++.h>

using namespace std;

const int  N  = 11;
int f[N][N];
/*
f(i,j) ���ܹ� i λ �����λΪ j �ĺϷ�������
*/
void init(){
    for(int i=0;i<=9;i++) f[1][i]=1;

    for(int i=2;i<N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                if(abs(j-k)>=2)
                    f[i][j]+=f[i-1][k];
            }
        }
    }
}
int dp(int n){
    if(!n) return 0;

    vector<int> nums;
    while(n) nums.push_back(n%10),n/=10;

    int res=0;
    int last=-10;
    //���� n λ�����
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        for(int j=(i==nums.size()-1);j<x;j++){
            if(abs(j-last)>=2)
            res+=f[i+1][j];
        }
        if(abs(last-x)>=2) last=x;
        else break;

        if(!i) res++;
    }
    //����n-1����� [������ǰ�� 0 �����]
    for(int i=1;i<nums.size();i++){
        for(int j=1;j<=9;j++)
            res+=f[i][j];
    }
    return res;
}
int main(){
    init();

    int l,r;
    cin>>l>>r;
    cout<<dp(r) - dp(l-1)<<endl;
    return 0;
}
/*

// ���仯����

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 15 ;
int a[N];
int dp[N][N][N][N];
int DP(int pos,int pre,int lead,int limit){
    if(!pos) return 1;
    if(!lead&&!limit&&dp[pos][pre][lead][limit]!=-1)
        return dp[pos][pre][lead][limit];
    int high=limit?a[pos]:9;
    int sum=0;
    for(int i=0;i<=high;i++){
        if(abs(pre-i)<2) continue;
        if(lead&&!i) sum+=DP(pos-1,100,1,limit&&(i==high));
        else sum+=DP(pos-1,i,0,limit&&(i==high));
    }
    if(!lead&&!limit)
        dp[pos][pre][lead][limit]=sum;
    return sum;
}
int slove(int n){
    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    return DP(len,100,1,1);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int L,R;
    cin>>L>>R;
    cout<<slove(R)-slove(L-1);
    return 0;
}
*/
