// This Code was made by Chinese_zjc_.
#include<bits/stdc++.h>
int T;
int mysystem(std::string command){return system(command.c_str());}
signed main()
{
    std::ios::sync_with_stdio(false);
    while(!(mysystem("./mkdata > dict.in")||
            mysystem("./boom")||
            mysystem("./dict")||
            mysystem("diff dict.out dict.ans")))
        std::cout<<++T<<std::endl;
    return 0;
}