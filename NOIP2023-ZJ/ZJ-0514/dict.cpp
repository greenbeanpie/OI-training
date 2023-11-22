#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
string cmin[3005],cmax[3005];
char ch[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",ch);
		sort(ch,ch+m);
		for(int j=0;j<m;++j)
			cmin[i]+=ch[j];
		for(int j=m-1;j>=0;--j)
			cmax[i]+=ch[j];
	}
	bool f;
	for(int i=1;i<=n;++i){
		f=true;
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			if(cmin[i]>=cmax[j]){
				f=false;
				break;
			}
		}
		if(f) printf("1");
		else printf("0");
	}
	return 0;
}