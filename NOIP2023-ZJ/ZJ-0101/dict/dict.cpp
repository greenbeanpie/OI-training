#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=5e5+5,inf=1e18;
ll n,m,a[_],b[_],i,j;char ch;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=0;i<n;i++){
		a[i]=inf;b[i]=-inf;
		for(j=0;j<m;j++){
			cin>>ch;
			a[i]=min(a[i],(ll)ch);
			b[i]=max(b[i],(ll)ch);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)if(j!=i&&a[i]>=b[j])break;
		cout<<(j==n);
	}
}