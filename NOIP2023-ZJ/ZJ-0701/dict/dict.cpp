/*
input
{
	num = i;
	maxstr = sortbydown;
	minstr = sortbyup;
	int sit;
}
sort(string)
{
	ac by sit;
}
for(i : 0<= , <(2 * strnum))
{
	if(sit == acmax)maxbe++;
	else ans[num] = (maxbe == 0 ? 1 : 0);
}
*/
#include <bits/stdc++.h>
using namespace std;

#define minstr -1
#define maxstr 1
struct str
{
	int num;
	string nowque;
	int sit;
};
int strnum , lenofstr;
str *que = 0;
bool *ans = 0;
bool sortrule(str a , str b)
{
	return a.nowque < b.nowque;
}
bool sortruleup(char a , char b)
{
	return a < b;
}
bool sortruledown(char a , char b)
{
	return a > b;
}
string sortstr(string que , bool up)
{
	if(up)
		sort(que.begin() , que.begin() + que.length() , sortruleup);
	else 
		sort(que.begin() , que.begin() + que.length() , sortruledown);
	return que;
}
int main()
{
	// cout << freopen("dict.in" , "r" , stdin) << endl;
	freopen("dict.in" , "r" , stdin);
	freopen("dict.out" , "w" , stdout);
	cin >> strnum >> lenofstr;
	que = new str [2 * strnum];
	ans = new bool [strnum];
	for(int i = 0;i < 2 * strnum - 1;i += 2)
	{
		string a;
		cin >> a;
		que[i].nowque = sortstr(a , 1);
		que[i].sit = minstr;
		que[i].num = i / 2;
		que[i + 1].nowque = sortstr(a , 0);
		que[i + 1].sit = maxstr;
		que[i + 1].num = i / 2;
	}
	if(strnum == 1)
	{
		cout << "1" << endl;
		return 0;
	}
	for(int i = 0;i < strnum;i++)
	{
		ans[i] = 0;
	}
	// cout << endl;
	// for(int i = 0;i < 2 * strnum;i++)
	// {
	// 	cout << que[i].nowque << " " << que[i].sit << endl;
	// }
	// cout << endl;
	sort(que , que + 2 * strnum , sortrule);
	// cout << endl;
	// for(int i = 0;i < 2 * strnum;i++)
	// {
	// 	cout << que[i].nowque << " " << que[i].sit << endl;
	// }
	for(int i = 0;i < 2 * strnum;i++)
	{
		if(que[i].sit == maxstr)break;
		ans[que[i].num] = 1;
	}
	for(int i = 0;i < strnum;i++)
	{
		if(ans[i] == 1)cout << "1";
		else cout << "0";
	}
	// cout << endl;
	// for(int i = 0;i < 2 * strnum;i++)
	// {
	// 	cout << que[i].nowque << " " << que[i].sit << endl;
	// }
	return 0;
}