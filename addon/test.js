const z$ = require('bindings')('zhscript2')
z$('.', '/opt2/debug/zhscript2/'/*, '-zhscript-o-tree -zhscript-o-ansi'*/)

function f1__(s) {
	console.log("f1(" + s + ")")
}

z$("加载test.zs、‘参数栈’", "a", "2", 3, 4.444, null, undefined, f1__, this)

console.log(z$("加载test2.zs"))

let a = 1
console.log("a = " + a)
/*console.log(__filename)
console.log(z$("我的回、先我的插脚、a+1了。"))
console.log("a = " + a)*/

function f2__(i) {
	a += Number(i)
}

z$("我的调、‘参数1’、hi", f1__)
z$("我的调、‘参数1’、1", f2__)
console.log("a = " + a)

z$("加载test3.zs、‘参数栈’", f1__, f2__)
console.log("a = " + a)

console.log("a")
z$("加载test4.zs、5")
console.log("b")

console.log("a")
z$([], "加载test4.zs、10、‘参数栈’", f1__)
console.log("b")
