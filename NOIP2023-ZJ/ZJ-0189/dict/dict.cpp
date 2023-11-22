#include<bits/stdc++.h>
using namespace std;
const int maxn = 3005;
int n,m,p[maxn],cnt1,cnt2;
char s[maxn][maxn],str[maxn];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f * x;
}
bool cmp(char x,char y){return y < x;}
bool cmpp(int x,int y){
	for(int i = 1;i <= m;i++)
		if(s[x][i] < s[y][i])	return 1;
		else if(s[x][i] > s[y][i])	return 0;
	return 1;
}
void input(){
	n = read(),m = read();
	for(int i = 1;i <= n;i++)	scanf("%s",s[i] + 1),p[i] = i;
	for(int i = 1;i <= n;i++)	sort(s[i] + 1,s[i] + 1 + m,cmp);
}
void solve(){
	cnt1 = p[1];
	cnt2 = p[2];
	for(int i = 1;i <= n;i++)
	{
		int k = (p[1] == i) ? cnt2 : cnt1;
		for(int j = 1;j <= m;j++)	str[j] = s[i][m - j + 1];
		bool fl = 1;
		for(int j = 1;j <= m;j++)
			if(str[j] < s[k][j])	break;
			else if(str[j] > s[k][j])
			{
				fl = 0;break;
			}
		putchar(fl ? '1' : '0');
	}
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	input();
	sort(p + 1,p + 1 + n,cmpp);
	if(n == 1)
	{
		puts("1");
		return 0 ;
	}
	solve();
	return 0  ;
}


