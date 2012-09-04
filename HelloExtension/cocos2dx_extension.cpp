#include "jsapi.h"
#include "jsfriendapi.h"
#include "cocos2dx_extension.hpp"
#include "cocos-ext.h"

template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	TypeTest<T> t;
	T* cobj = new T();
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	assert(p);
	JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
	js_proxy_t *pp;
	JS_NEW_PROXY(pp, cobj, _tmp);
	JS_AddObjectRoot(cx, &pp->obj);
	JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

	return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
	return JS_FALSE;
}


JSClass  *js_cocos2dx_extension_CCScale9Sprite_class;
JSObject *js_cocos2dx_extension_CCScale9Sprite_prototype;

JSBool js_cocos2dx_extension_CCScale9Sprite_updateWithBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 3) {
		cocos2d::CCSpriteBatchNode* arg0;
		cocos2d::CCRect arg1;
		cocos2d::CCRect arg2;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteBatchNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		arg1 = jsval_to_ccrect(cx, argv[1]);
		arg2 = jsval_to_ccrect(cx, argv[2]);
		bool ret = cobj->updateWithBatchNode(arg0, arg1, arg2);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCRect ret = cobj->getCapInsets();
		jsval jsret;
		jsret = ccrect_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_initWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj;
	cocos2d::extension::CCScale9Sprite* cobj;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		bool ret = cobj->initWithSpriteFrameName(arg0);
		jsval jsret; jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		bool ret = cobj->initWithSpriteFrameName(arg0, arg1);
		jsval jsret; jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setOpacityModifyRGB(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		JSBool arg0;
		JS_ValueToBoolean(cx, argv[0], &arg0);
		cobj->setOpacityModifyRGB(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setOriginalSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCSize arg0;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		cobj->setOriginalSize(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setInsetBottom(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		double arg0;
		JS_ValueToNumber(cx, argv[0], &arg0);
		cobj->setInsetBottom(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_isOpacityModifyRGB(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		bool ret = cobj->isOpacityModifyRGB();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_visit(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cobj->visit();
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setOpacity(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		uint16_t arg0;
		JS_ValueToUint16(cx, argv[0], &arg0);
		cobj->setOpacity(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setInsetTop(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		double arg0;
		JS_ValueToNumber(cx, argv[0], &arg0);
		cobj->setInsetTop(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setPreferredSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCSize arg0;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		cobj->setPreferredSize(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getOpacity(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		unsigned char ret = cobj->getOpacity();
		jsval jsret;
		JS_NewNumberValue(cx, ret, &jsret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCSpriteFrame* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteFrame*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cobj->setSpriteFrame(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::ccColor3B ret = cobj->getColor();
		jsval jsret;
		jsret = cccolor3b_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_initWithBatchNode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 3) {
		cocos2d::CCSpriteBatchNode* arg0;
		cocos2d::CCRect arg1;
		cocos2d::CCRect arg2;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteBatchNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		arg1 = jsval_to_ccrect(cx, argv[1]);
		arg2 = jsval_to_ccrect(cx, argv[2]);
		bool ret = cobj->initWithBatchNode(arg0, arg1, arg2);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 3);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getInsetBottom(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		float ret = cobj->getInsetBottom();
		jsval jsret;
		JS_NewNumberValue(cx, ret, &jsret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_resizableSpriteWithCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCRect arg0;
		arg0 = jsval_to_ccrect(cx, argv[0]);
		cocos2d::extension::CCScale9Sprite* ret = cobj->resizableSpriteWithCapInsets(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCSize arg0;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		cobj->setContentSize(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getInsetRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		float ret = cobj->getInsetRight();
		jsval jsret;
		JS_NewNumberValue(cx, ret, &jsret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getOriginalSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCSize ret = cobj->getOriginalSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_initWithFile(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj;
	cocos2d::extension::CCScale9Sprite* cobj;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		bool ret = cobj->initWithFile(arg0, arg1);
		jsval jsret; jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 3) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::CCRect arg2;
		arg2 = jsval_to_ccrect(cx, argv[2]);
		bool ret = cobj->initWithFile(arg0, arg1, arg2);
		jsval jsret; jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		cocos2d::CCRect arg0;
		arg0 = jsval_to_ccrect(cx, argv[0]);
		const char* arg1;
		std::string arg1_tmp = jsval_to_std_string(cx, argv[1]); arg1 = arg1_tmp.c_str();
		bool ret = cobj->initWithFile(arg0, arg1);
		jsval jsret; jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		bool ret = cobj->initWithFile(arg0);
		jsval jsret; jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::ccColor3B arg0;
		arg0 = jsval_to_cccolor3b(cx, argv[0]);
		cobj->setColor(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getInsetTop(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		float ret = cobj->getInsetTop();
		jsval jsret;
		JS_NewNumberValue(cx, ret, &jsret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setInsetLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		double arg0;
		JS_ValueToNumber(cx, argv[0], &arg0);
		cobj->setInsetLeft(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_initWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj;
	cocos2d::extension::CCScale9Sprite* cobj;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCSpriteFrame* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteFrame*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		bool ret = cobj->initWithSpriteFrame(arg0);
		jsval jsret; jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		cocos2d::CCSpriteFrame* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteFrame*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		bool ret = cobj->initWithSpriteFrame(arg0, arg1);
		jsval jsret; jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getPreferredSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCSize ret = cobj->getPreferredSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCRect arg0;
		arg0 = jsval_to_ccrect(cx, argv[0]);
		cobj->setCapInsets(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_getInsetLeft(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		float ret = cobj->getInsetLeft();
		jsval jsret;
		JS_NewNumberValue(cx, ret, &jsret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_setInsetRight(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScale9Sprite* cobj = (cocos2d::extension::CCScale9Sprite *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		double arg0;
		JS_ValueToNumber(cx, argv[0], &arg0);
		cobj->setInsetRight(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_node(JSContext *cx, uint32_t argc, jsval *vp)
{
	cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::node();
	jsval jsret;
	do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
	JS_SET_RVAL(cx, vp, jsret);
	return JS_TRUE;
}

JSBool js_cocos2dx_extension_CCScale9Sprite_spriteWithFile(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	if (argc == 2) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::spriteWithFile(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 3) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::CCRect arg2;
		arg2 = jsval_to_ccrect(cx, argv[2]);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::spriteWithFile(arg0, arg1, arg2);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		cocos2d::CCRect arg0;
		arg0 = jsval_to_ccrect(cx, argv[0]);
		const char* arg1;
		std::string arg1_tmp = jsval_to_std_string(cx, argv[1]); arg1 = arg1_tmp.c_str();
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::spriteWithFile(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::spriteWithFile(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	if (argc == 2) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::create(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 3) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::CCRect arg2;
		arg2 = jsval_to_ccrect(cx, argv[2]);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::create(arg0, arg1, arg2);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		cocos2d::CCRect arg0;
		arg0 = jsval_to_ccrect(cx, argv[0]);
		const char* arg1;
		std::string arg1_tmp = jsval_to_std_string(cx, argv[1]); arg1 = arg1_tmp.c_str();
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::create(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::create(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 0) {
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::create();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_spriteWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::spriteWithSpriteFrameName(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::spriteWithSpriteFrameName(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_createWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_spriteWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	if (argc == 1) {
		cocos2d::CCSpriteFrame* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteFrame*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::spriteWithSpriteFrame(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		cocos2d::CCSpriteFrame* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteFrame*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::spriteWithSpriteFrame(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_createWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	if (argc == 1) {
		cocos2d::CCSpriteFrame* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteFrame*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::createWithSpriteFrame(arg0);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		cocos2d::CCSpriteFrame* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCSpriteFrame*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cocos2d::CCRect arg1;
		arg1 = jsval_to_ccrect(cx, argv[1]);
		cocos2d::extension::CCScale9Sprite* ret = cocos2d::extension::CCScale9Sprite::createWithSpriteFrame(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScale9Sprite>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScale9Sprite_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{

	if (argc == 0) {
		cocos2d::extension::CCScale9Sprite* cobj = new cocos2d::extension::CCScale9Sprite();
#ifdef COCOS2D_JAVASCRIPT
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
#endif
		TypeTest<cocos2d::extension::CCScale9Sprite> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t *p;
		JS_NEW_PROXY(p, cobj, obj);
#ifdef COCOS2D_JAVASCRIPT
		JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::CCScale9Sprite");
#endif
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_cocos2dx_extension_CCScale9Sprite_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_cocos2dx_extension_CCScale9Sprite(JSContext *cx, JSObject *global) {
	js_cocos2dx_extension_CCScale9Sprite_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_cocos2dx_extension_CCScale9Sprite_class->name = "Scale9Sprite";
	js_cocos2dx_extension_CCScale9Sprite_class->addProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCScale9Sprite_class->delProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCScale9Sprite_class->getProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCScale9Sprite_class->setProperty = JS_StrictPropertyStub;
	js_cocos2dx_extension_CCScale9Sprite_class->enumerate = JS_EnumerateStub;
	js_cocos2dx_extension_CCScale9Sprite_class->resolve = JS_ResolveStub;
	js_cocos2dx_extension_CCScale9Sprite_class->convert = JS_ConvertStub;
	js_cocos2dx_extension_CCScale9Sprite_class->finalize = js_cocos2dx_extension_CCScale9Sprite_finalize;
	js_cocos2dx_extension_CCScale9Sprite_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("updateWithBatchNode", js_cocos2dx_extension_CCScale9Sprite_updateWithBatchNode, 3, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getCapInsets", js_cocos2dx_extension_CCScale9Sprite_getCapInsets, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("initWithSpriteFrameName", js_cocos2dx_extension_CCScale9Sprite_initWithSpriteFrameName, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setOpacityModifyRGB", js_cocos2dx_extension_CCScale9Sprite_setOpacityModifyRGB, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setOriginalSize", js_cocos2dx_extension_CCScale9Sprite_setOriginalSize, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setInsetBottom", js_cocos2dx_extension_CCScale9Sprite_setInsetBottom, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("isOpacityModifyRGB", js_cocos2dx_extension_CCScale9Sprite_isOpacityModifyRGB, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("visit", js_cocos2dx_extension_CCScale9Sprite_visit, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setOpacity", js_cocos2dx_extension_CCScale9Sprite_setOpacity, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setInsetTop", js_cocos2dx_extension_CCScale9Sprite_setInsetTop, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("init", js_cocos2dx_extension_CCScale9Sprite_init, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setPreferredSize", js_cocos2dx_extension_CCScale9Sprite_setPreferredSize, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getOpacity", js_cocos2dx_extension_CCScale9Sprite_getOpacity, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setSpriteFrame", js_cocos2dx_extension_CCScale9Sprite_setSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getColor", js_cocos2dx_extension_CCScale9Sprite_getColor, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("initWithBatchNode", js_cocos2dx_extension_CCScale9Sprite_initWithBatchNode, 3, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getInsetBottom", js_cocos2dx_extension_CCScale9Sprite_getInsetBottom, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("resizableSpriteWithCapInsets", js_cocos2dx_extension_CCScale9Sprite_resizableSpriteWithCapInsets, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setContentSize", js_cocos2dx_extension_CCScale9Sprite_setContentSize, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getInsetRight", js_cocos2dx_extension_CCScale9Sprite_getInsetRight, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getOriginalSize", js_cocos2dx_extension_CCScale9Sprite_getOriginalSize, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("initWithFile", js_cocos2dx_extension_CCScale9Sprite_initWithFile, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setColor", js_cocos2dx_extension_CCScale9Sprite_setColor, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getInsetTop", js_cocos2dx_extension_CCScale9Sprite_getInsetTop, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setInsetLeft", js_cocos2dx_extension_CCScale9Sprite_setInsetLeft, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("initWithSpriteFrame", js_cocos2dx_extension_CCScale9Sprite_initWithSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getPreferredSize", js_cocos2dx_extension_CCScale9Sprite_getPreferredSize, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setCapInsets", js_cocos2dx_extension_CCScale9Sprite_setCapInsets, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getInsetLeft", js_cocos2dx_extension_CCScale9Sprite_getInsetLeft, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setInsetRight", js_cocos2dx_extension_CCScale9Sprite_setInsetRight, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("node", js_cocos2dx_extension_CCScale9Sprite_node, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("spriteWithFile", js_cocos2dx_extension_CCScale9Sprite_spriteWithFile, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("create", js_cocos2dx_extension_CCScale9Sprite_create, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("spriteWithSpriteFrameName", js_cocos2dx_extension_CCScale9Sprite_spriteWithSpriteFrameName, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("createWithSpriteFrameName", js_cocos2dx_extension_CCScale9Sprite_createWithSpriteFrameName, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("spriteWithSpriteFrame", js_cocos2dx_extension_CCScale9Sprite_spriteWithSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("createWithSpriteFrame", js_cocos2dx_extension_CCScale9Sprite_createWithSpriteFrame, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	js_cocos2dx_extension_CCScale9Sprite_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_cocos2dx_extension_CCScale9Sprite_class,
		js_cocos2dx_extension_CCScale9Sprite_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::CCScale9Sprite> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_cocos2dx_extension_CCScale9Sprite_class;
		p->proto = js_cocos2dx_extension_CCScale9Sprite_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_cocos2dx_extension_CCScrollView_class;
JSObject *js_cocos2dx_extension_CCScrollView_prototype;

JSBool js_cocos2dx_extension_CCScrollView_isClippingToBounds(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		bool ret = cobj->isClippingToBounds();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setContainer(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCNode* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cobj->setContainer(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setContentOffsetInDuration(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		cocos2d::CCPoint arg0;
		double arg1;
		arg0 = jsval_to_ccpoint(cx, argv[0]);
		JS_ValueToNumber(cx, argv[1], &arg1);
		cobj->setContentOffsetInDuration(arg0, arg1);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setZoomScaleInDuration(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		double arg0;
		double arg1;
		JS_ValueToNumber(cx, argv[0], &arg0);
		JS_ValueToNumber(cx, argv[1], &arg1);
		cobj->setZoomScaleInDuration(arg0, arg1);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_addChild(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj;
	cocos2d::extension::CCScrollView* cobj;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		cocos2d::CCNode* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		int arg1;
		JS_ValueToInt32(cx, argv[1], (int32_t *)&arg1);
		cobj->addChild(arg0, arg1);
		return JS_TRUE;
	}
	if (argc == 3) {
		cocos2d::CCNode* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		int arg1;
		JS_ValueToInt32(cx, argv[1], (int32_t *)&arg1);
		int arg2;
		JS_ValueToInt32(cx, argv[2], (int32_t *)&arg2);
		cobj->addChild(arg0, arg1, arg2);
		return JS_TRUE;
	}
	if (argc == 1) {
		cocos2d::CCNode* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cobj->addChild(arg0);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_getContainer(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCNode* ret = cobj->getContainer();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::CCNode>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_getDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::extension::CCScrollViewDirection ret = cobj->getDirection();
		jsval jsret;
		JS_NewNumberValue(cx, ret, &jsret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_getZoomScale(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		float ret = cobj->getZoomScale();
		jsval jsret;
		JS_NewNumberValue(cx, ret, &jsret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_initWithViewSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		cocos2d::CCSize arg0;
		cocos2d::CCNode* arg1;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg1 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg1)
		} while (0);
		bool ret = cobj->initWithViewSize(arg0, arg1);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_pause(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCObject* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCObject*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cobj->pause(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setDirection(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::extension::CCScrollViewDirection arg0;
		JS_ValueToInt32(cx, argv[0], (int32_t *)&arg0);
		cobj->setDirection(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_visit(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cobj->visit();
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setBounceable(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		JSBool arg0;
		JS_ValueToBoolean(cx, argv[0], &arg0);
		cobj->setBounceable(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setContentOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		cocos2d::CCPoint arg0;
		JSBool arg1;
		arg0 = jsval_to_ccpoint(cx, argv[0]);
		JS_ValueToBoolean(cx, argv[1], &arg1);
		cobj->setContentOffset(arg0, arg1);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_isDragging(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		bool ret = cobj->isDragging();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_init(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		bool ret = cobj->init();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_isBounceable(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		bool ret = cobj->isBounceable();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_getContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCSize ret = cobj->getContentSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setTouchEnabled(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		JSBool arg0;
		JS_ValueToBoolean(cx, argv[0], &arg0);
		cobj->setTouchEnabled(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_getContentOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCPoint ret = cobj->getContentOffset();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_resume(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCObject* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCObject*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cobj->resume(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setClippingToBounds(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		JSBool arg0;
		JS_ValueToBoolean(cx, argv[0], &arg0);
		cobj->setClippingToBounds(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setViewSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCSize arg0;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		cobj->setViewSize(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_getViewSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCSize ret = cobj->getViewSize();
		jsval jsret;
		jsret = ccsize_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_maxContainerOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCPoint ret = cobj->maxContainerOffset();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::extension::CCScrollViewDelegate* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::extension::CCScrollViewDelegate*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cobj->setDelegate(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCSize arg0;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		cobj->setContentSize(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_isTouchMoved(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		bool ret = cobj->isTouchMoved();
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_getDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::extension::CCScrollViewDelegate* ret = cobj->getDelegate();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScrollViewDelegate>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_isNodeVisible(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCNode* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		bool ret = cobj->isNodeVisible(arg0);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_minContainerOffset(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cocos2d::CCPoint ret = cobj->minContainerOffset();
		jsval jsret;
		jsret = ccpoint_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_registerWithTouchDispatcher(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCScrollView* cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cobj->registerWithTouchDispatcher();
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_setZoomScale(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj;
	cocos2d::extension::CCScrollView* cobj;
	obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cobj = (cocos2d::extension::CCScrollView *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		double arg0;
		JS_ValueToNumber(cx, argv[0], &arg0);
		JSBool arg1;
		JS_ValueToBoolean(cx, argv[1], &arg1);
		cobj->setZoomScale(arg0, arg1);
		return JS_TRUE;
	}
	if (argc == 1) {
		double arg0;
		JS_ValueToNumber(cx, argv[0], &arg0);
		cobj->setZoomScale(arg0);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	if (argc == 0) {
		cocos2d::extension::CCScrollView* ret = cocos2d::extension::CCScrollView::create();
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScrollView>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	if (argc == 2) {
		cocos2d::CCSize arg0;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		cocos2d::CCNode* arg1;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg1 = (cocos2d::CCNode*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg1)
		} while (0);
		cocos2d::extension::CCScrollView* ret = cocos2d::extension::CCScrollView::create(arg0, arg1);
		jsval jsret;
		do {
			if (ret) {
				js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCScrollView>(cx, ret);
				jsret = OBJECT_TO_JSVAL(proxy->obj);
			} else {
				jsret = JSVAL_NULL;
			}
		} while (0);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCScrollView_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{

	if (argc == 0) {
		cocos2d::extension::CCScrollView* cobj = new cocos2d::extension::CCScrollView();
#ifdef COCOS2D_JAVASCRIPT
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
#endif
		TypeTest<cocos2d::extension::CCScrollView> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t *p;
		JS_NEW_PROXY(p, cobj, obj);
#ifdef COCOS2D_JAVASCRIPT
		JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::CCScrollView");
#endif
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_cocos2dx_extension_CCScrollView_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_cocos2dx_extension_CCScrollView(JSContext *cx, JSObject *global) {
	js_cocos2dx_extension_CCScrollView_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_cocos2dx_extension_CCScrollView_class->name = "ScrollView";
	js_cocos2dx_extension_CCScrollView_class->addProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCScrollView_class->delProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCScrollView_class->getProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCScrollView_class->setProperty = JS_StrictPropertyStub;
	js_cocos2dx_extension_CCScrollView_class->enumerate = JS_EnumerateStub;
	js_cocos2dx_extension_CCScrollView_class->resolve = JS_ResolveStub;
	js_cocos2dx_extension_CCScrollView_class->convert = JS_ConvertStub;
	js_cocos2dx_extension_CCScrollView_class->finalize = js_cocos2dx_extension_CCScrollView_finalize;
	js_cocos2dx_extension_CCScrollView_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("isClippingToBounds", js_cocos2dx_extension_CCScrollView_isClippingToBounds, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setContainer", js_cocos2dx_extension_CCScrollView_setContainer, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setContentOffsetInDuration", js_cocos2dx_extension_CCScrollView_setContentOffsetInDuration, 2, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setZoomScaleInDuration", js_cocos2dx_extension_CCScrollView_setZoomScaleInDuration, 2, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("addChild", js_cocos2dx_extension_CCScrollView_addChild, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getContainer", js_cocos2dx_extension_CCScrollView_getContainer, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getDirection", js_cocos2dx_extension_CCScrollView_getDirection, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getZoomScale", js_cocos2dx_extension_CCScrollView_getZoomScale, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("initWithViewSize", js_cocos2dx_extension_CCScrollView_initWithViewSize, 2, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("pause", js_cocos2dx_extension_CCScrollView_pause, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setDirection", js_cocos2dx_extension_CCScrollView_setDirection, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("visit", js_cocos2dx_extension_CCScrollView_visit, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setBounceable", js_cocos2dx_extension_CCScrollView_setBounceable, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setContentOffset", js_cocos2dx_extension_CCScrollView_setContentOffset, 2, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("isDragging", js_cocos2dx_extension_CCScrollView_isDragging, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("init", js_cocos2dx_extension_CCScrollView_init, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("isBounceable", js_cocos2dx_extension_CCScrollView_isBounceable, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getContentSize", js_cocos2dx_extension_CCScrollView_getContentSize, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setTouchEnabled", js_cocos2dx_extension_CCScrollView_setTouchEnabled, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getContentOffset", js_cocos2dx_extension_CCScrollView_getContentOffset, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("resume", js_cocos2dx_extension_CCScrollView_resume, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setClippingToBounds", js_cocos2dx_extension_CCScrollView_setClippingToBounds, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setViewSize", js_cocos2dx_extension_CCScrollView_setViewSize, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getViewSize", js_cocos2dx_extension_CCScrollView_getViewSize, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("maxContainerOffset", js_cocos2dx_extension_CCScrollView_maxContainerOffset, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setDelegate", js_cocos2dx_extension_CCScrollView_setDelegate, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setContentSize", js_cocos2dx_extension_CCScrollView_setContentSize, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("isTouchMoved", js_cocos2dx_extension_CCScrollView_isTouchMoved, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getDelegate", js_cocos2dx_extension_CCScrollView_getDelegate, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("isNodeVisible", js_cocos2dx_extension_CCScrollView_isNodeVisible, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("minContainerOffset", js_cocos2dx_extension_CCScrollView_minContainerOffset, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("registerWithTouchDispatcher", js_cocos2dx_extension_CCScrollView_registerWithTouchDispatcher, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setZoomScale", js_cocos2dx_extension_CCScrollView_setZoomScale, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_CCScrollView_create, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	js_cocos2dx_extension_CCScrollView_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_cocos2dx_extension_CCScrollView_class,
		js_cocos2dx_extension_CCScrollView_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::CCScrollView> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_cocos2dx_extension_CCScrollView_class;
		p->proto = js_cocos2dx_extension_CCScrollView_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}


JSClass  *js_cocos2dx_extension_CCEditBox_class;
JSObject *js_cocos2dx_extension_CCEditBox_prototype;

JSBool js_cocos2dx_extension_CCEditBox_keyboardDidShow(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCIMEKeyboardNotificationInfo arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR CCIMEKeyboardNotificationInfo;
		cobj->keyboardDidShow(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_getText(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		const char* ret = cobj->getText();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setContentSize(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCSize arg0;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		cobj->setContentSize(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_visit(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cobj->visit();
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_keyboardDidHide(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCIMEKeyboardNotificationInfo arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR CCIMEKeyboardNotificationInfo;
		cobj->keyboardDidHide(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_getPlaceHolder(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		const char* ret = cobj->getPlaceHolder();
		jsval jsret;
		jsret = c_string_to_jsval(cx, ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setInputMode(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::extension::EditBoxInputMode arg0;
		JS_ValueToInt32(cx, argv[0], (int32_t *)&arg0);
		cobj->setInputMode(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_keyboardWillShow(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCIMEKeyboardNotificationInfo arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR CCIMEKeyboardNotificationInfo;
		cobj->keyboardWillShow(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setPlaceholderFontColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::ccColor3B arg0;
		arg0 = jsval_to_cccolor3b(cx, argv[0]);
		cobj->setPlaceholderFontColor(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setReturnType(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::extension::KeyboardReturnType arg0;
		JS_ValueToInt32(cx, argv[0], (int32_t *)&arg0);
		cobj->setReturnType(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setFontColor(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::ccColor3B arg0;
		arg0 = jsval_to_cccolor3b(cx, argv[0]);
		cobj->setFontColor(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_keyboardWillHide(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCIMEKeyboardNotificationInfo arg0;
		#pragma warning NO CONVERSION TO NATIVE FOR CCIMEKeyboardNotificationInfo;
		cobj->keyboardWillHide(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_touchDownAction(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		cocos2d::CCObject* arg0;
		unsigned int arg1;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::CCObject*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		JS_ValueToECMAUint32(cx, argv[1], &arg1);
		cobj->touchDownAction(arg0, arg1);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setDelegate(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::extension::CCEditBoxDelegate* arg0;
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[0]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg0 = (cocos2d::extension::CCEditBoxDelegate*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg0)
		} while (0);
		cobj->setDelegate(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_initWithSizeAndBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 2) {
		cocos2d::CCSize arg0;
		cocos2d::extension::CCScale9Sprite* arg1;
		arg0 = jsval_to_ccsize(cx, argv[0]);
		do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg1 = (cocos2d::extension::CCScale9Sprite*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg1)
		} while (0);
		bool ret = cobj->initWithSizeAndBackgroundSprite(arg0, arg1);
		jsval jsret;
		jsret = BOOLEAN_TO_JSVAL(ret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 2);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setPlaceHolder(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cobj->setPlaceHolder(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setPosition(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::CCPoint arg0;
		arg0 = jsval_to_ccpoint(cx, argv[0]);
		cobj->setPosition(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_onExit(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		cobj->onExit();
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_getMaxLength(JSContext *cx, uint32_t argc, jsval *vp)
{
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 0) {
		int ret = cobj->getMaxLength();
		jsval jsret;
		JS_NewNumberValue(cx, ret, &jsret);
		JS_SET_RVAL(cx, vp, jsret);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setInputFlag(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		cocos2d::extension::EditBoxInputFlag arg0;
		JS_ValueToInt32(cx, argv[0], (int32_t *)&arg0);
		cobj->setInputFlag(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setText(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		const char* arg0;
		std::string arg0_tmp = jsval_to_std_string(cx, argv[0]); arg0 = arg0_tmp.c_str();
		cobj->setText(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_setMaxLength(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	JSObject *obj = JS_THIS_OBJECT(cx, vp);
	js_proxy_t *proxy; JS_GET_NATIVE_PROXY(proxy, obj);
	cocos2d::extension::CCEditBox* cobj = (cocos2d::extension::CCEditBox *)(proxy ? proxy->ptr : NULL);
	TEST_NATIVE_OBJECT(cx, cobj)

	if (argc == 1) {
		int arg0;
		JS_ValueToInt32(cx, argv[0], (int32_t *)&arg0);
		cobj->setMaxLength(arg0);
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 1);
	return JS_FALSE;
}
JSBool js_cocos2dx_extension_CCEditBox_create(JSContext *cx, uint32_t argc, jsval *vp)
{
	jsval *argv = JS_ARGV(cx, vp);
	cocos2d::CCSize arg0;
	cocos2d::extension::CCScale9Sprite* arg1;
	cocos2d::extension::CCScale9Sprite* arg2;
	cocos2d::extension::CCScale9Sprite* arg3;
	assert(argc >= 4);

	arg0 = jsval_to_ccsize(cx, argv[0]);
	do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[1]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg1 = (cocos2d::extension::CCScale9Sprite*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg1)
		} while (0);
	do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[2]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg2 = (cocos2d::extension::CCScale9Sprite*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg2)
		} while (0);
	do {
			js_proxy_t *proxy;
			JSObject *tmpObj = JSVAL_TO_OBJECT(argv[3]);
			JS_GET_NATIVE_PROXY(proxy, tmpObj);
			arg3 = (cocos2d::extension::CCScale9Sprite*)(proxy ? proxy->ptr : NULL);
			TEST_NATIVE_OBJECT(cx, arg3)
		} while (0);
	cocos2d::extension::CCEditBox* ret = cocos2d::extension::CCEditBox::create(arg0, arg1, arg2, arg3);
	jsval jsret;
	do {
		if (ret) {
			js_proxy_t *proxy = js_get_or_create_proxy<cocos2d::extension::CCEditBox>(cx, ret);
			jsret = OBJECT_TO_JSVAL(proxy->obj);
		} else {
			jsret = JSVAL_NULL;
		}
	} while (0);
	JS_SET_RVAL(cx, vp, jsret);
	return JS_TRUE;
}

JSBool js_cocos2dx_extension_CCEditBox_constructor(JSContext *cx, uint32_t argc, jsval *vp)
{

	if (argc == 0) {
		cocos2d::extension::CCEditBox* cobj = new cocos2d::extension::CCEditBox();
#ifdef COCOS2D_JAVASCRIPT
		cocos2d::CCObject *_ccobj = dynamic_cast<cocos2d::CCObject *>(cobj);
		if (_ccobj) {
			_ccobj->autorelease();
		}
#endif
		TypeTest<cocos2d::extension::CCEditBox> t;
		js_type_class_t *typeClass;
		uint32_t typeId = t.s_id();
		HASH_FIND_INT(_js_global_type_ht, &typeId, typeClass);
		assert(typeClass);
		JSObject *obj = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
		JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(obj));
		// link the native object with the javascript object
		js_proxy_t *p;
		JS_NEW_PROXY(p, cobj, obj);
#ifdef COCOS2D_JAVASCRIPT
		JS_AddNamedObjectRoot(cx, &p->obj, "cocos2d::extension::CCEditBox");
#endif
		return JS_TRUE;
	}
	JS_ReportError(cx, "wrong number of arguments: %d, was expecting %d", argc, 0);
	return JS_FALSE;
}



void js_cocos2dx_extension_CCEditBox_finalize(JSFreeOp *fop, JSObject *obj) {
}

void js_register_cocos2dx_extension_CCEditBox(JSContext *cx, JSObject *global) {
	js_cocos2dx_extension_CCEditBox_class = (JSClass *)calloc(1, sizeof(JSClass));
	js_cocos2dx_extension_CCEditBox_class->name = "EditBox";
	js_cocos2dx_extension_CCEditBox_class->addProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCEditBox_class->delProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCEditBox_class->getProperty = JS_PropertyStub;
	js_cocos2dx_extension_CCEditBox_class->setProperty = JS_StrictPropertyStub;
	js_cocos2dx_extension_CCEditBox_class->enumerate = JS_EnumerateStub;
	js_cocos2dx_extension_CCEditBox_class->resolve = JS_ResolveStub;
	js_cocos2dx_extension_CCEditBox_class->convert = JS_ConvertStub;
	js_cocos2dx_extension_CCEditBox_class->finalize = js_cocos2dx_extension_CCEditBox_finalize;
	js_cocos2dx_extension_CCEditBox_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

	static JSPropertySpec properties[] = {
		{0, 0, 0, 0, 0}
	};

	static JSFunctionSpec funcs[] = {
		JS_FN("keyboardDidShow", js_cocos2dx_extension_CCEditBox_keyboardDidShow, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getText", js_cocos2dx_extension_CCEditBox_getText, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setContentSize", js_cocos2dx_extension_CCEditBox_setContentSize, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("visit", js_cocos2dx_extension_CCEditBox_visit, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("keyboardDidHide", js_cocos2dx_extension_CCEditBox_keyboardDidHide, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getPlaceHolder", js_cocos2dx_extension_CCEditBox_getPlaceHolder, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setInputMode", js_cocos2dx_extension_CCEditBox_setInputMode, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("keyboardWillShow", js_cocos2dx_extension_CCEditBox_keyboardWillShow, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setPlaceholderFontColor", js_cocos2dx_extension_CCEditBox_setPlaceholderFontColor, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setReturnType", js_cocos2dx_extension_CCEditBox_setReturnType, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setFontColor", js_cocos2dx_extension_CCEditBox_setFontColor, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("keyboardWillHide", js_cocos2dx_extension_CCEditBox_keyboardWillHide, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("touchDownAction", js_cocos2dx_extension_CCEditBox_touchDownAction, 2, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setDelegate", js_cocos2dx_extension_CCEditBox_setDelegate, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("initWithSizeAndBackgroundSprite", js_cocos2dx_extension_CCEditBox_initWithSizeAndBackgroundSprite, 2, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setPlaceHolder", js_cocos2dx_extension_CCEditBox_setPlaceHolder, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setPosition", js_cocos2dx_extension_CCEditBox_setPosition, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("onExit", js_cocos2dx_extension_CCEditBox_onExit, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("getMaxLength", js_cocos2dx_extension_CCEditBox_getMaxLength, 0, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setInputFlag", js_cocos2dx_extension_CCEditBox_setInputFlag, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setText", js_cocos2dx_extension_CCEditBox_setText, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FN("setMaxLength", js_cocos2dx_extension_CCEditBox_setMaxLength, 1, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	static JSFunctionSpec st_funcs[] = {
		JS_FN("create", js_cocos2dx_extension_CCEditBox_create, 4, JSPROP_PERMANENT | JSPROP_SHARED),
		JS_FS_END
	};

	js_cocos2dx_extension_CCEditBox_prototype = JS_InitClass(
		cx, global,
		NULL, // parent proto
		js_cocos2dx_extension_CCEditBox_class,
		js_cocos2dx_extension_CCEditBox_constructor, 0, // constructor
		properties,
		funcs,
		NULL, // no static properties
		st_funcs);

	// add the proto and JSClass to the type->js info hash table
	TypeTest<cocos2d::extension::CCEditBox> t;
	js_type_class_t *p;
	uint32_t typeId = t.s_id();
	HASH_FIND_INT(_js_global_type_ht, &typeId, p);
	if (!p) {
		p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
		p->type = typeId;
		p->jsclass = js_cocos2dx_extension_CCEditBox_class;
		p->proto = js_cocos2dx_extension_CCEditBox_prototype;
		p->parentProto = NULL;
		HASH_ADD_INT(_js_global_type_ht, type, p);
	}
}

void register_all_cocos2dx_extension(JSContext* cx, JSObject* obj) {
	// first, try to get the ns
	jsval nsval;
	JSObject *ns;
	JS_GetProperty(cx, obj, "cc", &nsval);
	if (nsval == JSVAL_VOID) {
		ns = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(ns);
		JS_SetProperty(cx, obj, "cc", &nsval);
	} else {
		JS_ValueToObject(cx, nsval, &ns);
	}
	obj = ns;

	js_register_cocos2dx_extension_CCEditBox(cx, obj);
	js_register_cocos2dx_extension_CCScrollView(cx, obj);
	js_register_cocos2dx_extension_CCScale9Sprite(cx, obj);
}

