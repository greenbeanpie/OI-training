#include<bits/stdc++.h>

using namespace std;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar())if( c == '-' )f = -1;
	for(;isdigit(c);c = getchar())x = ( x << 1 ) + ( x << 3 ) + c - '0';
	return x * f;
}

const int N = 5e5 + 5;

int c,n,m,q;
int a[N],b[N],ta[N],tb[N];

int main(){
	freopen("expand.in" , "r" , stdin);
	freopen("expand.out" , "w" , stdout);
	c = read();
	n = read();
	m = read();
	q = read();
	for(int i = 1;i <= n;i ++)ta[i] = a[i] = read();
	for(int i = 1;i <= m;i ++)tb[i] = b[i] = read();
	if( n == 1 && m == 1 ){
		if( ta[1] == tb[1] )printf("0");
		else printf("1");
		while( q -- ){
			int kx = read(),ky = read();
			for(int i = 1;i <= kx;i ++){
				int p = read(),v = read();
				ta[p] = v;
			}
			for(int i = 1;i <= ky;i ++){
				int p = read(),v = read();
				tb[p] = v;
			}
			if( ta[1] == tb[1] )printf("0");
			else printf("1");
			ta[1] = a[1];
			tb[1] = b[1];
		}
		return 0;
	}
	if( n == 1 && m == 2 ){
		if( ta[1] == tb[1] || ta[1] == tb[2] )printf("0");
		else printf("1");
		while( q -- ){
			int kx = read(),ky = read();
			for(int i = 1;i <= kx;i ++){
				int p = read(),v = read();
				ta[p] = v;
			}
			for(int i = 1;i <= ky;i ++){
				int p = read(),v = read();
				tb[p] = v;
			}
			if( ta[1] == tb[1] || ta[1] == tb[2] )printf("0");
			else printf("1");
			ta[1] = a[1];
			tb[1] = b[1];
			tb[2] = b[2];
		}
		return 0;
	}
	if( n == 2 && m == 1 ){
		if( ta[1] == tb[1] || ta[2] == tb[1] )printf("0");
		else printf("1");
		while( q -- ){
			int kx = read(),ky = read();
			for(int i = 1;i <= kx;i ++){
				int p = read(),v = read();
				ta[p] = v;
			}
			for(int i = 1;i <= ky;i ++){
				int p = read(),v = read();
				tb[p] = v;
			}
			if( ta[1] == tb[1] || ta[2] == tb[1] )printf("0");
			else printf("1");
			ta[1] = a[1];
			ta[2] = a[2];
			tb[1] = b[1];
		}
		return 0;
	}
	if( n == 2 && m == 2 ){
		if( ta[1] == tb[1] || ta[2] == tb[2] )printf("0");
		else if( ( ta[1] < tb[1] && ta[2] > tb[2] ) || ( ta[1] > tb[1] && ta[2] < tb[2] ) )printf("0");
		else printf("1");
		while( q -- ){
			int kx = read(),ky = read();
			for(int i = 1;i <= kx;i ++){
				int p = read(),v = read();
				ta[p] = v;
			}
			for(int i = 1;i <= ky;i ++){
				int p = read(),v = read();
				tb[p] = v;
			}
			if( ta[1] == tb[1] || ta[2] == tb[2] )printf("0");
			else if( ( ta[1] < tb[1] && ta[2] > tb[2] ) || ( ta[1] > tb[1] && ta[2] < tb[2] ) )printf("0");
			else printf("1");
			for(int i = 1;i <= n;i ++)ta[i] = a[i];
			for(int i = 1;i <= m;i ++)tb[i] = b[i];
		}
		return 0;
	}
	if( ta[1] == tb[1] || ta[n] == tb[m] )printf("0");
	else if( ( ta[1] > tb[1] && ta[n] < tb[m] ) || ( ta[1] < tb[1] && ta[n] > tb[m] ) )printf("0");
	else {
		bool fl = ( ta[1] > tb[1] ) ? 1 : 0;
		bool suc = 1;
		for(int i = 2;i < min( n , m );i ++){
			if( fl == 1 ){
				if( ta[i] < tb[i] && !( ta[i - 1] > tb[i] && ta[i] > tb[i + 1] ) && !( ta[i] > tb[i - 1] && ta[i + 1] > tb[i] ) ){
					suc = 0;
					break;
				}
			}
			else{
				if( ta[i] > tb[i] && !( ta[i - 1] < tb[i] && ta[i] < tb[i + 1] ) && !( ta[i] < tb[i - 1] && ta[i + 1] < tb[i] ) ){
					suc = 0;
					break;
				}
			}
		}
		if( suc == 1 )printf("1");
		else printf("0");
	}
	while( q -- ){
		int kx = read(),ky = read();
		for(int i = 1;i <= kx;i ++){
			int p = read(),v = read();
			ta[p] = v;
		}
		for(int i = 1;i <= ky;i ++){
			int p = read(),v = read();
			tb[p] = v;
		}
		if( ta[1] == tb[1] || ta[n] == tb[m] )printf("0");
		else if( ( ta[1] > tb[1] && ta[n] < tb[m] ) || ( ta[1] < tb[1] && ta[n] > tb[m] ) )printf("0");
		else {
			bool fl = ( ta[1] > tb[1] ) ? 1 : 0;
			bool suc = 1;
			for(int i = 2;i < min( n , m );i ++){
				if( fl == 1 ){
					if( ta[i] < tb[i] && !( ta[i - 1] > tb[i] && ta[i] > tb[i + 1] ) && !( ta[i] > tb[i - 1] && ta[i + 1] > tb[i] ) ){
						suc = 0;
						break;
					}
				}
				else{
					if( ta[i] > tb[i] && !( ta[i - 1] < tb[i] && ta[i] < tb[i + 1] ) && !( ta[i] < tb[i - 1] && ta[i + 1] < tb[i] ) ){
						suc = 0;
						break;
					}
				}
			}
			if( suc == 1 )printf("1");
			else printf("0");
		}
		for(int i = 1;i <= n;i ++)ta[i] = a[i];
		for(int i = 1;i <= m;i ++)tb[i] = b[i];
	}
	return 0;
}