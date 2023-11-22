#include<bits/stdc++.h>
using namespace std;
#define MAXN 3005
string a[MAXN];
struct Node{
	string s;
	int id;
}maxw[MAXN],minw[MAXN];
int n,m;
char mx,mn;
bool f=0;
inline bool cmp(Node x,Node y){return x.s<y.s;}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		maxw[i].s=a[i];
		maxw[i].id=i;
		f=0;
		for(int j=0;j<m;j++){
			for(int k=m-1;k>j;k--){
				if(maxw[i].s[j]<maxw[i].s[k]){
					swap(maxw[i].s[j],maxw[i].s[k]);
					f=1;
				}
			}
			if(f) break;
		}
		minw[i].s=a[i];
		minw[i].id=i;
		f=0;
		for(int j=0;j<m;j++){
			for(int k=m-1;k>j;k--){
				if(minw[i].s[j]>minw[i].s[k]){
					swap(minw[i].s[j],minw[i].s[k]);
					f=1;
				}
			}
			if(f) break;
		}
	}
	sort(maxw,maxw+n,cmp);
	for(int i=0;i<n;i++){
		if(i==maxw[0].id){
			if(minw[i].s<maxw[1].s) printf("1");
			else printf("0");
		}
		else{
			if(minw[i].s<maxw[0].s) printf("1");
			else printf("0");
		}
	}
	return 0;
}
