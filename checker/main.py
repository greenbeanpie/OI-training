#! /usr/bin/python3
# encoding=utf-8
import os, prettytable, time, subprocess, threading, sys, multiprocessing,  json,warnings
try:
    import cyaron
except:
    pass
try:
    import PyQt5
except:
    warnings.warn("Warning: PyQt5 isn't installed. GUI will not be available.")
from math import ceil, floor

true = True
false = False

f = 1  # 请输入测试平台速度/你的电脑速度的比值
wawrite = threading.Lock()
lock1 = threading.Lock()
consolelock = threading.Lock()

result = prettytable.PrettyTable()
result.field_names = ["Test Case", "Result", "Time"]

max_buffer_size = -1

generator_timeout = 5.0

islinux = True

if sys.platform[0:3] == "win":
    islinux = False
    print(
        "\033[43mWindows platform does not support set memory limit(this feature will be released soon). Use Linux to enable this feature.\nWarning: SPJ and interactive problems are not supported yet,don't try to use them!\n\033[0m"
    )

print(
    "Python code checker for OI.\nDeveloped by HMZ_0915.\nThese features are developing in progress: check by subtasks, memory limit set(on linux platform)\n\n"
)

# work_dir = "F:/OI-training/"
work_dir = os.getcwd() + "/"

print("目前支持自动查找文件目录的题目: Luogu, CodeForces, ZROI 10-day NOIP")

enable_sanitizer = False


def findfile(problem_name):
    try:
        if problem_name[0] == "P":
            os.chdir(
                work_dir
                + "Luogu/"
                + problem_name[0:2]
                + "/"
                + problem_name[0:3]
                + "/"
                + problem_name
                + "/"
            )
        elif problem_name[0:2] == "CF":
            problem_name = problem_name[2:]
            sub_dir = problem_name[: len(problem_name) - 1]
            os.chdir(
                work_dir
                + "Codeforce/"
                + sub_dir
                + "/"
                + problem_name[len(problem_name) - 1 :]
            )
            problem_name = problem_name[len(problem_name) - 1 :]
        elif problem_name[0:2] == "ZR":
            if problem_name[0:10] == "ZR-NOIP10-":
                if problem_name[10:12] == "10":
                    os.chdir(
                        work_dir
                        + "ZROI/NOIP10/"
                        + problem_name[10:12]
                        + "/"
                        + problem_name[13:]
                    )
                    problem_name = problem_name[13:]
                else:
                    os.chdir(
                        work_dir
                        + "ZROI/NOIP10/"
                        + problem_name[10:11]
                        + "/"
                        + problem_name[11:]
                    )
                    problem_name = problem_name[11:]
            elif problem_name[0:10] == "ZR-NOIP20-":
                if int(problem_name[10:12]) >= 10:
                    os.chdir(
                        work_dir
                        + "ZROI/NOIP20/"
                        + problem_name[10:12]
                        + "/"
                        + problem_name[13:]
                    )
                    problem_name = problem_name[13:]
                else:
                    os.chdir(
                        work_dir
                        + "ZROI/NOIP20/"
                        + problem_name[10:11]
                        + "/"
                        + problem_name[11:]
                    )
                    problem_name = problem_name[11:]
            elif problem_name[0:7] == "ZR-CSP-":
                os.chdir(
                    work_dir + "ZROI/CSP7/" + problem_name[7:8] + "/" + problem_name[9:]
                )
                problem_name = problem_name[9:]
        elif problem_name[0:2] == "SP":
            os.chdir(work_dir + "SPOJ/" + problem_name)
        elif problem_name[0:3] == "UVA":
            os.chdir(work_dir + "UVA/" + problem_name)
        elif problem_name == "test":
            os.chdir(work_dir + "/test/")
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
    return problem_name


def compile(problem, OJ, sanitizer=enable_sanitizer):
    option = [
        "g++",
        problem + ".cpp",
        "-O2",
        "-Wall",
        "-Wextra",
        "--std=c++14",
        "-o" + problem,
    ]
    if OJ:
        option.append("-DONLINE_JUDGE")
    if sanitizer:
        option.append("-static-libasan")
        option.append("-static-libubsan")
        option.append("-fsanitize=undefined,address")
    return subprocess.Popen(option)


