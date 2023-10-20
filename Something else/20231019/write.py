#! /usr/bin/python3
# encoding=utf-8

shape = ""


def write(
    file, # 要写入的文件
    word="", # 原文
    pronunciation="", # 音标
    chinese="", # 中文
    part_of_speech="", # 词性
    attri="" # 其他属性，如是否可数
    example_CHN=[], # 例子中文
    example_ENG=[], # 例子英文
    sentence=[], # 只有英文的例句
):
    file.write("")
    file.write("\\begin{itemize}\n")
    file.write("\\item ")
    file.write(word + " $ " + part_of_speech + " $")
    file.write("\n")
    file.write("\\item[] ")
    file.write(chinese)
    file.write("\n")
    file.write("\\item ")
    file.write("examples:\n")
    file.write("\\begin{enumerate}\n")
    for i in range(len(example_CHN)):
        file.write("\\item ")
        file.write(example_ENG[i].text)
        file.write("\n")
        file.write(example_CHN[i].text)
        file.write("\n")
    file.write("\\end{enumerate}\n")
    file.write("sentence:\n")
    file.write("\\begin{enumerate}\n")
    for i in sentence:
        file.write("\\item ")
        file.write(i.text)
        file.write("\n")
    file.write("\\end{enumerate}\n")
    file.write("\\end{itemize}\n")
