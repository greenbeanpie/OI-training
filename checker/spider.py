#! /usr/bin/python3
# encoding=utf-8
import requests
from bs4 import BeautifulSoup


class Luogu:
    def __init__(self):
        self.header = {
            "Accept-Language": "zh-CN,zh;q=0.9",
            "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 Edg/119.0.0.0",
            "Content-Type":"charset=UTF-8"
        }

    def get_mainpage(self):
        url = "https://www.luogu.com.cn/"
        res = requests.get(url,headers=self.header)
        soup = BeautifulSoup(res.content,"lxml")
        return soup.script.get_text()

    def get_problem_md(self, Problem_name="P1001"):
        url = "https://www.luogu.com.cn/problem/" + Problem_name
        res = requests.get(url,headers=self.header)
        soup = BeautifulSoup(res.content,"lxml")
        return soup.contents

if __name__=="__main__":
    app = Luogu()
    print(app.get_mainpage())