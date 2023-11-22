#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N],b[N],c,q;
int qa,qb,na[N],nb[N],fa[N][33],fb[N][33];
void init(){
	for(int i=1;i<=n;i++) na[i]=a[i];
	for(int j=1;j<=m;j++) nb[j]=b[j];
}
void iinit(){
	for(int i=1;i<=n;i++) fa[i][0]=a[i];
	for(int k=1;k<=int(log2(n));k++){
		for(int j=1;j<=n-(1<<k)+1;j++){
			fa[j][k]=min(fa[j][k-1],fa[j+(1<<k-1)][k-1]);
		}
	}
}
int aska(int l,int r){
	int mi=1e9;
	for(int i=l;i<=r;i++) mi=min(na[i],mi);
	return mi;
}
int askb(int l,int r){
	int mi=1e9;
	for(int i=l;i<=r;i++) mi=min(mi,nb[i]);
	return mi;
}
void print(){
	cout<<endl;
	for(int i=1;i<=n;i++) cout<<na[i]<<" ";cout<<endl;
	for(int j=1;j<=m;j++) cout<<nb[j]<<" ";cout<<endl;
}
int pan(){
	int ans1=1,ans2=1;
	for(int i=1,j=1;i<=n;i++){
		int ji=i,jj=j;
		while(jj<m&&na[ji]>nb[jj]) jj++;
		while(ji<n&&na[ji]<=nb[jj]) ji++;
		if(aska(i,ji)>askb(j,jj)) i=ji,j=min(m,jj+1);
		else ans1=0;
	}
	for(int i=1,j=1;i<=n;i++){
		int ji=i,jj=j;
		while(jj<m&&nb[ji]>na[jj]) jj++;
		while(ji<n&&nb[ji]<=na[jj]) ji++;
		if(askb(i,ji)>aska(j,jj)) i=ji,j=min(m,jj+1);
		else ans2=0;
	}if(ans1||ans2) return 1;
	return 0;
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int j=1;j<=m;j++) scanf("%d",&b[j]);
	init();
	cout<<pan();
	while(q--){
		scanf("%d%d",&qa,&qb);init();
		for(int i=1;i<=qa;i++){
			int x,y;scanf("%d%d",&x,&y);
			na[x]=y;
		}for(int i=1;i<=qb;i++){
			int x,y;scanf("%d%d",&x,&y);
			nb[x]=y;
		}cout<<pan();
	}return 0;
}