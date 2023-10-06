# encoding=utf-8
import os, prettytable, time, subprocess, threading, sys, multiprocessing
from math import *

f = 1  # 请输入测试平台速度/你的电脑速度的比值
wawrite=threading.Lock()
lock1 = threading.Lock()

result = prettytable.PrettyTable()
result.field_names = ["Test Case", "Result", "Time"]

if sys.platform[0:3] == "win":
    print(
        "\033[43mWindows platform does not support set memory limit(this feature will be released soon). Use Linux to enable this feature.\033[0m"
    )

print(
    "Python code checker for OI.\nDeveloped by HMZ_0915.\nThese features are developing in progress: check by subtasks, memory limit set(on linux platform)\n\n"
)
if sys.platform[0:3] == "win":
    print(
        "\033[43mWindows platform does not support set memory limit(this feature will be released soon). Use Linux to enable this feature.\033[0m"
    )

print(
    "Python code checker for OI.\nDeveloped by HMZ_0915.\nThese features are developing in progress: check by subtasks, memory limit set(on linux platform)\n\n"
)

work_dir = "C:\\Users\\Administrator.DESKTOP-51JH54T\\Documents\\OI-training\\"

print("目前支持自动查找文件目录的题目: Luogu, CodeForces, ZROI 10-day NOIP")

problem_name = input("请输入希望进行对拍的题目 ")
try:
    if problem_name[0] == "P":
        os.chdir(
            work_dir
            + "Luogu\\"
            + problem_name[0:2]
            + "\\"
            + problem_name[0:3]
            + "\\"
            + problem_name
            + "\\"
        )
    elif problem_name[0:2] == "CF":
        problem_name = problem_name[2:]
        sub_dir = problem_name[: len(problem_name) - 1]
        os.chdir(
            work_dir
            + "Codeforce\\"
            + sub_dir
            + "\\"
            + problem_name[len(problem_name) - 1 :]
        )
        problem_name = problem_name[len(problem_name) - 1 :]
    elif problem_name[0:2] == "ZR":
        if problem_name[0:8] == "ZR-NOIP-":
            if problem_name[8:10] == "10":
                os.chdir(
                    work_dir
                    + "ZROI\\NOIP10\\"
                    + problem_name[8:10]
                    + "\\"
                    + problem_name[11:]
                )
                problem_name = problem_name[11:]
            else:
                os.chdir(
                    work_dir
                    + "ZROI\\NOIP10\\"
                    + problem_name[8:9]
                    + "\\"
                    + problem_name[10:]
                )
                problem_name = problem_name[10:]
    elif problem_name == "test":
        os.chdir(work_dir + "\\test\\")
    else:
        relative_dir = input("请输入路径 ")
        try:
            os.chdir(work_dir + relative_dir)
        except:
            os.chdir(relative_dir)
except FileNotFoundError:
    relative_dir = input("请输入路径 ")
    try:
        os.chdir(work_dir + relative_dir)
    except:
        os.chdir(relative_dir)

def compile(problem,OJ):
    if OJ:
        return subprocess.open(["g++",problem+".cpp","-O2","-Wall","-Wextra","--std=c++14","-o"+problem,"-DONLINE_JUDGE"])
    return subprocess.open(["g++",problem+".cpp","-O2","-Wall","-Wextra","--std=c++14","-o"+problem])

prc = 1
prc1 = 1

spj = bool(int(input("是否需要使用SPJ(testlib.h)? 0: 否 1: 是 ")))
multi_threading = int(input("使用线程数量: (建议数量:" + str(multiprocessing.cpu_count()/2) + ") "))
generator_cpp = bool(int(input("请选择生成器语言: Python(0)/C++(1) ")))
if generator_cpp:
    if multi_threading == 1:
        prc = subprocess.Popen(["g++", "generator.cpp", "-Ofast", "-ogenerator"])
    else:
        prc = subprocess.Popen(
            ["g++", "generator.cpp", "-Ofast", "-ogenerator", "-DONLINE_JUDGE"]
        )

if spj:
    subprocess.Popen(["g++", "checker.cpp", "-Ofast", "-ochecker"])
elif multi_threading == 1:
    prc = subprocess.Popen(
        [
            "g++",
            problem_name + "_TJ.cpp",
            "-O2",
            "-Wall",
            "-Wextra",
            "--std=c++23",
            "-o" + problem_name + "_TJ",
        ]
    )
    prc1 = subprocess.Popen(
        [
            "g++",
            problem_name + ".cpp",
            "-O2",
            "-Wall",
            "-Wextra",
            "--std=c++23",
            "-o" + problem_name,
        ]
    )
