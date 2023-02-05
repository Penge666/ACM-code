 /*�����Ͼ����⡣

��Ŀ���⣺����һ��������ķ��̣����������ϵĵ���ԭ��������Сֵ

 ��Ŀ��������Ϊ�漰��������Сֵ�����ǿ��Կ������֣�����Ϊÿһ���㶼����ά��(x,y,z)������z����ͨ��x��y�ļ���ó����������ǿ��������������֣�һ������x��һ������y��ÿ�αƽ��𰸼���.

�����ĿҲ�ǹ���ѧ�ģ������������ֵĴ����inf���̫С�ܲ����𰸣�inf���̫��Ҳ�ܲ����𰸣��赽1e4���.

*/
#include<bits/stdc++.h>

using namespace std;
const double inf=1e4;
const double eps=1e-8;
double a,b,c,d,e,f;
double ans;
double dis(double x,double y,double z){
    return sqrt(x*x+y*y+z*z);
}
double cal(double x,double y)//ȷ��x��y�󷵻ص�z
{
    double A=c;
    double B=d*y+e*x;
    double C=a*x*x+b*y*y+f*x*y-1;
    double delta=B*B-4*A*C;
    if(delta<0)
        return inf;
    double z1=(-B+sqrt(delta))/A/2;
    double z2=(-B-sqrt(delta))/A/2;
    if(z1*z1<z2*z2){
        return z1;
    }else{
        return z2;
    }
   /*double t1=dis(x,y,z1);
    double t2=dis(x,y,z2);
    ans=min(ans,min(t1,t2));
    return min(t1,t2);*/
}
double check1(double X){
    double l=-inf,r=inf;
    double res;
    while(fabs(l-r)>eps){
        double mid=(l+r)/2;
        double mmid=(mid+r)/2;
        double t1=dis(X,mid,cal(X,mid));
        double t2=dis(X,mmid,cal(X,mmid));
        ans=min(ans,min(t1,t2));
        if(t1<t2){
            r=mmid;res=mid;
        }else{
            l=mid;res=mmid;
        }
    }
    return dis(X,res,cal(X,res));
}
void slove(){
    double l=-inf,r=inf;
    while(fabs(l-r)>eps){
        double mid=(l+r)/2;
        double mmid=(mid+r)/2;
        double t1=check1(mid);
        double t2=check1(mmid);
        if(t1<t2){
            r=mmid;
        }else{
            l=mid;
        }
    }
}
signed main(){
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)!=EOF)
    {
        ans=1e16;
        slove();
        printf("%.8f\n",ans);
    }
    return 0;
}
