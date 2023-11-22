#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
struct tribool {
	bool value;
	bool is_U;
} tris[100010];
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		cin>>n>>m;
		for(int j=1; j<=m; j++) {
			char v;
			int a,b;
			cin>>v;
			switch(v) {
				case 'T': {
					cin>>a;
					tris[a].value=1;
					tris[a].is_U=0;
					break;
				}
				case 'F': {
					cin>>a;
					tris[a].value=0;
					tris[a].is_U=0;
					break;
				}
				case 'U': {
					cin>>a;
					tris[a].value=0;
					tris[a].is_U=1;
					break;
				}
				case '+':{
					cin>>a>>b;
					tris[a].value=tris[b].value;
					tris[a].is_U=tris[b].is_U;
					break;
				}
				case '-':{
					cin>>a>>b;
					if(tris[b].is_U) tris[a].value=tris[b].value;
					else tris[a].value=!tris[b].value;
					tris[a].is_U=tris[b].is_U;
					break;
				}
			}
		}
		int ans=0;
		for(int k=1; k<=n; k++) if(tris[k].is_U) ans++;
		cout<<ans<<endl;
	}
	return 0;
}

