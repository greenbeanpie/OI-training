#include <bits/stdc++.h>
using namespace std;
int C,T,n,lx,ly,x,y,m,k,ans,f[100010],a[100010];
char op;
int find(int x){
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>T;
	while (T--){
		cin>>n>>m;
		for (int i=1;i<=n;i++) f[i]=i;
		ans=k=0;		
		for (int i=1;i<=m;i++){
			cin>>op;
			if (op=='+'){
				cin>>x>>y;
				lx=find(x);ly=find(y);
				if (lx!=ly)
				f[lx]=ly;
			}
			if (op=='U'){
				cin>>x;
				a[++k]=x;
			}
		}
		/*
		for (int i=1;i<=k;i++){
			a[i]=find(a[i]);
			for (int j=1;j<=n;j++)
				if (find(j)==a[i]) 
					ans++;
		}
		*/
		for (int i=1;i<=n;i++){
			for (int j=1;j<=k;j++)
				if (find(i)==find(a[j])){
					ans++;
					break;
				}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
