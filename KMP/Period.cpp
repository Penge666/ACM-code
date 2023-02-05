/*
kmp�Ļ��ص㿼���next�������⣬next[i]��ָ�ع�����һ��ƥ���λ�ã����Է���ÿ�λع��ĳ��ȶ��� j-next[j] �����Ե���ѭ����
��n%(n?next[n])==0 && next[n] != 0����ʱ��n-next[n]������С��ѭ���ڳ��ȣ�ѭ���������� n / ( n - next[n] ) 
 Period POJ - 1961 ��KMP��Next������һ���ַ�������Сѭ���ڡ�
 */

/*
 ����ĵ�һ��KMP���⡣�ٺٺ�

KMP��Next���������һ���ַ�������Сѭ���ڣ�������еĻ���
ѭ���ڳ��� x=len-Next[len]��
����ababab��xΪ2
abbcabbcabbc��xΪ3
���������abba�Ļ�xΪ3�������Ҫ������ַ�������Сѭ���ڳ����ټ�һ���ж��������ɣ�
�����len%x!=0�Ļ�x=len��
��abba,xӦ��Ϊlen����Ϊ4.
��abbabba��xӦ��Ϊ7��abbabbab,xΪ8��abbabbabb��xΪ3����Ϊ�����������ˡ�

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
    int T=1,n;
    while(~scanf("%lld",&n)&&n){

        scanf("%s",pattern);
        for(int i=0;i<=n;i++) Next[i]=0;
        getFail(pattern,n);
        printf("Test case #%lld\n",T++);
        for(int i=0;i<n;i++){
            int len=i+1;
            if(len%(len-Next[i+1])==0&&(len-Next[i+1])!=len){
                printf("%lld %lld\n",len,len/(len-Next[i+1]));
            }
        }
         puts("");
    }
    return 0;
}
