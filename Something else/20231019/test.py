#! /usr/bin/python3
# encoding=utf-8

import requests, os, sys
from bs4 import BeautifulSoup
from write import *
from tqdm import tqdm
from requests.adapters import HTTPAdapter
from requests.packages.urllib3.util.retry import Retry

os.chdir(os.getcwd() + "/Something else/20231019/")



head = """
\\documentclass[a4paper,top=2.5cm,buttom=2.5cm10.5pt]{book}

\\usepackage[UTF8]{ctex}
\\usepackage{tipa}
\\usepackage{color}
\\usepackage{geometry}

\\setmainfont{Times New Roman}

\\begin{document}

\\title{Vocabulary}
\\maketitle

\\pagenumbering{roman}
\\tableofcontents
\\newpage
\\pagenumbering{arabic}
"""

tail = """\\end{document}"""

header = {
	"Cookie": 'XSRF-TOKEN=091b0a7e-7b7c-440f-82ba-7853a686d0e8; preferredDictionaries="english-chinese-simplified,english-chinese-traditional,english,british-grammar"; _ga=GA1.3.1985437458.1697684466; _gid=GA1.3.1397756659.1697684466; amp-access=amp-DgWec-PNndO292HPfqJugg; _hjFirstSeen=1; _hjSession_2790984=eyJpZCI6Ijc4ZmUwMGE3LTM0MjQtNGNhNi1hMjYwLTE3Yjc3YmQxMTE0MSIsImNyZWF0ZWQiOjE2OTc2ODQ0Njc0NTcsImluU2FtcGxlIjpmYWxzZSwic2Vzc2lvbml6ZXJCZXRhRW5hYmxlZCI6dHJ1ZX0=; _sp_ses.7ecc=*; OptanonConsent=isGpcEnabled=0&datestamp=Thu+Oct+19+2023+11%3A01%3A20+GMT%2B0800+(China+Standard+Time)&version=202308.1.0&browserGpcFlag=0&isIABGlobal=false&hosts=&landingPath=NotLandingPage&groups=C0001%3A1%2CC0002%3A1%2CC0003%3A1%2CC0004%3A0&AwaitingReconsent=false; _sp_id.7ecc=3979def0-c2d7-4674-82ae-82dabd30e180.1697684468.1.1697684480..0b270403-3325-4540-80fe-b9939b45295d....0; _hjSessionUser_2790984=eyJpZCI6IjllMjU2Zjk3LTU5ZjAtNWNhYi1hYzI4LWUyZDlhYmIzOGY4ZiIsImNyZWF0ZWQiOjE2OTc2ODQ0Njc0NTcsImV4aXN0aW5nIjp0cnVlfQ==; _gat=1; iawsc1m=1; _sharedID=54582c27-481b-45f6-af8b-567598974fc2; _sharedID_cst=zix7LPQsHA%3D%3D; _pbjs_userid_consent_data=3524755945110770; _sharedid=0362b518-b56a-4a08-9f01-687b29d9e710; _lr_retry_request=true; _lr_env_src_ats=false; pbjs-unifiedid=%7B%22TDID%22%3A%22b82f813d-b87d-406b-920c-4d28ffdd6e63%22%2C%22TDID_LOOKUP%22%3A%22TRUE%22%2C%22TDID_CREATED_AT%22%3A%222023-09-19T03%3A10%3A42%22%7D; pbjs-unifiedid_cst=zix7LPQsHA%3D%3D; loginPopup=5; _ga_L9GCR21SZ7=GS1.3.1697684466.1.1.1697685069.27.0.0; iawpvccs=4; iawpvc=4; iawpvtc1m=4; cto_bundle=-fkA8F9VeGgzOEh2TlVBQyUyQnowREg4QkhxZlY5USUyQnRrdSUyQmQ3ZHFlSTRJJTJCTmppNmt1WCUyRlFxQWhKSlNKN1d6T0NwU3Z1RUx6WmUxSmxqOWd4RHROekZuclFJZCUyRjZQYnNyTjVoSmRpUzBpSyUyQmdGWnI3bHFVZFZ4Q3YzU1hxd0JQZmMlMkJFV0NUZjAlMkZuQm96NU9BNU14M2RVSkxaS0ElM0QlM0Q; cto_bidid=PEgR8V9vZWpoUjBET21nT0lHSUhkZUMySG1WZUhYMDJFbGxmUUR5cFJxUTZhejNRY3lmNWFDZlJrRjlJTDRoMnNxQTFlaTJKd3U3Z3BWdmx0S3FBNXZVZU8xMEZmbUQwVUZKRXpRdFNqSFZYZ3RQdyUzRA',
	"User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/118.0.0.0 Safari/537.36 Edg/118.0.2088.46",
	"sec-ch-ua-mobile": "0",
}

file = open("test.tex", "w+")