tot = 0

readhistory = bool(int(input("Read last configuration from history.cfg?")))

if not readhistory:
    problem_name = input("请输入希望进行对拍的题目 ")
    problem_name = findfile(problem_name)
    enable_sanitizer = bool(int(input("Enable UE/Address sanitizer?")))

    global prc, prc1

    spj = bool(int(input("是否需要使用SPJ(testlib.h)? 0: 否 1: 是 ")))
    multi_threading = int(
        input("使用线程数量: (建议数量:" + str(multiprocessing.cpu_count() / 2) + ") ")
    )
    generator_cpp = bool(int(input("请选择生成器语言: Python(0)/C++(1) ")))
    if generator_cpp:
        prc = compile("generator", 1)

    if spj:
        compile("checker", 1)

    prc = compile(problem_name + "_TJ", 1)
    prc1 = compile(problem_name, 1)

    cnt = int(input("请输入对拍次数 "))
    timeout = float(input("请输入超时时间(单位:s) "))
    timeout *= f  # Don't ask me why. I just know the computer on Luogu platform is fx faster than the computer in my school. You can change this in your own way.
    stopwhennotac = bool(int(input("是否需要在第一次答案错误时退出?(1. 是 0. 否)")))

    validator = bool(int(input("是否需要使用数据校验程序(validator.cpp)?(1: 是 0: 否)")))

    op = bool(int(input("Does the data generated by generator.cpp need additional operation? 0:N 1:Y")))  # type: ignore

    if op:
        prc3 = compile("operate", 1)
        prc3.communicate()
    if validator:
        prc2 = compile("validator", 1)
        prc2.communicate()
    prc.communicate()
    prc1.communicate()
    if prc.returncode != 0 or prc1.returncode != 0:
        print("Compile Error.\nChecker will now exit")

    history = {
        "dir": os.getcwd(),
        "problem_name": problem_name,
        "enable_sanitizer": enable_sanitizer,
        "multi_threading": multi_threading,
        "generator_cpp": generator_cpp,
        "spj": spj,
        "cnt": cnt,
        "timeout": timeout,
        "stopwhennotac": stopwhennotac,
        "validator": validator,
        "op": op,
    }

    temp = json.dumps(history, ensure_ascii=False)
    hist = open(work_dir + "checker/history.cfg", "w+")
    hist.write(temp)
    hist.close()
else:
    histfile = open(work_dir + "checker/history.cfg", "r+")
    content = histfile.read()
    hist = json.loads(content)
    problem_name = hist["problem_name"]
    multi_threading = hist["multi_threading"]
    enable_sanitizer = hist["enable_sanitizer"]
    generator_cpp = hist["generator_cpp"]
    spj = hist["spj"]
    cnt = hist["cnt"]
    timeout = hist["timeout"]
    stopwhennotac = hist["stopwhennotac"]
    validator = hist["validator"]
    op = hist["op"]
    os.chdir(hist["dir"])
    if generator_cpp:
        prc4 = compile("generator", 1)
        prc4.communicate()
    if spj:
        compile("checker", 1)
    prc = compile(problem_name + "_TJ", 1)
    prc1 = compile(problem_name, 1)
    if op:
        prc3 = compile("operate", 1)
        prc3.communicate()
    if validator:
        prc2 = compile("validator", 1)
        prc2.communicate()
    prc.communicate()
    prc1.communicate()

    if prc.returncode != 0 or prc1.returncode != 0:
        print("Compile Error.\nChecker will now exit")


def writedata(stdin):
    wawrite.acquire()
    output = open(problem_name + "_hack.in", "w+")
    output.write(stdin.replace("\n\n", "\n"))
    output.close()
    print(result.get_string())
    print("Hack data has written. Check will now exit.")
    os._exit(0)


