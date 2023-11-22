#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,m,k,j,l,c1,T,ans[N],ans1;
char c;
struct node{
	int x;
	int	v=-1;
}a[N];
void dfs(int x,int wx){
	if (wx>=ans1) return;
	if (x==n+1){
		for (int i=1;i<=n;i++){
			if (a[i].v==0){
				int val;
				if (a[i].x<0)	val=-ans[-a[i].x];else val=ans[a[i].x];
				if (abs(val)==2&&abs(ans[i])==2) continue;
				if (val!=ans[i]) return;
			}
		}
		/*for (int i=1;i<=n;i++)
			cout<<ans[i]<<' ';cout<<endl;*/
		ans1=min(ans1,wx);
		return;
	}
	if (a[x].v!=0){
		ans[x]=a[x].v;
		if (a[x].v==1||a[x].v==-1)	dfs(x+1,wx);else dfs(x+1,wx+1);
	}else{
		ans[x]=1;
		dfs(x+1,wx);
		ans[x]=-1;dfs(x+1,wx);ans[x]=-2;dfs(x+1,wx+1);
	}
	
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c1,&T);
	
	while(T--){
		ans1=N;scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			a[i].x=i,a[i].v=0;
		for (int i=1;i<=m;i++){
			int x,y;
			cin>>c;
			//cout<<c;
			if (c=='+'){
				scanf("%d%d",&x,&y);
				a[x].x=a[y].x,a[x].v=a[y].v;
			}else if (c=='-'){
				scanf("%d%d",&x,&y);
				a[x].x=-a[y].x;
				a[x].v=-a[y].v;
			}else{
				scanf("%d",&x);
				if (c=='T')	a[x].v=1;else if (c=='F') a[x].v=-1;else a[x].v=-2;
			}
		}
		/*for (int i=1;i<=n;i++)
			cout<<a[i].x<<' '<<a[i].v<<endl;*/
		if (c1<=2||c1>=5){
			
			dfs(1,0);
			printf("%d\n",ans1);
		}else if (c1==3||c1==4){
			int ans3=0;
			for (int i=1;i<=n;i++)
				if (abs(a[i].v)==2) ans3++;
			printf("%d\n",ans3);
		}
	}
	
	return 0;
}
