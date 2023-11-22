//madoka magica *
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXN=2e5+3;
int dfn[MAXN],low[MAXN],cnt,in[MAXN],scc[MAXN],scc_cnt,size[MAXN],color[MAXN],vis[MAXN];
int n,m;
int val[MAXN];
stack<int> s;
struct edge{
    int v,w,id,opt;
    edge(){}
    void init(){v=w=id=0;}
};
struct Node{
    int v,w;
    Node(){}
    Node(int a,int b){v=a;w=b;}
};
edge p[MAXN];
vector<Node> graph[MAXN];
void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    in[u]=1;
    s.push(u);
    for(auto i:graph[u]){
        int v=i.v;
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(in[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        int y;
        scc_cnt++;
        do{
            y=s.top();
            s.pop();
            scc[y]=scc_cnt;
            size[scc_cnt]++;
            in[y]=0;
        }while(!s.empty()&&y!=u);
    }
}
bool check(int u,int col){
    if(color[u]){
        if(col!=color[u]){
            return false;
        }
        return true;
    }
    color[u]=col;
    for(auto i:graph[u]){
        int v=i.v,w=i.w;
        if(scc[v]!=scc[u]) continue;
        if(!check(v,col^w)){
            return false;
        }
    }
    return true;
}
int fa[MAXN];
int ans;
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int xx=find(x),yy=find(y);
    if(xx==yy) return;    
    val[xx]=val[yy];  
    if(size[xx]<size[yy]) swap(xx,yy);
    fa[yy]=xx,size[xx]+=size[yy],size[yy]=0;
}
void init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        ans=0;
        memset(color,0,sizeof(color));
        memset(val,-1,sizeof(val));
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(scc,0,sizeof(scc));
        memset(size,0,sizeof(size));
        memset(in,0,sizeof(in));
        scc_cnt=cnt=0;
        for(int i=1;i<=m;i++){
            p[i].init();
        }
        for(int i=1;i<=n;i++){
            graph[i].clear();
        }
        while(!s.empty()){
            s.pop();
        }
        cin>>n>>m;
        init();
        for(int i=1;i<=m;i++){
            char opt;
            cin>>opt;
            p[i].id=i;
            if(opt!='+'&&opt!='-'){
                p[i].opt=1;
                int j;   
                cin>>j;
                p[i].v=j;
                // //<<opt<<j<<"\n";
                if(opt=='T'){
                    p[i].w=2;
                    //<<t<<"C\n";
                }
                else if(opt=='F'){
                    p[i].w=1;
                }
                else{
                    p[i].w=0;
                }
            }
            else{
                p[i].opt=-1;
                int j,k,O=(opt=='-');
                cin>>j>>k;
                // //<<opt<<j<<k<<"\n";
                p[i].v=j;
                p[i].w=k;
                graph[j].push_back({k,O});
            }
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i);
            }
            //<<scc[i]<<" ";
        }
        //<<"A\n";
        for(int i=1;i<=m;i++){
            if(p[i].opt==1){
                val[scc[p[i].v]]=p[i].w;
            }
        }
        for(int i=1;i<=n;i++){
            //<<val[scc[i]]<<"B\n";
        }
        for(int i=1;i<=n;i++){
            if(!vis[scc[i]]&&val[scc[i]]==-1){
                if(check(i,2)){
                    vis[scc[i]]=1;
                }
                else{
                    val[scc[i]]=0;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++){
            if(p[i].opt==-1){
                merge(scc[p[i].v],scc[p[i].w]);
            }
        }
        for(int i=1;i<=n;i++){
            int f=find(scc[i]);
            if(!val[f]){
                //<<f<<"A\n";
            }
            if(!vis[f]&&!val[f]){
                ans+=size[f];
                vis[f]=1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}