//滑动窗口的思想 
/*
滑窗: 
10011
1001
 0011
首先先假设前M个字符满足s0==s1的条件，紧接着通过滑窗求出?的值或者是进行错误判断
通过for循环判断滑窗后的数组是否符合，如何不符合则排除。否则，意味着只要是前M个字符满足
S0==s1的条件话，后面的字符都满足条件。此时对前M个字符进行判断即可 

*/
//滑动窗口的思想
/*
滑窗:
10011
1001
 0011
首先先假设前M个字符满足s0==s1的条件，紧接着通过滑窗求出?的值或者是进行错误判断
通过for循环判断滑窗后的数组是否符合，如何不符合则排除。否则，意味着只要是前M个字符满足
S0==s1的条件话，后面的字符都满足条件。此时对前M个字符进行判断即可

*/
#include<bits/stdc++.h>

using namespace std;

#define int long long
const int N = 666666 ;
char s[N];
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n,m,F=1;
        cin>>n>>m>>(s+1);
        int s0=0,s1=0;
        for(int i=1;i<=m;i++) if(s[i]=='0') s0++;else if(s[i]=='1') s1++;
        if(s0>m/2||s1>m/2) F=0;
        for(int i=m+1;i<=n;i++){
            if(s[i-m]=='0') s0--;
            else if(s[i-m]=='1') s1--;
            if(s[i]=='0') s0++;
            else if(s[i]=='1') s1++;
            if(s0>m/2||s1>m/2) F=0;
        }
        for(int i=m+1;i<=n;i++){
            if(s[i]!=s[i-m]){
                if(s[i-m]=='?') continue;
                else if(s[i-m]!='?'&&s[i]=='?') s[i]=s[i-m];
                else F=0;
            }
        }
        s0=0,s1=0;
        for(int i=1;i<=m;i++) if(s[i]=='0') s0++;else if(s[i]=='1') s1++;
        if(s0>m/2||s1>m/2) F=0;
        for(int i=m+1;i<=n;i++){
            if(s[i-m]=='0') s0--;
            else if(s[i-m]=='1') s1--;
            if(s[i]=='0') s0++;
            else if(s[i]=='1') s1++;
            if(s0>m/2||s1>m/2) F=0;
        }
        int a=0,b=0,c=0;
        for(int i=1;i<=m;i++){
            if(s[i]=='1') a++;
            else if(s[i]=='0') b++;
            else c++;
        }
        if(a>m/2||b>m/2||!F) cout<<"NO";else cout<<"YES";
        cout<<'\n';
    }
    return 0;
}
/*


*/