else:
    prc = subprocess.Popen(
        [
            "g++",
            problem_name + "_TJ.cpp",
            "-O2",
            "-Wall",
            "-Wextra",
            "--std=c++23",
            "-DONLINE_JUDGE",
            "-o" + problem_name + "_TJ",
        ]
    )
    prc1 = subprocess.Popen(
        [
            "g++",
            problem_name + ".cpp",
            "-O2",
            "-Wall",
            "-Wextra",
            "--std=c++23",
            "-DONLINE_JUDGE",
            "-o" + problem_name,
        ]
    )

cnt = int(input("请输入对拍次数 "))
timeout = float(input("请输入超时时间(单位:s) "))
timeout *= f  # Don't ask me why. I just know the computer on Luogu platform is fx faster than the computer in my school. You can change this in your own way.
stopwhennotac = bool(int(input("是否需要在第一次答案错误时退出?(1. 是 0. 否)")))
validator = bool(int(input("是否需要使用数据校验程序(validator.cpp)?(1: 是 0: 否)")))
prc2 = 0
prc2 = 0
if validator:
    prc2 = subprocess.Popen(
        ["g++", "validator.cpp", "-ovalidator", "-O2", "-Wall" "-Wextra" "--std=c++23"]
    )
prc.communicate()
prc1.communicate()
try:
    prc2.communicate()
except:
    pass

tot = 0

def writedata(stdin):
    wawrite.acquire()
    output = open(problem_name+"_hack.in","w+")
    output.write(stdin.decode().replace("\n\n","\n"))
    output.close()
    print(result.get_string())
    print("Hack data has written. Check will now exit.")
    os.system("taskkill /im python.exe /f")
    # sys.exit(0)

