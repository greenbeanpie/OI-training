//baoli
#include<iostream>
using namespace std;

const int MAXN=1000;
int c,t,n,m;
int p[MAXN],tmp[MAXN];
int op[MAXN][5];
void copy(){
	for(int i=1;i<=n;++i) tmp[i]=p[i];
}
bool check(){
	copy();
	for(int i=1;i<=m;++i){
		if(op[i][0]==1){
			tmp[op[i][1]]=op[i][2];
		}else if(op[i][0]==2){
			tmp[op[i][1]]=tmp[op[i][2]];
		}else if(op[i][0]==3){
			tmp[op[i][1]]=4-tmp[op[i][2]];
		}
	}
	for(int i=1;i<=n;++i)
		if(tmp[i]!=p[i]) return false;
	return true;
}
int ans=-1;
void dfs(int dep,int now){
	if(now>dep) return;
	if(dep==n+1){
		if(check())
			ans=min(ans,now);
		return;
	}
	for(int i=1;i<=3;++i){
		p[dep]=i;
		dfs(dep+1,now+(i==2));
		p[dep]=0;
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	cin>>c>>t;
	char ch;
	int x,y;
	while(t--){
		cin>>n>>m;
		ans=n;
		for(int i=1;i<=m;++i){
			cin>>ch;
			if(ch=='+'){
				cin>>x>>y;
				op[i][0]=2;
				op[i][1]=x;
				op[i][2]=y;
			}else if(ch=='-'){
				cin>>x>>y;
				op[i][0]=3;
				op[i][1]=x;
				op[i][2]=y;
			}else{
				cin>>x;
				op[i][0]=1;
				op[i][1]=x;
				if(ch=='T'){
					op[i][2]=1;
				}else if(ch=='F'){
					op[i][2]=3;
				}else if(ch=='U'){
					op[i][2]=2;
				}
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1 3
3 3
‐ 2 1
‐ 3 2
+ 1 3
3 3
‐ 2 1
‐ 3 2
‐ 1 3
2 2
T 2
U 2
*/