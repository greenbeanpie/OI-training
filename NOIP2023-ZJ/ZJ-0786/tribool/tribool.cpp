#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100005];
int fk[128];
bool sign[100005];
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	fk['T']=1,fk['F']=-1,fk['U']=0;
	int c,T;
	cin>>c>>T;
	while(T--){
		memset(a,0x3f,sizeof(a));
		int n,m;
		scanf("%d %d",&n,&m);
		if(c==3||c==4){
			for(int i=1;i<=m;++i){
				string s;
				int x;
				cin>>s>>x;
				a[x]=fk[s[0]];
			}
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(!a[i])cnt++;
			printf("%d\n",cnt);
		}
		else if(c==7||c==8)puts("0");
		else if(c==5||c==6){
			for(int i=1;i<=m;++i){
				string s;
				cin>>s;
				if(s[0]=='U'){
					int x;
					scanf("%d",&x);
					a[x]=fk['U'];
				}else if(s[0]=='+'){
					int x,y;
					scanf("%d",&x,&y);
					a[x]=a[y];
				}
			}
			int cnt=0;
			for(int i=1;i<=n;++i)
				if(!a[i])cnt++;
			printf("%d\n",cnt);
		}
		else{
			for(int i=1;i<=m;++i){
				string s;
				cin>>s;
				if(s[0]=='+'){
					int x,y;
					scanf("%d %d",&x,&y);
					if(a[x]!=0)sign[x]=1;
					a[x]=a[y];
				}else if(s[0]=='-'){
					int x,y;
					scanf("%d %d",&x,&y);
					if(a[x]!=0)sign[x]=1;
					a[x]=-a[y];
				}else{
					int x;
					scanf("%d",&x);
					a[x]=fk[s[0]];
				}
				int cnt=0;
				for(int i=1;i<=n;++i)
					if(!a[i])cnt++;
				printf("%d\n",cnt);
			}
		}
	}
	return 0;
}


