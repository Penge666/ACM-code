#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
const double g=9.80665;
const double pi2=1.570796327;
double H,v;
double f(double th)
{
    return (v*sin(th)+sqrt(v*v*sin(th)*sin(th)+2*g*H))*v*cos(th)/g;
}
void slove()
{
    double l=0,r=pi2;
    while(r-l>=eps)
    {
        double mid1=l+(r-l)/3.0;
        double mid2=r-(r-l)/3.0;
        if(f(mid1)<=f(mid2))
            l=mid1;
        else
            r=mid2;
    }
    printf("%.5lf\n",f(l));
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&H,&v);
        slove();
    }
    return 0;
}
