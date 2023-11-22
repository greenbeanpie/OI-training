/*
case testnum == 3,4:
prework
{
	v[i] = t
}
input
{
	v[i] = cin;
}
ans = v[i] u num

case test == 5,6:
prework
{
	v[i] = t
}
input
{
	if <-:
	vi = vj;
	else:
	vi = u;
}
ans = u num;
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// printf("here-5\n");
	//cout << freopen("tribool3.in" , "r" , stdin) << endl;
	freopen("tribool.in" , "r" , stdin);
	freopen("tribool.out" , "r" , stdout);
	int testc , testtimes;
	// printf("here-4\n");
	cin >> testc >> testtimes;
	if(testc == 3 || testc == 4)
	{
		int pointnum , asknum;
		for(int csyy = 0;csyy < testtimes;csyy++)
		{
			cin >> pointnum >> asknum;
			int *point = new int [pointnum];
			for(int i = 0;i < pointnum;i++)
			{
				point[i] = 1;
			}
			//printf("here\n");
			for(int i = 0;i < asknum;i++)
			{
				char v;
				cin >> v;
				int aimpos;
				cin >> aimpos;
				aimpos--;
				if(v == 'T')
				{
					point[aimpos] = 1;
				}
				else if(v == 'F')
				{
					point[aimpos] = -1;
				}
				else point[aimpos] = 0;
			}
			//printf("here2\n");
			int ans = 0;
			for(int i = 0;i < pointnum;i++)
			{
				if(point[i] == 0)ans++;
			}
			cout << ans << endl;
			//delete point;
		}
	}
	if(testc == 5 || testc == 6)
	{
		int pointnum , asknum;
		// printf("here-3");
		int point[100000];
		// printf("here-2\n");
		vector <int> con[100000];
		//bool worked[100000];
		// printf("here-1\n");
		for(int csyy = 0;csyy < testtimes;csyy++)
		{
			cin >> pointnum >> asknum;
			// int *point = new int [pointnum];
			// vector <int> *con = new vector <int> [pointnum];
			// printf("here0\n");
			for(int i = 0;i < pointnum;i++)
			{
				point[i] = 1;
				con[i].clear();
			}
			//printf("here\n");
			for(int i = 0;i < asknum;i++)
			{
				char v;
				cin >> v;
				if(v == 'U')
				{
					int aimpos;
					cin >> aimpos;
					aimpos--;
					point[aimpos] = 0;
				}
				else
				{
					int pos1 , pos2;//pos1 <- pos2;
					cin >> pos1 >> pos2;
					pos1--;
					pos2--;
					con[pos2].push_back(pos1);
				}
			}
			//printf("here2\n");
			// bool *worked = new bool [pointnum];
			// for(int i = 0;i < pointnum;i++)worked[i] = 0;
			for(int i = 0;i < pointnum;i++)
			{
				if(point[i] == 0)
				{
					int pos = i;
					queue <int> wait;
					wait.push(pos);
					while(wait.size() > 0)
					{
						pos = wait.front();
						wait.pop();
						// if(worked[pos] == 1)continue;
						// worked[pos] = 1;
						for(int nextpos : con[pos])
						{
							if(point[nextpos] == 0)continue;
							// if(worked[nextpos] == 1)continue;
							point[nextpos] = 0;
							wait.push(nextpos);
						}
					}
				}
			}
			//printf("here3\n");
			int ans = 0;
			for(int i = 0;i < pointnum;i++)
			{
				if(point[i] == 0)ans++;
			}
			cout << ans << endl;
			// delete point;
			// delete con;
			// delete worked;
		}
	}
	return 0;
}