//�������ڵ�˼�� 
/*
����: 
10011
1001
 0011
�����ȼ���ǰM���ַ�����s0==s1��������������ͨ���������?��ֵ�����ǽ��д����ж�
ͨ��forѭ���жϻ�����������Ƿ���ϣ���β��������ų���������ζ��ֻҪ��ǰM���ַ�����
S0==s1����������������ַ���������������ʱ��ǰM���ַ������жϼ��� 

*/
//�������ڵ�˼��
/*
����:
10011
1001
 0011
�����ȼ���ǰM���ַ�����s0==s1��������������ͨ���������?��ֵ�����ǽ��д����ж�
ͨ��forѭ���жϻ�����������Ƿ���ϣ���β��������ų���������ζ��ֻҪ��ǰM���ַ�����
S0==s1����������������ַ���������������ʱ��ǰM���ַ������жϼ���

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