stdin = open("word.in", "r")

file.write(head)

# book = input("请输入书本:")

cntbook = int(stdin.readline())

lock=threading.Lock()

def solve(word):
	# templine.set_description("Processing "+nowpage)
	word = word.replace(" ","-")
	word = word.replace("/","-")
	session = requests.Session()
	retry = Retry(total=114514, backoff_factor=5)
	adapter = HTTPAdapter(max_retries=retry)
	session.mount('http://', adapter)
	session.mount('https://', adapter)
	response = session.get(
		"https://dictionary.cambridge.org/dictionary/english-chinese-simplified/"
		+ word,
		headers=header,
	)
	contentori = BeautifulSoup(response.text, "lxml")
	try:
		word = contentori.find_all("span",class_="hw dhw")[0].text
	except:
		print("Error occured on word "+word+", please check the code or spelling.")
	# tempfile = open("test.out","r")
	# temptext = tempfile.read()
	# tempfile.close()
	# content = BeautifulSoup(temptext ,"lxml")
	# print(content)
	try:
		lock.acquire()
		for content1 in contentori.find_all("div", class_="pr entry-body__el"):
			temp = content1.find_all("div", class_="pr dsense")
			pronoun=""
			try:
				pronoun = content1.find_all("span", class_="pron dpron")[0].text
			except:
				pass
			try:
				part_of_speech = content1.find_all("span", class_="pos dsense_pos")[0].text
			except:
				part_of_speech = content1.find_all("span",class_="pos dpos")[0].text
			attri=""
			try:
				attri = content1.find_all("span", class_="dgram")[0].text
			except:
				pass
			temp2 = content1.find_all("div",class_="def-block ddef_block")
			for content in temp2:
				chinese = content.find_all(
					"span", class_="trans dtrans dtrans-se break-cj"
				)[0].text
				try:
					attri = content.find_all("span", class_="dgram")[0].text
				except:
					pass
				describe = content.find_all("span", class_="guideword dsense_gw")
				example_ENG = content.find_all("span", class_="eg deg")
				example_CHI = content.find_all(
					"span", class_="trans dtrans dtrans-se hdb break-cj"
				)
				sentence = content.find_all("li", class_="eg dexamp hax")
				write(
					file,
					word,
					pronoun,
					chinese,
					part_of_speech,
					attri,
					example_CHI,
					example_ENG,
					sentence,
				)
		lock.release()
			# else:
			# 	# content = temp[0]
			# 	chinese = contentori.find_all(
			# 		"span", class_="trans dtrans dtrans-se break-cj"
			# 	)[0].text
			# 	part_of_speech = ""
			# 	try:
			# 		part_of_speech = contentori.find_all("span", class_="pos dpos")[0].text
			# 	except IndexError:
			# 		part_of_speech = contentori.find_all("span", class_="pos dsense_pos")[
			# 			0
			# 		].text
			# 	attri = ""
			# 	try:
			# 		attri = contentori.find_all("span", class_="dgram")[0].text
			# 	except:
			# 		pass
			# 	describe = contentori.find_all("span", class_="guideword dsense_gw")
			# 	example_ENG = contentori.find_all("span", class_="eg deg")
			# 	example_CHI = contentori.find_all(
			# 		"span", class_="trans dtrans dtrans-se hdb break-cj"
			# 	)
			# 	sentence = contentori.find_all("li", class_="eg dexamp hax")
			# 	write(
			# 		file,
			# 		word,
			# 		pronoun,
			# 		chinese,
			# 		part_of_speech,
			# 		attri,
			# 		example_CHI,
			# 		example_ENG,
			# 		sentence,
			# 	)
	except:
		print("Error occured on word "+word+", please check the code or spelling.")
		lock.release()
	# file.write("\n\n\n")


for nowbook in range(cntbook):
	book = stdin.readline().replace("\n","")

	page = int(stdin.readline())

	file.write("\\chapter{" + book + "}\n")

	for i in range(page):
		# temp = stdin.readline().split()
		nowpage = stdin.readline().replace("\n", "")
		# print("processing "+nowpage)
		file.write(
			"\\textcolor[RGB]{128,0,255}{\\section{"
			+ book
			+ " "
			+ nowpage
			+ " "
			+ stdin.readline().replace("\n", "")
			+ "}}\n"
		)
		# file.write("\\begin{enumerate}\n")
		# cnt = int(stdin.readline())
		cnt=int(stdin.readline())
		words=[]
		for i in range(cnt):
			words.append(stdin.readline().replace("\n",""))
		# words = stdin.readline()
		threadings = []
		for word in words:
			threadings.append(
				threading.Thread(
					target=solve,
					args=[
						word,
					],
				)
			)
		for t in threadings:
			t.start()
		for t in threadings:
			t.join()
			


file.write(tail)
file.close()
