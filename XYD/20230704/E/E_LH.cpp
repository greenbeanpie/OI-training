#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mod 1000000009
using namespace std;
int n,ma[102][102],cnt,h[102][102],movx[4]={1,-1,0,0},movy[4]={0,0,1,-1},d[102][102],way[102][102];
bool vis[102][102];
struct edge{
	int vx,vy,w,nxt;
}e[40002];
struct ele{
	int dist,x,y;
	bool operator >(const ele& other)const{
		return dist > other.dist;
	}
};

void Dijkstra(){
	priority_queue<ele,vector<ele>,greater<ele> > q;
	q.push({0,0,0});
	way[0][0] = 1;
	while(!q.empty()){
		ele t = q.top();
		q.pop();
		vis[t.x][t.y] = 1;
		for(int i=h[t.x][t.y];~i;i=e[i].nxt){
			int tx = e[i].vx,ty = e[i].vy;
			if(!vis[tx][ty] && d[tx][ty]>=d[t.x][t.y]+e[i].w){
				if(d[tx][ty]==d[t.x][t.y]+e[i].w){
					way[tx][ty] += way[t.x][t.y];
					if(way[tx][ty]>=mod)	way[tx][ty] -= mod;
				}else{
					d[tx][ty] = d[t.x][t.y]+e[i].w;
					way[tx][ty] = way[t.x][t.y];
					q.push({d[tx][ty],tx,ty});
				}
//				cout << t.x << ' ' << t.y << ' ' << tx << ' ' << ty << ' ' << d[tx][ty] << ' ' << way[tx][ty] << '\n';
			}
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("E.in","r",stdin);
		freopen("E_LH.out","w",stdout);
	#endif
	while(cin>>n){
		if(n==0)	return 0;
		memset(d,0x3f,sizeof(d));	d[0][0] = 0;
		memset(vis,0,sizeof(vis));	cnt = 0;
		memset(h,-1,sizeof(h));	
		memset(way,0,sizeof(way));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin >> ma[j][i];
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=n-i;j++){
				ma[j][i] += ma[n+1-i][n+1-j];
			}
		}
		e[cnt] = {1,1,ma[1][1],h[0][0]};
		h[0][0] = cnt++;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n-i;j++){
				for(int k=0;k<4;k++){
					int tx = j+movx[k],ty = i+movy[k];
					if(tx>0 && tx<=n && ty>0 && ty<=n && tx+ty<=n+1){
						e[cnt] = {tx,ty,ma[tx][ty],h[j][i]};
						h[j][i] = cnt++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			e[cnt] = {n+1,n+1,0,h[i][n+1-i]};
			h[i][n+1-i] = cnt++;
		}
		Dijkstra();
		cout << way[n+1][n+1] << '\n';
	}

	return 0;
}
