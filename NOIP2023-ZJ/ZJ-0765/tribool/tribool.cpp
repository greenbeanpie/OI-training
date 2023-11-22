#include<bits/stdc++.h>
#define up(i,a,b) for(int i=a;i<=b;i++)
#define down(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 1e5+7;
inline read(){
	int x=0,f=1,ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int c,T;
int n,m;
struct Edge{
	int next,to,op,t;
}edge[MAXN<<1],edge1[MAXN<<1];

int head[MAXN],cnt,cnt1,head1[MAXN];
int ind[MAXN];
int val[MAXN<<1];
void add(int u,int v,int op,int t){
	edge[++cnt].to=v;
	edge[cnt].op=op;
	edge[cnt].t=t;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
void add1(int u,int v,int op){
	edge1[++cnt1].to=v;
	edge1[cnt1].op=op;
	edge1[cnt1].next=head1[u];
	head1[u]=cnt1;
}
int rt;
void dfs(int v,int t,int op){
	int flag = 1;
	for(int i=head[v];i;i=edge[i].next){
		int u=edge[i].to;
		if(edge[i].t<t){
			dfs(u,edge[i].t,op*edge[i].op);	
			flag=0;
			break;
		}
	}
	if(flag){
		add1(v,rt,op);
	//	printf("%lld %lld %lld %lld \n",v,rt,val[v],op);
		if(v==rt&&op==-1){
			val[v] = INF;
		}
		if(val[v]==0){
			val[v]=1;
		}
	//	printf("%lld %lld %lld %lld \n",v,rt,val[v],op);
	}
	return ;
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c = read(),T = read();
	while(T--){
		n = read(), m = read();
		up(t,1,m){
			char ch; scanf(" %c",&ch);
			if(ch == 'T'||ch == 'F'||ch == 'U'){
				int id=read();
				add(id,id+n,1,t);
				ind[id]++;
				if(ch == 'T')val[id+n]=1;
				if(ch == 'F')val[id+n]=-1;
				if(ch == 'U')val[id+n]=INF;
			}
			else if(ch == '-'){
				int v=read();
				int u=read();
				add(v,u,-1,t);
				ind[v]++;
			}
			else if(ch == '+'){
				int v=read();
				int u=read();
				add(v,u,1,t);
				ind[v]++;
			}
		}
		
		up(i,1,n){
			if(ind[i]!=0){
				rt=i;
				dfs(i,m+1,1);
			}
		}
		int ans=0;
		up(u,1,2*n){
			for(int i=head1[u];i;i=edge1[i].next){
				int v=edge1[i].to;
				val[v]=val[u]*edge1[i].op;
			//	printf("%lld %lld\n",u,val[u]);
			}			
		}
		up(u,1,n){
			if(val[u]==INF||val[u]==-INF){
				ans++;
			}			
		}
		printf("%lld\n",ans);
		cnt=0;
		cnt1=0;
		memset(val,0,sizeof(val));
		memset(head1,0,sizeof(head1));
		memset(head,0,sizeof(head));
	}
	return 0;
}

