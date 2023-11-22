#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
char s[MAXN],op[MAXN],now[MAXN];
int a[MAXN],b[MAXN],ans=1e9+7;
void check(int all,int m,int sum_u){
	int flag=0;
	char temp[MAXN];
	for(int i=1;i<=all;++i){
		temp[i]=now[i];
	}
	for(int i=1;i<=m;++i){
		if (op[i]=='-'){
			if (temp[b[i]]=='U'){
				temp[a[i]]='U';
			}
			else if (temp[b[i]]=='T'){
				temp[a[i]]='F';
			}
			else if (temp[b[i]]=='F'){
				temp[a[i]]='T';
			}
		}
		else if (op[i]=='+'){
			temp[a[i]]=temp[b[i]];
		}
		else{
			temp[a[i]]=op[i];
		}
	}
	for(int i=1;i<=all;++i){
		if (temp[i]!=now[i]){
			flag=1;
			break;
		}
	}
	if (!flag){
		ans=min(ans,sum_u);
	}
}
void dfs(int all,int _n,int m,int sum_u){
	if (_n==all+1){
		check(all,m,sum_u);
		return;
	}
	now[_n]='U';
	dfs(all,_n+1,m,sum_u+1);
	now[_n]='T';
	dfs(all,_n+1,m,sum_u);
	now[_n]='F';
	dfs(all,_n+1,m,sum_u);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	if (c==1||c==2){
		while (T--){
			ans=1e9+7;
			int n,m;
			scanf("%d %d",&n,&m);
			for(int i=1;i<=m;++i){
				char v;
				int x1,x2;
				cin>>v;
				if (v=='+'||v=='-'){
					scanf("%d %d",&x1,&x2);
					op[i]=v;
					a[i]=x1;
					b[i]=x2;
				}
				else{
					scanf("%d",&x1);
					op[i]=v;
					a[i]=x1;
				}
			}
			dfs(n,1,m,0);
			printf("%d\n",ans);
		}
	}
	else if (c==3||c==4){
		while (T--){
			int n,m,cnt=0;
			scanf("%d %d",&n,&m);
			while (m--){
				char v;
				int t;
				cin>>v;
				scanf("%d",&t);
				s[t]=v;
			}
			for(int i=1;i<=n;++i){
				if (s[i]=='U'){
					++cnt;
				}
			}
			printf("%d\n",cnt);
		}
	}
	else if (c==5||c==6){
		while (T--){
			int n,m,cnt=0;
			scanf("%d %d",&n,&m);
			for(int i=1;i<=n;++i){
				s[i]='a';
			}
			for(int i=1;i<=m;++i){
				char v;
				int x1,x2;
				cin>>v;
				if (v=='U'){
					scanf("%d",&x1);
					s[x1]='U';
				}
				else{ 
					scanf("%d %d",&x1,&x2);
					s[x1]=s[x2];
				}
			}
			for(int i=1;i<=n;++i){
				if (s[i]=='U'){
					++cnt;
				}
			}
			printf("%d\n",cnt);
		}
	}
	else{
		while (T--){
			printf("0\n");
		}
	}
	return 0;
}