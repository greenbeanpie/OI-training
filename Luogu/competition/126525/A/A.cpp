#include <bits/stdc++.h>
#define int long long
#define INF 2147483647
using namespace std;
int t;
struct node{
	int a,b;
}x[305];
bool cmp(node p,node q){
	return p.a < q.a;
}
signed main(){
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 1;i <= n;i++){
			cin >> x[i].a >> x[i].b;
		}
		sort(x+1,x+1+n,cmp);
		int sum=0;
		bool flag = 0;
		for(int i = 1;i <= n;i++){
			int s=x[i].a*k;
			s-=sum;
//			cout << s << " ";
			if(s >= x[i].b){
				sum+=x[i].b;
			}else{
				cout << "No\n";
				flag=1;
			}
		}
		if(!flag){
			cout << "Yes\n";
		}
	}
	return 0;
}
