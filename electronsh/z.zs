#!/usr/lib/zhscript2/l --。
定义提示、内容以下代码
	显示“# ‘内容’”换行。
上代码。
定义运行、命令、饶以下代码
	提示‘命令’。
	赋予错以执行‘命令’。
	提示‘错’。
	如果‘错’并且不‘饶’那么结束10。
上代码。
定义行析以下代码
	调用‘命令行解析’、‘参数栈’。
上代码。

加载lib/clpars4。
调用‘命令行加回调’、
	n、下代码
		运行下原样
	rm -r node_modules
	mkdir -p node_modules
	cd node_modules
	ln -sfn ../../../../../../../opt2/bin/lib/node_modules/bindings/
	ln -sfn ../../../../../opt2/bin/lib/node_modules/electron
	ln -sfn /opt2/old/node_modules/electron-prebuilt/
	ln -sfn /opt2/bin/lib/node_modules/zhscript2/
	上原样。
	上代码、0、、
	h、、0、“提示。行析-h”、
	#、、h、。
（行析‘参数栈’。）
调用‘命令行解析’、‘参数栈’。

