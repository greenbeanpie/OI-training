#include <bits/stdc++.h>
using namespace std;
#define int long long
struct block
{
    int flag[3200][3200] = {0};
    int val[3200] = {0};
    int &operator[](int a)
    {
        return flag[(a-1)/3200][(a-1)%3200];
    }
}b;
struct node{
    int l,r,k;
}nodes[10005];
bool cmp(node a,node b){
    return a.k>b.k;
}
signed main()
{
    int n,m,p;
    cin >> n >> m >> p;
    for(int i=0;i<n;i++){
        int a;
        scanf("%lld %lld",&a,&a);
        p-=a;
    }
    for(int i=0;i<m;i++){
        scanf("%lld %lld %lld",&nodes[i].l,&nodes[i].r,&nodes[i].k);
    }
    sort(nodes,nodes+m,cmp);
    int sum=0;
    for(int i=0;i<m;i++){
        int left=ceil(1.0*nodes[i].l/3200),right=floor(1.0*nodes[i].r/3200);
        for(int j=left;j<=right;j++){
            sum+=(3200-nodes.val[i])*nodes[i].k;
        }
    }
    return 0;
}