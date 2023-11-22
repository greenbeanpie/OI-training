#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e3+100;
int n,m;
struct edge{
    int u,v,w;
};
int getpval(int c,int op){
    if(op==0 || c==0 || c=='U')return c;
    if(c=='T')return 'F';
    return 'T';
}
class lineargraph{
private:
    int current;
public:
    int top[MAXN];
    edge father[MAXN];
    vector<edge> children[MAXN];
    int value[MAXN];
    int topof[MAXN];
    int ances[MAXN],op[MAXN];
    queue<int> q;
    void dfs(int u,int val){
        if(value[u])return;
        value[u]=val;
        for(edge child : children[u])if(!value[child.v]){
            dfs(child.v,getpval(value[u],child.w));
            if(topof[child.v]){
                q.push(topof[child.v]);
            }
        }
    }
    void push(){
        queue<int> q2;
        q.swap(q2);
        for(int i =1;i<=n;i++){
            topof[top[i]]=i;
            if(value[top[i]]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int i = q.front();q.pop();
            dfs(i,value[top[i]]);
        }
    }
    void reset(){
        memset(top,0,sizeof top);
        memset(father,0,sizeof father);
        for(int i =0;i<=n;i++){
            children[i].resize(0);
        }
        memset(value,0,sizeof value);
        memset(topof,0,sizeof topof);
        memset(ances,0,sizeof ances);
        memset(op,0,sizeof op);
    }
    void search(){
        for(int i = 1;i<=n;i++){
            int v = top[i];
            int cnt = 0;
            while(father[v].u){
                cnt+=father[v].w;
                v=father[v].u;
            }
            ances[i]=v;
            op[i]=cnt%2;
        }
    }
    void build(){
        for(int i =1;i<=n;i++){
            top[i]=i;
        }
        current = n;
    }
    void setvalue(int pos,char val){
        int id = ++current;
        value[id]=val;

        top[pos]=id;
    }
    void envalue(int from,int to,int op){//op=0 normal op=1 reversed
        int id = ++current;
        value[id]=getpval(value[from],op);
        children[from].push_back({from,id,op});
        father[id]={from,id,op};
        top[to]=id;
    }
} grph;
char a[MAXN];
bool check(int i ){
    int ances = grph.ances[i];
    if(ances<=i){
        if(getpval(a[i],grph.op[i])!=a[ances]){
            return false;
        }
    }else{
        a[ances]=getpval(a[i],grph.op[i]);
    }
    return true;
}
bool dfs(int i){
    if(i==n+1){
            //printf("df[1] in %d\n",i);
        return true;
    }
    if(grph.value[i])return dfs(i+1);
    if(a[i]){
        int ances = grph.ances[i];
        int ancesbk = a[ances];
        if(!check(i)){
            a[i]=0;
            return false;
        }
        if(!dfs(i+1)){
            a[ances]=ancesbk;
            return false;
        }
            //printf("df[2] in %d\n",i);
        return true;
    }
    else{
        a[i]='T';
        if(dfs(i)){
            //printf("df[3] in %d\n",i);
            return true;
        }
        a[i]='F';
        if(dfs(i)){
            //printf("df[4] in %d\n",i);
            return true;
        }
        a[i]='U';
        if(dfs(i)){
            //printf("df[5] in %d\n",i);
            return true;
        }
        return false;
    }
};
void solve(){
    scanf("%d%d",&n,&m);
    grph.reset();
    grph.build();
    for(int i = 1;i<=m;i++){
        char a;int b,c;
        scanf("%s %d",&a,&b);
        if(a=='+' || a=='-'){
            scanf("%d",&c);
            grph.envalue(c,b,a=='+' ? 0 : 1);
        }else{
            grph.setvalue(b,a);
        }
    }
    grph.push();
    grph.search();
    memset(a,0,sizeof a);
    /*for(int i = 1;i<=n;i++){
        if(grph.value[i])printf("%d : %c--%c\n",i,grph.value[i],grph.value[grph.top[i]]);
        else printf("%d : %d->%d\n",i,grph.ances[i],grph.op[i]);
    }*/
    dfs(1);
    int ans = 0;
    for(int i = 1;i<=n;i++)if(a[i]=='U')ans++;
    for(int i = 1;i<=n;i++)if(grph.value[i]=='U')ans++;
    printf("%d\n",ans);
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;scanf("%d%d",&c,&t);
    while(t--){
        solve();
    }
}