def compare(
    str1="", str2="", mode=0
):  # 0(default). ignore space in the end of line and the last \n 1. strict mode
    if mode == 0:
        str1 = str1.replace(" \n", "\n")
        str2 = str2.replace(" \n", "\n")
        while len(str1) > 1 and (
            str1[len(str1) - 1] == "\n" or str1[len(str1) - 1] == " "
        ):
            str1 = str1[0 : len(str1) - 1]
        while len(str2) > 1 and (
            str2[len(str2) - 1] == "\n" or str2[len(str2) - 1] == " "
        ):
            str2 = str2[0 : len(str2) - 1]
        return str1 == str2
    elif mode == 1:
        return str1 == str2
    else:
        raise RuntimeError


# return code:
# 0: Accepted
# 1: Wrong Answer
# 2: Presentation Error
# 3. Unknown Error (Special Judge Error)
# 4. Output Limit Exceeded
# 5. Runtime Error
# 6. Time Limit Exceeded
# 7. Memory Limit Exceeded
# $ \geq 16$. Partial Accepted


def run(name="", stdin="", timeout=generator_timeout):
    start = time.perf_counter()
    prc = 0
    if islinux:
        prc = subprocess.Popen(
            ["./" + name],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            # bufsize=max_buffer_size,
        )
    else:
        prc = subprocess.Popen(
            ["./" + name],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            # bufsize=max_buffer_size,
        )
    code = 0
    output = b""
    try:
        output = prc.communicate(input=stdin.encode(), timeout=timeout)
        output, stderr = output
        if stderr != None:
            return (output.decode(), 6, time.perf_counter() - start)
        code = prc.returncode
    except subprocess.TimeoutExpired:
        prc.kill()
        prc.wait()
        return (output.decode(), 6, -1.0)
    if code == 0:
        return (output.decode(), 0, time.perf_counter() - start)
    else:
        return (output.decode(), 5, time.perf_counter() - start)


def judge(ins="", out="", ans="", spj=False):
    if spj:
        assert 1
    else:
        if compare(out, ans):
            return 0
        else:
            return 1


def gen():
    return run("generator")


def op(stdin=""):
    return run("operate", stdin)[0]


def check(cnt1):
    global tot
    for i in range(1, cnt1 + 1):
        wawrite.acquire()
        wawrite.release()
        # launch your data generator or generate input data here
        stdin = ""
        if generator_cpp:
            stdin = gen()
            if stdin[1] != 0:
                tot = tot + 1
                result.add_row(
                    [str(tot), "\033[35m Skipped Unknown Error(Generator) \033[0m", "-1ms"]
                )
                continue
            else:
                stdin = stdin[0]
        else:
            stdin = (
                subprocess.Popen(
                    ["python3", "generator.py"],
                    stdin=subprocess.PIPE,
                    stdout=subprocess.PIPE,
                )
                .communicate()[0]
                .decode()
            )
        tot = tot + 1
        if validator:
            while run("validator")[1] != 0:
                stdin = run("generator")[0]
        if op == 1:
            stdin = op(stdin)
        TJ = run(problem_name + "_TJ", stdin=stdin)
        if TJ[1] == 5:
            result.add_row(
                [str(tot), "\033[35m Skipped Unknown Error(std) \033[0m", "-1ms"]
            )
            continue
        target = run(problem_name, stdin=stdin, timeout=timeout)

        if target[1] == 5:
            result.add_row([str(tot), "\033[35m Runtime Error \033[0m", "-1ms"])
            if stopwhennotac:
                writedata(stdin)
        elif target[1] == 6:
            result.add_row(
                [str(tot), "\033[35m Time Limit Exceeded \033[0m", ">1000ms"]
            )
            if stopwhennotac:
                writedata(stdin)
        elif judge(stdin, target[0], TJ[0]) == 0:
            result.add_row(
                [
                    str(tot),
                    "\033[32m Accepted \033[0m",
                    str(round(target[2] * 1000)) + "ms",
                ]
            )
        else:
            result.add_row(
                [
                    str(tot),
                    "\033[31m Wrong Answer \033[0m",
                    str(round(target[2] * 1000)) + "ms",
                ]
            )
            if stopwhennotac:
                writedata(stdin)
        consolelock.acquire()
        print("checking in progress: " + str(tot) + "/" + str(cnt), end="\r")
        consolelock.release()
        # lock1.release()


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
    threads[i].daemon = true
    threads[i].start()
for i in range(cnt1 + cnt2):
    threads[i].join()

print(result.get_string())
