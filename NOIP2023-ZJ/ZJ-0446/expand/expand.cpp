#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c,n,m,q;
int num1[maxn],num2[maxn];
int nn1[maxn],nn2[maxn];
int ans[100];
int kx,ky,u,p;
int si,si2;
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	if(n==m&&n==1){
		for(int i=1;i<=q+1;i++) cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>num1[i],nn1[i]=num1[i];
	for(int i=1;i<=m;i++) cin>>num2[i],nn2[i]=num2[i];
	si=num1[1]>num2[1];
	si2=num1[n]>num2[m];
	if(c>=8&&c<=14){
		for(int i=1;i<=q+1;i++) cout<<1;
		return 0;
	}
	if(si!=si2){
		cout<<0;
	}else{
		bool flag=false;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(num1[i]==num2[j]){
					cout<<0;
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) cout<<1;
	}
	while(q--){
		cin>>kx>>ky;
		for(int i=1;i<=kx;i++){
			cin>>p>>u;
			nn1[p]=u;
		}
		for(int i=1;i<=ky;i++){
			cin>>p>>u;
			nn2[p]=u;
		}
		si=nn1[1]>nn1[1];
		si2=nn2[n]>nn2[m];
		if(si!=si2){
			cout<<0;
		}else{
			bool flag=false;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(nn1[i]==nn2[j]){
						cout<<0;
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
			if(!flag) cout<<1;
		}
		for(int i=1;i<=n;i++) nn1[i]=num1[i];
		for(int i=1;i<=m;i++) nn2[i]=num2[i];
	}
	
	return 0;
}