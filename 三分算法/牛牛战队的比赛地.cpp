#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int a[N],b[N];
int n;
double check(double pos){
    double sum=0;
    for(int i=1;i<=n;i++){
        double temp=(a[i]-pos)*(a[i]-pos)+(b[i]*b[i]);
        sum=max(sum,temp);
    }
    return sum;
}
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    double l=-10000.0;
    double r=10000.0;
    while(l+1e-9<r){
        double l_mid=l+(r-l)/3.0;
        double r_mid=r-(r-l)/3.0;
        if(check(l_mid)<check(r_mid)){
            r=r_mid;
        }else{
            l=l_mid;
        }
    }
    printf("%.4lf\n",sqrt(check(l)*1.0));
    return ;
}
signed main(){
    slove();
    return 0;
}
