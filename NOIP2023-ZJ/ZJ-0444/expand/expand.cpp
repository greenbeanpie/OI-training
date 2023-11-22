#include <bits/stdc++.h>
using namespace std;
#define wr(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
const int N=500100;
int read(){
	int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int c,n,m,q;
int a[N],b[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(c==1){
		int x,y,kx,ky,p,v;
		cin>>x>>y;
		if(x==y) cout<<0;
		else cout<<1;
		wr(i,1,q){
			kx=read();ky=read();
			wr(j,1,kx){
				p=read();v=read();
			}
			x=v;
			wr(j,1,ky){
				p=read();v=read();
			}
			y=v;
			if(x==y) cout<<0;
	    	else cout<<1;
		}
	}
	if(c>=8&&c<=14){
		wr(i,1,n) a[i]=read();
		wr(i,1,m) b[i]=read();
		int x,y,kx,ky,p,v;
		if(a[n]>=b[m]) cout<<0;
	    else cout<<1;
		wr(i,1,q){
			kx=read();ky=read();
			wr(j,1,kx){
				p=read();v=read();
				a[p]=v;
			}
			wr(j,1,ky){
				p=read();v=read();
				b[p]=v;
			}
			if(a[n]>=b[m]) cout<<0;
	    	else cout<<1;
		}
	}
	
	return 0;
}
/*
5 1
4 4 
+ 2 1
U 2
+ 3 2
+ 4 2
*/