def check(cnt1):
    global tot
    for i in range(1, cnt1 + 1):
        wawrite.acquire()
        wawrite.release()
        # launch your data generator or generate input data here
        stdin = ""
        stdout = ""
        stdout_TJ = ""
        stderr = ""
        if generator_cpp:
            # os.system(".\\generator")
            stdin, stderr = subprocess.Popen(
                [".\\generator.exe"], stdin=subprocess.PIPE, stdout=subprocess.PIPE
            ).communicate()
        else:
            # os.system("python generator.py")
            stdin, stderr = subprocess.Popen(
                ["python", "generator.py"],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
            ).communicate()
        if validator:
            while subprocess.Popen([".\\validator.exe"]).returncode != 0:
                stdin, stderr = subprocess.Popen(
                    ["python", "generator.py"],
                    stdin=subprocess.PIPE,
                    stdout=subprocess.PIPE,
                ).communicate()
        # launch your program here
        start_time = time.perf_counter()
        prcTJ = subprocess.Popen(
            [".\\" + problem_name + "_TJ"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
        )
        output_tj, err_TJ = prcTJ.communicate(input=stdin)
        output_hmz = ""
        proc = subprocess.Popen(
            [".\\" + problem_name], stdin=subprocess.PIPE, stdout=subprocess.PIPE
        )
        try:
            output_hmz, err_hmz = proc.communicate(input=stdin, timeout=timeout)
            used_time = time.perf_counter() - start_time
            used_time /= f
            if proc.returncode != 0:
                result.add_row([str(tot), "\033[35m Runtime Error \033[0m", "-1ms"])
                if stopwhennotac:
                    writedata(stdin)
                continue
        except subprocess.TimeoutExpired:
            lock1.acquire()
            tot = tot + 1
            result.add_row(
                [str(tot), "\033[35m Time Limit Exceeded \033[0m", ">1000ms"]
            )
            lock1.release()
            if stopwhennotac:
                writedata(stdin)
            continue
        output_hmz = output_hmz.decode()
        output_tj = output_tj.decode()
        while (
            output_hmz[len(output_hmz) - 1 : len(output_hmz)] == "\n"
            or output_hmz[len(output_hmz) - 1 : len(output_hmz)] == " "
        ):
            output_hmz = output_hmz[: len(output_hmz) - 1]
        while (
            output_tj[len(output_tj) - 1 : len(output_tj)] == "\n"
            or output_tj[len(output_tj) - 1 : len(output_tj)] == " "
        ):
            output_tj = output_tj[: len(output_tj) - 1]
        output_hmz = output_hmz.replace(" \n", "\n")
        output_tj = output_tj.replace(" \n", "\n")
        lock1.acquire()
        tot = tot + 1
        if output_tj != output_hmz:
            result.add_row(
                [
                    str(tot),
                    "\033[31m Wrong Answer \033[0m",
                    str(round(used_time * 1000)) + "ms",
                ]
            )
            if stopwhennotac:
                writedata(stdin)
                
        else:
            result.add_row(
                [
                    str(tot),
                    "\033[32m Accepted \033[0m",
                    str(round(used_time * 1000)) + "ms",
                ]
            )
        lock1.release()
        print("checking in progress: " + str(tot) + "/" + str(cnt), end="\r")


if multi_threading > 1:
    total = floor(cnt / multi_threading)
    num1 = total
    num2 = total + 1
    cnt2 = cnt % multi_threading
    cnt1 = multi_threading - cnt2
    threads = []
    for i in range(cnt1):
        threads.append(threading.Thread(target=check, args=(num1,)))
    for i in range(cnt2):
        threads.append(threading.Thread(target=check, args=(num2,)))
    for i in range(cnt1 + cnt2):
        threads[i].start()
    for i in range(cnt1 + cnt2):
        threads[i].join()

else:
    for tot in range(1, cnt + 1):
        # launch your data generator or generate input data here
        if generator_cpp:
            # os.system(".\\generator")
            subprocess.Popen([".\\generator.exe"]).communicate()
        else:
            # os.system("python generator.py")
            subprocess.Popen(["python", "generator.py"]).communicate()
        if validator:
            while subprocess.Popen([".\\validator.exe"]).returncode != 0:
                os.system(".\\generator")
        # launch your program here
        start_time = time.perf_counter()
        proc = subprocess.Popen([".\\" + problem_name])

        if not (spj):
            prcTJ = subprocess.Popen([".\\" + problem_name + "_TJ"])
            try:
                rescode = proc.communicate(timeout=timeout)
                used_time = time.perf_counter() - start_time
                used_time /= f
                if proc.returncode != 0:
                    result.add_row([str(tot), "\033[35m Runtime Error \033[0m", "-1ms"])
                    if stopwhennotac:
                        break
                    continue
            except subprocess.TimeoutExpired:
                result.add_row(
                    [str(tot), "\033[35m Time Limit Exceeded \033[0m", ">1000ms"]
                )
                if stopwhennotac:
                    break
                continue
            hmz = open(problem_name + ".out", "r")
            output_hmz = hmz.read()
            prcTJ.communicate()
            tj = open(problem_name + "_TJ.out", "r")
            output_tj = tj.read()
            hmz.close()
            tj.close()
            while (
                output_hmz[len(output_hmz) - 1 : len(output_hmz)] == "\n"
                or output_hmz[len(output_hmz) - 1 : len(output_hmz)] == " "
            ):
                output_hmz = output_hmz[: len(output_hmz) - 1]
            while (
                output_tj[len(output_tj) - 1 : len(output_tj)] == "\n"
                or output_tj[len(output_tj) - 1 : len(output_tj)] == " "
            ):
                output_tj = output_tj[: len(output_tj) - 1]
            if output_tj != output_hmz:
                result.add_row(
                    [
                        str(tot),
                        "\033[31m Wrong Answer \033[0m",
                        str(round(used_time * 1000)) + "ms",
                    ]
                )
                if stopwhennotac:
                    break
            else:
                result.add_row(
                    [
                        str(tot),
                        "\033[32m Accepted \033[0m",
                        str(round(used_time * 1000)) + "ms",
                    ]
                )
        else:
            # Special Judge required
            try:
                rescode = proc.communicate(timeout=timeout)
                used_time = time.perf_counter() - start_time
                used_time /= f
                if proc.returncode != 0:
                    result.add_row([str(tot), "\033[35m Runtime Error \033[0m", "-1ms"])
                    if stopwhennotac:
                        break
                    continue
            except subprocess.TimeoutExpired:
                result.add_row(
                    [str(tot), "\033[35m Time Limit Exceeded \033[0m", ">1000ms"]
                )
                if stopwhennotac:
                    break
                # result.add_row([str(tot), "\033[35m Runtime Error \033[0m", "-1ms"])
                continue

            prc = subprocess.Popen(
                [
                    ".\\checker",
                    problem_name + ".in ",
                    problem_name + ".out ",
                    problem_name + ".ans ",
                    problem_name + ".res",
                ]
            )
            res = open(problem_name + ".res", "r+")
            if res.read().find("Wrong Answer"):
                result.add_row(
                    [
                        str(tot),
                        "\033[31m Wrong Answer \033[0m",
                        str(round(used_time / f)) + "ms",
                    ]
                )
                if stopwhennotac:
                    break
            else:
                result.add_row(
                    [
                        str(tot),
                        "\033[32m Accepted \033[0m",
                        str(round(used_time / f)) + "ms",
                    ]
                )
        print("checking in progress: " + str(tot) + "/" + str(cnt), end="\r")

print("\n")
print(result.get_string())
