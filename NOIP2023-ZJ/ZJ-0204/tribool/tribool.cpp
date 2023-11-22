#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,vis[N],d[N],sz[N];//,fa[N],sz[N];
struct node{int p,n;}a[N];
//int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
//void merge(int x,int y){
//	x=find(x);y=find(y);
//	if(x==y)return;
//	if(sz[x]>sz[y])swap(x,y);
//	fa[x]=y;sz[y]+=sz[x];
//}
void solve(){
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
//    memset(fa,0,sizeof(fa));
//    memset(sz,0,sizeof(sz));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+3;i++)a[i]={i,0},sz[i]=1;//,fa[i]=i,sz[i]=1;
    for(int _=1;_<=m;_++){
        char op[2];int i,j;
        scanf("%s",op);
        if(op[0]=='+'){
            scanf("%d%d",&j,&i);
            a[j]=a[i];
        }else if(op[0]=='-'){
            scanf("%d%d",&j,&i);
            a[j]=a[i];
            a[j].n^=1;
        }else{
            scanf("%d",&i);
            if(op[0]=='T')a[i]=a[n+1];
            if(op[0]=='F')a[i]=a[n+2];
            if(op[0]=='U')a[i]=a[n+3];
        }
    }
    int cnt=0;
    queue<int>q;
    for(int i=1;i<=n+3;i++)d[a[i].p]++;
    for(int i=1;i<=n+3;i++)if(d[i]==0)q.push(i);
    while(q.size()){
    	int x=q.front();q.pop();
    	vis[x]=0;
    	--d[a[x].p];
    	sz[a[x].p]+=sz[x];sz[x]=0;
    	if(d[a[x].p]==0)q.push(a[x].p);
	}
	for(int i=1;i<=n+3;i++)if(d[i]){
		vector<int>c;
		int x=i,sum=0,f=0;
		while(d[x])d[x]=0,c.push_back(x),sum+=sz[x],x=a[x].p;
		for(int j=0;j<c.size();j++)f^=a[c[j]].n;
		if(f!=0||x==n+3){
			cnt+=sum-(x==n+3);
		}
	}
	printf("%d\n",cnt);
//    for(int i=1;i<=n;i++)printf("%2d ",i);puts("");
//    for(int i=1;i<=n;i++)printf("%2d ",a[i].p);puts("");
//    for(int i=1;i<=n;i++)printf("%2d ",a[i].n);puts("");
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--)solve();
    return 0;
}
/*
*/