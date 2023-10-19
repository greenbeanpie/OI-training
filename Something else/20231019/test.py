#! /usr/bin/python3
# encoding=utf-8

import requests, os
from bs4 import BeautifulSoup
from write import *

os.chdir(os.getcwd() + "/Something else/")


head = """
\\documentclass[a4paper,12pt]{article}

\\usepackage[UTF8]{ctex}
\\usepackage[UTF8]{fontspec}

\\setmainfont{Times New Roman}

\\begin{document}
"""

tail = """\\end{document}"""

header = {
    "Cookie": 'XSRF-TOKEN=091b0a7e-7b7c-440f-82ba-7853a686d0e8; preferredDictionaries="english-chinese-simplified,english-chinese-traditional,english,british-grammar"; _ga=GA1.3.1985437458.1697684466; _gid=GA1.3.1397756659.1697684466; amp-access=amp-DgWec-PNndO292HPfqJugg; _hjFirstSeen=1; _hjSession_2790984=eyJpZCI6Ijc4ZmUwMGE3LTM0MjQtNGNhNi1hMjYwLTE3Yjc3YmQxMTE0MSIsImNyZWF0ZWQiOjE2OTc2ODQ0Njc0NTcsImluU2FtcGxlIjpmYWxzZSwic2Vzc2lvbml6ZXJCZXRhRW5hYmxlZCI6dHJ1ZX0=; _sp_ses.7ecc=*; OptanonConsent=isGpcEnabled=0&datestamp=Thu+Oct+19+2023+11%3A01%3A20+GMT%2B0800+(China+Standard+Time)&version=202308.1.0&browserGpcFlag=0&isIABGlobal=false&hosts=&landingPath=NotLandingPage&groups=C0001%3A1%2CC0002%3A1%2CC0003%3A1%2CC0004%3A0&AwaitingReconsent=false; _sp_id.7ecc=3979def0-c2d7-4674-82ae-82dabd30e180.1697684468.1.1697684480..0b270403-3325-4540-80fe-b9939b45295d....0; _hjSessionUser_2790984=eyJpZCI6IjllMjU2Zjk3LTU5ZjAtNWNhYi1hYzI4LWUyZDlhYmIzOGY4ZiIsImNyZWF0ZWQiOjE2OTc2ODQ0Njc0NTcsImV4aXN0aW5nIjp0cnVlfQ==; _gat=1; iawsc1m=1; _sharedID=54582c27-481b-45f6-af8b-567598974fc2; _sharedID_cst=zix7LPQsHA%3D%3D; _pbjs_userid_consent_data=3524755945110770; _sharedid=0362b518-b56a-4a08-9f01-687b29d9e710; _lr_retry_request=true; _lr_env_src_ats=false; pbjs-unifiedid=%7B%22TDID%22%3A%22b82f813d-b87d-406b-920c-4d28ffdd6e63%22%2C%22TDID_LOOKUP%22%3A%22TRUE%22%2C%22TDID_CREATED_AT%22%3A%222023-09-19T03%3A10%3A42%22%7D; pbjs-unifiedid_cst=zix7LPQsHA%3D%3D; loginPopup=5; _ga_L9GCR21SZ7=GS1.3.1697684466.1.1.1697685069.27.0.0; iawpvccs=4; iawpvc=4; iawpvtc1m=4; cto_bundle=-fkA8F9VeGgzOEh2TlVBQyUyQnowREg4QkhxZlY5USUyQnRrdSUyQmQ3ZHFlSTRJJTJCTmppNmt1WCUyRlFxQWhKSlNKN1d6T0NwU3Z1RUx6WmUxSmxqOWd4RHROekZuclFJZCUyRjZQYnNyTjVoSmRpUzBpSyUyQmdGWnI3bHFVZFZ4Q3YzU1hxd0JQZmMlMkJFV0NUZjAlMkZuQm96NU9BNU14M2RVSkxaS0ElM0QlM0Q; cto_bidid=PEgR8V9vZWpoUjBET21nT0lHSUhkZUMySG1WZUhYMDJFbGxmUUR5cFJxUTZhejNRY3lmNWFDZlJrRjlJTDRoMnNxQTFlaTJKd3U3Z3BWdmx0S3FBNXZVZU8xMEZmbUQwVUZKRXpRdFNqSFZYZ3RQdyUzRA',
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36 Edg/118.0.2088.46",
    "sec-ch-ua-mobile": "0",
}

file = open("test.tex", "w+")

file.write(head)

cnt = int(input("输入次数:"))

page = input("请输入页数:")

for j in range(cnt):
    word = input()

    response = requests.get(
        "https://dictionary.cambridge.org/dictionary/english-chinese-simplified/"
        + word,
        headers=header,
    )
    content = BeautifulSoup(response.text, "lxml")
    res = content.find_all("div", class_="pr dsense")
    if len(res)==0:
        write(
        file,
        word,
        content.find_all("span", class_="trans dtrans dtrans-se break-cj")[0].text,
        content.find_all("span", class_="pos dpos")[0].text,
        content.find_all(
            "span", class_="trans dtrans dtrans-se hdb break-cj", lang="zh-Hans"
        ),
        content.find_all("span", class_="eg deg"),
        content.find_all("li", class_="eg dexamp hax"),
    )
    # for i in content.find_all("span",class_="pos dpos"):
    # 	print(i.text)
    # for i in content.find_all("span", class_="pos dsense_pos"):
    # 	print(i.text)
    # for i in content.find_all("span", class_="trans dtrans dtrans-se break-cj"):
    # 	print(i.text)
    # for i in content.find_all(
    # 	"span", class_="trans dtrans dtrans-se hdb break-cj", lang="zh-Hans"
    # ):
    # 	print(i.text)
    # for i in content.find_all("span", class_="eg deg"):
    # 	print(i.text)
    # for i in content.find_all("li", class_="eg dexamp hax"):
    # 	print(i.text)
    # for j in res:
    pronoun = content.find_all("span", class_="pron dpron")[0]
	temp = content.find_all("")
    write(
        file,
        word,
        j.find_all("span", class_="trans dtrans dtrans-se break-cj")[0].text,
        j.find_all("span", class_="pos dpos")[0].text,
        j.find_all(
            "span", class_="trans dtrans dtrans-se hdb break-cj", lang="zh-Hans"
        ),
        j.find_all("span", class_="eg deg"),
        j.find_all("li", class_="eg dexamp hax"),
    )
    file.write("\n\n\n")

file.write(tail)
file.close()
