#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
typedef long long int LL;
LL n,m,C,q;
inline LL read(){
	LL x = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x*10+ch-'0',ch = getchar();
	return x;
}
string ans;
LL A[N],B[N];
LL a[N];
LL b[N];
bool check(){
	LL t = 1;
	for(LL cnt = 1;cnt <= n;cnt++){
		while(a[cnt]>b[t] && t <= m){ 
			t++;
	    }
		if(a[cnt] == b[t]) return false;
	}
	if(t >= n) return true;
	return false;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	C = read();
	n = read();
	m = read();
	q = read();
	if(C == 1){
		n = read();
		m = read();
		if(n > m) ans += "1";
		else ans += "0";
		while(q--){
			LL kx = read();
			LL ky = read();
			for(LL i = 1;i <= kx;i++){
				LL px = read();
				LL vx = read();
				n = vx;
			}
			for(LL i = 1;i <= ky;i++){
				LL py = read();
				LL vy = read();
				m = vy;
			}
			if(n > m) ans += "1";
		    else ans += "0";
		}
		cout<< ans;
		return 0;
	}
	for(LL i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(LL i = 1;i <= m;i++){
		cin >> b[i];
	}
	if(check()) ans += "1";
	else ans += "0";
	while(q--){
		LL kx = read();
		LL ky = read();
		for(LL i = 1;i <= n;i++) A[i] = a[i];
		for(LL i = 1;i <= m;i++) B[i] = b[i];
		for(LL i = 1;i <= kx;i++){
			LL px = read();
			LL vx = read();
			a[px] = vx;
		}
		for(LL i = 1;i <= ky;i++){
			LL py = read();
			LL vy = read();
			b[py] = vy;
		}
		if(check()) ans += "1";
		else ans += "0";
		for(LL i = 1;i <= n;i++) a[i] = A[i];
		for(LL i = 1;i <= m;i++) b[i] = B[i];
	}
	cout << ans;
	return 0;
}
