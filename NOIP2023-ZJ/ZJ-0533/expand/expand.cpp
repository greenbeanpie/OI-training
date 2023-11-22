#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<cstring>
using namespace std;

void IO(string str){
	freopen((str+".in").c_str(), "r", stdin);
	freopen((str+".out").c_str(), "w", stdout);
}

constexpr int N=5e5+5;
int c, n, m, q;
int a[N], b[N], aa[N], bb[N];

namespace task1{
	bool dfs1(int x, int y){
		if(x>n || y>m){
			if(x<=n && a[x]>=b[m])  return false;
			if(y<=m && a[n]<=b[y])  return false;
			return true;
		}
		bool res=0;
		if((a[x]<b[y]))  res|=dfs1(x+1, y+1);
		else{
			if((a[x-1]<b[y]))  res|=dfs1(x, y+1);
			if((a[x]<b[y-1]))  res|=dfs1(x+1, y);
		}
		return res;
	}
	bool dfs2(int x, int y){
		if(x>n || y>m){
			if(x<=n && a[x]<=b[m])  return false;
			if(y<=m && a[n]>=b[y])  return false;
			return true;
		}
		bool res=0;
		if((a[x]>b[y]))  res|=dfs2(x+1, y+1);
		if((a[x-1]>b[y]))  res|=dfs2(x, y+1);
		if((a[x]>b[y-1]))  res|=dfs2(x+1, y);
		return res;
	}
	bool solve(int a[], int b[]){
		if(a[1]==b[1])  return false;
		int i=1, j=1;
		if(a[1]<b[1]){
			while(i<=n && j<=m){
				if((a[i]>b[j]))  i++, j++;
				else if((a[i-1]>b[j]))  j++;
				else if((a[i]>b[j-1]))  i++;
				else  return false;
			}
			if(i<=n && a[i]<=b[m])  return false;
			if(j<=m && a[n]>=b[j])  return false;
		}
		else{
			while(i<=n && j<=m){
				if((a[i]<b[j]))  i++, j++;
				else if((a[i-1]<b[j]))  j++;
				else if((a[i]<b[j-1]))  i++;
				else  return false;
			}
			if(i<=n && a[i]>=b[m])  return false;
			if(j<=m && a[n]<=b[j])  return false;
		}
		return true;
	}
	int main(){
		memcpy(aa, a, sizeof(int)*(n+1));
		memcpy(bb, b, sizeof(int)*(m+1));
		cout<<solve(aa, bb);
		for(int i=1, kx, ky, p, v; i<=q; ++i){
			memcpy(aa, a, sizeof(int)*(n+1));
			memcpy(bb, b, sizeof(int)*(m+1));
			cin>>kx>>ky;
			for(int j=1; j<=kx; ++j){
				cin>>p>>v;
				aa[p]=v;
			}
			for(int j=1; j<=ky; ++j){
				cin>>p>>v;
				bb[p]=v;
			}
			cout<<solve(aa, bb);
		}
		cout<<endl;
		return 0;
	}
}

namespace task2{
	int mxa, mib;
	int main(){
		puts("NOIP RP++!");
		return 0;
	}
}

int main(){
	IO("expand");
//	IO("expand2");
//	freopen("expand2.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>q;
	for(int i=1; i<=n; ++i)  cin>>a[i];
	for(int i=1; i<=m; ++i)  cin>>b[i];
	if(c<=7)  return task1::main();
	else if(c<=14)  return task2::main();
	else puts("NOIP RP++!");
	return 0;
}
/*
1 5 5 0
4 8 2 7 1
8 5 4 3 9
*/         