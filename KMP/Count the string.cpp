/*
����:
�����ַ���S, ���S����ǰ׺�ĳ��ִ���֮��

���:
��ϸ����һ��KMP��next����ĺ���, 0 - i �е����ǰ׺��׺ƥ��, ���з���������˵��ĳǰ׺�ɹ�ƥ����һ��.
��������һ������������ͼ�һ�Ļ�, ��������ǰ׺�ĳ��ִ�������.
�ǵü���M, ����M��ǰ׺���ٶ�����һ��

*/
#include <cstdio>
#include <cstring>

using namespace std;
#define int long long
const int MAX_N=1010000;
char str[MAX_N],pattern[MAX_N];
int Next[MAX_N];
void getFail(char *p,int plen){
    int i;
    Next[0]=0;Next[1]=0;
    for(i=1;i<plen;i++){
        int j=Next[i];
        while(j&&p[i]!=p[j])
            j=Next[j];
        Next[i+1]=(p[i]==p[j])?j+1:0;
    }
}

signed main(){
    int T,n;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        scanf("%s",pattern);
        for(int i=0;i<=n;i++) Next[i]=0;
        getFail(pattern,n);
        int ans=n;
        for(int i=n;i>0;i--){
            int k=Next[i];
            while(k>0){
                ans=(ans+1)%10007;
                k=Next[k];
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
