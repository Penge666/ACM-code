#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = ( 1<<10 ) + 20;
vector<int> state;//state���úϷ�״̬
vector<int> head[N];//head[a]��ʾa��Ӧ�ķ��ü���״̬����ת�Ƶ��ļ���״̬��
int n,k;
int dp[12][120][N];
int cnt[N];//����1������
int check(int x){ // �����û�г������ڵ�����1
    for(int i=0;i<n;i++){
        if((x>>i&1)&&(x>>i+1&1))
            return 0;
    }
    return 1;
}
int count(int x){//����1������
    int sum=0;
    while(x){
        sum+=x%2;
        x/=2;
    }
    return sum;
}
signed main(){
    cin>>n>>k;
    for(int i=0;i<(1<<n);i++){
        if(check(i)){
            state.push_back(i);
            cnt[i]=count(i);
        }
    }
    for(int i=0;i<state.size();i++){
        for(int j=0;j<state.size();j++){
            int a=state[i],b=state[j];
            if((a&b)==0&&check(a|b)){
                head[i].push_back(j);
            }
        }
    }
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            for(int a=0;a<state.size();a++){
                for(int b=0;b<head[a].size();b++){
                    int c=cnt[state[a]];
                    if(j>=c){
                        dp[i][j][a]+=dp[i-1][j-c][head[a][b]];
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<state.size();i++) ans=ans+=dp[n][k][i];
    cout<<ans;
    return 0;
}
