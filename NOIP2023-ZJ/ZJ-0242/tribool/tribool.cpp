#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,inf=0x3f3f3f3f;
//bool be;
int cas,T,n,m;
namespace K1{
	int op[15],x[15],y[15],a[15],b[15],ans;
	void dfs(int p){
		if(p>n){
			int res=0;
			for(int i=1;i<=n;i++){
				b[i]=a[i];
				if(b[i]==2)res++;
			}
			for(int i=1;i<=m;i++){
				if(op[i]==0)b[x[i]]=0;
				if(op[i]==1)b[x[i]]=1;
				if(op[i]==2)b[x[i]]=2;
				if(op[i]==3)b[x[i]]=b[y[i]];
				if(op[i]==4){
					if(b[y[i]]==0)b[x[i]]=1;
					else if(b[y[i]]==1)b[x[i]]=0;
					else if(b[y[i]]==2)b[x[i]]=2;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]!=b[i])return;
			}
			ans=min(ans,res);
			return;
		}
		for(int i=0;i<=2;i++){
			a[p]=i;
			dfs(p+1);
		}
		return;
	}
	void main(){
		while(T--){
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				char s[5];
				scanf("%s%d",s,&x[i]);
				if(s[0]=='F')op[i]=0;
				if(s[0]=='T')op[i]=1;
				if(s[0]=='U')op[i]=2;
				if(s[0]=='+'){
					op[i]=3;
					scanf("%d",&y[i]);
				}
				if(s[0]=='-'){
					op[i]=4;
					scanf("%d",&y[i]);
				}
			}
			ans=inf;
			dfs(1);
			printf("%d\n",ans);
		}
		exit(0);
	}
}
namespace K2{
	int a[N];
	void main(){
		while(T--){
			scanf("%d%d",&n,&m);
			memset(a,0,sizeof a);
			for(int i=1;i<=m;i++){
				char s[5];
				int x;
				scanf("%s%d",s,&x);
				if(s[0]=='F')a[x]=0;
				if(s[0]=='T')a[x]=1;
				if(s[0]=='U')a[x]=2;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2)ans++;
			}
			printf("%d\n",ans);
		}
		exit(0);
	}
}
namespace K3{
	int a[N],op[N],x[N],y[N];
	void solve(){
		for(int i=1;i<=m;i++){
			if(op[i]==0)a[x[i]]=1;
			if(op[i]==1)a[x[i]]=a[y[i]];
		}
		return;
	}
	void main(){
		while(T--){
			scanf("%d%d",&n,&m);
			memset(a,0,sizeof a);
			for(int i=1;i<=m;i++){
				char s[5];
				scanf("%s%d",s,&x[i]);
				if(s[0]=='U')op[i]=0;
				if(s[0]=='+'){
					op[i]=1;
					scanf("%d",&y[i]);
				}
			}
			int up=100;
			if(n<=1000)up=1000;
			for(int i=1;i<=up;i++){
				solve();
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
			}
			printf("%d\n",ans);
		}
		exit(0);
	}
}
namespace K4{
	int op[N],x[N],y[N],a[N],b[N],mark[N][3];
	void solve(){
		memcpy(b,a,sizeof b);
		for(int i=1;i<=m;i++){
			if(op[i]==0)a[x[i]]=0;
			if(op[i]==1)a[x[i]]=1;
			if(op[i]==2)a[x[i]]=2;
			if(op[i]==3)a[x[i]]=a[y[i]];
			if(op[i]==4){
				if(a[y[i]]==0)a[x[i]]=1;
				else if(a[y[i]]==1)a[x[i]]=0;
				else if(a[y[i]]==2)a[x[i]]=2;
			}
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=b[i]&&a[i]!=2&&b[i]!=2)mark[i][a[i]]++;
			if(mark[i][a[i]]>=5&&a[i]!=2)a[i]=2,flag=1;
		}
		if(flag)memset(mark,0,sizeof mark);
		return;
	}
	void main(){
		while(T--){
			scanf("%d%d",&n,&m);
			memset(a,0,sizeof a);
			memset(mark,0,sizeof mark);
			for(int i=1;i<=m;i++){
				char s[5];
				scanf("%s%d",s,&x[i]);
				if(s[0]=='F')op[i]=0;
				if(s[0]=='T')op[i]=1;
				if(s[0]=='U')op[i]=2;
				if(s[0]=='+'){
					op[i]=3;
					scanf("%d",&y[i]);
				}
				if(s[0]=='-'){
					op[i]=4;
					scanf("%d",&y[i]);
				}
			}
			int up=100;
			if(n<=1000)up=1000;
			for(int i=1;i<=up;i++){
				solve();
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]==2)ans++;
			}
			printf("%d\n",ans);
		}
		exit(0);
	}
}
//bool en;
int main(){
//	printf("%d\n",(&en-&be)/1024/1024);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&cas,&T);
	if(cas<=2)K1::main();
	if(3<=cas&&cas<=4)K2::main();
	if(5<=cas&&cas<=6)K3::main();
	K4::main();
	return 0;
}