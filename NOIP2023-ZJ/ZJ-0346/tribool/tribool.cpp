#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,m,val[N],jcnt[N];
char s[N];bool vis[N];
int find(int f){
	int x=val[f];vis[f]=1;
	bool fl=0;
	if(x<0) return x;
	if(x==f) return -1;
	if(x==f+n) return -3;
	if(x>=n) fl=1,x-=n;
	if(vis[x]){
		if(val[x]<0) return val[x];
		if(fl) jcnt[f]++;
		if((jcnt[f]-jcnt[x])%2==0) return -1;
		else return -3;
	}else{
		jcnt[x]=jcnt[f];
		if(fl) jcnt[x]++;
		val[x]=find(x);
	}
	if(val[x]==-1){
		if(fl) return -2;
		else return -1;
	}else if(val[x]==-2){
		if(fl) return -1;
		else return -2;
	}else return -3;
}
void work(){
	cin>>n>>m;int ans=0;memset(vis,0,sizeof vis);memset(jcnt,0,sizeof jcnt);
	for(int i=0;i<n;i++) val[i]=i;
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		if(s[0]=='+'){
			int a,b;
			scanf("%d%d",&a,&b);a--;b--;
			val[a]=val[b];
			
		}else if(s[0]=='-'){
			int a,b;
			scanf("%d%d",&a,&b);a--;b--;
			if(val[b]==-3) val[a]=-3;
			else if(val[b]==-2) val[a]=-1;
			else if(val[b]==-1) val[a]=-2;
			else val[a]=(val[b]+n)%(2*n);
		}else{
			int x;scanf("%d",&x);x--;
			if(s[0]=='T') val[x]=-1;
			else if(s[0]=='F') val[x]=-2;
			else{
				val[x]=-3;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			val[i]=find(i);
		}
	}
	for(int i=0;i<n;i++){
		if(val[i]==-3) ans++;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;scanf("%d%d",&c,&t);
	while(t--){
		work();
	}return 0;
}