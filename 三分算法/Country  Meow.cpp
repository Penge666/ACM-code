/*
 ��Ŀ��n����ά�����꣨x��y��z��������ϣ������һ���㣬ʹ������㵽����n�������������С��Ȼ����������롣

 ����������������д��   ���Ӷ�O(n*log^3)

�ֱ�����X,Y,Z��������Сֵ��ֱ���װ��ӡ�


*/
#include<bits/stdc++.h>

using namespace std;
#define N 666
int n;
double ans;
double res1,res2,res3;
struct str{
    int x,y,z;
}st[N];
double slove(double X,double Y,double Z){
    double sum=0;
    for(int i=1;i<=n;i++){
        double temp=(X-st[i].x)*(X-st[i].x)+(Y-st[i].y)*(Y-st[i].y)+(Z-st[i].z)*(Z-st[i].z);
        if(temp>sum) sum=temp;
    }
    if(sum<ans) ans=sum;

    return sum;
}
double check2(double X,double Y){

    double l=-1e6,r=1e6;
    double res=0;
    for(int i=1;i<=100;i++){
        double  mid=(l+r)/2;
        double  mmid=(mid+r)/2;
        double t1=slove(X,Y,mid);
        double t2=slove(X,Y,mmid);
        if(t1>=t2){
            l=mid;

        }else{
            r=mmid;res=mmid;
        }
    }
    return slove(X,Y,res);
}
double check1(double X){
    double res=0;
    double l=-1e6,r=1e6;
    for(int i=1;i<=100;i++){
        double  mid=(l+r)/2;
        double  mmid=(mid+r)/2;
        double t1=check2(X,mid);
        double t2=check2(X,mmid);

        if(t1>=t2){
            l=mid;
        }else{
            r=mmid;    res=mmid;
        }
    }
    return check2(X,res);
}
signed main(){
    cin>>n;
    ans=1e18;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&st[i].x,&st[i].y,&st[i].z);
    }
    double l=-1e6,r=1e6;
    for(int i=1;i<=100;i++){
        double  mid=(l+r)/2;
        double  mmid=(mid+r)/2;
        double t1=check1(mid);
        double t2=check1(mmid);
        if(t1>=t2){
            l=mid;
        }else{
            r=mmid;
        }
    }
    printf("%.9lf",sqrt(ans));
    return 0;
}
/*
3
0 0 0
3 0 0
0 4 0

4
0 0 0
1 0 0
0 1 0
0 0 1

*/
