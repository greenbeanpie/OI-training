#include<bits/stdc++.h>
using namespace std;
int n,m,fa[200005],Fa[200005],a[100005],ans;
//200001 T 200002 F 200003 U
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);}
int getFa(int x){return x==Fa[x]?x:Fa[x]=getFa(Fa[x]);}
int R(char x){
	if(x=='T')return 200001;
	if(x=='F')return 200002;
	if(x=='U')return 200003;
	return 0;
}
int f(int x){
	int res=0;
	if(x==200001)res=200002;
	if(x==200002)res=200001;
	if(x==200003)res=200003;
	if(x>=1&&x<=n)res=x+n;
	if(x>n&&x<=2*n)res=x-n;
	return res;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T,i;
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		ans=0;
		fa[200001]=Fa[200001]=200001;
		fa[200002]=Fa[200002]=200002;
		fa[200003]=Fa[200003]=200003;
		for(i=1;i<=2*n;i++)fa[i]=Fa[i]=i;
		for(i=1;i<=n;i++)a[i]=i;
		for(i=1;i<=m;i++){
			char op;
			int x,y;
			scanf("%c",&op);
			while(op!='-'&&op!='+'&&op!='T'&&op!='F'&&op!='U'){
				scanf("%c",&op);
			}
			if(op=='T'||op=='F'||op=='U'){
				scanf("%d",&x);
				a[x]=R(op);
			}
			if(op=='+'){
				scanf("%d%d",&x,&y);
				a[x]=a[y];
			}
			if(op=='-'){
				scanf("%d%d",&x,&y);
				a[x]=f(a[y]);
			}
		}
		for(i=1;i<=n;i++){
			int x=getfa(i),y=getfa(a[i]);
			fa[x]=y;
			x=getFa(i);
			y=getFa(a[i]);
			Fa[x]=y;
			Fa[getFa(i)]=getFa(i+n);
			int u=getfa(f(a[i])),v=getfa(i+n);
			fa[u]=v;
			u=getFa(f(a[i])),v=getFa(i+n);
			Fa[u]=v;
		}
		for(i=1;i<=n;i++){
			if(getfa(i)==getfa(i+n)){
				Fa[getFa(i)]=getFa(200003);
			}
		}
		for(i=1;i<=n;i++)if(getFa(i)==getFa(200003))ans++;
		printf("%d\n",ans);
	}
	return 0;
}