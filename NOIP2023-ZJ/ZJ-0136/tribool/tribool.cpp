#include<bits/stdc++.h>
using namespace std;
int c,T,n,m,op[100005][5],minval=114514,val[15],cur[15];
char tp[100005];

void dfs(int x){
	if(x==n+1){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			cur[i]=val[i];
			if(val[i]==2)cnt++;
		}
		for(int i = 1; i <= m; i++){
			if(tp[i]=='T'){
				cur[op[i][1]]=1;
			}else if(tp[i]=='F'){
				cur[op[i][1]]=0;
			}else if(tp[i]=='U'){
				cur[op[i][1]]=2;
			}else if(tp[i]=='+'){
				cur[op[i][1]]=cur[op[i][2]];
			}else{
				if(cur[op[i][2]]==2)cur[op[i][1]]=2;
				else cur[op[i][1]]=1-cur[op[i][2]];
			}
		}
		bool flag = 1;
		for(int i = 1; i <= n; i++)if(cur[i]!=val[i])flag = 0;
		if(flag)minval = min(minval,cnt);
		return;
	}
	for(int i = 0; i <= 2; i++){
		val[x]=i;
		dfs(x+1);
	}
}

void sol1(){
	minval = 114514;
	dfs(1);
	cout << minval << endl;
}
bool isok[100005];
void sol2(){
	memset(isok,0,sizeof(isok));
	int ans = 0;
	for(int i = 1; i <= m; i++){
		if(tp[i]=='U')isok[op[i][1]]=1;
		else isok[op[i][0]]=0;
	}
	for(int i = 1; i <= n; i++){
		if(isok[i])ans++;
	}
	cout << ans << endl;
}
int fa[100005];
bool isu[100005],lau[100005];
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void sol3(){
	memset(fa,0,sizeof(fa));
	for(int i = 1; i <= n; i++)fa[i]=i;
	memset(isu,0,sizeof(isu));
	int cnt = 0;
	for(int i = 1; i <= m; i++){
		if(tp[i]!='U'){
			int x = op[i][1],y=op[i][2];
			isu[x]=isu[y];
		}else{
			isu[op[i][1]]=1;
		}
	}
	for(int i = 1;i <= n; i++)if(isu[find(i)])cnt++;
	cout << cnt << endl;
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		memset(op,0,sizeof(op));
		memset(tp,0,sizeof(tp));
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= m; i++){
			scanf(" %c",&tp[i]);
			//cout << tp[i] << endl;
			scanf("%d",&op[i][1]);
			if(tp[i]=='-'||tp[i]=='+'){
				scanf("%d",&op[i][2]);
			}
		}
		if(c <= 2) sol1();
		else if(c<=4)sol2();
		else if(c <= 6)sol3();
	}
	return 0;
}