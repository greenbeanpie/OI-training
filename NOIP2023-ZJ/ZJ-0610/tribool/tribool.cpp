#include<bits/stdc++.h>
using namespace std;
char fan(char a) {
	if(a=='U') return 'U';
	if(a=='F') return 'T';
	if(a=='T') return 'F';
	if(a=='?') return '?';
}
char trib[100009];
int point[100009];
int find(int d) {
	if(abs(point[d])!=d) {
		return(find(abs(point[d])));
	} else return abs(d);
}
void inset(int x,int y) {
	point[x]=find(y);
}
void dinset(int x,int y) {
	point[x]=-find(y);
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t,n,k,a,b;
	char l;
	cin>>c>>t;
	while (t--) {
		cin>>k>>n;
		for(int i=1; i<=k; i++) {
			point[i]=i;
			trib[i]='?';
		}
		for(int i=1; i<=n; i++) {
			cin>>l;
			if(l=='+') {
				cin>>a>>b;
				inset(a,b);
			}
			if(l=='-') {
				cin>>a>>b;
				dinset(a,b);
			}
			if(l=='U'||l=='T'||l=='F') {
				cin>>a;
				trib[a]=l;
			}
		}
		for(int i=1; i<=k; i++) {
			if(point[i]==i&&trib[i]=='?') trib[i]='T';
			if(point[i]==-i&&trib[i]=='?') trib[i]='U';
		}
		for(int _=1; _<=k; _++) {
			for(int i=1; i<=k; i++) {
				if(point[i]<0&&trib[i]=='?') trib[i]=fan(trib[abs(point[i])]);
				if(point[i]>0&&trib[i]=='?') trib[i]=trib[abs(point[i])];
			}
		}
		for(int i=1; i<=k; i++) {
			cout<<i<<" "<<trib[i]<<":"<<point[i]<<endl;
		}
		int ans=0;
		for(int i=1;i<=k;i++){
			if(trib[i]=='U') ans++;
		}
		cout<<ans<<endl;
	}
}