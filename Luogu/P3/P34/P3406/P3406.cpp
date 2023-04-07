#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[100050],a[100050],b[100050],c[100050],t[100050],chafen[100050];
signed main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> p[i];
	}
	
	for(int i=1;i<=m-1;i++){
		chafen[min(p[i],p[i+1])]++;
		chafen[max(p[i],p[i+1])]--;
	}
	
	for(int i=1;i<=n;i++){
		t[i]=t[i-1]+chafen[i];
	}

	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(b[i]*t[i]+c[i]<a[i]*t[i]){
			sum+=b[i]*t[i]+c[i];
		}
		else{
			sum+=a[i]*t[i];
		}
	}
	cout <<  sum;
	return 0;
}