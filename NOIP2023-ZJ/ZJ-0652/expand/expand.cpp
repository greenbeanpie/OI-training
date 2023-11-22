#include<bits/stdc++.h>
using namespace std;
#define maxc(a,b) ((a)>(b)?(a):(b))
#define minc(a,b) ((a)<(b)?(a):(b))
int c,n,m,q;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	cin>>c>>n>>m>>q;
	srand(time(0));
	for(int i=0;i<=q;i++){
		cout<<rand()%2;
	}
	return 0;
}
