#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,is[1000010][2];char s[30];
int sz[1000010],pt[1000010],T,res;
int fnd(int x){return (pt[x]==x?x:fnd(pt[x]));}
void merge(int a,int b){
	a=fnd(a),b=fnd(b);
	if(a==b)return;
	if(sz[a]<sz[b])pt[a]=b,sz[b]+=sz[a];
	else pt[b]=a,sz[a]+=sz[b];
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	for(scanf("%d%d",&T,&T);T--;){
		scanf("%d%d",&n,&m),res=0;
		for(int i=1;i<=n;i++)is[i][0]=0,is[i][1]=i;
		for(int i=1,a,b;i<=m;i++){
			scanf("%s",s);
			if(s[0]=='+'){
				scanf("%d%d",&a,&b);
				is[a][0]=is[b][0],is[a][1]=is[b][1];
			}else if(s[0]=='-'){
				scanf("%d%d",&a,&b);
				if(is[b][0]==2){
					is[a][0]=2;
					if(is[b][1]==2)is[a][1]=2;
					else is[a][1]=is[b][1]^1;
				}else is[a][0]=is[b][0]^1,is[a][1]=is[b][1];
			}else{
				scanf("%d",&a);
				is[a][0]=2;
				is[a][1]=(s[0]=='U')?2:(s[0]=='T'?1:0);
			}
		}
		for(int i=1;i<=n*2+3;i++)pt[i]=i,sz[i]=1;
		for(int i=1;i<=n;i++){
			if(is[i][0]==0){
				merge(i,is[i][1]);
				merge(i+n,is[i][1]+n);
			}else if(is[i][0]==1){
				merge(i+n,is[i][1]);
				merge(i,is[i][1]+n);
			}else{
				if(is[i][1]==2){
					merge(i,n*2+3);
					merge(i+n,n*2+3);
				}else if(is[i][1]==1){
					merge(i,n*2+2);
					merge(i+n,n*2+1);
				}else{
					merge(i,n*2+1);
					merge(i+n,n*2+2);
				}
			}
		}
		for(int i=1;i<=n;i++)if(fnd(i)==fnd(i+n))merge(i,n*2+3);
		for(int i=1;i<=n;i++)if(fnd(i)==fnd(n*2+3))res++;
		cout<<res<<endl;
	}
	return 0;
}
