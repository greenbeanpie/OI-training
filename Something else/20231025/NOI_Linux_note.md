这应该是全洛谷最不全+最迟的 NOI Linux 使用体验。

给自家机房同学看的，基本无有效信息。

$\color{white}{\text{我才不会说这是应我们机房老师要求写的}}$

# NOI Linux 官网镜像使用体验

1. 不支持 UEFI 引导，原因不明。怀疑 CCF 玩原神玩多了，但是原神出来的时候 Ubuntu 官方镜像早就支持 UEFI 引导了，是否玩原神存疑。

2. 官方自带软件如下：

	比赛语言编译器：GCC G++ 9.3.0 支持 sanitizer

	非比赛语言编译器/解释器：FPC(Pascal) 3.0.4 Python 2.7+3.8

	比赛语言调试工具： GDB 9.1 DDB 3.3.12

	IDE：

	| 名称 | 版本 |
	| :----------- | :----------- |
	| Code::Blocks | 20.03 |
	| Lazarus | 2.0.6 |
	| Geany | 1.36 |
	| Visual Studio Code | 1.54.3 |
	| Emacs | 26.3 |
	| Gedit | 3.36.2 |
	| Vim | 8.1 |
	| Joe | 4.6 |
	| nano | 4.8 |
	| Sublime Text | 3.2.2 |

	温馨提醒：VS Code 虽然自带 C++ 插件，但是插件没有 Linux 下调试所需要的可执行文件，属于半残状态，不支持自动代码补全、编译、调试功能（但是有Windows调试所需的exe？）

	温馨提醒2：Sublime Text 内可以直接在 Build System 里面选择 C++ - Single File 来编译，但是据说我们机房某位同学在用命令行编译+ Sublime (?)

3. SELinux 默认处于 Disabled 状态，甚至 selinux-utils 没安装用不了 getenforce。

4. 使用默认镜像源，如果你希望下载新软件包的话一般建议换成清华大学 TUNA 镜像站。（但是如果你想把它当主力系统为什么不用原版 Ubuntu 或者 Fedora 呢？）

# NOI Linux 浙江考场使用体(jiao)验(cheng)

1. 考试电脑用户名为准考证号，即 $\text{**-S*****/**-J*****}$ 。考试时四个题目的文件夹直接放在用户主文件夹下即可。如：

	你的准考证是 ZJ-S00001 ，那么你的用户名就是 ZJ-S00001 ，点开文件，选择右边图标为房子的主文件夹就是你的用户主文件夹。四个题目文件夹都放在下面。即：

	/home/ZJ-S00001/lock

	或：
	
	~/lock

	密码为 123456。
    
    请注意：考场的 NOI Linux 启用了 root 账号及 SSH 远程登录 root，同时你的用户 $\text{ZJ-S00001}$ 将不在 wheel 组里，这意味着你将不能使用 sudo 提权，有效防止了部分同学试图使用某清理电脑脚本。

2. 考场电脑 i5 6代 + 4G 内存 Visual Studio Code 运行流畅，估计其他软件不在话下。

3. 喜闻乐见：

	```text
	ssh
	usage: ssh [-46AaCfGgKkMNnqsTtVvXxYy] [-B bind_interface]
			[-b bind_address] [-c cipher_spec] [-D [bind_address:]port]
			[-E log_file] [-e escape_char] [-F configfile] [-I pkcs11]
			[-i identity_file] [-J [user@]host[:port]] [-L address]
			[-l login_name] [-m mac_spec] [-O ctl_cmd] [-o option] [-p port]
			[-Q query_option] [-R address] [-S ctl_path] [-W host:port]
			[-w local_tun[:remote_tun]] destination [command]
	```

	```text
	systemctl status sshd
	sshd.service - OpenSSH server daemon
		Loaded: loaded (/usr/lib/systemd/system/sshd.service; enabled; preset: disabled)
		Active: active (running)
	```
	甚至是开机自动启动。

	虽然这是下发文件用的，但是确实难蚌。另外考场工作人员你用root传文件是怕我们有权限打开文件还是删除文件？

4. 考场用 SSH 传文件，为了避免选手沟通所以考前就把网线拔了，但是考场人员似乎忘记了 SSH 传文件的时候会接网线，忘记了断网，所以理论上选了 NOI Linux 的人考前有约 30 秒的开网时间（？可以在这段时间里面把 VS Code 的调试下下来，但是不要手残重启 VS Code，否则有概率需要重新安装。
