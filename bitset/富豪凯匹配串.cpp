/*
��⣺
�����������ƴ�a,tag,q����ѯ�ʵĵ�iλΪ��_��,��q[i]=0,tag[i]=0������iλΪ0,��q[i]=1,tag[i]=0������iλΪ1����q[i]=1,tag[i]=1������һ��ȷ�����ı���������iλΪ0,a[i]=0,����a[i]=1������ÿһλ����a[i]&q[i]==tag[i]����ѯ�ʵĴ�������ı���ƥ�䡣Ȼ��bitset�Ż�һ�£���λѹ����long long��


*/
#include<bits/stdc++.h>
using namespace std;

#define N 1005

bitset<N> s,t,res[N];
char str[N],ss[N];
signed main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        for(int j=0;j<m;j++){
            res[i][j]=str[j]-'0';
        }
    }
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",ss);
        for(int i=0;i<m;i++){
            if(ss[i]=='_'){
                s[i]=0;
                t[i]=0;
            }else{

                if(ss[i]=='1'){
                    s[i]=1;
                    t[i]=1;
                }else{
                    s[i]=1;
                    t[i]=0;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if((res[i]&s)==t) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
