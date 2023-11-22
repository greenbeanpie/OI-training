#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7fffffff
const int maxn=1e5+5;
int opt,T;
int n,m,ans;
bool f=false;
char a[maxn],b[maxn];
struct node{
	char c;
	int x,y;
}d[15];
char fei(char x){
	if(x=='T') return 'F';
	if(x=='F') return 'T';
	return 'U';
}
void chk(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		if(a[i]=='U'){
			cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		if(d[i].c=='+'){
			b[d[i].x]=b[d[i].y];
		}else if(d[i].c=='-'){
			b[d[i].x]=fei(b[d[i].y]);
		}else{
			b[d[i].x]=d[i].c;
		}
	}
	bool g=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			g=false;
			break;
		}
	}
	if(g){
		ans=cnt;
		f=true;
	}
}
void dfs(int u){
	if(f){
		return;	
	}
	if(u==n+1){
		chk();
		return;
	}
	a[u]='T';
	dfs(u+1);
	a[u]='F';
	dfs(u+1);
	a[u]='U';
	dfs(u+1);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
    cin.tie(0),cout.tie(0);
	cin>>opt>>T;
	if(opt>=1&&opt<=2){
		while(T--){
			f=false;
			cin>>n>>m;
			char o;
			int x,y;
			for(int i=1;i<=m;i++){
				cin>>o;
				if(o=='+'||o=='-'){
					cin>>x>>y;
					d[i].c=o,d[i].x=x,d[i].y=y;
				}else{
					cin>>x;
					d[i].c=o,d[i].x=x;
				}
			}
			dfs(1);
			cout<<ans<<endl;
		}
	}else if(opt>=3&&opt<=4){
		while(T--){
			cin>>n>>m;
			char o;
			int x;
			while(m--){
				cin>>o>>x;
				a[x]=o;
			}
			for(int i=1;i<=n;i++){
				if(a[i]=='U'){
					ans++;
				}
				a[i]=' ';
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}