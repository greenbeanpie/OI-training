#include<bits/stdc++.h>
using namespace std;
long long  n,m,k,d,f[100100],a[100100];
struct node{
	long long x,y,v;
}q[100100];
bool cmp(node x,node y){
	return x.x<y.x;
}
int ch,T;
void solve(){
	cin>>n>>m>>k>>d;
	if (ch==17||ch==18){
		long long ans=0,x,y,v;
		for (int i=1;i<=m;i++){
		cin>>x>>y>>v;
		if (y<=k) ans+=max(0ll,v-y*d);
		}
		cout<<ans<<endl;
		return ;
	}
	for (int i=1;i<=n;i++)
	f[i]=0,a[i]=0;
	for (int i=1;i<=m;i++)
	cin>>q[i].x>>q[i].y>>q[i].v;
	sort(q+1,q+m+1,cmp);
	int w=1;
	for (int i=1;i<=n;i++)
	{
		while(w<=m&&q[w].x<=i)a[q[w].x-q[w].y+1]+=q[w].v,w++; 
		long long sum=0;
		for (int j=1;j<=k&&i-j>=0;j++)
		{
			sum+=a[i-j+1]-d;
			f[i]=max(f[i],f[max(0,i-j-1)]+sum);
		}
		f[i]=max(f[i],f[i-1]);
	}
	cout<<f[n]<<endl;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	
	cin>>ch>>T;
	while(T--)solve();
}