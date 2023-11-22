#include<bits/stdc++.h>
using namespace std;
int c,n,m,q,a[500010],b[500010],x[500010],y[500010];
int k[2],upd[2][500010];
struct val{
    int mn,mx;
}prex[500010],prey[500010],sufx[500010],sufy[500010];
void init(){
    prex[1].mx=prex[1].mn=1,prey[1].mn=prey[1].mx=1;
    sufx[n].mx=sufx[n].mn=n,sufy[m].mn=sufy[m].mx=m;
    for(int i=2;i<=n;i++){
        prex[i].mn=x[prex[i-1].mn]<x[i]?prex[i-1].mn:i;
        prex[i].mx=x[prex[i-1].mx]>x[i]?prex[i-1].mx:i;
    }
    for(int i=2;i<=m;i++){
        prey[i].mn=y[prey[i-1].mn]<y[i]?prey[i-1].mn:i;
        prey[i].mx=y[prey[i-1].mx]>y[i]?prey[i-1].mx:i;
    }
    for(int i=n-1;i;i--){
        sufx[i].mn=x[sufx[i+1].mn]<x[i]?sufx[i+1].mn:i;
        sufx[i].mx=x[sufx[i+1].mx]>x[i]?sufx[i+1].mx:i;
    }
    for(int i=m-1;i;i--){
        sufy[i].mn=y[sufy[i+1].mn]<y[i]?sufy[i+1].mn:i;
        sufy[i].mx=y[sufy[i+1].mx]>y[i]?sufy[i+1].mx:i;
    }
}
bool solve_pre_gr(int p,int q){
    if(y[prey[q].mx]>=x[p]||x[prex[p].mn]<=y[q])return false;
    if(p==1||q==1)return true;
    if(x[prex[p-1].mn]<=y[prey[q-1].mn])
        return solve_pre_gr(prex[p-1].mx,q);
    return solve_pre_gr(p,prey[q-1].mn);
}
bool solve_pre_le(int p,int q){
    if(x[prex[p].mx]>=y[q]||y[prey[q].mn]<=x[p])return false;
    if(p==1||q==1)return true;
    if(x[prex[p-1].mx]>=y[prey[q-1].mx])
        return solve_pre_le(prex[p-1].mn,q);
    return solve_pre_le(p,prey[q-1].mx);
}
bool solve_suf_gr(int p,int q){
    if(x[sufx[p].mn]<=y[q]||y[sufy[q].mx]>=x[p])return false;
    if(p==n||q==m)return true;
    if(x[sufx[p+1].mn]<=y[sufy[q+1].mn])
        return solve_suf_gr(sufx[p+1].mx,q);
    return solve_suf_gr(p,sufy[q+1].mn);
}
bool solve_suf_le(int p,int q){
    if(x[sufx[p].mx]>=y[q]||y[sufy[q].mn]<=x[p])return false;
    if(p==n||q==m)return true;
    if(x[sufx[p+1].mx]>=y[sufy[q+1].mx])
        return solve_suf_le(sufx[p+1].mn,q);
    return solve_suf_le(p,sufy[q+1].mx);
}
bool solve(){
    init();
    if(x[1]<y[1]){
        return solve_pre_le(prex[n].mn,prey[m].mx)&&solve_suf_le(prex[n].mn,prey[m].mx);
    }else if(x[1]>y[1]){
        return solve_pre_gr(prex[n].mx,prey[m].mn)&&solve_suf_gr(prex[n].mx,prey[m].mn);
    }else return false;
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&c,&n,&m,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),x[i]=a[i];
    for(int i=1;i<=m;i++)scanf("%d",&b[i]),y[i]=b[i];
    putchar(solve()+'0');
    for(int i=1;i<=q;i++){
        scanf("%d%d",&k[0],&k[1]);
        for(int j=1,tmp;j<=k[0];j++)
            scanf("%d%d",&upd[0][j],&tmp),x[upd[0][j]]=tmp;
        for(int j=1,tmp;j<=k[1];j++)
            scanf("%d%d",&upd[1][j],&tmp),y[upd[1][j]]=tmp;
        putchar(solve()+'0');
        for(int j=1;j<=k[0];j++)x[upd[0][j]]=a[upd[0][j]];
        for(int j=1;j<=k[1];j++)y[upd[1][j]]=b[upd[1][j]];
    }
    putchar('\n');
    return 0;
}