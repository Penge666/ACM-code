/*
���⣺��һ��û���α����ƽ����n�����ȣ�m��ѯ�ʣ� ÿ��һ��k���ʿɷ�ӳ�k��������� ���ȿ��Է����ߡ�

˼·�����ǿ��Զ�����ö��ÿһ���Ӽ�����Ҫע��һ����ǣ��������������������ȣ�2��8�����ǲ�����¼2��8��2+8����Ҫ��¼8-2�������������ÿ������һ�飬 ��ȥÿ����������Ǽ��ɡ�


*/
#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define N 2666
int arr[N];
int vis[N];
signed main(){
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<=2000;i++) vis[i]=0;
        int n;
        scanf("%d",&n);

        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    //    sort(arr+1,arr+1+n);
        for(int i=0;i<(1<<n);i++){
            int s=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    s+=arr[j];
                }
            }
            vis[s]=1;
            for(int j=0;j<n;j++){
                if(s-arr[j]>=0) vis[s-arr[j]]=1;

            }
        }
        int m;
        scanf("%d",&m);
        while(m--){
            int q;
            scanf("%d",&q);
            if(vis[q]) printf("YES");
            else printf("NO");
            printf("\n");
        }
    }
    return 0;
}
