/*
���⣺����һ���ַ������ҳ�����һ������Ӵ���ʹ������Ӵ�����ǰ׺���Ǻ�׺�����м���֡�
˼·:i + z[i] == n iλ��ʼ��ƥ�䵽�� ��׺ ͬʱ ma >= n - i ֮ǰ ���ֹ���С�� �Ĵ�
���ӣ�https://codeforces.com/contest/126/problem/B
*/
#include<bits/stdc++.h>

using namespace std;

#define int long long

const int maxn=1000910;   //�ַ����������ֵ
int nt[maxn],ex[maxn]; //ex���鼴Ϊextend����
///Ԥ�������next����
void GETNEXT(char *str)
{
    int i=0,j,po,len=strlen(str);
    nt[0]=len;///���Լ���Ϊ��׺���Լ�ƥ��
    while(str[i]==str[i+1]&&i+1<len) i++;///������next[1]
    nt[1]=i;

    po=1;///�Ӵ˵����next��������λ����Զ
    for(i=2;i<len;i++)
    {
        if(nt[i-po]< nt[po]+po-i )///��һ�����������ֱ�ӵõ�next[i]��ֵ
        nt[i]=nt[i-po];
        else///�ڶ��������Ҫ����ƥ����ܵõ�next[i]��ֵ
        {
            j=nt[po]+po-i;
            if(j<0)j=0; ///С��0��ʾû����֪��ͬ���֣����¿�ʼƥ��
            while(i+j<len&&str[j]==str[j+i])
            j++;
            nt[i]=j;
            po=i;///����po��λ��
        }
    }
}
///����extend����
//void EXKMP(char *s1,char *s2)
//{
//    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
//    GETNEXT(s2);
//    while(s1[i]==s2[i]&&i<l2&&i<len)
//    i++;
//    ex[0]=i;
//    po=0;
//    for(i=1;i<len;i++)
//    {
//        if(nt[i-po]<ex[po]+po-i)
//        ex[i]=nt[i-po];
//        else
//        {
//            j=ex[po]+po-i;
//            if(j<0)j=0;
//            while(i+j<len&&j<l2&&s1[j+i]==s2[j])
//            j++;
//            ex[i]=j;
//            po=i;
//        }
//    }
//}
char S[maxn],T[maxn];
map<int,int> mp;
signed main(){
    cin>>S;
    GETNEXT(S);
    int Slen=strlen(S);
//    for(int i=0;i<Slen;i++) cout<<nt[i]<<" ";cout<<endl;
    int ans=-1;
    int mx=0;
    for(int i=1;i<Slen;i++){
        if(i+nt[i]==Slen&&(mx>=(Slen-i))){
            ans=max(ans,(Slen-i));
        }
        mx=max(mx,nt[i]);
    }
    if(ans==-1){
        cout<<"Just a legend";
    }else{
        for(int i=0;i<ans;i++) cout<<S[i];
    }
//    for(int i=0;i<Slen;i++) cout<<nt[i]<<" ";cout<<endl;
//    EXKMP(S,T);
//    for(int i=0;i<Slen;i++) cout<<ex[i]<<" ";cout<<endl;
    return 0;
}
/*
qwertyqwertyqwerty

*/
