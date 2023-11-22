#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define fd(i,x,y,z) for(ll i=x;i>=y;i-=z)
ll n,m;
char s[3005][3005];
char t[3005][3005];
ll qmn[3005],hmn[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	f(i,1,n,1){
		scanf("%s",s[i]+1);
		t[i][0]=s[i][0];
		f(j,1,m,1){
			t[i][j]=s[i][j];
		}
	}
	qmn[1]=1;
	sort(t[1]+1,t[1]+m+1);
	f(i,2,n,1){
		sort(t[i]+1,t[i]+m+1);
		fd(j,m,1,1){
			if(t[qmn[i-1]][j]<t[i][j]){
				qmn[i]=qmn[i-1];
				break;
			}
			else if(t[qmn[i-1]][j]>t[i][j]){
				qmn[i]=i;
				break;
			}
		}
	}
	hmn[n]=n;
	sort(t[n]+1,t[n]+m+1);
	fd(i,n-1,1,1){
		sort(t[i]+1,t[i]+m+1);
		fd(j,m,1,1){
			if(t[hmn[i+1]][j]<t[i][j]){
				hmn[i]=hmn[i+1];
				break;
			}
			else if(t[hmn[i+1]][j]>t[i][j]){
				hmn[i]=i;
				break;
			}
		}
	}
	f(i,1,n,1){
		//printf("%lld %lld\n",qmn[i],hmn[i]);
		bool flag=true;
		sort(s[i]+1,s[i]+m+1);
		ll gg=0;
		if(i>1){
			ll hh=0;
			gg=qmn[i-1];
			ll tp=m;
			f(j,1,m,1){
				if(t[gg][tp]<s[i][j]){
					break;
				}
				else if(t[gg][tp]>s[i][j]){
					hh=1;
					break;
				}
				tp--;
			}
			if(hh!=1){
				flag=false;
			}
		}
		if(i<n){
			ll hh=0;
			gg=hmn[i+1];
			ll tp=m;
			f(j,1,m,1){
				if(t[gg][tp]<s[i][j]){
					break;
				}
				else if(t[gg][tp]>s[i][j]){
					hh=1;
					break;
				}
				tp--;
			}
			if(hh!=1){
				flag=false;
			}
		}
		if(flag){
			putchar('1');
		}
		else{
			putchar('0');
		}
	}
	printf("\n");
	
	return 0;
}
