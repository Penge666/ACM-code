/*
 一篇生动形象的漫画：

https://mp.weixin.qq.com/s__biz=MzIzMTE1ODkyNQ==&mid=2649410225&idx=1&sn=ed045e8edc3c49a436a328e5f0f37a55&chksm=f0b60f53c7c18645b4c04a69ad314723cce94ed56994d6f963c2275a2db8d85f973f15f508e4&mpshare=1&scene=23&srcid=1001JCsBlpxgUWjgixasChNQ#rd
不错的博客:

https://www.cnblogs.com/five20/p/8610733.html

*/
#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N=36666666;
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
        ans=max(ans,p[i]-1);
    }
    return ans;
}
signed main(){
    scanf("%s",str);
    int ans=manacher();
    cout<<ans<<'\n';
    return 0;
}
