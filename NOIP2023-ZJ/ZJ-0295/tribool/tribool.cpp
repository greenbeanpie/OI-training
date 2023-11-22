#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int c,t,n,m,now[N],cnt,x[N],y[N],in[N],a[N],ans,b[N];
char s[N][1];
void dfs(int t){
	if(t>n){
		bool flag=1;
		for(int i = 1; i <= n; i++) b[i]=a[i];
		for(int i = 1; i <= m; i++){
			if(s[i][0]=='+'){
				b[x[i]]=b[y[i]];
			}else if(s[i][0]=='-'){
				if(b[y[i]]==2) b[x[i]]=b[y[i]];
				else b[x[i]]=1-b[y[i]];
			}else{
				if(s[i][0]=='T') b[x[i]]=1;
				if(s[i][0]=='F') b[x[i]]=0;
				if(s[i][0]=='U') b[x[i]]=2;
			}
		}
		for(int i = 1; i <= n; i++)
			if(b[i]!=a[i]){
				flag=0;
				break;
			}
		if(flag){
			int cnt=0;
			for(int i = 1; i <= n; i++) cnt+=(a[i]==2);
			ans=min(ans,cnt);
		}
		return;
	}
	for(int i = 0; i < 3; i++){
		a[t]=i;
		dfs(t+1);
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d", &c, &t);
	while(t--){
		scanf("%d%d", &n, &m);
		cnt=n;
		ans=1e9+5;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i = 1; i <= n; i++) now[i]=i;
		for(int i = 1; i <= m; i++){
			scanf("%s%d", s[i],&x[i]);
			if(s[i][0]=='+' || s[i][0]=='-') scanf("%d", &y[i]);
		}
		if(n<=10){
			dfs(1);
			printf("%d\n", ans);
		}else if(c==3 || c==4){
			for(int i = 1; i <= m; i++){
				if(s[i][0]=='T') b[i]=1;
				else if(s[i][0]=='F') b[i]=0;
				else b[i]=2;
			}
			int tot=0;
			for(int i = 1; i <= n; i++) tot+=(b[i]==2);
			printf("%d\n", tot);
		}
	}
	return 0;
}
