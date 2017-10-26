#include <node.h>
#include <v8.h>
#include <uv.h>

using namespace v8;

#include "l4/l4___.cc"
#include <deque>
#include "for_arg_.h"
#include "call_util.cpp"

static l4___ l4_;
static void* main_qu_ = NULL;
static bool init_ = false;

static bool is_wksp__(Local<Value> v) {
	return v->IsArray();
}

class call4___ {
private:
	String::Utf8Value* src;
	int argc;
	const char** argv;
	String::Utf8Value** args2;
	int fn_c_;
public:
	Persistent<Function> fn_[16];
	int fn_c__() {return fn_c_;}
	call4___() {
		src = NULL;
		argv = NULL;
		args2 = NULL;
		argc = 0;
		fn_c_ = 0;
	}
	~call4___() {
		for(int i = 0; i < argc; i++) {
			if(args2[i])
				delete args2[i];
			else if(argv[i])
				delete argv[i];
		}
		if(argv)
			delete argv;
		if(args2)
			delete args2;
		if(src)
			delete src;
		for(int i = 0; i < fn_c_; i++) {
			fn_[fn_c_].Reset();
		}
	}
	int with__(const FunctionCallbackInfo<Value>& args, int off, Isolate* isolate) {
		src = new String::Utf8Value(args[off]);
		int off1 = off + 1;
		int ret = off1;

		for(; ret < args.Length(); ret++) {
			if(off1 > 1 && is_wksp__(args[ret]))
				break;
			argc++;
		}
		args2 = new String::Utf8Value*[argc];
		argv = new const char*[argc];
		for(int i = 0; i < argc; i++) {
			Local<Value> v = args[i + off1];
			if(v->IsFunction()) {
				args2[i] = NULL;
				fn_[fn_c_].Reset(isolate, Local<Function>::Cast(v));
				char* buf = new char[16];
				sprintf(buf, "%d", fn_c_);
				argv[i] = buf;
				fn_c_++;
				continue;
			}
			args2[i] = new String::Utf8Value(v);
			argv[i] = **args2[i];
		}
		//for(int i = 0; i < argc; i++) cout << i <<") " << argv[i] << endl;
		return ret;
	}
	void z__(int& err, deque<string>* ret, const char** ret2);
};

static void my__(char**addr_ret, deque<string> *ret, call4___* call4, void*ce,void* shangji, int argc,...) {
	if(argc <= 0)
		return;

	deque<string> p;
	_for_args( argc )
		p.push_back(s ? s : l4_.keyword__(keyword_null_));
	_next_args

	for(;;) {
		const string& p0 = p[0];
		if(p0 == "回" && ret) {
			for(size_t i = 1; i < p.size(); i++) {
				ret->push_back(p[i]);
			}
			return;
		}
		if(p0 == "插脚") {
			if(p.size() <= 1)
				break;
			Isolate* isolate = Isolate::GetCurrent();
			Handle<String> source = String::NewFromUtf8(isolate, p[1].c_str());
			Handle<Script> script = Script::Compile(source);
			Handle<Value> result = script->Run();
			String::Utf8Value result2(result);
			*addr_ret = dup__(*result2);
			return;
		}
		if(p0 == "调") {
			if(p.size() <= 1)
				break;

			int i;
			if(sscanf(p[1].c_str(), "%d", &i) != 1)
				break;
			if(i < 0 || i >= call4->fn_c__())
				break;
			Handle<Function> f = *reinterpret_cast<Handle<Function>*>(&call4->fn_[i]);

			int argc = p.size() - 2;
			Handle<Value> argv[argc];
			Isolate* isolate = Isolate::GetCurrent();
			HandleScope scope(isolate);
			for(int i = 0; i < argc; i++) {
				argv[i] = String::NewFromUtf8(isolate, p[i + 2].c_str());
			}

			f->Call(Null(isolate), argc, argv);
			return;
		}
		break;
	}
	cerr << "不支持";
	for(size_t i = 0; i < p.size(); i++) {
		cerr << p[i];
	}
	cerr << endl;
}

