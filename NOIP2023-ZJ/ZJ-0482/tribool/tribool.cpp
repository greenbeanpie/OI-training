#include<bits/stdc++.h>
#define fei(x) ((x)==2?2:!(x))
using namespace std;
const int N=100010;
int n,m,c,T,t[200];
char o[3],a[N],b[15];
struct opt{
	int o,x,y;
}op[N];
bool check(){
	for(int i=1;i<=n;++i)
		if(a[i]!=b[i])return 0;
	return 1;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	t['T']=1,t['F']=0,t['U']=2;
	scanf("%d%d",&c,&T);
	while(T--){
		int ans=1e9;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i){
			int a,b;
			scanf("%s%d",o,&a);
			if(isalpha(*o))op[i]={t[(int)*o],a,-1};
			else{
				scanf("%d",&b);
				op[i]={*o=='+'?3:4,a,b};
			}
		}
		if(!m)
			puts("0");
		if(c<=2){
			int p=1;
			for(int i=0;i<n;++i)p*=3;
			for(int i=0;i<p;++i){
				int x=i,cnt=0;
				for(int j=1;j<=n;++j){
					a[j]=x%3;
					cnt+=x%3==2;
					x/=3;
				}
				memcpy(b+1,a+1,n);
				for(int j=1;j<=m;++j){
					if(op[j].o<=2)
						a[op[j].x]=op[j].o;
					else a[op[j].x]=
					op[j].o==3?a[op[j].y]:
					fei(a[op[j].y]);
				}
				if(check())
					ans=min(ans,cnt);
			}
			printf("%d\n",ans);
		}
		else if(c<=4){
			memset(a+1,0,n);
			ans=0;
			for(int i=1;i<=m;++i)
				a[op[i].x]=op[i].o;
			for(int i=1;i<=n;++i)
				ans+=a[i]==2;
			printf("%d\n",ans);
		}
		else printf("%d\n",n);
	}
	return 0;
}