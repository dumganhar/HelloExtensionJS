#ifndef __cocos2dx_extension_h__
#define __cocos2dx_extension_h__

#include "cocos2d.h"
#include "ScriptingCore.h"
#include "cocos2d_specifics.hpp"

extern JSClass  *js_cocos2dx_extension_CCScale9Sprite_class;
extern JSObject *js_cocos2dx_extension_CCScale9Sprite_prototype;

JSBool js_cocos2dx_extension_CCScale9Sprite_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_extension_CCScale9Sprite_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_extension_CCScale9Sprite(JSContext *cx, JSObject *global);
void register_all_cocos2dx_extension(JSContext* cx, JSObject* obj);
JSBool js_cocos2dx_extension_CCScale9Sprite_updateWithBatchNode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getCapInsets(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_initWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setOpacityModifyRGB(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setOriginalSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setInsetBottom(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_isOpacityModifyRGB(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_visit(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setOpacity(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setInsetTop(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setPreferredSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getOpacity(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getColor(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_initWithBatchNode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getInsetBottom(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_resizableSpriteWithCapInsets(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setContentSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getInsetRight(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getOriginalSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_initWithFile(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setColor(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getInsetTop(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setInsetLeft(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_initWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getPreferredSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setCapInsets(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_getInsetLeft(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_setInsetRight(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_node(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_spriteWithFile(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_create(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_spriteWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_createWithSpriteFrameName(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_spriteWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_createWithSpriteFrame(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScale9Sprite_CCScale9Sprite(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_cocos2dx_extension_CCScrollView_class;
extern JSObject *js_cocos2dx_extension_CCScrollView_prototype;

JSBool js_cocos2dx_extension_CCScrollView_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_extension_CCScrollView_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_extension_CCScrollView(JSContext *cx, JSObject *global);
void register_all_cocos2dx_extension(JSContext* cx, JSObject* obj);
JSBool js_cocos2dx_extension_CCScrollView_isClippingToBounds(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setContainer(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setContentOffsetInDuration(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setZoomScaleInDuration(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_addChild(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_getContainer(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_getDirection(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_getZoomScale(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_initWithViewSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_pause(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setDirection(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_visit(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setBounceable(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setContentOffset(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_isDragging(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_init(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_isBounceable(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_getContentSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setTouchEnabled(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_getContentOffset(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_resume(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setClippingToBounds(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setViewSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_getViewSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_maxContainerOffset(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setContentSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_isTouchMoved(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_getDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_isNodeVisible(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_minContainerOffset(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_registerWithTouchDispatcher(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_setZoomScale(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_create(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCScrollView_CCScrollView(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *js_cocos2dx_extension_CCEditBox_class;
extern JSObject *js_cocos2dx_extension_CCEditBox_prototype;

JSBool js_cocos2dx_extension_CCEditBox_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_extension_CCEditBox_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_extension_CCEditBox(JSContext *cx, JSObject *global);
void register_all_cocos2dx_extension(JSContext* cx, JSObject* obj);
JSBool js_cocos2dx_extension_CCEditBox_keyboardDidShow(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_getText(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setContentSize(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_visit(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_keyboardDidHide(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_getPlaceHolder(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setInputMode(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_keyboardWillShow(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setPlaceholderFontColor(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setReturnType(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setFontColor(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_keyboardWillHide(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_touchDownAction(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setDelegate(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_initWithSizeAndBackgroundSprite(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setPlaceHolder(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setPosition(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_onExit(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_getMaxLength(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setInputFlag(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setText(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_setMaxLength(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_create(JSContext *cx, uint32_t argc, jsval *vp);
JSBool js_cocos2dx_extension_CCEditBox_CCEditBox(JSContext *cx, uint32_t argc, jsval *vp);
#endif

