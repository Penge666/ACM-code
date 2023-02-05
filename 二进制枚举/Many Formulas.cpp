// 二进制枚举加号

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int arr[N];
vector<int> v1,v0;
int a[N],b[N];
map<int,int> mp;
signed main(){
    string str;
    cin>>str;
    int n=str.size();int ans=0;
    for(int i=0;i<(1<<(n-1));i++){
        int temp=(str[0]-'0');
        for(int j=0;j<n;j++){

            if(i&(1<<j)||j==n-1){ //有
                ans+=temp;
                temp=0;

                //break;
            }
            temp=temp*10+(str[j+1]-'0');

            //add*=10;

        }
    }
    cout<<ans;
    return 0;
}
/*
