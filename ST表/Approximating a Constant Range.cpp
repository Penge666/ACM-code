#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 666666
int n;
struct str{
    int num;
    int pos;
};
int a[maxn];
int stmin[maxn][20];
int stmax[maxn][20];
void Init(){
    int i,j;
    for(i=1;i<=n;i++)
        stmin[i][0]=stmax[i][0]=a[i];
    for(i=1;(1<<i)<=n;i++){   //�����䳤�ȵ���˳�����
        for(j=1;j+(1<<i)-1<=n;j++){   //�������
            stmin[j][i]=min(stmin[j][i-1],stmin[j+(1<<(i-1))][i-1]);
            stmax[j][i]=max(stmax[j][i-1],stmax[j+(1<<(i-1))][i-1]);
        }
    }
}
int Query_MAX(int l,int r){//�õ�[l,r]����ֵ
    int k=(int)(log(r-l+1)/log(2));//logҲ����Ҫʱ��ģ���Щ��Ŀ��T��Ԥ��������ȡ������
    return max(stmax[l][k],stmax[r-(1<<k)+1][k]);
//    return min(stmin[l][k],stmin[r-(1<<k)+1][k]);
}
int Query_MIN(int l,int r){//�õ�[l,r]����ֵ
    int k=(int)(log(r-l+1)/log(2));//logҲ����Ҫʱ��ģ���Щ��Ŀ��T��Ԥ��������ȡ������
//    return max(stmax[l][k],stmax[r-(1<<k)+1][k]);
    return min(stmin[l][k],stmin[r-(1<<k)+1][k]);
}
deque<str> q;
signed main(){

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    Init();
    int ans=0;
    for(int i=1;i<=n;i++){
        q.push_back((str){a[i],i});
        while(abs(Query_MAX(q.front().pos,q.back().pos)-Query_MIN(q.front().pos,q.back().pos))>1) q.pop_front();
        int t=q.size();
        ans=max(ans,t);
    }
    cout<<ans;
    return 0;
}
