/*
���⣺����Ҷ���������ַ�ʹ���ֻ��Ĵ�������Ĵ��ĳ�����Сֵ�� 

˼·�����ȣ����������������ַ���ƴ������һ���ǻ��Ĵ������ǣ���Ŀ�������С���Ĵ������ԣ�����Ҫ��Ĵ𰸾���2*len-res(res:�������һ���ַ��Ļ��Ĵ������һ��)


*/
#include<bits/stdc++.h>

using namespace std;
const int N=3666666;
char s[N],str[N];
int p[N];
int slove(){
    int len=strlen(str);
    s[0]='$',s[1]='#';
    int j=2;
    for(int i=0;i<len;i++){
        s[j++]=str[i];
        s[j++]='#';
    }
    s[j++]='\0';
    return j;
}
int manacher(){
    int len=slove();
    int ans=-N;
    int id=0,mx=0;
    for(int i=1;i<len;i++){
        if(i<mx) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        while(s[i+p[i]]==s[i-p[i]]) p[i]++;
        if(mx<i+p[i]) mx=i+p[i],id=i;
        if((i+p[i])>=len-1){//�������һ���ַ��Ļ��Ĵ������һ��
            ans=max(p[i],ans);
        }
    }
   //cout<<ans<<'\n';
    return ans-1;
}
signed main(){
    int cnt=1;
    int T;
    cin>>T;
    while(T--){
        memset(str,'\0',sizeof(str));
        memset(p,0,sizeof(p));
        memset(s,'\0',sizeof(s));
        scanf("%s",str);
        int len=strlen(str);
        int ans=manacher();
        int res=len*2-ans;
        printf("Case %d: %d\n",cnt++,res);
    }

    return 0;
}
