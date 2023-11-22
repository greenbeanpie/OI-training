#include<bits/stdc++.h>
using namespace std; constexpr int maxn(12);
mt19937 rnd(time(nullptr));
inline int random(int l,int r){
	return rnd()%(r-l+1)+l;
}
signed main(){ freopen("tribool.in","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cout << 1 << ' ' << 1 << '\n';
	int n=5,m=7; cout << n << ' ' << m << '\n';
	for(int i=1;i<=m;i++){
		int op=rnd()%2;
		if(op&1){
			int x=random(1,n),y=random(1,n);
			cout << "+ " << x << ' ' << y << '\n'; 
		}else{
			int x=random(1,n),y=random(1,n);
			cout << "- " << x << ' ' << y << '\n';
		}
	}
	return 0;
}
