/*
题意概括  :
给出一个字符串，求在其尾部需要加几个字符使其构成循环节

解题思路  :
首先，求出所给字符串的next数组，然后判断字符串数组长度与next数组最后一个值的差值与n的关系：是否等于n以及是否为n的约数，如果不是则所需加字符数量为零，如果是所加字符数量为差值减去n与差值的余数。


*/
/*
pku3461(Oulipo), hdu1711(Number Sequence)
这个模板 字符串是从0开始的
Next数组是从1开始的


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
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
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
返回模式串在主串S中出现的次数
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
