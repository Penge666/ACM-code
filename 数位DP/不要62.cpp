/*
������ͬ����·����������num��ǰö�ٵ���iλ���ҵ�iλ������x����ô���ڴ𰸵ĵ�iλ��˵��������j�����������

1.0~x-1
������last��ʾnum�е�iλ�ĸ�һλ���֣���ô�������⣬j������4 �� ��last��6��ʱ��j����Ϊ2�������������ö�ٵ�ʱ������һ�¼���
Ȼ���ۼӵ����У�res += f[i+1][j]

2.x
��ô��һλ�Ͳ��ô����ˣ�����һ��last���ɣ�last = x
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 12;

int f[N][10];

void init(){
    for(int i = 0; i<=9; i++) f[1][i] = !(i==4);

    for(int i = 2; i<N; i++)
        for(int j = 0; j<=9; j++){
            if(j == 4) continue;
            for(int k = 0; k<=9; k++){
                if(k == 4 || (j==6 && k==2)) continue;
                f[i][j] += f[i-1][k];
            }
        }

}

int dp(int n){
    if(!n) return 1;  //�������һ�£��������������ܳ�����
    int res = 0, last = 0;  //last��ʾnum��һλ�������Ƕ���

    vector<int> a;
    while(n) a.push_back(n%10),n/=10;

    int len = a.size()-1;
    for(int i = len; i>=0; i--){
        int x = a[i];
        for(int j = 0; j<x; j++){
            if(j == 4 || (last == 6 && j == 2)) continue;
            res += f[i+1][j];
        }
        if(x == 4 || (last == 6 && x == 2)) break;  //����һ�£�����������ֱ��break
        last = x;
        if(!i) res ++;
    }
    return res;
}
int main()
{
    init();
    int l,r;
    while(cin>>l>>r){
        if(l==0 && r==0) break;
        cout<<dp(r)-dp(l-1)<<endl;
    }
    return 0;
}
/*
// ���仯����

#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 66 ;
int a[N];
int dp[N][N][N];
int DP(int pos,int pre,int limit){
    //cout<<pos<<" "<<pre<<" "<<limit<<'\n';
    if(!pos) return 1;
    if(dp[pos][pre][limit]!=-1&&!limit) return dp[pos][pre][limit];
    int high=limit?a[pos]:9;
    int ans=0;
    for(int i=0;i<=high;i++){
        if(i==4||pre==6&&i==2) continue;
        ans+=DP(pos-1,i,limit&&i==high);
    }
    if(!limit) dp[pos][pre][limit]=ans;
    return ans;
}
int slove(int n){

    int len=0;
    while(n){
        a[++len]=n%10;
        n=n/10;
    }
    return DP(len,0,1);
}
signed main(){
    memset(dp,-1,sizeof(dp));
    int L,R;
    while(scanf("%lld%lld",&L,&R)&&(L+R)){
        printf("%lld\n",slove(R)-slove(L-1));
    }
    return 0;
}
/*
99 1000000
*/
*/
