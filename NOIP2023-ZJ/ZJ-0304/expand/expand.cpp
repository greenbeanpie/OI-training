#include <bits/stdc++.h>
using namespace std;

long long x[500010];
long long y[500010];
int opt[500010];
int tox,toy;

bool check(int endx,int endy){
	if(x[1]>y[1]){
		int nw=1;
		int nw2=1;
		for(int i=1;i<=endx+endy;i++){
			if(opt[i]==0){
				nw++;
			}else{
				nw2++;
			}
			if(x[nw]<=y[nw2]){
				return 0;
			}
		}
	}else if(x[1]<y[1]){
		int nw=1;
		int nw2=1;
		for(int i=1;i<=endx+endy;i++){
			if(opt[i]==0){
				nw++;
			}else{
				nw2++;
			}
			if(x[nw]>=y[nw2]){
				return 0;
			}
		}
	}else{
		return 0;
	}
	return 1;
}

bool dfs(int nw,int endx,int endy,int tox,int toy){
	if(tox==endx && toy==endy){
		return check(endx,endy);
	}
	bool ans=0;
	if(tox==endx){
		opt[nw]=1;
		return dfs(nw+1,endx,endy,tox,toy+1);
	}else if(toy==endy){
		opt[nw]=0;
		return dfs(nw+1,endx,endy,tox+1,toy);
	}else{
		opt[nw]=0;
		ans=ans || dfs(nw+1,endx,endy,tox+1,toy);
		opt[nw]=1;
		ans=ans || dfs(nw+1,endx,endy,tox,toy+1);
		opt[nw]=0;
	}
	return ans;
}

int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q;
	cin >> c >> n >> m >> q;
	if(c==1 || c==2){
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<=m;i++){
			cin >> y[i];
		}
		if(n==1 && m==1){
			if(x[1]==y[1]){
				cout << 0;
			}else{
				cout << 1;
			}
		}
		if(n==2 && m==2){
			if(x[1]<y[1] && x[2]<y[2]){
				cout << 1;
			}else if(x[1]>y[1] && x[2]>y[2]){
				cout << 1;
			}else{
				cout << 0;
			}
		}
		if(n==1 && m==2){
			if(x[1]<y[1] && x[1]<y[2]){
				cout << 1;
			}else if(x[1]>y[1] && x[1]>y[2]){
				cout << 1;
			}else{
				cout << 0;
			}
		}
		if(n==2 && m==1){
			if(x[1]<y[1] && x[2]<y[1]){
				cout << 1;
			}else if(x[1]>y[1] && x[2]>y[1]){
				cout << 1;
			}else{
				cout << 0;
			}
		}
		while(q--){
			int kx,ky;
			cin >> kx >> ky;
			for(int i=0;i<kx;i++){
				int px,vx;
				cin >> px >> vx;
				x[px]=vx;
			}
			for(int i=0;i<ky;i++){
				int px,vx;
				cin >> px >> vx;
				y[px]=vx;
			}
			if(n==1 && m==1){
				if(x[1]==y[1]){
					cout << 0;
				}else{
					cout << 1;
				}
			}
			if(n==2 && m==2){
				if(x[1]<y[1] && x[2]<y[2]){
					cout << 1;
				}else if(x[1]>y[1] && x[2]>y[2]){
					cout << 1;
				}else{
					cout << 0;
				}
			}
			if(n==1 && m==2){
				if(x[1]<y[1] && x[1]<y[2]){
					cout << 1;
				}else if(x[1]>y[1] && x[1]>y[2]){
					cout << 1;
				}else{
					cout << 0;
				}
			}
			if(n==2 && m==1){
				if(x[1]<y[1] && x[2]<y[1]){
					cout << 1;
				}else if(x[1]>y[1] && x[2]>y[1]){
					cout << 1;
				}else{
					cout << 0;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		for(int i=1;i<=m;i++){
			cin >> y[i];
		}
		tox=0;
		toy=0;
		cout << dfs(1,n-1,m-1,0,0);
		while(q--){
			memset(opt,0,sizeof(opt));
			int kx,ky;
			cin >> kx >> ky;
			for(int i=0;i<kx;i++){
				int px,vx;
				cin >> px >> vx;
				x[px]=vx;
			}
			for(int i=0;i<ky;i++){
				int px,vx;
				cin >> px >> vx;
				y[px]=vx;
			}
			cout << dfs(1,n-1,m-1,0,0);
		}
	}
	return 0;
}