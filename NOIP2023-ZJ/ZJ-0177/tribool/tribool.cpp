#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=2e5+5;
const int M=2e6+5;
int n,m;
int x[N],y[N];
int h[N],num,ne[M],to[M],w[M];
int p[N];
int f[N];
void add(int a,int b,int c){
    ne[num]=h[a],to[num]=b,w[num]=c,h[a]=num++;
}
int Find(int t){
	if(x[t]>=1 && x[t]!=t){
		int g=x[t];
		// x[t]=Find(x[t]);
		// y[t]^=y[g];
		return x[t];
	}
	return x[t];
}
int find(int x){
    if(f[x]!=x) return f[x]=find(f[x]);
    return f[x];
}
void merge(int a,int b){
    f[find(a)]=find(b);
    return;
}
void calc(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) x[i]=i,y[i]=0;
    for(int i=1;i<=m;i++){
        char op[2];
        int id,id1;
        scanf("%s",op);
        if(op[0]=='U'){
            scanf("%d",&id);
            x[id]=-1,y[id]=0;
        }
        else if(op[0]=='F'){
            scanf("%d",&id);
            x[id]=-2,y[id]=0;
        }
        else if(op[0]=='T'){
            scanf("%d",&id);
            x[id]=-3,y[id]=0;
        }
        else if(op[0]=='-'){
            scanf("%d%d",&id,&id1);
            x[id]=Find(id1);
            y[id]=(y[id1]^1);
        }
        else if(op[0]=='+'){
            scanf("%d%d",&id,&id1);
            x[id]=Find(id1);
            y[id]=y[id1];
        }
    }
    // for(int i=1;i<=n;i++) cerr<<x[i]<<' '<<y[i]<<"\n";puts("");
    for(int i=1;i<=n;i++) Find(i);
    // for(int i=1;i<=n;i++) cerr<<x[i]<<' '<<y[i]<<"\n";
    memset(h,-1,sizeof(h));
    memset(p,0,sizeof(p));
    num=0;
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(x[i]<=0) q.push(i),p[i]=x[i];
        else add(x[i],i,y[i]);
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=to[i];
            p[j]=p[t];
            if(w[i]){
                if(p[j]==-2) p[j]=-3;
                else if(p[j]==-3) p[j]=-2;
            }
            q.push(j);
        }
    }
    for(int i=1;i<=2*n;i++) f[i]=i;
    for(int i=1;i<=n;i++){
        if(p[i]) continue;
        int u=x[i],v=i;
        if(!y[i]) merge(u,v),merge(u+n,v+n);
        else merge(u+n,v),merge(u,v+n);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(p[i] && p[i]==-1) ans++;
        else if(!p[i] && find(i)==find(i+n)) ans++;
    }
    printf("%d\n",ans);
    // cerr<<ans<<"\n";
    return;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,T;
    scanf("%d%d",&c,&T);
    while(T--) calc();
    return 0;
}