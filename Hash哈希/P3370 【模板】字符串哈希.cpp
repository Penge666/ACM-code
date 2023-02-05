#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
ull base = 131;
ull a[10010];
char s[10010];
int n,ans=1;
ull hash(char s[]){
    int len = strlen(s);
    ull ans=0;
    for(int i=0;i<len;i++){
        ans=ans*base+(ull)s[i];
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        a[i]=hash(s);
    }
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    cout<<s.size()<<endl;
    return 0;
}
