/*
����
����һЩ��Ŀ�ļ�ֵ����a��b����������ļ�ֵΪt��a+b��t�Ǵ����Ŀ���������������ڴ�
������⣩��ÿ���ⲻ��˵����ܴ�Ļ����������������������Ŀ�����������е�������ļ�
ֵ��
��⣺ö�����п��ܵ�״̬,������ѡ��һ����Ʒ�����Ƿ������Ʒ��Ҫ��״̬�ǵ�ǰö��״̬
ȥ�������Ʒ״̬���Ӽ�,����,����Խ���ת�ơ�
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 21 , M = 1<<21 , inf = 99999999999;
int n,a[N],b[N],tmp[N];
int dp[M];//dp[state]:��״̬Ϊstate[����state״̬�Ϸ�]������ֵ
int count(int state){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(state>>i)&1;
    }
    return sum;
}
signed main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a[i],&b[i]);
        int num=0;
        scanf("%lld",&num);
        for(int j=0;j<num;j++){
            int k;
            scanf("%lld",&k);
            tmp[i]=tmp[i]|(1<<(k-1));
        }
    }
    for(int i=0;i<M;i++) dp[i]=-inf;
    dp[0]=0;
    for(int i=0;i<(1<<n);i++){
        int cnt=count(i)+1;
        for(int j=0;j<n;j++){
            if((1<<j)&i) continue;
            if((tmp[j]&i)!=tmp[j]) continue;
            dp[i|(1<<j)]=max(dp[i|(1<<j)],dp[i]+cnt*a[j]+b[j]);
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++) ans=max(ans,dp[i]);

    printf("%lld",ans);
    return 0;
}
