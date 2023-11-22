#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	freopen("tribool.in","w",stdout);
	
	printf("5 1\n");
	int m=rand()%100+1;
	printf("10 %d\n",m);
	for (int i=1;i<=m;i++)
	{
		int op=rand()%2,x=rand()%10+1,y=rand()%10+1;
		if (op==0)
			printf("U %d\n",x);
		else
			printf("+ %d %d\n",x,y);
	}
	
}