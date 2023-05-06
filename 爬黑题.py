import requests
from bs4 import BeautifulSoup
header={"referer":"https://www.luogu.com.cn/problem/T313426?contestId=105199","user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/112.0.0.0 Safari/537.36","cookie":"__client_id=dd4da8f44e27b8b8d905f44ee93f2a22c724c51e; _uid=499156"}
for j in range(1,19):
    response=requests.get("https://www.luogu.com.cn/problem/list?difficulty=7&page="+str(j),headers=header) 
    if(response.status_code!=200):
        raise(Exception)
        break
    soup=BeautifulSoup(response.text,"lxml")
    soup=soup.find_all("li")
    for i in soup:
        print(i.select("a")[0]["href"].replace("P",""),end=",")
