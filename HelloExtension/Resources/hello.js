require("helper.js");
//require("CCControlSceneManager.js");

// 校正滑动动画速度
var ADJUST_ANIM_VELOCITY = 800;

var director = cc.Director.getInstance();
var winSize = director.getWinSize();

var HelloWorld = cc.LayerGradient.extend({
    scrollView: null,
    label: null,
    ctor:function () {
        var parent = new cc.LayerGradient();
        __associateObjWithNative(this, parent);
        this.init(cc.c4b(0, 0, 0, 255), cc.c4b(0, 128, 255, 255));
        this.setTouchEnabled( true );

        scrollView = cc.ScrollView.create();
        var layer = cc.Layer.create();

        var sprite1 = cc.Sprite.create("HelloWorld.png");
        var sprite2 = cc.Sprite.create("HelloWorld.png");

        layer.setAnchorPoint(cc.p(0, 0));
        layer.setPosition(cc.p(0, 0));

        // Menu
        var menuItem1 = cc.MenuItemSprite.create(sprite1, sprite1, this, this.menu1Callback);
        menuItem1.setPosition(cc.pAdd(cc.p(0, 0), cc.p(winSize.width / 2, winSize.height / 2)));
        menuItem1.setScale(0.4);
        var menuItem2 = cc.MenuItemSprite.create(sprite2, sprite2, this, this.menu2Callback);
        menuItem2.setPosition(cc.pAdd(cc.p(480, 0), cc.p(winSize.width / 2, winSize.height / 2)));
        menuItem2.setScale(0.4);
        var menu = cc.Menu.create(menuItem1, menuItem2);
        
        menu.setPosition(cc.p(0, 0));
        layer.addChild(menu);

        
        scrollView.setPosition(cc.p(0, 0));
        scrollView.setContentOffset(cc.p(0, 0), false);
        layer.setContentSize(cc.size(960, 320));
        scrollView.setContentSize(cc.size(480, 320));
        scrollView.setContainer(layer);
        scrollView.setDirection(cc.ScrollViewDirectionHorizontal);
        scrollView.setDelegate(this);

        this.addChild(scrollView, 10, 1234);
        //this.addChild(layer);
        
        /*
        var sp = cc.Sprite.create("HelloWorld.png");
        sp.setPosition(cc.p(winSize.width/2, winSize.height/2));
        layer.addChild(sp);
        */
        
        var scale9Sp = cc.Scale9Sprite.create("green_edit.png");
        //scale9Sp.setPosition(cc.p(winSize.width/2, winSize.height/2));
        //scale9Sp.setPreferredSize(cc.size(200, 50));
        //layer.addChild(scale9Sp);
        
        //var editBox = cc.EditBox.create(cc.size(200, 50), scale9Sp);
        //editBox.setPosition(cc.p(winSize.width/2, winSize.height/2));
        //layer.addChild(editBox);
        
        
        var btn = cc.ControlButton.create(scale9Sp);
        btn.setPreferredSize(cc.size(200, 50));
        btn.setPosition(cc.p(winSize.width/2, 50));

        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchUpInside);
        /*btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchDown);
        
        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchDragInside);
        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchDragOutside);
        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchDragEnter);
        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchDragExit);
        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchUpInside);
        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchUpOutside);
        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchCancel);
        btn.addTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventValueChanged); */
        this.addChild(btn);
       
        /*
        var lab = "Houston we have liftoff!";
        var label = cc.LabelTTF.create(lab, "Arial", 28);
        layer.addChild(label, 1);
        label.setPosition( cc.p(winSize.width / 2, winSize.height / 2));
        */
    },
    
    touchEventCallback: function(sender, event) {
        cc.log("touchEventCallback... " + sender + " "+event);
        //sender.removeTargetWithActionForControlEvents(this, this.touchEventCallback, cc.ControlEventTouchDown);

        // var pManager = ControlSceneManager.getInstance();
        // var pScene = pManager.currentControlScene();
        // cc.Director.getInstance().replaceScene(pScene);
    },

    menu1Callback: function() {
        cc.log("menu1Callback");
       /* var pManager = ControlSceneManager.getInstance();
        var pScene = pManager.currentControlScene();
        cc.Director.getInstance().replaceScene(pScene);*/
        __jsc__.dumpRoot();
        __jsc__.garbageCollect();
       cc.log("menu1Callback 01");
        run();
        __jsc__.dumpRoot();
        __jsc__.garbageCollect();
         cc.log("menu1Callback 02");
    },

    menu2Callback: function() {
        cc.log("menu2Callback");
    }, 

    onTouchesBegan:function (touches, event) {
        cc.log("HelloWorld onTouchesBegan");
    },

    onTouchesMoved:function (touches, event) {
        cc.log("HelloWorld onTouchesMoved");
    },

    onTouchesEnded:function (touches, event) {
        cc.log("HelloWorld onTouchesEnded");
        this.adjustScrollView();
    },

    adjustScrollView: function() {
        
        // 关闭CCScrollView中的自调整
        scrollView.unscheduleAllSelectors();
        
        var x = scrollView.getContentOffset().x;
        var offset = x % 480;
        // 调整位置
        var adjustPos;
        // 调整动画时间
        var adjustAnimDelay;
        
        if (offset < -240) {
            // 计算下一页位置，时间
            adjustPos = cc.pSub(scrollView.getContentOffset(), cc.p(480 + offset, 0));
            adjustAnimDelay = (480 + offset) / ADJUST_ANIM_VELOCITY;
        }
        else {
            // 计算当前页位置，时间
            adjustPos = cc.pSub(scrollView.getContentOffset(), cc.p(offset, 0));
            // 这里要取绝对值，否则在第一页往左翻动的时，保证adjustAnimDelay为正数
            adjustAnimDelay = Math.abs(offset) / ADJUST_ANIM_VELOCITY;
        }
        
        // 调整位置
        scrollView.setContentOffsetInDuration(adjustPos, adjustAnimDelay);
        
    },

    onScrollViewDidScroll: function(sender) {
        cc.log("onScrollViewDidScroll " + sender.getTag());
    },

    onScrollViewDidZoom: function(sender) {
        cc.log("onScrollViewDidZoom " + sender.getTag());
    },
});

try {
  
    cc.p = cc.p || function( x, y ) {
        return {x:x, y:y};
    };
    
    cc.c4b = cc.c4 || function (r, g, b, o) {
        return {r: r, g: g, b: b, a: o};
    };



    var scene = new cc.Scene();
    var layer = new HelloWorld();
    scene.addChild(layer);

    director.runWithScene(scene);

    __jsc__.dumpRoot();
    __jsc__.garbageCollect();

} catch(e) {log(e);}

require("CCControlScene.js");
