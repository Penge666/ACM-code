/*
dp[i][j]����ʾ�����ߵ��� i�����ң����߹��Ķ�����״̬Ϊ j ʱ����̵ľ��롣
������������ѭ�����ֱ�ö�����п��ܵĶ�����״̬����ǰ�����ڵ�λ�ú����ڵ�ǰ״̬�µ���
��ǰ���λ�á�

�ڵڶ���ѭ����Ҫ�ж�һ�� i �ڵ�ǰ������״̬���Ƿ����߹����������û�߹�����Ҫ����
�������ļ��㣬ֱ��continue�Ϳ��ԡ�

�ڵ�����������ͬ��Ҫ�жϵ�ǰ���Ƿ����߹����ҵ�ǰ�㲻�� i ����ͬ��
*/
#include<bits/stdc++.h>

using namespace std;

const int N =  66666 , mod = 1e8 , inf = 0x3f3f3f3f;
double dp[20][1<<16];//dp[i][j]:��ǰ��iλ��,���Ѿ��߹�j״̬����С����
double x[N],y[N];
double dis[666][666];
double F(int v,int w){//�����v���͵�w������֮��ľ���
  return sqrt((x[v]-x[w])*(x[v]-x[w])+(y[v]-y[w])*(y[v]-y[w]));//�������빫ʽ
}
signed main(){
    memset(dp,127,sizeof(dp));
    int n;
    cin>>n;
    x[0]=0.0,y[0]=0.0;
    for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=F(i,j);
        }
    }
    for(int i=1;i<=n;i++) dp[i][(1<<(i-1))]=dis[i][0];
    for(int k=1;k<(1<<n);k++){
        for(int i=1;i<=n;i++){
            if(((1<<(i-1))&k)==0) continue;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if((k&(1<<(j-1)))==0) continue;
                dp[i][k]=min(dp[i][k],dp[j][k-(1<<(i-1))]+dis[i][j]);
            }
        }
    }
    double ans=dp[1][(1<<n)-1];
    for(int i=1;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
    printf("%.2lf\n",ans);
    return 0;
}
/*
//ò���������DP����������
#include<bits/stdc++.h>

using namespace std;

const int N =  66666 , mod = 1e8 , inf = 0x3f3f3f3f;
double dp[20][1<<16];//dp[i][j]:��ǰ��iλ��,���Ѿ��߹�j״̬����С����
double x[N],y[N];
double dis[666][666];
double F(int v,int w){//�����v���͵�w������֮��ľ���
  return sqrt((x[v]-x[w])*(x[v]-x[w])+(y[v]-y[w])*(y[v]-y[w]));//�������빫ʽ
}
signed main(){
    memset(dp,127,sizeof(dp));
    int n;
    cin>>n;
    x[0]=0.0,y[0]=0.0;
    for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dis[i][j]=F(i,j);
        }
    }
    for(int i=1;i<=n;i++) dp[i][(1<<(i-1))]=dis[i][0];
    for(int k=1;k<(1<<n);k++){
        for(int i=1;i<=n;i++){
            //if(((1<<(i-1))&k)==0) continue;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                //if((k&(1<<(j-1)))==0) continue;
            //    dp[i][k]=min(dp[i][k],dp[j][k-(1<<(i-1))]+dis[i][j]);
                dp[j][k|(1<<(j-1))]=min(dp[i][k]+dis[i][j],dp[j][k|(1<<(j-1))]);
            }

        }
    }
    double ans=dp[1][(1<<n)-1];
    for(int i=1;i<=n;i++) ans=min(ans,dp[i][(1<<n)-1]);
    printf("%.2lf\n",ans);
    return 0;
}

*/
