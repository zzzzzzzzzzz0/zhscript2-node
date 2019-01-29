const electron = require('electron')
const app = electron.app
const BrowserWindow = electron.BrowserWindow
const z$ = require('bindings')('zhscript2')

const ipc_ = electron.ipcMain

function window_open(url, conf, o) {
	let w = new BrowserWindow(conf)
	w.loadURL(url)

	let wc = w.webContents
	wc.on('did-finish-load', function() {
		wc.send('wid', w.id)

		if(o) {
			let chnname = ['htm_', 'args_']
			for(let i = 0; i < chnname.length; i++) {
				let n = chnname[i], o2 = o[n]
				if(o2) {
					wc.send(n, o2)
				}
			}
		}
	})

	if(conf) {
		if(conf.max_)
			w.maximize()
		if(!conf.menubar_) {
			console.log('!conf.menubar_')
			w.setMenu(null)
		}
	}
	return w
}

let mainWindow
let conf_ = {menubar_:true}
function createWindow () {
	let app = process.env.ELECTRONSH_APP
	if(app) {
		let s = z$('加载“' + app + 'app.conf.zs”')
		console.log(s)
		conf_ = eval(s)
		
		if(conf_.sock_) {
			const net = require('net')
			const fs = require('fs')
			let server = net.createServer((socket) => {
				console.log('收到请求')
				socket.on('data', (data) => {
					let s = data.toString()
					console.log(s)
					mainWindow.webContents.send('index.html', s)
				})
				socket.on('close', () => console.log('连接断开'))
				socket.on('error', function (e) {
					console.log("意外 " + e)
				})
			})
			if (fs.existsSync(conf_.sock_))
				fs.unlinkSync(conf_.sock_)
			server.listen(conf_.sock_, () => console.log('开始监听'))
		}
	}
	mainWindow = window_open('file://' + __dirname + '/index.html', conf_)
	mainWindow.on('closed', function () {
		mainWindow = null
		if(conf_.sock_) {
			const fs = require('fs')
			if (fs.existsSync(conf_.sock_))
				fs.unlinkSync(conf_.sock_)
		}
	})
}

app.on('ready', createWindow)
app.on('window-all-closed', function () {
	app.quit()
})
app.on('activate', function () {
	if (mainWindow === null) {
		createWindow()
	}
})

ipc_.on('window_open', function(event, url, conf, o) {
	let conf1 = {}
	Object.assign(conf1, conf_)
	conf1.max_ = false
	Object.assign(conf1, conf)
	window_open(url, conf1, o)
})
ipc_.on('window_min', function(event, wid) {
	BrowserWindow.fromId(wid).minimize()
})
ipc_.on('conf', function(event, arg) {
	let ret
	switch(arg) {
	case 'zs_path':
		ret = conf_.path_ ? conf_.path_ : __dirname + '/bin/zhscript2/'
		break
	}
	console.log(arg + ': ' + ret)
	event.returnValue = ret
})

ipc_.on('index.html', function(event, arg1, arg2, arg3, arg4) {
	//console.log('main index.html\n\t' + arg1 + '\n\t' + arg2 + '\n\t' + arg3 + '\n\t' + arg4)
	mainWindow.webContents.send('index.html', arg1, arg2, arg3, arg4)
})

ipc_.on('o_', function(event, arg1, arg2, arg3, arg4, arg5, arg6, arg7) {
	//console.log('main o_\n\t' + arg1 + '\n\t' + arg2 + '\n\t' + arg3 + '\n\t' + arg4 + '\n\t' + arg5 + '\n\t' + arg6 + '\n\t' + arg7)
	BrowserWindow.fromId(arg1).webContents.send('i_', arg3, arg4, arg5, arg6, arg7)
})
