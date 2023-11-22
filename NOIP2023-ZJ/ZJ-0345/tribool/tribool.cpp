#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,ans,q[100005],hed,til,du[100005],s[100005];
struct RP{
	int x,y;
};
vector<RP> e[100005];
bool vis[100005];
char a[100005];
int read(){
	int ret=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
	memset(a,'#',sizeof a);
	if(c==3||c==4) while(t--){
		memset(a,'#',sizeof a);
		n=read(),m=read();ans=0;
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='U'&&ch!='T'&&ch!='F') ch=getchar();
			int x=read();
			a[x]=ch;
		}
		for(int i=1;i<=n;i++) if(a[i]=='U') ans++;
		printf("%d\n",ans);
	}else while(t--){
		n=read(),m=read();ans=0;
		for(int i=1;i<=m;i++){
			char ch=getchar();
			while(ch!='-'&&ch!='+'&&ch!='U'&&ch!='T'&&ch!='F') ch=getchar();
			int x=read();;
			if(isalpha(ch)){a[x]=ch;continue;}
			int y=read();
			if(ch=='-'&&(a[y]=='T'||a[y]=='F')){
				if(a[y]=='T') a[x]='F';else a[x]='T';
			}else a[x]=a[y];
			if(x==y) continue;
			if(ch=='-') e[y].push_back((RP){x,-1}),du[y]++;else e[y].push_back((RP){x,1}),du[y]++;
		}
//		for(int i=1;i<=e[10].size();i++) printf("%d-1\n",e[10][i].x);
		til=hed=0;
		for(int i=1;i<=n;i++) if(a[i]=='U') ans++,vis[i]=1,q[++til]=i;
		while(til!=hed){
			hed++;
			for(auto i:e[q[hed]]){
//				printf("%d %d-1\n",q[hed],i.x);
				if(vis[i.x]) continue;
				if(a[i.x]=='#') ans++;
				vis[i.x]=1,q[++til]=i.x;
			}
		}
		til=hed=0;
		for(int i=1;i<=n;i++) if(du[i]==1) q[++til]=i;
		while(til!=hed){
			hed++;
			s[q[hed]]++;
			for(auto i:e[q[hed]]){
				if(i.y==1) continue;
				if(s[i.x]){
					if((s[q[hed]]-s[i.x])%2==0) ans+=s[q[hed]]-s[i.x]+1;
					continue;
				}
				s[i.x]+=s[q[hed]];
				q[++til]=i.x;
			}
		}
		for(int i=1;i<=n;i++){
			vector<RP> ls;
//			ls.clear();
			swap(e[i],ls);vis[i]=0,a[i]='#',du[i]=s[i]=0;
		}
		printf("%d\n",ans);
	}
//	printf("\n%lf\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}
