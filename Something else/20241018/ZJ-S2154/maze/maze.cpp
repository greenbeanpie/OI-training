#include <bits/stdc++.h>
using namespace std;

namespace Main{
	#define int long long
	const int N=1e3+5,B=1e15,C=2*B+21;
	char mp[N][N];
	bool vis[N][N];
	int val[N][N],maximum[N][N];
	int n,m;
	int walk(int x,int y){
		memset(vis,0,sizeof(vis));
		int cur=0,maxv=val[x][y],flag=1;
		while(!vis[x][y]){
			vis[x][y]=1;
			cur+=flag*val[x][y];
			if(mp[x][y]=='<'){
				y-=1;
			}
			else if(mp[x][y]=='>'){
				y+=1;
			}
			else if(mp[x][y]=='^'){
				x-=1;
			}
			else{
				x+=1;
			}
			if(x<0||x>n||y<0||y>m){
				break;
			}
			maxv=max(maxv,cur);
			flag=-flag;
		}
		if(0<=x&&x<=n&&0<=y&&y<=m){
			while(vis[x][y]){
				vis[x][y]=0;
				cur-=flag*val[x][y];
				if(mp[x][y]=='<'){
					y-=1;
				}
				else if(mp[x][y]=='>'){
					y+=1;
				}
				else if(mp[x][y]=='^'){
					x-=1;
				}
				else{
					x+=1;
				}
				maxv=max(maxv,cur);
				flag=-flag;
			}
			cur-=flag*val[x][y];
			maxv=max(maxv,cur);
		}
		return maxv;
	}
	int quickpower(int a,int b){
		unsigned int  ans=1,base=a;
		while(b){
			if(b&1){
				ans*=base;
			}
			base*=base;
			b>>=1;
		}
		return ans;
	}
	int main(){
		cin >> n >> m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> mp[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> val[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				maximum[i][j]=walk(i,j);
			}
		}
		unsigned int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				sum+=(maximum[i][j]+B)*quickpower(C,(i-1)*m+j-1);
			}
		}
		cout << sum;
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	Main::main();
	return 0;
}
