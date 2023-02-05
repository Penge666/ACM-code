/*
�������ͬ���ǻ��ģ���������Ҫ����������Ӵ����е������߷��ϸ�ݼ���ͬ����Ԥ�����ʱ����Ҫ�ò���Ӱ����Ŀ�����֣�������0�ȵȣ�������µĶ��С�
��չ�����Ӵ�ʱ��Ҫ��һ�� s[i-p[i]]<=s[i-p[i]+2] ���������ƴ��е������߷��ϸ�ݼ�������Ϊʲô+2����Ϊ���ڵ�����Ԥ����ʱ��ӵĸ�����0������Ӱ��ԭ���Ļ����ж���

*/
#include<bits/stdc++.h>

using namespace std;
const int N=100000+100;
int a[N],b[N];
int p[N];
int n;
int init(){
    b[0]=-1,b[1]=0;
    int j=2;
    for(int i=0;i<n;i++){
        b[j++]=a[i];
        b[j++]=0;
    }
    b[j++]=1;
    return j;
}
int manacher(){
    int len=init();
    int id=0,mx=0;
    int ans=0;
    for(int i=1;i<len;i++){
        if(i<mx){
            p[i]=min(p[2*id-i],mx-i);
        }else{
            p[i]=1;
        }
        while(b[i+p[i]]==b[i-p[i]]&&b[i+p[i]]<=b[i+p[i]-2]) ++p[i];
        if((i+p[i])>mx) mx=i+p[i],id=i;
        ans=max(ans,p[i]-1);
    }
    return ans;
}
signed main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int ans=manacher();
        printf("%d\n",ans);
    }
    return 0;
}
