#include<stdio.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

inline int read(){
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){
        if(c=='-')
            flag=1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    if(flag)
        x=-x;
    return x;
}
struct str{
    int pos;
    int val;
};
int n,k;
int arr[1500000];
void ok1(){//min
    deque<str> q;
    for(int i=1;i<=k;i++){
        while(!q.empty()&&arr[i]<q.front().val){
            q.pop_front();
        }
        struct  str temp;
        temp.pos=i;
        temp.val=arr[i];
        q.push_front(temp);
    }
    printf("%d",q.back().val);
    for(int i=k+1;i<=n;i++){
        while(!q.empty()&&arr[i]<q.front().val){
            q.pop_front();
        }
        struct  str temp;
        temp.pos=i;temp.val=arr[i];
        q.push_front(temp);// da--->xiao
        while(!q.empty()&&q.back().pos<=i-k){
            q.pop_back();
        }
        printf(" %d",q.back().val);
    }
}
void ok2(){
    deque<str> q;
    for(int i=1;i<=k;i++){
        while(!q.empty()&&arr[i]>q.front().val){
            q.pop_front();
        }
        struct  str temp;
        temp.pos=i;temp.val=arr[i];
        q.push_front(temp);
    }
    printf("%d",q.back().val);
    for(int i=k+1;i<=n;i++){
        while(!q.empty()&&arr[i]>q.front().val){
            q.pop_front();
        }
        struct  str temp;
        temp.pos=i;temp.val=arr[i];
        q.push_front(temp);
        while(!q.empty()&&q.back().pos<=i-k){
            q.pop_back();
        }
        printf(" %d",q.back().val);
    }
}
int  main(){
    n=read();
    k=read();
    for(int i=1;i<=n;i++){
        arr[i]=read();
    }
    ok1();// min
    printf("\n");
    ok2();// max
    return 0;
}
