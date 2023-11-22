#include <bits/stdc++.h>
using namespace std;
#define mk make_pair
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(; isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f*x;
}
inline void write(int x){
	if(x>9) write(x/10);
	putchar(x%10^48);
}
inline char readc(){
	char ch=getchar();
	for(;ch=='\n'||ch==' '||ch==EOF;ch=getchar());
	return ch;
}
int main(){
	freopen("run.out","w",stdout);
	srand(time(0));
	write(rand());
	return 0;
}//90