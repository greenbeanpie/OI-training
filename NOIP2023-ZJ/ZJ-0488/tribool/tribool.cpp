#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int c,t,n,m;
char v[N];
int x[N];
int a[N];
int i[N],j[N];
int ans;
void change(int m,int x[]){
	for(int k=1;k<=m;k++){
		if(v[k]=='U')
			x[i[k]]=2;
		else if(v[k]=='F')
			x[i[k]]=0;
		else if(v[k]=='T')
			x[i[k]]=1;
		else if(v[k]=='+')
			x[i[k]]=x[j[k]];
		else if(v[k]=='-'){
			if(x[j[k]]==2)x[i[k]]=2;
			if(x[j[k]]==1)x[i[k]]=0;
			if(x[j[k]]==0)x[i[k]]=1;
		}
	}
}
void dfs(int step,int m){
	if(step==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			x[i]=a[i];
			if(a[i]==2)sum++;
		}
		change(m,a);
		for(int i=1;i<=n;i++){
			if(a[i]!=x[i])
				return;
		}
		if(sum<ans)
			ans=sum;
		return;
	}
	a[step]=1;
	dfs(step+1,m);
	a[step]=0;
	dfs(step+1,m);
	a[step]=2;
	dfs(step+1,m);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
//	srand(time(0));
	while(t--){
		ans=1e9;
		scanf("%d%d",&n,&m);
		for(int k=1;k<=m;k++){
			cin>>v[k];
			if(v[k]=='U')
				scanf("%d",&i[k]);
			else if(v[k]=='F')
				scanf("%d",&i[k]);
			else if(v[k]=='T')
				scanf("%d",&i[k]);
			else if(v[k]=='+')
				scanf("%d%d",&i[k],&j[k]);
			else if(v[k]=='-')
				scanf("%d%d",&i[k],&j[k]);
		}
		dfs(0,m);
		printf("%d\n",ans);
//		cout<<rand()<<endl;
	}
}