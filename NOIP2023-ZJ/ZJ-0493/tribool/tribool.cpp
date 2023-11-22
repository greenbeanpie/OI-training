#include<bits/stdc++.h>

using namespace std;

const int N=100005;

inline int read(){
	int t=1,x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') t=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return t*x;
}

int c,t;
int n,m;
int a[N];
struct node{
	char ch;
	int x,y;
}s[N];
char w[N],p[N];
int ans;
bool be[N];
struct nodel{
	int to,next,value;
}edge[N];
int head[N],tot;

char back(char x){
	if(x=='F') return 'T';
	if(x=='T') return 'F';
	return 'U';
}

bool check(){
	for(int i=1;i<=m;i++){
		char op=s[i].ch;
		if(op=='+' || op=='-'){
			int l=s[i].x,r=s[i].y;
			if(op=='+') p[l]=p[r];
			else p[l]=back(p[r]);
		}
		else{
			int x=s[i].x;
			p[x]=op;
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i]!=w[i]) return 0;
	}
	return 1;
}

void dfs(int x,int res){
	if(x>n){
		for(int i=1;i<=n;i++) p[i]=w[i];
		if(check()) ans=min(ans,res);
		return ;
	}
	w[x]='T';
	dfs(x+1,res);
	w[x]='F';
	dfs(x+1,res);
	w[x]='U';
	dfs(x+1,res+1);
}

void add(int x,int y,int v){
	tot++;
	edge[tot].to=y;
	edge[tot].next=head[x];
	edge[tot].value=v;
	head[x]=tot;
}

void find(int x,int res,int siz){
	for(int i=head[x];i;i=edge[i].next){
		int xx=edge[i].to;
		if(be[xx]){
			int now=res;
			if(edge[i].value==-1) now^=1;
			if(now==1) ans+=siz;
			continue;
		}
		else{
			be[xx]=1;
			if(edge[i].value==-1) find(xx,res^1,siz+1);
			else find(xx,res,siz+1);
		}
	}
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=1e9;
		n=read(),m=read();
		int pd1=0,pd2=0,pd3=1,pd4=1;
		for(int i=1;i<=m;i++){
			cin>>s[i].ch;
			if(s[i].ch=='+' || s[i].ch=='-'){
				pd2=1;
				if(s[i].ch!='+') pd4=0;
				s[i].x=read();
				s[i].y=read();
			}
			else{
				pd1=1;
				if(s[i].ch!='U') pd3=0;
				s[i].x=read();
			}
		}
		if(n<=10 && m<=10){
			dfs(1,0);
		}
		else if(pd1 && !pd2){
			for(int i=m;i>=1;i--){
				char op=s[i].ch;
				int x=s[i].x;
				if(!be[x]){
					be[x]=1;
					w[x]=op;
				}
			}
			for(int i=1;i<=n;i++){
				if(!be[i]) w[i]='T';
				else be[i]=0;
				w[i]=' ';
			}
			ans=0;
			for(int i=1;i<=n;i++){
				if(w[i]=='U') ans++;
			}
		}
		else if(!pd1 && pd2){
			ans=0;
			for(int i=1;i<=tot;i++) edge[i].to=edge[i].next=edge[i].value=0;
			for(int i=1;i<=n;i++) be[i]=head[i]=0;
			tot=0;
			for(int i=1;i<=m;i++){
				char op=s[i].ch;
				int x=s[i].x,y=s[i].y;
				if(x==y){
					if(op=='-') ans++;
					continue;
				}
				else{
					if(op=='+') add(y,x,1);
					else add(y,x,-1);
				}
			}
			for(int i=1;i<=n;i++){
				if(!be[i]){
					be[i]=1;
					find(i,0,1);
				}
				//cout<<ans<<endl;
			}
		}
		else if(pd3 && pd4){
			ans=0;
			for(int i=1;i<=m;i++){
				char op=s[i].ch;
				int x=s[i].x;
				if(op=='U'){
					w[x]='U';
				}
				else{
					int y=s[i].y;
//					w[x]=w[y];
					if(w[y]=='U') w[x]='U';
					else if(w[x]=='U'){
						w[x]=' ';
						ans++;
					}
				}
			}
			for(int i=1;i<=n;i++){
				//cout<<w[i]<<"";
				if(w[i]=='U') ans++;
				w[i]=' ';
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
