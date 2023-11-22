#include<bits/stdc++.h>
using namespace std;
#define MAXN 114514

struct query{
	int x,y,st;
}q[MAXN];

int c,n,m,ccf,cnt=0,ans=MAXN;
//The variable "ccf" is a short form of "Could Count F",and "F" means the times of query in this question.
//Particularly, "ccf" doesn't means "China Computer Federation", please believe me, sir.
//The char variable "op" below is named after the word "operation". There's no other meanings of "op" in my mind, to be honest.
int u[MAXN*2],fa[MAXN*2],st[MAXN];



int findfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=findfa(fa[x]);
}

bool check(){
	int nowst[MAXN]={0};
	memcpy(nowst,st,sizeof(st));
	for(int i=1;i<=m;i++){
		query now=q[i];
		if(now.y==0){
			nowst[now.x]=now.st;
		}else{
			if(now.st==1)nowst[now.x]=nowst[now.y];
			if(now.st==2){
				if(nowst[now.y]==1)nowst[now.x]=2;
				else if(nowst[now.y]==2)nowst[now.x]=1;
				else if(nowst[now.y]==3)nowst[now.x]=3;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(nowst[i]!=st[i])return false;
	}
	return true;
}

void dfs(int x){
	if(x>n){
		if(check()) {
			int now=0;
			for(int i=1;i<=n;i++){
				if(st[i]==3)now++;
				//cout<<st[i]<<' ';
			}
			//cout<<endl;
			ans=min(ans,now);
		}
		return ;
	}
	for(int i=1;i<=3;i++){
		st[x]=i;
		dfs(x+1);
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	cin>>c>>ccf;
	
	if(c==1||c==2||c==9||c==10){
		while(ccf--){
			memset(st,0,sizeof(0));
			ans=MAXN;
			cin>>n>>m;
			for(int i=1;i<=m;i++){
				char op;
				cin>>op;
				if(op=='T'){
					int x;
					cin>>x;
					q[i]=(query){x,0,1};
				}else if(op=='F'){
					int x;
					cin>>x;
					q[i]=(query){x,0,2};
				}else if(op=='U'){
					int x;
					cin>>x;
					q[i]=(query){x,0,3};
				}else if(op=='+'){
					int x,y;
					cin>>x>>y;
					q[i]=(query){x,y,1};
				}else if(op=='-'){
					int x,y;
					cin>>x>>y;
					q[i]=(query){x,y,2};
				}
			}
			dfs(1);
			cout<<ans<<endl;
		}
		
/*
1 2
3 3
‐ 2 1
‐ 3 2
+ 1 3
3 3
‐ 2 1
‐ 3 2
‐ 1 3

*/
	}
	else if(c==3||c==4){
		while(ccf--){
			memset(st,0,sizeof(st));
			cin>>n>>m;
			int ans=0;
			while(m--){
				char op;
				int x;
				cin>>op>>x;
				if(op=='T'||op=='F'){
					if(st[x]==3)ans--;
					st[x]=1;
				}
				else {
					if(st[x]!=3)ans++;
					st[x]=3;
				}
			}
			cout<<ans<<endl;
		}
/*

3 1
2 2
T 2
U 2
*/
	}
	
	else if(c==5||c==6){
		while(ccf--){
			cin>>n>>m;
			while(m--){
				char op;
				cin>>op;
				if(op=='U'){
					int x;
					cin>>x;
					u[x]=1;
				}
				else if(op=='+'){
					int x,y;
					cin>>x>>y;
					u[x]=u[y];
				}	
			}
			int ans=0;
			for(int i=1;i<=n;i++) if(u[i]) ans++;
			cout<<ans<<endl;
		}
	}
	
	else if(c==7||c==8){
		while(ccf--){
			cin>>n>>m;
			memset(u,0,sizeof(u));
			for(int i=1;i<=n;i++)fa[i]=i,fa[n+i]=n+i;
			//cout<<n<<m;
			while(m--){
				char op;
				int x,y;
				cin>>op>>x>>y;
				if(op=='+'){
					int fx=findfa(x),fy=findfa(y);
					fa[fx]=fa[fy];
					
					fx=findfa(x+n),fy=findfa(y+n);
					fa[fx]=fa[fy];
					
				}else if(op=='-'){
					
					int fx=findfa(x),fy=findfa(y+n);
					fa[fx]=fa[fy];
					
					fx=findfa(x+n),fy=findfa(y);
					fa[fx]=fa[fy];
					
				}
			}
			
			int ans=0;
			for(int i=1;i<=n;i++){
				if(findfa(i)==findfa(i+n)){
					u[findfa(i)]=1;
				}
			}
			for(int i=1;i<=n;i++)if(u[findfa(i)])ans++;
			cout<<ans<<endl;
		}
	}
/*
7 2
3 3
‐ 2 1
‐ 3 2
+ 1 3
3 3
‐ 2 1
‐ 3 2
‐ 1 3
2-sat zha le , GG.
*/
	
	return 0;
}