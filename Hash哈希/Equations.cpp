// +-两种情况

#include<bits/stdc++.h>

using namespace std;
#define N 666666
map<int,int> f1,f2;
signed main(){
    int a,b,c,d;
    while(~scanf("%d%d%d%d",&a,&b,&c,&d)){
        if((a>0&&b>0&&c>0&&d>0)||(a<0&&b<0&&c<0&&d<0)){
            printf("0\n");
            continue;
        }
    //    cout<<"==0"<<'\n';
        f1.clear();
        f2.clear();
        int s=0;
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                int t=a*i*i+b*j*j;
                if(t>0) f1[t]++;
                else if(t<0)   f2[abs(t)]++;
                else if(t==0) s++;
            }
        }
        int ans=0;
        for(int i=1;i<=100;i++){
            for(int j=1;j<=100;j++){
                int tt=c*i*i+d*j*j;
                if(tt>0){
                    ans+=f2[tt];
                }else if(tt<0){
                    ans+=f1[abs(tt)];
                }else{
                    ans+=s;
                }
            }
        }
        printf("%d\n",ans*16);
    }
    return 0;
}
