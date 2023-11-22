#include<bits/stdc++.h>
using namespace std;
int n,m,a[3100][31];
string s;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++){
			a[i][s[j]-'a'+1]++;
		}
	}
	for(int i=1;i<=n;i++){
		bool p=1;
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			int li=1,vi=a[i][1],lj=26,vj=a[j][26];	
				while(vi==0&&li<=26) li++,vi=a[i][li];
				while(vj==0&&lj>=1) lj--,vj=a[j][lj];
				if(li>=lj) p=0;
		}
		cout<<p;
	}
	return 0;
}