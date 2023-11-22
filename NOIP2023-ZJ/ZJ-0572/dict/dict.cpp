#include<bits/stdc++.h>
using namespace std;
char s[26];
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n == 1)
		{
			cin >> s[0];
			cout << 1;
		}
		else
			{
				if(m == 1)//检测数据是否满足 
					{//每个数据只有一个字符 
					//不能交换，相当于找最大值
						int min = 0; 
						for(int i = 0;i < n;i++)
							{
								cin >> s[i];
								if(s[i] < s[min])
									{	
										min = i;								
						 			} 								
							}
						for(int i = 0;i < min;i++)
							{
								cout << 0;
							}
						cout << 1;
						for(int i = 0;i < n-min-1;i++)
							{
								cout << 0;
							}
					}
					else
						{
							if(m == 2)
								{//找率先行完的字符串 
									char min = 'z';
									char aa,bb;
									int z = 0;
									char a[20],b[20];
									for(int i = 0;i < n;i++)
										{
											cin >> aa >> bb;
											if(aa > bb)
												{
													a[i] = bb;
													b[i] = aa;
												}	
												else	
													{
														a[i] = aa;
														b[i] = bb;
													}					
										}	
									for(int i = 0;i < n;i++)
										{
											if(b[i] < min)
												{
													min = b[i];
													z = i;
												}
										}	
									for(int i = 0;i < n;i++)
										{
											if(a[i] <= a[z])
												{
													cout << 1;
												}
												else
													{
														cout << 0;
													}
										}
																	
								}
								else
									{
										char min = 'z';
										char aa,bb,c;
										int z = 0;
										char a[3000],b[3000];
										for(int i = 0;i < n;i++)
											{
												for(int j = 0;j < m;j++)
													{
														cin >> c;
														if(c <= aa)
															{
																aa = c;
															}	
														if(c > bb)	
															{
																bb = c;
															}	
													}
												a[i] = aa;
												b[i] = bb;		
											}	
										
										for(int i = 0;i < n;i++)
											{
												if(b[i] < min)
													{
														min = b[i];
														z = i;
													}
											}	
										for(int i = 0;i < n;i++)
											{
												if(a[i] <= a[z])
													{
														cout << 1;
													}
													else
														{
															cout << 0;
														}
											}
									}
						}
			}
	return 0;
}
