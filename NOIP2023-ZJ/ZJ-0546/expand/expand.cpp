#include<bits/stdc++.h>
using namespace std;
#define MAXN 114514
int c,n,m,q;
int x[MAXN]={0},y[MAXN]={0};


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=m;i++)cin>>y[i];
	
	if(c==1){
		if(x[1]!=y[1])cout<<1;
		else cout<<0;
		while(q--){
			int xx[MAXN],yy[MAXN],xc,yc;
			memcpy(xx,x,sizeof(x));
			memcpy(yy,y,sizeof(y));
			cin>>xc>>yc;
			while(xc--){
				int p,v;
				cin>>p>>v;
				xx[p]=v;
			}
			while(yc--){
				int p,v;
				cin>>p>>v;
				yy[p]=v;
			}
			if(xx[1]!=yy[1])cout<<1;
			else cout<<0;
		}
	}else{
		if(x[1]>y[1]){
			int now=1,flg=1;
			for(int i=1;i<=n;i++){
				if(x[i]<=y[now]){
					flg=0;
					break;
				}
				while(x[i]>y[now]&&now<=m)now++;
				if(now>m)now--;
			}
			if(flg)cout<<1;
			else cout<<0;
			while(q--){
				int xx[MAXN],yy[MAXN],xc,yc;
				memcpy(xx,x,sizeof(x));
				memcpy(yy,y,sizeof(y));
				cin>>xc>>yc;
				while(xc--){
					int p,v;
					cin>>p>>v;
					xx[p]=v;
				}
				while(yc--){
					int p,v;
					cin>>p>>v;
					yy[p]=v;
				}
				
				/*for(int i=1;i<=n;i++)cout<<xx[i]<<' ';
				cout<<endl;
				for(int i=1;i<=m;i++)cout<<yy[i]<<' ';
				cout<<endl;*/
				
				int now=1,flg=1;
				for(int i=1;i<=n;i++){
					if(xx[i]<=yy[now]){
						flg=0;
						break;
					}
					while(xx[i]>yy[now]&&now<=m)now++;
					if(now>m)now--;
				}
				if(flg)cout<<1;
				else cout<<0;
			}
		}
	}
	
	return 0;
}
/*
3 3 3 3
8 6 9
1 7 4
1 0
3 0
0 2
1 8
3 5
1 1
2 8
1 7
*/