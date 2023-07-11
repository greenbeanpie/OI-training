#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <vector>
using namespace std;
int top, zhan[100010], n, jin[100010], chu[100010];
void push(int x) { zhan[++top] = x; }
void pop() { top--; }
int main()
{
	scanf("%d", &n); // 读入。
	int len, js = 1;
	for (int i = 0; i < n; i++) // 核心部分。
	{
		scanf("%d", &len);
		for (int j = 1; j <= len; j++)
			scanf("%d", &jin[j]);
		for (int j = 1; j <= len; j++)
			scanf("%d", &chu[j]);
		for (int j = 1; j <= len; j++)
		{
			push(jin[j]); // 进栈。
			while (zhan[top] == chu[js] && zhan[top] && chu[js])
			{
				pop();
				js++;
			}
		} // 之所以用while循环，是因为可以简单直接的让相同元素出栈。
		if (top != 0)
			puts("No"); // 如果栈非空，失败。
		else
			puts("Yes");
		// 初始化，进入下一轮访问。
		top = 0;
		js = 1;
	}
	return 0;
}