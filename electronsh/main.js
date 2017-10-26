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
		if(!conf.menubar_)
			w.setMenu(null)
	}
	return w
}

let mainWindow
function createWindow () {
	let conf = {menubar_:true}
	let app = process.env.ELECTRONSH_APP
	if(app) {
		let s = z$('加载“' + app + 'app.conf.zs”')
		console.log(s)
		conf = eval(s)
		
		if(conf.sock_) {
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
			if (fs.existsSync(conf.sock_))
				fs.unlinkSync(conf.sock_)
			server.listen(conf.sock_, () => console.log('开始监听'))
		}
	}
	mainWindow = window_open('file://' + __dirname + '/index.html', conf)
	mainWindow.on('closed', function () {
		mainWindow = null
		if(conf.sock_) {
			const fs = require('fs')
			if (fs.existsSync(conf.sock_))
				fs.unlinkSync(conf.sock_)
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
	window_open(url, conf, o)
})
ipc_.on('window_min', function(event, wid) {
	BrowserWindow.fromId(wid).minimize()
})

ipc_.on('index.html', function(event, arg1, arg2, arg3, arg4) {
	mainWindow.webContents.send('index.html', arg1, arg2, arg3, arg4)
})