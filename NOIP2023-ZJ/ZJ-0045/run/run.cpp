#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+(c^'0'),c=getchar();
    return x;
}
#define ll long long
int n,m,k,d;
int val[200005],len;
struct node{
    int l,r,v;
}a[100005];
vector<pair<int,ll>>vec[200005];
ll dp[200005];
ll tree[800005],tag[800005];
void pushdown(int k){
    if(tag[k]){
        tree[k*2]+=tag[k];
        tree[k*2+1]+=tag[k];
        tag[k*2]+=tag[k];
        tag[k*2+1]+=tag[k];
        tag[k]=0;
    }
}
void change(int k,int l,int r,int x,int y,ll z){
    if(l>=x&&r<=y){
        tree[k]+=z;
        tag[k]+=z;
        return;
    }
    pushdown(k);
    int mid=l+r>>1;
    if(x<=mid)change(k*2,l,mid,x,y,z);
    if(y>mid)change(k*2+1,mid+1,r,x,y,z);
    tree[k]=max(tree[k*2],tree[k*2+1]);
}
ll query(int k,int l,int r,int x,int y){
    if(l>=x&&r<=y)return tree[k];
    pushdown(k);
    int mid=l+r>>1;
    if(y<=mid)return query(k*2,l,mid,x,y);
    else if(x>mid)return query(k*2+1,mid+1,r,x,y);
    else return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    read();int _=read();
    while(_--){
        n=read(),m=read(),k=read(),d=read();len=0;
        for(int i=1;i<=m;i++){
            a[i].r=read(),a[i].l=a[i].r-read(),a[i].v=read();
            val[++len]=a[i].l,val[++len]=a[i].r;
        }
        sort(val+1,val+len+1);len=unique(val+1,val+len+1)-val-1;
        for(int i=1;i<=len;i++)vec[i].clear();
        for(int i=1;i<=m;i++){
            a[i].l=lower_bound(val+1,val+len+1,a[i].l)-val;
            a[i].r=lower_bound(val+1,val+len+1,a[i].r)-val;
            vec[a[i].r].push_back(make_pair(a[i].l,a[i].v));
        }
        memset(dp,0,sizeof(dp));
        memset(tree,0,sizeof(tree));
        memset(tag,0,sizeof(tag));
        for(int i=1,j=0;i<=len;i++){
            for(auto p:vec[i])change(1,0,len,0,p.first,p.second);
            while(j<i&&val[i]-val[j]>k)j++;
            dp[i]=dp[i-1];
            if(j<i)dp[i]=max(dp[i],query(1,0,len,j,i-1)-1ll*val[i]*d);
            change(1,0,len,i,i,dp[i-1]+1ll*val[i]*d);
        }
        printf("%lld\n",dp[len]);
    }
    // cerr<<"time: "<<clock()*1000./CLOCKS_PER_SEC<<"ms"<<endl;
    return 0;
}