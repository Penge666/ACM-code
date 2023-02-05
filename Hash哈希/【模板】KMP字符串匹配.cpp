// 可恶的NEXT数组。太牵强了。
//
//感觉Hash求解KMP比较容易理解
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ull unsigned long long
using namespace std;
const int MAXN=2e7+10;
const int mod=19260817;
const int seed=233;
ull po[MAXN];
ull hash(ull *a,int l,int r)
{
    if(l-1<0)    return a[r];
    return a[r]-po[r-l+1]*a[l-1];
}
char s1[MAXN],s2[MAXN];
ull h1[MAXN],h2;
int l1,l2;
int nxt[MAXN];
int main()
{
    po[0]=1;
    for(int i=1;i<=10001;i++)    po[i]=po[i-1]*seed;
    scanf("%s",s1);scanf("%s",s2);
    l1=strlen(s1);l2=strlen(s2);
    for(int i=0;i<l1;i++)    h1[i]=h1[i-1]*seed+s1[i];
    for(int i=0;i<l2;i++)    h2=h2*seed+s2[i];
    for(int i=0;i<l1;i++)
        if(hash(h1,i,i+l2-1)==h2)
            printf("%d\n",i+1);

    int j=0;
    for(int i=1;i<l2;i++)
    {
        while(j>0&&s2[i]!=s2[j])    j=nxt[j-1];
        if(s2[i]==s2[j])    j++;
        nxt[i]=j;
    }//题目中说要输出nxt数组
    for(int i=0;i<l2;i++)    printf("%d ",nxt[i]);
    return 0;
}
