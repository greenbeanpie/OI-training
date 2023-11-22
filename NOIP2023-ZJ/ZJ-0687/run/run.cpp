#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1,w=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		w=w<<3+w<<1+ch-'0';
		ch=getchar();
	}
	return w*f;
}
int main(){

	return 0;
}

