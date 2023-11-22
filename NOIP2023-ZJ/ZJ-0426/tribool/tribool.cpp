#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int n,m,T,o;
struct co {
	char type;
	int x,y;
};
vector <int> map[100050];
vector <co> command;
bool b[100005];//If x is 'U'
int vis[100005];//1T 2F 3U
char p[100050],c[100050];
void print(int x,int val) {
//	if(b[x]==val) return ;
	vis[x]=val;
	for(int i=0; i<map[x].size(); i++) {
		if(b[map[x][i]]!=val)
			print(map[x][i],val);
	}
	return ;
}
int minn=114514;
void dfs(int x) {
	if(x==n+1) {
		for(int i=1; i<=n; i++) {
			c[i]=p[i];
//			cout<<c[i];
		}
//		cout<<endl;
		for(int i=0; i<=m-1; i++) {
			if(command[i].type=='U') c[command[i].x]='U';
			if(command[i].type=='T') c[command[i].x]='T';
			if(command[i].type=='F') c[command[i].x]='F';
			if(command[i].type=='-')
				if(c[command[i].y]=='T')c[command[i].x]='F';
				else if(c[command[i].y]=='F')c[command[i].x]='T';
				else c[command[i].x]='U';
			if(command[i].type=='+') c[command[i].x]=c[command[i].y];
		}
//		for(int i=1; i<=n; i++) {
//			cout<<c[i];
//		}
//		cout<<endl<<endl;
		int sum=0;
		for(int i=1; i<=n; i++) {
			if(c[i]!=p[i]) return ;
			if(p[i]=='U') sum++;
		}
//		cout<<"OK"<<endl<<endl;
		minn=min(minn,sum);
		return ;
	}
	p[x]='U';
	dfs(x+1);
	p[x]='T';
	dfs(x+1);
	p[x]='F';
	dfs(x+1);

}
int main() {

	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>o>>T;
	while(T--) {
		memset(b,0,sizeof(b));
		cin>>n>>m;
		if(o>=7) {
			memset(vis,0,sizeof(vis));
			for(int i=1; i<=100000; i++) {
				map[i].clear();
			}
		}
		if(o<=2) {
			command.clear();
			minn=114514;
			for(int i=1; i<=m; i++) {
				char e;
				cin>>e;
				if(e=='T'||e=='U'||e=='F') {
					int x;
					cin>>x;
					command.push_back({e,x,-1});
				} else {
					int x,y;
					cin>>x>>y;
					command.push_back({e,x,y});
				}
			}
			dfs(1);
			cout<<minn<<endl;

		}
		if(o>=3&&o<=4) {
			int s=0;
			for(int i=1; i<=m; i++) {
				char e;
				cin>>e;
				if(e=='U') {
					int x;
					cin>>x;
					if(b[x]==0) s+=1;
					b[x]=1;
				} else {
					int x;
					cin>>x;
				}
			}
			cout<<s<<endl;
		}
//		if(o>=7&&o<=8) {
//			int s=0;
//			for(int i=1; i<=m; i++) {
//				char e;
//				cin>>e;
//				if(e=='+') {
//					int x,y;
//					cin>>x>>y;
//					if(vis[x]&&vis[y]){
//						if(vis[x]!=vis[y]) print(x,3); 
//					}
//				}
//			}
//		}
//		if(o>=5&&o<=6) {
//			int s=0;
//			for(int i=1; i<=m; i++) {
//				char e;
//				cin>>e;
//				if(e=='U') {
//					int x;
//					cin>>x;
//					print(x,1);
//				} else {
//					int x,y;
//					cin>>x>>y;
//					map[y].push_back(x);
//					map[x].push_back(y);
////					int t=b[y];
////					b[y]=1-b[y];
//					print(y,b[y]);
//
////					map[y].push_back(x);
//				}
//			}
////			for(int i=1;i<=n;i++){
////				if(b[i]){
////					b[i]=0;
////					print(i);
////				}
////			}
//			for(int i=1; i<=n; i++) {
//				if(b[i]) {
//					s++;
//				}
//			}
//			cout<<s<<endl;
//		}

	}
		fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
5 114514
4 4
+ 1 2
+ 2 3
U 3
+ 3 4
*/