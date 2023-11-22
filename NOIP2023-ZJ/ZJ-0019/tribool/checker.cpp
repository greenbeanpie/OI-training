// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int T;
int mysystem(std::string command){return system(command.c_str());}
signed main()
{
    std::ios::sync_with_stdio(false);
    while(!(mysystem("./mkdata > tribool.in")||
            mysystem("./boom")||
            mysystem("./tribool")||
            mysystem("diff tribool.out tribool.ans")))
        std::cout<<++T<<std::endl;
    return 0;
}