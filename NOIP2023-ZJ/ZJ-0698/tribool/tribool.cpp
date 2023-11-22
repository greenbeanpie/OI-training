#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e5+5;

int c,t;
int n,m,x,y,z;
char ch;

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	srand(time(NULL));
	while(t--) printf("%d\n",rand()%N);
	return 0;
}
