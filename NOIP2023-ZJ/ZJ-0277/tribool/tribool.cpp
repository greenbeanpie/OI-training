#include<bits/stdc++.h>
#define R read()

using namespace std;

const int N=1e5+10;
int lp,T,n,m,i,ans,ai[N],aj[N],c[N],a[N],f[N];
char v[N];
int read(){
	int x=0,fl=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')fl=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
	return x*fl;
}
bool pd(){
	int i;
	for(i=1;i<=n;i++)a[i]=c[i];
	for(i=1;i<=m;i++){
		if(v[i]=='T')a[ai[i]]=1;
		if(v[i]=='U')a[ai[i]]=0;
		if(v[i]=='F')a[ai[i]]=-1;
		if(v[i]=='+')a[ai[i]]=a[aj[i]];
		if(v[i]=='-')a[ai[i]]=-a[aj[i]];
	}
	for(i=1;i<=n;i++)
		if(a[i]!=c[i])return 0;
	return 1;
}
void sc(int t,int s){
	if(t==n+1){
		if(pd())ans=min(ans,s);
		return ;
	}
	c[t]=1;
	sc(t+1,s);
	c[t]=-1;
	sc(t+1,s);
	c[t]=0;
	sc(t+1,s+1);
}
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	lp=R;T=R;
	while(T--){
		n=R;m=R;
		for(i=1;i<=m;i++){
			cin>>v[i];
//			cout<<v[i]<<" ";
			if(v[i]=='+'||v[i]=='-')ai[i]=R,aj[i]=R;
			else ai[i]=R;
//			cout<<ai[i]<<" "<<aj[i]<<"\n";
		}
		if(lp<=2){
			ans=2e9;
			sc(1,0);
			cout<<ans<<"\n";
		}
		if(3<=lp&&lp<=4){
			ans=0;
			for(i=1;i<=n;i++)a[i]=2;
			for(i=1;i<=m;i++){
				if(v[i]=='U')a[ai[i]]=0;
				if(v[i]=='T')a[ai[i]]=1;
				if(v[i]=='F')a[ai[i]]=-1;
			}
			for(i=1;i<=n;i++)if(a[i]==0)ans++;
			cout<<ans<<"\n";
		}
		if(5<=lp&&lp<=6){
			ans=0;
			for(i=1;i<=n;i++)a[i]=2,f[i]=i;
			for(i=1;i<=m;i++){
				if(v[i]=='U')a[ai[i]]=0,f[ai[i]]=ai[i];
				if(v[i]=='+'){
					int fx=find(ai[i]),fy=find(aj[i]);
					if(fx!=fy)f[fx]=fy;
				}
			}
			for(i=1;i<=n;i++)if(a[find(i)]==0)ans++;
			cout<<ans<<"\n";
		}
	}
	return 0;
}
