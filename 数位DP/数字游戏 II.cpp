/*
�ڼ�����λDp��Ŀ��ϰ����������Ŀ�ص������ҵ������һ�����ֱ�Ӽ���
������һ����˵���������ǵ�ǰö�ٵ��ĵ�iλ���ҵ�iλ�ϵ�������x����ô���ڴ��еĵ�iλ����j��˵����������������

1.0~x-1
������last��ʾ����ǰΪֹ��ǰ����λ�ϵ�����֮�ͣ��Դˣ���ǰ��iλ����Ϊj��ǰ������֮��Ϊlast����ô
��iλ(����j��һλ)����֮��sum��last�Ĺ�ϵ����(last+sum)%N == 0,��ôsum%N�Ľ���ȼ���(-last)%N,
����res += f[i+1][j][(-last%N)]; (������ᵽf����Ĵ���)
2.x
���j��x����ô����ö���ˣ�last += x����ö����һλ����
*/
#include<bits/stdc++.h>

using namespace std;

const int N = 11, M = 110;

int P;
int f[N][N][M];
/*
f(i,j,k):�ܹ� i λ�����λΪ j ���������ּӺ�mod P ==k �ķ�����
*/
int mod(int x,int y){
    return (x%y+y)%y;
}
void init(){
    memset(f,0,sizeof(f));
    for(int i=0;i<=9;i++) f[1][i][i%P]=1;
    for(int i=2;i<N;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<P;k++){
                for(int x=0;x<=9;x++)
                    f[i][j][k]+=f[i-1][x][mod(k-j,P)];
            }
        }
    }
    return ;
}
int dp(int n){
    if(!n) return 1;

    vector<int> nums;
    while(n) nums.push_back(n%10),n/=10;

    int res=0;
    int last=0;

    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        for(int j=0;j<x;j++){
            res+=f[i+1][j][mod(-last,P)];
        }
        last+=x;
        if(!i&&last%P==0) res++;
    }
    return res;
}
signed main(){
    int l,r;
    while(cin>>l>>r>>P){
        init();
        cout<<dp(r) - dp(l-1)<<'\n';
    }
    return 0;
}
