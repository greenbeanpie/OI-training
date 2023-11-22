#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int C=1,T=1,n=5,m=rnd()%10+1;
int main()
{
	printf("%d %d\n%d %d\n",C,T,n,m);
	for(int i=1;i<=m;i++)
	{
		switch(rnd()%10)
		{
			case 0: printf("U %d\n",rnd()%n+1); break;
			case 1: printf("T %d\n",rnd()%n+1); break;
			case 2: printf("F %d\n",rnd()%n+1); break;
			case 3: case 4: case 5:
				printf("+ %d %d\n",rnd()%n+1,rnd()%n+1); break;
			default:
				printf("- %d %d\n",rnd()%n+1,rnd()%n+1);
		}
	}
	return 0;
}