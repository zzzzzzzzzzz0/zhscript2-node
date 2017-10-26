const electron = require('electron')
const ipc_ = electron.ipcRenderer
const win_ = electron.remote.getCurrentWindow()

function e__(s) {
	return document.getElementById(s);
}
function e_cn__(s) {
	return document.getElementsByClassName(s);
}
function e_tn__(s) {
	return document.getElementsByTagName(s);
}

function q__(s) {
	return document.querySelector(s);
}
function q_a__(s) {
	return document.querySelectorAll(s);
}

function id__(id) {
	switch(typeof(id)) {
	case "string": case "number":
		return e__(id);
	}
	return id;
}

function log__(s) {
	console.log(s);
}

function new__(s) {
	return document.createElement(s);
}
function add__(e, id2) {
	id__(id2).appendChild(e); 
}

function htm__(id, val, op) {
	var e = id__(id);
	if(val == undefined)
		return e.innerHTML;
	switch(op) {
	case true:
		e.innerHTML += val;
		return;
	case "top":
		e.innerHTML = val + e.innerHTML;
		return;
	}
	e.innerHTML = val;
}

function s2js__(s) {
	return s
		.replace(/\n/g,'\\n')
		.replace(/\r/g,'\\r')
		.replace(/"/g,'\\"')
		.replace(/'/g,"\\'")
}