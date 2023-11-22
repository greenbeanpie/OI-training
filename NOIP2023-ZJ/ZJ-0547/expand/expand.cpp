#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c,q,p,kx,ky,v,a[100005],b[100005],b1[100005],a1[100005],px[100005],py[100005];
void work()
{
	int maxa=0,maxb=0,mina=1e18,minb=1e18;
	int p=0;
	for (int i=1;i<=n;i++){
		maxa=max(maxa,a[i]);
		mina=min(mina,a[i]);
	}
	for (int i=1;i<=m;i++){
		maxb=max(maxb,b[i]);
		minb=min(minb,b[i]);
	}
	if ((maxa-maxb)*(mina-minb)<=0){
		cout<<0;
		p=1;	
	}
	if (p==0){
		if (maxa>=maxb){
			int i=1,j=1;
			while (i<=n&&j<=m&&p==0){
				while (a[i]>b[j]&&i<=n&&j<=m) j++;
				j--;
				while (a[i+1]<=a[i]&&i<n&&j<m) i++;
				while (a[i]<=b[j]&&i<=n&&j<=m) j--;
				if (j<1) {p=1;break;}
				i++;
			}
			if (p==1||j<m) cout<<0;
				else cout<<1;
		}
		if (maxa<=maxb){
			int i=1,j=1;
			while (i<=m&&j<=n&&p==0){
				while (b[i]>a[j]&&i<=m&&j<=n) j++;
				j--;
				while (b[i+1]<=b[i]&&i<m&&j<n) i++;
				while (b[i]<=a[j]&&i<=m&&j<=n) j--;
				if (j<1) {p=1;break;}
				i++;
			}
			if (p==1||j<n) cout<<0;
				else cout<<1;
		}
	}	
}

void work2()
{
	int maxa=0,maxb=0,mina=1e18,minb=1e18;
	int p=0;
	for (int i=1;i<=n;i++){
		maxa=max(maxa,a[i]);
		mina=min(mina,a[i]);
	}
	for (int i=1;i<=m;i++){
		maxb=max(maxb,b[i]);
		minb=min(minb,b[i]);
	}
	if ((maxa>=maxb)||(mina>=minb)){
		cout<<0;
		p=1;	
	}
	if (p==0){
		int i=1,j=1;
		while (i<=m&&j<=n&&p==0){
			while (b[i]>a[j]&&i<=m&&j<=n) j++;
			if (j>=n) {p=2;break;}
			j--;
			while (b[i+1]<=b[i]&&i<m&&j<n) i++;
			while (b[i]<=a[j]&&i<=m&&j<=n) j--;
			if (j<1) {p=1;break;}
			if (i>=n-1&&j>=1) {p=2;break;}
			i++;
		}
		if (p==1||j<n) cout<<0;
			else cout<<1;
	}	
}
signed main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>q;
	if (c<=7){
		for (int i=1;i<=n;i++) cin>>a1[i],a[i]=a1[i];
		for (int j=1;j<=m;j++) cin>>b1[j],b[j]=b1[j];
		work();
		while (q--){
			cin>>kx>>ky;
			for (int i=1;i<=kx;i++) {
				cin>>px[i]>>v;
				a[px[i]]=v;
			}
			for (int i=1;i<=ky;i++) {
				cin>>py[i]>>v;
				b[py[i]]=v;
			}
			work();
			for (int i=1;i<=kx;i++) {
				a[px[i]]=a1[px[i]];
			}
			for (int i=1;i<=ky;i++) {
				b[py[i]]=b1[py[i]];
			}
		}
	}
	else{
		for (int i=1;i<=n;i++) cin>>a1[i],a[i]=a1[i];
		for (int j=1;j<=m;j++) cin>>b1[j],b[j]=b1[j];
		work();
		while (q--){
			cin>>kx>>ky;
			for (int i=1;i<=kx;i++) {
				cin>>px[i]>>v;
				a[px[i]]=v;
			}
			for (int i=1;i<=ky;i++) {
				cin>>py[i]>>v;
				b[py[i]]=v;
			}
			work();
			for (int i=1;i<=kx;i++) {
				a[px[i]]=a1[px[i]];
			}
			for (int i=1;i<=ky;i++) {
				b[py[i]]=b1[py[i]];
			}
		}
	}
	return 0;
}