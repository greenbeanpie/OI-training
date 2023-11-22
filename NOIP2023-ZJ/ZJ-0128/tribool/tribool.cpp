/*
10:34
感觉有点像并查集的应用。
如果是赋值就是强行改阵营，反赋值就是反向阵营。
不是
发现好像是一个类似于桶的东西。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e5+20;
int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int cid,T,n,m,a[N],ans[N],siz[N],tot;
bool vis[N],Flag;
vector<PII>f[N];
//T-> n+1,F->n+2,U->n+3
void dfs(int x){
    vis[x]=1;
    siz[tot]++;
    for(PII PI:f[x]){
        int y=PI.first,w=PI.second;
        if(vis[y]&&ans[y]*w!=ans[x])Flag=0;
        if(!vis[y]){
            ans[y]=ans[x]*w;
            dfs(y);
        }
    }
    return;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cid=read(),T=read();
    while(T--){
        n=read(),m=read();
        for(int i=1;i<=n+3;i++){
            a[i]=i;
            vis[i]=0;
            f[i].clear();
            siz[i]=0;
        }
        tot=0;
        for(int ww=1,x,y;ww<=m;ww++){
            char opt;
            cin>>opt;
            if(opt=='+'){
                x=read(),y=read();
                a[x]=a[y];
            }else if(opt=='-'){
                x=read(),y=read();
                a[x]=-a[y];
            }else if(opt=='T'){
                x=read();
                a[x]=n+1;
            }else if(opt=='F'){
                x=read();
                a[x]=n+2;
            }else{
                x=read();
                a[x]=n+3;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]>0)f[a[i]].push_back({i,1}),f[i].push_back({a[i],1});
            else f[-a[i]].push_back({i,-1}),f[i].push_back({-a[i],-1});
        }
        int ANS=0;
        ans[n+1]=1,ans[n+2]=-1,ans[n+3]=0;
        dfs(n+1),dfs(n+2);
        tot++;
        dfs(n+3);
        ANS+=siz[tot]-1;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                tot++;
                Flag=1;
                dfs(i);
                if(!Flag)ANS+=siz[tot];
            }
        }
        printf("%d\n",ANS);
    }
    return 0;
}