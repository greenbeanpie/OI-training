#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int ID,n,m,Q;
int A[N],B[N],GA[N],GB[N];
int main(){
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>ID>>n>>m>>Q;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=m;i++) cin>>B[i];
	if(A[1]<=B[1]){
		swap(A,B);
		swap(n,m);
	}
	memcpy(GA,A,sizeof A);
	memcpy(GB,B,sizeof B);
	if(A[1]>B[1]&&A[n]>B[m]) cout<<1;
	else cout<<0;
	while(Q--){
		int sa,sb;
		cin>>sa>>sb;
		memcpy(A,GA,sizeof A);
		memcpy(B,GB,sizeof B);
		while(sa--){
			int x,y;
			cin>>x>>y;
			A[x]=y;
		}
		while(sb--){
			int x,y;
			cin>>x>>y;
			B[x]=y;
		}
		if(A[1]>B[1]&&A[n]>B[m]) cout<<1;
		else cout<<0;
	}
	return 0;
}
/*
3 3 3 3
8 6 9
1 7 4
1 0
3 0
0 2
1 8
3 5
1 1
2 8
1 7
*/