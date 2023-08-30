#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+ch-'0';
        ch=getchar();
    }
    return s*w;
}
const int maxn=6e5+5;
struct tu{
    int x,y;
    tu operator +(tu a){return {x+a.x,y+a.y};}
    tu operator -(tu a){return {x-a.x,y-a.y};}
    int operator *(tu a){return x*a.y-y*a.x;};
    bool cmp1(){
        return x>0||(!x&&y>0);
    }
}c[maxn],s[maxn],ans,g[maxn];
bool cmp2(tu a,tu b){
    return ((a.cmp1()!=b.cmp1())?a.cmp1():a*b>0);
}

struct tree{
    int to,next,id;
}tr[maxn];
int head[maxn],cnt;
void add(int u,int v,int id){
    tr[++cnt].to=v;
    tr[cnt].next=head[u];
    tr[cnt].id=id;
    head[u]=cnt;
}
int vis[maxn],tot,res,huan[maxn],fa[maxn],fid[maxn],a[maxn],b[maxn],id[maxn];
bool cmp(tu a,tu b){
    return (a.x!=b.x)?a.x<b.x:a.y<b.y;
}
void build(int &n,tu *d){
    sort(d+1,d+n+1,cmp);
    int top=0;
    for(int i=1;i<=n;i++){
        while(top>1&&((d[i]-s[top])*(s[top]-s[top-1])>=0))top--;
        s[++top]=d[i];
    }
    n=top;
}
void dfs(int x){
    vis[x]=++tot;
    for(int i=head[x];i;i=tr[i].next){
        int y=tr[i].to,z=tr[i].id;
        if(y==fa[x])continue;
        if(!vis[y]){
            fa[y]=x,fid[y]=z;
            dfs(y);
        }
        else if(vis[x]>vis[y]){
            int t=0,suma=0,sumb=0;
            for(int i=x;i!=y;i=fa[i])id[++t]=fid[i];
            id[++t]=z;
            for(int i=1;i<=t;i++)suma+=a[id[i]],sumb+=b[id[i]];
            for(int i=1;i<=t;i++)huan[id[i]]=1,c[i]={suma-a[id[i]],sumb-b[id[i]]};
            build(t,c);
            ans=ans+s[1];
            for(int i=2;i<=t;i++)g[++res]=s[i]-s[i-1];
        }
    }
}
int n,m;
signed main(){
    freopen("carnation.in","r",stdin);
    freopen("carnation_TJ.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=m;i++){
        int u=read(),v=read();
        a[i]=read(),b[i]=read();
        add(u,v,i);add(v,u,i);
    }
    dfs(1);
    for(int i=1;i<=m;i++){
        if(!huan[i])ans=ans+(tu){a[i],b[i]};
    }
    sort(g+1,g+res+1,cmp2);
    int minn=ans.x*ans.y;
    for(int i=1;i<=res;i++){
        ans=ans+g[i];
        minn=min(minn,ans.x*ans.y);
    }
    cout<<minn;
    fclose(stdin);fclose(stdout);
    return 0;
}
