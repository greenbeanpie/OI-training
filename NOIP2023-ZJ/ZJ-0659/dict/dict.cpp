#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar())if( c == '-' )f = -1;
	for(;isdigit(c);c = getchar())x = ( x << 1 ) + ( x << 3 ) + c - '0';
	return x * f;
}

const int N = 3005;

int n,m;
string str[N],Big[N],Small[N];

inline int num(char c){
	return c - 'a' + 1;
}

int main(){
	freopen("dict.in" , "r" , stdin);
	freopen("dict.out" , "w" , stdout);
	n = read();
	m = read();
	for(register int i = 1;i <= n;i ++){
		string s;
		cin >> s;
		int mx1 = 0,p1 = -1,mx2 = 0,p2 = -1;
		int mn1 = 30,p3 = -1,mn2 = 30,p4 = -1;
		for(register int j = 0;j < m;j ++){
			int v = num( s[j] );
			if( v > mx1 ){
				mx2 = mx1;
				p2 = p1;
				mx1 = v;
				p1 = j;
			}
			else if( v > mx2 ){
				mx2 = v;
				p2 = j;
			}
			
			if( v < mn1 ){
				mn2 = mn1;
				p4 = p3;
				mn1 = v;
				p3 = j;
			}
			else if( v < mn2 ){
				mn2 = v;
				p4 = j;
			}
		}
		if( p1 == 0 ){
			string t = s;
			char c1 = t[1],c2 = t[p2];
			t[1] = c2;t[p2] = c1;
			Big[i] = t;
		}
		else{
			string t = s;
			char c1 = t[0],c2 = t[p1];
			t[0] = c2;t[p1] = c1;
			Big[i] = t;
		}
		
		if( p3 == 0 ){
			string t = s;
			char c1 = t[1],c2 = t[p4];
			t[1] = c2;t[p4] = c1;
			Small[i] = t;
		}
		else{
			string t = s;
			char c1 = t[0],c2 = t[p3];
			t[0] = c2;t[p3] = c1;
			Small[i] = t;
		}
	}
	for(register int i = 1;i <= n;i ++){
		bool flag = 1;
		for(register int j = 1;j <= n;j ++){
			if( j == i )continue;
			if( Small[i] >= Big[j] ){
				flag = 0;
				break;
			}
		}
		if( flag )printf("1");
		else printf("0");
	}
	return 0;
}