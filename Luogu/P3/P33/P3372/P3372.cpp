#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int f=0,l=0,r=0,sum=0,pdt=1,add=0,;
};
node tree[200005];
int num[100005];
int cnt=1;
void build_tree(int s,int t,int p){
    int mid=s+(t-s)/2;
    build_tree(s,mid,p*2);
    build_tree(mid+1,s,p*2+1);
    tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
    tree[p].l=p*2;
    tree[p].r=p*2+1;
    tree[p*2].f=p;
    tree[p*2+1].f=p;
}
int getsum(int l,int r,int s,int t,int p){
    int sum=0;
    if(l<=s&&r>=t){
        return tree[p].sum;
    }
    int mid=s+(t-s)/2;
    if(l<=mid){
        sum+=getsum(l,r,s,mid,p*2);
    }
    if(r>mid){
        sum+=getsum(l,r,s,mid,p*2+1);
    }
    return sum;
}
void update(int l,int r,int c,int s,int t,int p){
    if(l<=s&&t<=r){
        tree[p].add+=c;
        tree[p].sum+=(t-s+1)*c;
    }
    int mid=s+(t-s)/2;
    if(tree[p].add&&s!=t){
        tree[p*2].sum+=tree[p].add*(mid-s+1);
        tree[p*2+1].sum+=tree[p].add*(t-mid);
        tree[p].add=0;
    }
    if(l<=mid){
        update(l,r,c,s,mid,p*2);
    }
    if(r>mid){
        update(l,r,c,mid+1,t,p*2+1);
    }
    tree[p].sum=tree[p*2].sum+tree[p*2+1].sum;
}
signed main(){
    return 0;
}