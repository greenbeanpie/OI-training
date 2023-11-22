#include <bits/stdc++.h>
using namespace std;
const int N=3030;
#define wr(i,l,r) for(int i=l;i<=r;i++)
#define ll long long


bool cmp1(int x,int y){
    return x<y;
}
bool cmp2(int x,int y){
	return x>y;
}

int n,m;
string s[N];
int a[N][N],b[N][N],c[N][N];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	if(n==1){
		cout<<1;
		return 0;
	}
	cin>>n>>m;
	wr(i,1,n){
		cin>>s[i];
	}
	wr(i,1,n){
		for(int j=0;j<m;j++){
			a[i][j+1]=b[i][j+1]=s[i][j]-'a';
		}
		sort(a[i]+1,a[i]+m+1,cmp1);
		sort(b[i]+1,b[i]+m+1,cmp2);
	}
	
	wr(j,1,m){
		int fi=30,se=30;
		int pos;
		wr(i,1,n){
			if(b[i][j]<fi){
				se=fi;
				fi=b[i][j];
				pos=i;
			}
			else{
				if(b[i][j]<se){
					se=b[i][j];
				}
			}
		}
		wr(i,1,n){
			if(pos==i) c[i][j]=se;
			else c[i][j]=fi;
		}
	}
	
	wr(i,1,n){
		int f=0;
		wr(j,1,m){
			if(a[i][j]<c[i][j]){
				f=1;
				break;
			}
			if(a[i][j]>c[i][j]){
				f=0;
				break;
			}
		}
		printf("%d",f);
	}
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
*/