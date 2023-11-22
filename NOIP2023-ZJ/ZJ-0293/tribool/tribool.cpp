#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int c,T,n,m,id[N],ty[N],ans,fa[N],cnt,ok;
vector<int>e[N],f[N];int bn[N],co[N];
int cc(int x){return fa[x]==x?x:fa[x]=cc(fa[x]);}
void add(int x,int y){
    int fx=cc(x),fy=cc(y);
    if(fx!=fy)fa[fx]=fy;
    return;
}
void dfs(int d){
    if(co[d]==1)ans++;
    for(auto x:e[d]){
        if(co[x]==-1){
            co[x]=co[d];
            dfs(x);
        }
    }
    for(auto x:f[d]){
        if(co[x]==-1){
            co[x]=2-co[d];
            dfs(x);
        }
    }
    return;
}
void dfs2(int x){
    cnt++;
    for(auto v:e[x]){
        if(co[v]==-1){
            co[v]=co[x];
            dfs2(v);
        }else{
            if(co[v]!=co[x])ok=0;
        }
    }for(auto v:f[x]){
        if(co[v]==-1){
            co[v]=1-co[x];
            dfs2(v);
        }else{
            if(co[v]!=1-co[x])ok=0;
        }
    }
    return;
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cin>>c>>T;
    while(T--){
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++){
            id[i]=i;
            ty[i]=0;
            fa[i]=i;
            bn[i]=0;
            co[i]=-1;
        }
        for(int i=1;i<=m;i++){
            char op;
            int x,y;
            cin>>op;
            if(op=='+'){
                cin>>x>>y;
                id[x]=id[y];
                ty[x]=ty[y];
            }else if(op=='-'){
                cin>>x>>y;
                if(id[y]!=-1){
                    id[x]=id[y];
                    ty[x]=(ty[y]^1);
                }else{
                    id[x]=id[y];
                    ty[x]=2-ty[y];
                }
            }else{
                cin>>x;
                id[x]=-1;
                if(op=='T')ty[x]=0;
                else if(op=='U')ty[x]=1;
                else ty[x]=2;
            }
        }
        for(int x=1;x<=n;x++){
            if(id[x]!=-1){
                if(ty[x]==0){
                    e[x].push_back(id[x]);
                    e[id[x]].push_back(x);
                    add(id[x],x);
                }else{
                    f[x].push_back(id[x]);
                    f[id[x]].push_back(x);
                    add(id[x],x);
                }
            }
        }
        for(int i=1;i<=n;i++)
            fa[i]=cc(fa[i]);
        for(int i=1;i<=n;i++)
            if(id[i]==-1){
                if(!bn[fa[i]]){
                    bn[fa[i]]=1;
                    co[i]=ty[i];
                    dfs(i);
                }
            }
        for(int i=1;i<=n;i++)
            if(!bn[fa[i]]){
                bn[fa[i]]=1;
                co[i]=0;
                cnt=0;ok=1;
                dfs2(i);
                if(!ok)ans+=cnt;
            }
        for(int i=1;i<=n;i++){
            e[i].clear();
            f[i].clear();
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
key of value
T 0
U 1
F 2
*/
