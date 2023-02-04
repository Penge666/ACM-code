/*
������λDP�������裺 �������ǵ�ǰö�ٵ���iλ���ҵ�iλ�ϵ�������x����ô���ڶ��ڴ𰸵ĵ�iλ����j��˵���������������֣�

1.jȡ0~x-1
��ôres += f[i+1][j];

2.jȡx
last��¼x����ö����һλ

f����
f[i][j] ��ʾһ����iλ�������λ����Ϊj�Ĳ������ĸ���
״̬ת�ƣ� ��Ϊ���λ�Ѿ��̶������Լ����i-1λ��k�����ݲ���������k>=j,����
*/
#include<bits/stdc++.h>

using namespace std;

const int N=15;

int f[N][N];
/*
�ܹ� i λ�����λΪ j �ĺϷ�������

*/
void init(){
    for(int i=0;i<10;i++) f[1][i]=1;

    for(int i=2;i<N;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++)
                f[i][j]+=f[i-1][k];
        }
    }
}

int dp(int n){
    if(!n) return 1;

    vector<int> nums;
    while(n) nums.push_back(n%10),n/=10;

    int res=0;
    int last=0;//����ǰһλ��ֵ
    for(int i=nums.size()-1;i>=0;i--){
        int x=nums[i];
        for(int j=last;j<x;j++) res+=f[i+1][j];
        if(x<last) break;
        last=x;
        if(!i) res++;
    }
    return res;
}
int main(){
    init();

    int l,r;
    while( cin >> l >> r ){
        cout << dp(r) - dp(l-1) << endl;
    }
    return 0;
}
