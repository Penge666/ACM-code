/*
ת�Ʒ���Ϊ��dp[S|(1<<(j-1))][(k*10+a[j])%d]+=dp[S][k]��������д�Ǵ���ģ���Ϊ
û�п����ظ������У����˸���ʱ����b[i]b[i]����ʾ��ǰҪ�������i��û�б�����������Ϳ�
�Ա���һ��λ�÷���ͬԪ�ص������
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 11 , M = 1<<11 ;
int dp[M][1009];//dp[s,i]����״̬s������Ϊi�ķ�����
map<int,int> vis;
int a[N];
signed main(){
    int T;
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        string s;int d;
        cin>>s>>d;
        int n=s.size();
        for(int i=0;i<n;i++) a[i]=(int)(s[i]-'0');
        //for(int i=0;i<n;i++) cout<<a[i]<<" ";
        dp[0][0]=1;
        for(int s=0;s<(1<<n);s++){
            vis.clear();
            for(int i=0;i<n;i++){
                if(!((1<<i)&s)){
                    if(!vis[a[i]]){
                        vis[a[i]]=1;
                        for(int j=0;j<d;j++){
                            dp[s|(1<<i)][(10*j+a[i])%d]+=dp[s][j];
                        }
                    }
                }
            }
        }
        cout<<dp[(1<<n)-1][0]<<'\n';
    }
    return 0;
}
