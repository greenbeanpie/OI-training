#include <bits/stdc++.h>
using namespace std;
int c,t,n,m,a[100001],u,v,s,fr[100001][2];
char x;
vector<int> p[100001];
bool b[100011],bk[100001];
int ss(int ptt,int f,int sf){
	bk[ptt]=1;
	int fl=1,ct=1,os=0;
	for(int i=0,vl=p[ptt].size();i<vl;i++){
		int nt=p[ptt][i],nf=f;
		if(fr[nt][1]==1) nf^=1;
		if(bk[nt]){
			if(nf==sf) fl=0;
		}
		else{
			os=ss(nt,nf,sf);
			if(os) ct+=os;
			else ct=0;
		}
	}
	return fl*ct;
}
bool fd(int pt,int su,int f){
	b[pt]=1;
	if(pt==su&&f){
		bk[pt]=1;
		return 1;
	}
	for(int i=0,vl=p[pt].size();i<vl;i++){
		int nt=p[pt][i];
		if(bk[nt]) continue;
		else if(fd(nt,su,1)) return 1;
	}
	return 0;
}
void sv(){
	int dl[100011],l=0,h=1;
	dl[++l]=0;
	while(l>=h){
		u=dl[h++];
		for(int i=0,vl=p[u].size();i<vl;i++){
			v=p[u][i];
			if(u){
				a[v]=a[u];
				if(fr[v][1]=1&&(a[v]==1||a[v]==0)) a[v]^=1;
			}
			dl[++l]=v;
			b[v]=1;
		}
	}
	l=0;
	h=1;
	for(int i=1;i<=n;i++) if(a[i]==-2) dl[++l]=i;
	while(l>=h){
		u=dl[h++];
		for(int i=0,vl=p[u].size();i<vl;i++){
			v=p[u][i];
			dl[++l]=v;
			b[v]=1;
		}
	}
	for(int i=1;i<=n;i++) if(b[i]==0) fd(i,i,0);
	l=0;
	for(int i=1;i<=n;i++) if(bk[i]) dl[++l]=i;
	for(int i=1;i<=l;i++) s+=ss(dl[i],0,0);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--){
		scanf("\n%d %d",&n,&m);
		for(int i=0;i<=n;i++) a[i]=-2,b[i]=0,fr[i][0]=2,bk[i]=0,p[i].clear();
		s=0;
		for(int i=1;i<=m;i++){
			scanf("\n%c %d",&x,&u);
			if(x=='T'){
				a[u]=1;
				fr[u][0]=0;
			}
			else if(x=='F'){
				a[u]=0;
				fr[u][0]=0;
			}
			else if(x=='U'){
				a[u]=-1;
				fr[u][0]=0;
			}
			else{
				scanf(" %d",&v);
				a[u]=2;
				fr[u][0]=v;
				if(x=='-') fr[u][1]=1;
				if(x=='+') fr[u][1]=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]<2&&a[i]>-2){
				p[0].push_back(i);
			}
			else if(a[i]==2){
				p[fr[i][0]].push_back(i);
			}
		}
		sv();
		for(int i=1;i<=n;i++){
			if(a[i]==-1) s++;
		}
		printf("%d\n",s);
	}
}