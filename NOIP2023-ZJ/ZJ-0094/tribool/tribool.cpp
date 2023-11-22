#include<bits/stdc++.h>
#define ll long long
#define Ci const int
#define Cc const char
#define Cl const ll
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fll
#define For(i_,l_,r_) for(int i_=l_,p_=r_;i_<=p_;i_++)
#define Rep(i_,l_,r_) for(int i_=l_,p_=r_;i_>=p_;i_--)
using namespace std;
#define _c_ getchar()
#define getchar() (_u==_v&&(_v=(_u=_c)+fread(_c,1,inS,stdin),_u==_v)?EOF:*_u++)
Ci inS=1<<20,ouS=1<<20;
char _c[inS],*_u=_c,*_v=_c,_b[ouS],_d[55];int _p,_l=-1;
template<typename T=int>inline T read(){
    T x=0;bool fl=0;char ch=_c_;while(ch<48||ch>57)fl|=(ch==45),ch=_c_;
    while(ch>47&&ch<58)x=x*10+(ch^48),ch=_c_;return fl?-x:x;
}
inline char Gec(){char ch=_c_;while(ch<33)ch=_c_;return ch;}
inline void flush(){fwrite(_b,1,_l+1,stdout);_l=-1;}
inline void _pc(Cc c){if(c!=-1)_b[++_l]=c;}
inline void _chf(){if(_l>(ouS>>1))flush();}
template<typename T>inline void write(T x,char ch=-1){
    if(x<0)_pc(45),x=-x;do{_d[++_p]=(x%10)|48;}while(x/=10);
    do{_pc(_d[_p]);}while(--_p);_pc(ch);_chf();
}
Ci N_=2e5+5;
inline void init(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    atexit(flush);read();
}
int n,m,C,fa[N_],now[N_],d[N_],a[N_],X[N_],tmp[N_];
bool fl[N_],vis[N_],vv[N_];
vector<pair<int,char>>E[N_];
void dfs(Ci u){
    vis[u]=1;
    if(u==now[X[u]]&&!vis[X[u]])fl[X[u]]=1,a[X[u]]=a[u],dfs(X[u]);
    if(u==X[u]&&!vis[now[u]])fl[now[u]]=1,a[now[u]]=a[u],dfs(now[u]);
    for(pair<int,int> v:E[u])
        if(!vis[v.first]){
            fl[v.first]=1,a[v.first]=(v.second=='+'?a[u]:-a[u]),dfs(v.first);
        }
}
bool check(Ci u){
    // cerr<<u<<" ";
    vv[u]=1;bool GG=0;
    if(u==now[X[u]]&&vv[X[u]]&&tmp[X[u]]!=tmp[u])return 1;
    if(u==X[u]&&vv[now[u]]&&tmp[now[u]]!=tmp[u])return 1;
    if(u==now[X[u]]&&!vv[X[u]])tmp[X[u]]=tmp[u],GG|=check(X[u]);
    if(u==X[u]&&!vv[now[u]])tmp[now[u]]=tmp[u],GG|=check(now[u]);
    for(pair<int,int> v:E[u])
        if(!vv[v.first]){
            tmp[v.first]=(v.second=='+'?tmp[u]:-tmp[u]);
            GG|=check(v.first);
        }
        else{
    // if(u==15)cerr<<"\n??? "<<v.first<<" "<<v.second<<" "<<tmp[u]<<" "<<tmp[v.first]<<"\n";
            char gg=(v.second=='+'?tmp[u]:-tmp[u]);
            if(gg!=tmp[v.first])return 1;
        }
    return GG;
}
inline void ypa(){
    For(i,1,C)now[i]=0,d[i]=a[i]=tmp[i]=0,fl[i]=vis[i]=vv[i]=0,E[i].clear();
    n=read(),m=read();
    For(i,1,n)now[i]=i,fa[i]=i,d[i]=1,X[i]=i;
    C=n;
    For(i,1,m){
        int p=n+i;++C;
        char ch=Gec();int x=read();X[p]=x;
        if(ch=='+'||ch=='-'){
            int y=read();
            if(fl[now[y]])fl[p]=1,a[p]=(ch=='+'?a[now[y]]:-a[now[y]]),fa[p]=fa[now[y]];
            else d[p]=(ch=='+'?d[now[y]]:-d[now[y]]),fa[p]=fa[now[y]];
            E[now[y]].push_back({p,ch});
            E[p].push_back({now[y],ch});
            // cerr<<now[y]<<" "<<p<<"\n";
        }
        else{
            fl[p]=1;fa[p]=p;a[p]=(ch=='T'?1:(ch=='U'?0:-1));
        }
        now[x]=p;
    }
    int ans=0;
    For(i,1,n)
        if(fl[now[i]]&&!vis[i])fl[i]=1,a[i]=a[now[i]],dfs(i);
    For(i,1,n)
        if(!fl[i]&&!vv[i]){
            tmp[i]=1;
            bool fg=check(i);
            // cerr<<fg<<"\n";
            if(fg)fl[i]=1,a[i]=0,dfs(i);
        }
    For(i,1,n)
        if(fl[now[i]])ans+=(!a[now[i]]);
    write(ans,'\n');
}
signed main(){init();int T=read();For(i,1,T)ypa();return 0;}