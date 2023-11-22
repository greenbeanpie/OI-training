#include <bits/stdc++.h>
using namespace std;
int x,y,i;
char s1[3001],s2[3001];
int main()
{
	freopen("dict.out","r",stdin);
	for (i=1;i<3001;i++) s1[i]=getchar();
	freopen("dict4.ans","r",stdin);
	for (i=1;i<3001;i++) s2[i]=getchar();
	for (i=1;i<3001;i++) if (s1[i]!=s2[i])
	{
		cout<<"no";
		return 0;
	}
	cout<<"yes";
	return 0;
}