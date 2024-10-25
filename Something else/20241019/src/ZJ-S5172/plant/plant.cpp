#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005],b[100005],c[100005],k;
inline bool check(int x){
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]+b[i]*c[mid]>x)r=mid-1;
			else l=mid+1;
		}ans+=r;
	}
	return ans<k;
} 
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);cin>>k;
	int l=2,r=1e18;r+=(int)1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}cout<<l;
}
