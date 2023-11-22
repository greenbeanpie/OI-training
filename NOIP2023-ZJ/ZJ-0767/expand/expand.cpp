#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LL long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int c,n,m,q,A[N],B[N],kx,ky,p,v,a[N],b[N];
void print(){
	cout<<"---------------"<<endl<<"A : { ";
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<"}  B : { ";
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	cout<<"}"<<endl<<"---------------"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>A[i];
	for(int i=1;i<=m;i++)cin>>B[i];
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
//	print();
	if(n==1&&m==1){
		for(int i=0;i<q;i++)cout<<"1";
	}
	else{
			while(q--){
				for(int i=1;i<=n;i++)a[i]=A[i];
				for(int i=1;i<=m;i++)b[i]=B[i];
				cin>>kx>>ky;
				for(int i=1;i<=kx;i++){
					cin>>p>>v;
					a[p]=v;
				}
				for(int i=1;i<=ky;i++){
					cin>>p>>v;
					b[p]=v;
				}
				if((a[1]-b[1])*(a[n]-b[m])<=0){
					cout<<"0";
					continue;
				}
				cout<<"1";
			}
	}
	return 0;
}

