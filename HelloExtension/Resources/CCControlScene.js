/*
 * cc.ControlScene.m
 *
 * Copyright (c) 2011 Yannick Loriot
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

require("helper.js");
director = cc.Director.getInstance();

var scenes = [];
var currentScene = 0;


var ControlScene = cc.Layer.extend({

    ctor: function() {
        cc.log("ControlScene ctor 00");
        var parent = new cc.Layer();
        __associateObjWithNative(this, parent);
        cc.log("ControlScene ctor 01");
        this.init();
        cc.log("ControlScene ctor 02");
    }
});

scenes.push(ControlScene);

function run() {
    var scene = cc.Scene.create();
    // var layer = new ControlScene();
    var layer = new scenes[ currentScene ]();
    scene.addChild(layer);

    director.replaceScene(scene);
}


// var ControlScene = cc.Layer.extend({
//     m_pSceneTitleLabel: null,

//     ctor: function() {
//         var parent = new cc.Layer();
//         __associateObjWithNative(this, parent);
//     },

//     init: function() {
//         cc.log("ControlScene 01");
//         this._super();
        
//         // Get the sceensize
//         var screensize = cc.Director.getInstance().getWinSize();

//         var pBackItem = cc.MenuItemFont.create("Back", this, this.toExtensionsMainLayer);
//         pBackItem.setPosition(cc.p(screensize.width - 50, 25));
//         var pBackMenu = cc.Menu.create(pBackItem);
//         pBackMenu.setPosition( cc.p(0,0) );
//         this.addChild(pBackMenu, 10);

//         // Add the generated background
//         var background = cc.Sprite.create("extensions/background.png");
//         background.setPosition(cc.p(screensize.width / 2, screensize.height / 2));
//         this.addChild(background);
//         /*
//         // Add the ribbon
//         var ribbon = cc.Scale9Sprite.create("extensions/ribbon.png", cc.rect(1, 1, 48, 55));
//         ribbon.setContentSize(cc.size(screensize.width, 57));
//         ribbon.setPosition(cc.p(screensize.width / 2.0, screensize.height - ribbon.getContentSize().height / 2.0));
//         this.addChild(ribbon);
//         */
//         // Add the title
//         this.m_pSceneTitleLabel = cc.LabelTTF.create("Title", "Arial", 12);
//         this.m_pSceneTitleLabel.setPosition(cc.p (screensize.width / 2, screensize.height - this.m_pSceneTitleLabel.getContentSize().height / 2 - 5));
//         this.addChild(this.m_pSceneTitleLabel, 1);
        
//         // Add the menu
//         var item1 = cc.MenuItemImage.create("Images/b1.png", "Images/b2.png", this, this.previousCallback);
//         var item2 = cc.MenuItemImage.create("Images/r1.png", "Images/r2.png", this, this.restartCallback);
//         var item3 = cc.MenuItemImage.create("Images/f1.png", "Images/f2.png", this, this.nextCallback);
        
//         var menu = cc.Menu.create(item1, item3, item2);
//         menu.setPosition(cc.p(0, 0));
//         item1.setPosition(cc.p(screensize.width / 2 - 100, 37));
//         item2.setPosition(cc.p(screensize.width / 2, 35));
//         item3.setPosition(cc.p(screensize.width / 2 + 100, 37));
        
//         this.addChild(menu ,1);

//         cc.log("ControlScene 02");
//     },

//     toExtensionsMainLayer: function (sender) {
//         //var pScene = new ExtensionsTestScene();
//         //pScene.runThisTest();
//     },

//     previousCallback: function (sender) {
//         cc.Director.getInstance().replaceScene(ControlSceneManager.getInstance().previousControlScene());
//         __jsc__.dumpRoot();
//         __jsc__.garbageCollect();
//     },

//     restartCallback: function (sender) {
//         cc.Director.getInstance().replaceScene(ControlSceneManager.getInstance().currentControlScene());
//         __jsc__.dumpRoot();
//         __jsc__.garbageCollect();
//     },

//     nextCallback: function (sender) {
//         cc.Director.getInstance().replaceScene(ControlSceneManager.getInstance().nextControlScene());
//         __jsc__.dumpRoot();
//         __jsc__.garbageCollect();
//     }

// });





