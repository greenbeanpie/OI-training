#include<bits/stdc++.h>
using namespace std;
#define pd push_back
#define all(x) x.begin(),x.end()
#define allA(x,l,r) x+l,x+r+1
#define mpr make_pair
int n,m,q;
const int N=5e5+10;
vector<array<int,2> > c1,c2;
int A[N],B[N];
int id;
namespace As{
	bool f[2010][2010];
	void solve(){
		int pos=1;
		if(A[1]==B[1]){putchar('0');return;}
		int ft=(A[1]>B[1]?1:-1);
		memset(f,false,sizeof(f));
		f[1][1]=true;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(A[i]*ft>B[j]*ft)
					f[i][j]|=f[i][j-1],f[i][j]|=f[i-1][j];
				//f[i][j]|=f[i-1][j];
			}
		putchar(f[n][m]?'1':'0');
	}
}
namespace Bs{
	void solve(){
	/*	for(int i=1;i<=n;i++)
			if(A[i]>=B[min(i,m)]){
				putchar('0');
				return;
			}*/
		int pos=2;
		for(int i=1;i<=n;i++){
			int pre=pos;
			while(pos<m&&A[i]<B[pos])pos++;
			if(pos==m)break;
			if(pos!=pre){
				putchar('0');
				return;
			}
		}
		putchar(pos==m?'1':'0');
	}
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&id,&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&A[i]);
	for(int i=1;i<=m;i++)scanf("%d",&B[i]);
	if(id<=7)As::solve();
	else if(id<=14)Bs::solve();
	while(q--){
		
		int kx,ky;scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++){
			int x,y;scanf("%d%d",&x,&y);
			c1.pd({x,A[x]});A[x]=y;
		}for(int i=1;i<=ky;i++){
			int x,y;scanf("%d%d",&x,&y);
			c2.pd({x,B[x]});B[x]=y;
		}
		if(id<=7)As::solve();
		else if(id<=14)Bs::solve();
		reverse(all(c1));
		reverse(all(c2));
		for(auto y:c1)A[y[0]]=y[1];
		for(auto y:c2)B[y[0]]=y[1];
		c1.clear();c2.clear();
	}
	return 0;
}
/*
6 5 5 0
3 7 4 7 1
4 4 3 4 8

*/