void call4___::z__(int& err, deque<string>* ret, const char** ret2) {
	void* qu = l4_.new_qu__(main_qu_);
	const char* ret3 = NULL;
	{
		char buf[32];
		const char
			*dy=l4_.keyword__(keyword_call_)
			,*x=l4_.keyword__(keyword_jieheshi_)
			,*l=l4_.keyword__(keyword_jiehezhong_)
			,*fn=l4_.keyword__(-1)
			,*eq=l4_.keyword__(keyword_equ_)
			,*ky=l4_.keyword__(keyword_kaiyinhao_)
			,*by=l4_.keyword__(keyword_biyinhao_)
			,*d=l4_.keyword__(keyword_dunhao_)
			,*bs=l4_.keyword__(keyword_bianliangshi_)
			,*bz=l4_.keyword__(keyword_bianliangzhong_)
			,*c=l4_.keyword__(keyword_params_)
			,*j=l4_.keyword__(keyword_juhao_)
			;
		string s;
		s+=dy;s+=x;
		s+=fn;s+=eq;
		s+=d;
		s+=ky; sprintf(buf, "%lu", (unsigned long)my__);s+=buf; s+=by;s+=d;
		s+=ky;s+="-A-&-&-$11-$14-Z";s+=by;
		s+=l;s+=d;
		s+=ky; sprintf(buf, "%lu", (unsigned long)ret);s+=buf; s+=by;s+=d;
		s+=ky; sprintf(buf, "%lu", (unsigned long)this);s+=buf; s+=by;s+=d;
		s+=bs;s+=c;s+=bz;s+=j;
		err=l4_.def_new__("我的",s.c_str(), true,false, qu);
	}
	if(!err) {
		//cout << **src << " [" << argc << endl;
		ret3 = l4_.callback3__(&err, /*void*ce*/NULL, **src, false, NULL, qu, argc, argv, 0);
		if(ret2)
			*ret2 = ret3;
	}
	l4_.err_out__(ret3, err, 0);
}

class call44___ {
public:
	uv_work_t req_;
	call4___ *call_, *call2_;
	int err_;
	call44___(const FunctionCallbackInfo<Value>& args, int off, Isolate* isolate) {
		call_ = new call4___();
		int i = call_->with__(args, off, isolate);
		if(i < args.Length()) {
			call2_ = new call4___();
			call2_->with__(args, i + 1, isolate);
		} else
			call2_ = NULL;
	}
	~call44___() {
		delete call_;
		if(call2_)
			delete call2_;
	}
};

static void call4_start__(uv_work_t* req) {
	call44___ *call4 = static_cast<call44___*>(req->data);
	call4->call_->z__(call4->err_, NULL, NULL);
}

static void call4_after__(uv_work_t* req, int status) {
	call44___ *call4 = static_cast<call44___*>(req->data);
	if(call4->call2_ && !call4->err_)
		call4->call2_->z__(call4->err_, NULL, NULL);
	delete call4;
}

static void api__(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	int err;

	if(!init_) {
		const char *path = "/usr/lib/zhscript2/", *cmdline = "";
		String::Utf8Value *path2 = NULL, *cmdline2 = NULL;
		bool is_u = args.Length() > 0 && *String::Utf8Value(args[0]) == string(".");
		if(is_u) {
			if(args.Length() > 1) {
				path2 = new String::Utf8Value(args[1]);
				path = **path2;
			}
			if(args.Length() > 2) {
				cmdline2 = new String::Utf8Value(args[2]);
				cmdline = **cmdline2;
			}
		}
		err = l4_.init__(path, cmdline, 0, NULL, 0);
		if(path2)
			delete path2;
		if(cmdline2)
			delete cmdline2;
		if(!err) {
			main_qu_ = l4_.new_main_qu__();
			init_ = true;
		}
		//cout << "init " << is_u << endl;
		if(is_u)
			return;
	} else
		err = 0;

	if(args.Length() == 0)
		return;

	const char* ret2 = NULL;
	deque<string> ret;
	if(!err) {
		if(is_wksp__(args[0])) {
			call44___* call4 = new call44___(args, 1, isolate);
			call4->req_.data = call4;
			uv_queue_work(uv_default_loop(), &call4->req_, call4_start__, call4_after__);
			return;
		}
		call44___ call4(args, 0, isolate);
		call4.call_->z__(err, &ret, &ret2);
	}
	if(err)
		return;

	switch(ret.size()) {
	case 0:
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, ret2));
		break;
	case 1:
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, ret[0].c_str()));
		break;
	default:
	{
		Handle<Array> a = Array::New(isolate, ret.size());
		for(size_t i = 0; i < ret.size(); i++) {
			a->Set(i, String::NewFromUtf8(isolate, ret[i].c_str()));
		}
		args.GetReturnValue().Set(a);
		break;
	}
	}
}

void InitAll(Handle<Object> exports, Handle<Object> module) {
	NODE_SET_METHOD(module, "exports", api__);
}

NODE_MODULE(addon, InitAll)
