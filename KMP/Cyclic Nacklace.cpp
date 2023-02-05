/*
�������  :
����һ���ַ�����������β����Ҫ�Ӽ����ַ�ʹ�乹��ѭ����

����˼·  :
���ȣ���������ַ�����next���飬Ȼ���ж��ַ������鳤����next�������һ��ֵ�Ĳ�ֵ��n�Ĺ�ϵ���Ƿ����n�Լ��Ƿ�Ϊn��Լ�������������������ַ�����Ϊ�㣬����������ַ�����Ϊ��ֵ��ȥn���ֵ��������


*/
/*
pku3461(Oulipo), hdu1711(Number Sequence)
���ģ�� �ַ����Ǵ�0��ʼ��
Next�����Ǵ�1��ʼ��


*/
#include <iostream>
#include <cstring>
using namespace std;
#define int long long
const int N = 1000002;
int Next[N];
char S[N], T[N];
int slen, tlen;

void getNext()
{
    int j, k;
    j = 0; k = -1; Next[0] = -1;
    while(j < tlen)
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else
            k = Next[k];

}
/*
����ģʽ��T������S���״γ��ֵ�λ��
���ص�λ���Ǵ�0��ʼ�ġ�
*/
int KMP_Index()
{
    int i = 0, j = 0;
    getNext();

    while(i < slen && j < tlen)
    {
        if(j == -1 || S[i] == T[j])
        {
            i++; j++;
        }
        else
            j = Next[j];
    }
    if(j == tlen)
        return i - tlen;
    else
        return -1;
}
/*
����ģʽ��������S�г��ֵĴ���
*/
int KMP_Count()
{
    int ans = 0;
    int i, j = 0;

    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext();
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = j+1;
        }
    }
    return ans;
}
signed main()
{

    int TT;
    int  cc;
    cin>>TT;
    while(TT--){
      scanf("%s",T);
      tlen=strlen(T);
      if(tlen==1){
          printf("1\n");
          continue;
      }
      getNext();
      //cout<<Next[tlen]<<'\n';
      int Len=tlen-Next[tlen];
      if(Len!=tlen&&tlen%Len==0){
          printf("0\n");
      }else{
          printf("%lld\n",Len-tlen%Len);
      }

    }
    return 0;
}
/*
test case
4
aaaaaa a
abcd d
aabaa b
*/
