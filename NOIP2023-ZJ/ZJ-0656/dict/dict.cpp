#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,m;
struct node{
	int x;
	string s;
}a[N];
inline int read(){
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x*10+ch-'0',ch = getchar();
	return x;
}
bool cmp(node a,node b){
	return a.s < b.s;
}
bool check(int x){
	if(x == 1) return true;
	for(int i = 0;i < m;i++){
		for(int j = i+1;j < m;j++){
		    string temp = a[x].s;
			bool flag = true;
			swap(temp[i],temp[j]);
			for(int k = 1;k < x;k++){
				if(temp >= a[k].s) flag = false;
			}
			if(flag) return true;
		}
	}
	return false;
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n = read();
	m = read();
	for(int i = 1;i <= n;i++){
		cin >> a[i].s;
		a[i].x = i;
	}
	if(n == 1){
		cout << 1;
		return 0;
	}
	string ans = "";
	sort(a+1,a+n+1,cmp);
	int t = 0;
	for(int qwe = 1;qwe <= n;qwe++){
		for(int i = 1;i <= n;i++){
			if(a[i].x == qwe) t = i;
		}
		if(check(t)){
			ans += "1";
		}
		else ans += "0";
	}
	cout << ans;
	return 0;
}
