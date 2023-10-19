#! /usr/bin/python3
# encoding=utf-8

shape = ""


def write(
    file,
    word="",
    pronunciation="",
    chinese="",
    part_of_speech="",
    example_CHN=[],
    example_ENG=[],
    sentence=[],
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
