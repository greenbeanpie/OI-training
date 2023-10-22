#! /usr/bin/python3
# encoding=utf-8
import threading

shape = ""

lock=threading.Lock()

def write(
	file, # 要写入的文件
	word="", # 原文
	pronunciation="", # 音标
	chinese="", # 中文
	part_of_speech="", # 词性
	attri="", # 其他属性，如是否可数
	example_CHN=[], # 例子中文
	example_ENG=[], # 例子英文
	sentence=[], # 只有英文的例句
):
	try:
		pronunciation=pronunciation.replace("ː"," \\textlengthmark ")
		pronunciation=pronunciation.replace("ˈ"," \\textprimstress ")
		pronunciation=pronunciation.replace("ɪ"," \\i ")
		pronunciation=pronunciation.replace("ɔ"," \\textopeno ")
		pronunciation=pronunciation.replace("ɒ"," \\textturnscripta ")
		pronunciation=pronunciation.replace("ʃ"," \\textesh ")
		pronunciation=pronunciation.replace("ˌ", "\\textsecstress ")
		pronunciation=pronunciation.replace("ʒ"," \\textyogh ")
		pronunciation=pronunciation.replace("ʌ"," \\textturnv ")
		pronunciation=pronunciation.replace("ɡ"," \\textscriptg ")
		pronunciation=pronunciation.replace("ɑ"," \\textscripta ")
		pronunciation=pronunciation.replace("ʊ"," \\textupsilon ")
		pronunciation=pronunciation.replace("ɜ"," \\textrevepsilon ")
		# pronunciation=pronunciation.replace("","")
		lock.acquire()
		file.write("\\begin{itemize}\n")
		attri.replace("C"," $ C $ ")
		attri.replace("U"," $ U $ ")
		attri.replace("I"," $ I $ ")
		attri.replace("T"," $ T $ ")
		file.write("\\item "+word+" "+pronunciation+" $ "+part_of_speech+" $ "+attri+" "+chinese+"\n")
		if len(example_CHN)>0:
			file.write("\\begin{itemize}\n")
			while len(example_CHN)>3:
				example_CHN.pop()
				example_ENG.pop()
			for i in range(len(example_CHN)):
				file.write("\\item[$\\diamond$] ")
				file.write(example_ENG[i].text.replace("$"," \\$ "))
				file.write("\n")
				file.write(example_CHN[i].text.replace("%"," $ \\% $ "))
				file.write("\n")
			file.write("\\end{itemize}\n")
		# if len(sentence)!=0:
		# 	file.write("sentence:\n")
		# 	file.write("\\begin{itemize}\n")
		# 	for i in sentence:
		# 		file.write("\\item[$\\diamond$] ")
		# 		file.write(i.text)
		# 		file.write("\n")
		# 	file.write("\\end{itemize}\n")
		file.write("\\end{itemize}\n")
		lock.release()
	except:
		print("Error occured on word "+word+", please check the code or spelling.")
