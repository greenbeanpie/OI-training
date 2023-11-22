//      %%%
//sto shawryao orz
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
#define tc t[i][cur]
#define tl tc.l
#define tr tc.r
#define ls cur<<1
#define rs cur<<1|1
#define tll t[i][ls]
#define trr t[i][rs]
#define pushup tc.mi=min(tll.mi,trr.mi),tc.mx=max(tll.mx,trr.mx),tc.left=tll.left,tc.right=trr.right
//#define mxx t[0][1].mx
#define mix t[0][1].mi
#define mxy t[1][1].mx
#define miy t[1][1].mi
//#define f ((t[0][1].mx-mxy)*(mix-miy))>0
int c,q;
int n[2];
int yuan[2][N];
int idx[2];
struct ch{
	int x,val;
}a[2][N];
struct tree{
	int l,r,mi,mx,left,right;
}t[2][4*N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-f;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void build(int i,int cur,int l,int r){
	tl=l,tr=r;
	if (tl==tr){
		tc.left=tc.right=tc.mx=tc.mi=read();
		yuan[i][++idx[i]]=tc.mx;
		return ;
	}
	int mid=(l+r)>>1;
	build(i,ls,l,mid);
	build(i,rs,mid+1,r);
	pushup;
}
void update(int i,int cur,int x,int val){
	if (tl==tr){
		tc.left=tc.right=tc.mi=tc.mx=val;
		return ;
	}
	int mid=(tl+tr)>>1;
	if (mid>=x) update(i,ls,x,val);
	else update(i,rs,x,val);
	pushup;
}
void write(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n[0]=read(),n[1]=read(),q=read();
	build(0,1,1,n[0]);
	build(1,1,1,n[1]);
	int x=0,y=1;
//	printf("%d %d %d %d\n",t[0][1].mx,mix,mxy,miy);
	write(((1ll*(t[0][1].mx-mxy)*(mix-miy))>0)&&(1ll*(t[x][1].left-t[y][1].left)*(t[x][1].right-t[y][1].right)>0));
//	putchar('\n');
	while (q--){
		int k[2];
		k[x]=read(),k[y]=read();
		for (int i=1;i<=k[x];i++){
			int p=read(),v=read();
			a[x][i]={p,yuan[x][p]};
			update(x,1,p,v);
		}
		for (int i=1;i<=k[y];i++){
			int p=read(),v=read();
			a[y][i]={p,yuan[y][p]};
			update(y,1,p,v);
		}
//		printf("%d %d %d %d\n",t[0][1].mx,mix,mxy,miy);
		write(((1ll*(t[x][1].mx-mxy)*(mix-miy))>0)&&(1ll*(t[x][1].left-t[y][1].left)*(t[x][1].right-t[y][1].right)>0));
//		putchar('\n');
		for (int i=1;i<=k[x];i++) update(x,1,a[x][i].x,a[x][i].val);
		for (int i=1;i<=k[y];i++) update(y,1,a[y][i].x,a[y][i].val);
	}
	return 0;
}
