#include<iostream>
#include<cstdio>
using namespace std;
int c,t,n,m,x,y,s[100003],p[100003],d[100003],ans,i;
char v[10];
bool f[100003];
void find(int x,int w){
	if(p[x]==-1)  return;
	if(d[x]==-1)  d[x]=w;
	else{
		if(d[x]==w)  s[x]=1;
		else  s[x]=2;
		p[x]=-1;
		return;
	}
	if(s[x]==x){
		if(p[x]==1)  s[x]=1;
		else  s[x]=2;
	}else{
		if(p[x]==1)  find(s[x],w);
		else  find(s[x],1-w);
		if(p[x]!=-1)  s[x]=s[s[x]];
	}
	p[x]=-1;
}
int main(){
	freopen("tribool.in","r",stdin),freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		for(scanf("%d%d",&n,&m),i=1;i<=n;i++)  s[i]=i,p[i]=1,d[i]=-1;
		for(i=1;i<=m;i++){
			scanf("%s%d",v,&x);
			if(v[0]=='T')  s[x]=1,p[x]=-1;
			if(v[0]=='F')  s[x]=1,p[x]=-1;
			if(v[0]=='U')  s[x]=2,p[x]=-1,ans++;
			if(v[0]=='+'){
				scanf("%d",&y);
				if(p[y]==-1)  s[x]=s[y],p[x]=-1;
				else  s[x]=s[y],p[x]=p[y];
			}
			if(v[0]=='-'){
				scanf("%d",&y);
				if(p[y]==-1)  s[x]=s[y],p[x]=-1;
				else  s[x]=s[y],p[x]=1-p[y];
			}
		}
		for(ans=0,i=1;i<=n;i++){
			if(d[i]==-1)  find(i,0);
			if(s[i]==2)  ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
