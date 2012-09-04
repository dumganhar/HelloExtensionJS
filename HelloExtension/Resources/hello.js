require("helper.js");

try {
  
    cc.p = cc.p || function( x, y ) {
        return {x:x, y:y};
    };
    
    cc.c4b = cc.c4 || function (r, g, b, o) {
        return {r: r, g: g, b: b, a: o};
    };

    director = cc.Director.getInstance();
    winSize = director.getWinSize();

    var scene = new cc.Scene();
    var scrollView = cc.ScrollView.create();
    scrollView.setContentSize(cc.size(450, 300));
    scrollView.setPosition(cc.p(0, 0));
    scrollView.setAnchorPoint(cc.p(0, 0));
    //scrollView.setDirection(1);
    
    var layer = new cc.LayerGradient();
    layer.init(cc.c4b(0, 0, 0, 255), cc.c4b(0, 128, 255, 255));
    layer.setContentSize(cc.size(500, 400));
    layer.setAnchorPoint(cc.p(0, 0));
    
    scrollView.setContainer(layer);
    
    var sp = cc.Sprite.create("HelloWorld.png");
    sp.setPosition(cc.p(winSize.width/2, winSize.height/2));
    layer.addChild(sp);
    
    var scale9Sp = cc.Scale9Sprite.create("green_edit.png");
    //scale9Sp.setPosition(cc.p(winSize.width/2, winSize.height/2));
    //scale9Sp.setPreferredSize(cc.size(200, 50));
    //layer.addChild(scale9Sp);
    
    //var editBox = cc.EditBox.create(cc.size(200, 50), scale9Sp);
    //editBox.setPosition(cc.p(winSize.width/2, winSize.height/2));
    //layer.addChild(editBox);
    
    var btn = cc.ControlButton.create(scale9Sp);
    btn.setPreferredSize(cc.size(200, 50));
    btn.setPosition(cc.p(winSize.width/2, winSize.height/2));
    layer.addChild(btn);
    
    var lab = "Houston we have liftoff!";
    var label = cc.LabelTTF.create(lab, "Arial", 28);
    layer.addChild(label, 1);
    label.setPosition( cc.p(winSize.width / 2, winSize.height / 2));


    scene.addChild(scrollView);


    director.runWithScene(scene);

} catch(e) {log(e);}