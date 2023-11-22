#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int tt,t,n,m,a[N],x,y,ans,s[N];
char c;

int dfs(int i){
//	cout<<i<<" ";
	if(s[i]) return i;
	if(a[i]==-i||a[i]==0) return a[i]=0;
	if(a[i]==i||a[i]==n+1||a[i]==-n-1) return a[i];
	s[i]=1;
	if(a[i]<0) return a[i]=-dfs(-a[i]),s[i]=0,a[i]; else return a[i]=dfs(a[i]),s[i]=0,a[i];
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>tt>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) a[i]=i;
		while(m--){
			getchar(),scanf("%c%d",&c,&x);
			if(c=='+') scanf("%d",&y),a[x]=a[y];
			else if(c=='-') scanf("%d",&y),a[x]=-a[y];
			else a[x]=(c=='U')?0:(c=='T')?n+1:-n-1;
		}
		for(int i=1;i<=n;i++) dfs(i);
		for(int i=1;i<=n;i++) if(!a[i]) ans++;
//		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<ans<<"\n",ans=0;
	}
}
