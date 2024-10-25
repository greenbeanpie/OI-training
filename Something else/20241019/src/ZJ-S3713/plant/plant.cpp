#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=998244353;
int n,m,t,a[N],b[N],c[N],cnt,s[N];
int get(int a,int b,int x){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(c[mid]*b+a<x)
			l=mid+1;
		else
			r=mid-1;
	}
	return r;
}
int get(int x){
	int s=0;
	for(int i=1;i<=n;i++)
		s+=get(a[i],b[i],x);
	return s;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cin>>m;
	sort(c+1,c+1+n);
	int l=1,r=1e18+1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(get(mid)<m)
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<r;
	return 0;
}
