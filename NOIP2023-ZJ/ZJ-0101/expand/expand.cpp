#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=5e5+5;
ll ID,n,m,q,nx,ny,x,y,t,A[_],B[_],a[_],b[_],d[5005][5005],i,j;
inline ll p(ll x,ll y){return a[x]==b[y]?-1:(a[x]<b[y]);}
void P(){
	for(i=1;i<=n;i++)a[i]=A[i];
	for(i=1;i<=m;i++)b[i]=B[i];
	while(nx--)cin>>x>>y,a[x]=y;
	while(ny--)cin>>x>>y,b[x]=y;
	t=p(1,1);d[1][1]=1;
	if(t==-1){cout<<0;return;}
	for(i=1;i<=n;i++)for(j=1+(i==1);j<=m;j++)
		d[i][j]=((p(i,j)==t)?d[i][j-1]|d[i-1][j]|d[i-1][j-1]:0);
	cout<<d[n][m];
}
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>ID>>n>>m>>q;
	for(i=1;i<=n;i++)cin>>A[i];
	for(i=1;i<=m;i++)cin>>B[i];
	nx=ny=0;P();
	while(q--)cin>>nx>>ny,P();
}