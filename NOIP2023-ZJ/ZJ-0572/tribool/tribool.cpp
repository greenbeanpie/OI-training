#include<bits/stdc++.h>
using namespace std;
int x[100005];
int fang(int n)
{
	n--;
	int num = 3;
	while(n > 0)
		{
			if(n%2 == 1)
				{
					num *= 3;
					n--;
				}
				else
					{
						num *= num;
						n /= 2;
					}
		}
	return num;	
}
int work34()
{
	int n,m;
	cin >> n >> m;
	char a;
	int b;
	memset(x,-1,sizeof(x));
	for(int i = 1;i <= m;i++)
		{
			cin >> a >> b;
			if(a == 'T')
				{
					x[b] = 1;
				}
				else
					{
						if(a == 'F')
							{
								x[b] = -1;
							}
							else
								{
									if(a == 'U')
										{
											x[b] = 0;
										}
								}	
					}
								
		}	
	int sum = 0;
	for(int i = 1;i <= n;i++)
		{
			if(x[i] == 0)
				{
					sum++;
				}
		}
	cout << sum << endl;
	return 0;
}
int work78()
{
	int n,m;
	cin >> n >> m;
	char a;
	int b,c;
	memset(x,0,sizeof(x));
	return 0;
}
int work12()
{
	int n,m;
	cin >> n >> m;
	char a;
	int b,c;
	int chengxu[11][3];
	for(int i = 0;i < m;i++)
		{
			cin >> a;
			if(a == 'T')
				{
					chengxu[i][0] = 1;
					cin >> chengxu[i][1];
				}
				else
					{
						if(a == 'U')
							{
								chengxu[i][0] = 0;
								cin >> chengxu[i][1];
							}
							else
								{
									if(a == 'F')
										{
											chengxu[i][0] = -1;
											cin >> chengxu[i][1];
										}
										else
											{
												if(a == '+')
													{
														chengxu[i][0] = 11;
														cin >> chengxu[i][1];
														cin >> chengxu[i][2];
													}
													else
														{
															if(a == '-')
																{
																	chengxu[i][0] = 22;
																	cin >> chengxu[i][1];
																	cin >> chengxu[i][2];
																}
														}
											}
								}
					}
					
						
							
		}
	int chu[n];
	int min = 0;
	int sum;
	memset(chu,-1,sizeof(chu));
	for(int i = 1;i < fang(n);i++)
		{
			chu[1]++;
			for(int i = 1;i <= n;i++)
				{
					if(chu[i] > 1)
						{
							chu[i+1]++;
							chu[i] = -1;
						}
				}
			for(int i = 1;i <= n;i++)
				{
					x[i] = chu[i];
				}
			for(int i = 0;i < m;i++)
				{
					if(chengxu[i][0] == 1)
						{
							x[chengxu[i][1]] = 1;
						}
						else
							{
								if(chengxu[i][0] == 0)
									{
										x[chengxu[i][1]] = 0;
									}
									else
										{
											if(chengxu[i][0] == -1)
												{
													x[chengxu[i][1]] = -1;
												}
												else
													{
														if(chengxu[i][0] == 11)
															{
																x[chengxu[i][1]] = x[chengxu[i][2]];
															}
															else
																{
																	x[chengxu[i][1]] = x[chengxu[i][2]]*-1;
																}
													}
													
										}
							}
							
								
				}
			sum = 0;
			for(int i = 1;i <= n;i++)
				{
					if(chu[i] == x[i])
						{
							sum++;
						}
				}
			if(sum == n)
				{
					sum = 0;
					for(int i = 1;i <= n;i++)
						{
							if(chu[i] == 0)
								{
									sum++;
								}
						} 
					if(sum < min) 
						{
							min = sum;
						}
				}
		}
	cout << sum << endl;
	return 0;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c == 3 || c == 4)
		{
			for(int i = 0;i < t;i++)
				{
					work34();
				}
		}
		else
			{
				if(c == 7 || c == 8)
					{
						for(int i = 0;i < t;i++)
						{
							work78();
						}
					}
					else
						{
							if(c == 1 || c == 2)
							{
								for(int i = 0;i < t;i++)
								{
									work12();
								}
							}
						}		
			}			
	return 0;
}
