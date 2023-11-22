#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+(c^'0'),c=getchar();
    return x;
}
int n,m,q;
int a[500005],a1[500005],b[500005],b1[500005];
int tree1[2000005],tree2[2000005];
void build(int k,int l,int r){
    if(l==r){tree1[k]=tree2[k]=b[l];return;}
    int mid=l+r>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    tree1[k]=min(tree1[k*2],tree1[k*2+1]);
    tree2[k]=max(tree2[k*2],tree2[k*2+1]);
}
void change(int k,int l,int r,int x,int y){
    if(l==r){tree1[k]=tree2[k]=y;return;}
    int mid=l+r>>1;
    if(x<=mid)change(k*2,l,mid,x,y);
    else change(k*2+1,mid+1,r,x,y);
    tree1[k]=min(tree1[k*2],tree1[k*2+1]);
    tree2[k]=max(tree2[k*2],tree2[k*2+1]);
}
int findr1(int k,int l,int r,int x,int y){//min i>=x s.t. b[i]>=y
    if(tree2[k]<y)return m+1;
    if(l==r)return l;
    int mid=l+r>>1;
    if(x>mid)return findr1(k*2+1,mid+1,r,x,y);
    else{
        int res=findr1(k*2,l,mid,x,y);
        if(res<=m)return res;
        else return findr1(k*2+1,mid+1,r,x,y);
    }
}
int findl1(int k,int l,int r,int x,int y){//max i<=x s.t. b[i]>=y
    if(tree2[k]<y)return 0;
    if(l==r)return l;
    int mid=l+r>>1;
    if(x<=mid)return findl1(k*2,l,mid,x,y);
    else{
        int res=findl1(k*2+1,mid+1,r,x,y);
        if(res>=1)return res;
        else return findl1(k*2,l,mid,x,y);
    }
}
int findr2(int k,int l,int r,int x,int y){//min i>=x s.t. b[i]<=y
    if(tree1[k]>y)return m+1;
    if(l==r)return l;
    int mid=l+r>>1;
    if(x>mid)return findr2(k*2+1,mid+1,r,x,y);
    else{
        int res=findr2(k*2,l,mid,x,y);
        if(res<=m)return res;
        else return findr2(k*2+1,mid+1,r,x,y);
    }
}
int findl2(int k,int l,int r,int x,int y){//max i<=x s.t. b[i]<=y
    if(tree1[k]>y)return 0;
    if(l==r)return l;
    int mid=l+r>>1;
    if(x<=mid)return findl2(k*2,l,mid,x,y);
    else{
        int res=findl2(k*2+1,mid+1,r,x,y);
        if(res>=1)return res;
        else return findl2(k*2,l,mid,x,y);
    }
}
int dp[2005][2005];
void solve(){
    if(n<=2000){
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)dp[i][j]=0;
        dp[1][1]=1;
        if(a[1]<b[1]){
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)if(dp[i][j]){
                    if(i<n&&a[i+1]<b[j])dp[i+1][j]=1;
                    if(j<m&&a[i]<b[j+1])dp[i][j+1]=1;
                }
        }else if(a[1]>b[1]){
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)if(dp[i][j]){
                    if(i<n&&a[i+1]>b[j])dp[i+1][j]=1;
                    if(j<m&&a[i]>b[j+1])dp[i][j+1]=1;
                }
        }
        putchar(dp[n][m]^'0');
        return;
    }
    if(a[1]<b[1]){
        int l=1,r=1;
        while(r<m&&b[r+1]>a[1])r++;
        for(int i=2;i<=n;i++)
            if(a[i]>a[i-1]&&(i==n||a[i]>=a[i+1])){
                while(l<=m&&b[l]<=a[i])l++;
                r=findl1(1,1,m,r,a[i]+1);
                if(l>r)return putchar('0'),void();
            }else if(a[i]<a[i-1]&&(i==n||a[i]<=a[i+1])){
                r=findr2(1,1,m,r,a[i])-1;
            }
        if(r<m)putchar('0');
        else putchar('1');
    }else if(a[1]>b[1]){
        int l=1,r=1;
        while(r<m&&b[r+1]<a[1])r++;
        for(int i=2;i<=n;i++)
            if(a[i]<a[i-1]&&(i==n||a[i]<=a[i+1])){
                while(l<=m&&b[l]>=a[i])l++;
                r=findl2(1,1,m,r,a[i]-1);
                if(l>r)return putchar('0'),void();
            }else if(a[i]>a[i-1]&&(i==n||a[i]>=a[i+1])){
                r=findr1(1,1,m,r,a[i])-1;
            }
        if(r<m)putchar('0');
        else putchar('1');
    }else putchar('0');
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    read();n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)a1[i]=a[i]=read();
    for(int i=1;i<=m;i++)b1[i]=b[i]=read();
    build(1,1,m);
    solve();
    while(q--){
        int kx=read(),ky=read();
        vector<int> vecx,vecy;
        for(int i=1;i<=kx;i++){
            int x=read(),y=read();
            vecx.push_back(x);
            a[x]=y;
        }
        for(int i=1;i<=ky;i++){
            int x=read(),y=read();
            vecy.push_back(x);
            change(1,1,m,x,y);
            b[x]=y;
        }
        solve();
        for(int x:vecx)a[x]=a1[x];
        for(int x:vecy)b[x]=b1[x],change(1,1,m,x,b[x]);
    }
    puts("");
    // cerr<<"time: "<<clock()*1000./CLOCKS_PER_SEC<<"ms"<<endl;
    return 0;
}