#include<bits/stdc++.h>
using namespace std;
#define N 666666
#define eps 1e-9
double arr[N];
int n;
double  check(double num){
    double sum=0;
    for(int i=n;i>=0;i--)
        sum+=arr[i]*pow(num,i);
    return sum;
}
void slove(){
    scanf("%d",&n);
    double l,r;
    scanf("%lf%lf",&l,&r);
    for(int i=n;i>=0;i--){
        scanf("%lf",&arr[i]);
    }
    while(l+1e-6<r){
        double lmid=l+(r-l)/3.0;
        double rmid=r-(r-l)/3.0;
        double t1=check(lmid);
        double t2=check(rmid);
        if(t1<t2){
            l=lmid;
        }else{
            r=rmid;
        }
    }
    printf("%.5lf",l);
    return ;
}
signed main(){
    slove();
    return 0;
}
