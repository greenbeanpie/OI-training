#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<cstring>
using namespace std;

void IO(string str){
	freopen((str+".in").c_str(), "r", stdin);
	freopen((str+".out").c_str(), "w", stdout);
}

char inv(char t){
	if(t=='T')  return 'F';
	if(t=='F')  return 'T';
	return 'U';
}

struct option{
	char c;
	int x, y;
	void operate(char a[]){
		if(c=='+')  a[x]=a[y];
		else if(c=='-')  a[x]=inv(a[y]);
		else  a[x]=c;
	}
};

constexpr int N=1e5+5;
int n, m;

namespace task1{
	constexpr int N=15;
	char a[N];
	option op[N];
	int ans;
	bool query(){
		char aa[N];
		memcpy(aa, a, sizeof(a));
		for(int i=1; i<=m; ++i)  op[i].operate(aa);
		for(int i=1; i<=n; ++i){
			if(a[i]!=aa[i])  return false;
		}
		return true;
	}
	void dfs(int x, int sum){
		if(x>m){
			if(query())  ans=min(ans, sum);
			return;
		}
		a[x]='T';
		dfs(x+1, sum);
		a[x]='F';
		dfs(x+1, sum);
		a[x]='U';
		dfs(x+1, sum+1);
	}
	int solve(){
		ans=1e9;
		cin>>n>>m;
		for(int i=1; i<=m; ++i){
			char c, tmp[5];
			int x=0, y=0;
			scanf("%s", tmp);
			c=tmp[0];
			if(c=='+' || c=='-')  scanf("%d%d", &x, &y);
			else  scanf("%d", &x);
			op[i]={c, x, y};
		}
		dfs(1, 0);
		return ans;
	}
}

namespace task2{
	char a[N];
	int solve(){
		cin>>n>>m;
		memset(a, 'T', sizeof(char)*(n+1));
		for(int i=1; i<=m; ++i){
			char c;
			int x;
			scanf("%s%d", &c, &x);
			a[x]=c;
		}
		int ans;
		for(int i=1; i<=n; ++i){
			if(a[i]=='U')  ans++;
		}
		return ans;
	}
}

namespace task3{
	int solve(){
		return 114514;
	}
}

namespace task4{
	int solve(){
		return 114514;
	}
}

int main(){
	IO("tribool");
//	IO("tribool2");
	int c, T;
	cin>>c>>T;
	while(T--){
		if(c<=2)  printf("%d\n", task1::solve());
		else if(c<=4)  printf("%d\n", task2::solve());
		else if(c<=6)  printf("%d\n", task3::solve());
		else if(c<=8)  printf("%d\n", task4::solve());
		else  puts("NOIP RP++!");
	}
	return 0;
}