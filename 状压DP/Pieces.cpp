/*
��Ŀ���⣺
��һ���ַ�����ÿ�ο���ɾ��һ���ɲ����������Ӵ���������ɾ���ο���ȫ��ɾ�ꡣ

˼·��
��Ϊ�ַ����������16�����Կ��ö�����״̬��ʾ�� 1��ʾѡȡ����ַ���0��ѡ�����һ���Ӵ���
��Ԥ���������״̬�������״̬�ǲ��ǻ��ġ�
f[i]��ʾ״̬i���ټ��ο���ȫɾ�꣬ ��ʼ��f����INF
f[i] = min{f[i], f[s]+1 } s��i���Ӽ���
*/

#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>

using namespace std;

const int N = 1<<17;
char str[22];
int check[N];
int dp[N],n;//dp[i]:��ʾ����״̬i�������С����
int slove(int state){
    char s[22];
    int len=0;
    for(int i=0;i<n;i++){
        if((1<<i)&state){
            s[len++]=str[i];
        }
    }
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1])
            return 0;
    }
    return 1;
}
signed main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%s",str);
        n=strlen(str);
        int MAX=(1<<n);

        for(int i=0;i<=MAX;i++) dp[i]=n+10;
        check[0]=0;dp[0]=0;
        for(int i=1;i<MAX;i++){
            check[i]=slove(i);
        }
        for(int i=1;i<MAX;i++){
            for(int j=i;j!=0;j=(j-1)&i){
                if(check[j]){
                    dp[i]=min(dp[i],dp[i^j]+1);
                }
            }
        }

        printf("%d\n",dp[MAX-1]);
    }
    return 0;
}
/*
2
aa
*/
