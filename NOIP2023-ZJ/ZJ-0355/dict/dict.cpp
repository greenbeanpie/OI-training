#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re(i,a,b) for(int i=(a);i<=(b);i++)
int n,m;
char c[3005][3005];
namespace algo1{
	char sm[3005][3005],bg[3005][3005];
	il bool gre_c(char a,char b){
		return a>b;
	}
	il void run(){
		memcpy(sm,c,sizeof(c));
		memcpy(bg,c,sizeof(c));
		re(i,1,n){
			sort(sm[i]+1,sm[i]+m+1);
		}
		re(i,1,n){
			sort(bg[i]+1,bg[i]+m+1,gre_c);
		}
//		re(i,1,n){
//			printf("%s\n",sm[i]+1);
//		}
//		re(i,1,n){
//			printf("%s\n",bg[i]+1);
//		}
		re(i,1,n){
			bool ok=true;
			re(j,1,n){
				if(i==j)continue;
				if(strcmp(sm[i]+1,bg[j]+1)>0){
					ok=false;
					break;
				}
			}
			if(ok)putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	re(i,1,n){
		scanf("%s",c[i]+1);
	}
	if(n==1){
		putchar('1');
		putchar('\n');
		return 0;
	}
	algo1::run();
	return 0;
}
