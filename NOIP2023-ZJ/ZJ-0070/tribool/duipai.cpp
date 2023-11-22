#include<bits/stdc++.h>
using namespace std;
int main()
{
	do
	{
		system("gen > in.txt");
		system("vio < in.txt > ans.txt");
		system("tribool < in.txt > out.txt");
	}while(!system("fc out.txt ans.txt"));
	return 0;
}