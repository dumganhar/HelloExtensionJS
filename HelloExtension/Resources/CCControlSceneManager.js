/*
 * CCControlSceneManager.js
 *
 * Copyright (c) 2012 cocos2d-x.org
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

require("CCControlScene.js");
require("CCControlButtonTest.js");

/*
var kControlSliderTest = 0;
var kControlColourPickerTest = 1;
var kControlSwitchTest = 2;*/
var kControlButtonTest_HelloVariableSize = 0;
var kControlButtonTest_Event = 1;
var kControlButtonTest_Styling = 2;
var kControlTestMax = 3;

var s_testArray = [
 //   "CCControlSliderTest",
 //   "ControlColourPickerTest",
  //  "ControlSwitchTest",
    "ControlButtonTest_HelloVariableSize",
    "ControlButtonTest_Event",
    "ControlButtonTest_Styling"
];


var ControlSceneManager = cc.Layer.extend({
    m_nCurrentControlSceneId: kControlButtonTest_HelloVariableSize,
    ctor: function() {
        var parent = new cc.Layer();
        __associateObjWithNative(this, parent);
        this.init();
    },

    /** Returns the next control scene. */
    nextControlScene: function() {
        this.m_nCurrentControlSceneId = (this.m_nCurrentControlSceneId + 1) % kControlTestMax;

        return this.currentControlScene();
    },

    /** Returns the previous control scene. */
    previousControlScene: function() {
        this.m_nCurrentControlSceneId = this.m_nCurrentControlSceneId - 1;

        if (this.m_nCurrentControlSceneId < 0)
        {
            this.m_nCurrentControlSceneId = kControlTestMax - 1;
        }

        return this.currentControlScene();
    },

    /** Returns the current control scene. */
    currentControlScene: function() {
        switch (this.m_nCurrentControlSceneId)
        {
            //case kCCControlSliderTest: return CCControlSliderTest::sceneWithTitle(s_testArray[m_nCurrentControlSceneId]);
            //case kCCControlColourPickerTest:return CCControlColourPickerTest::sceneWithTitle(s_testArray[m_nCurrentControlSceneId]);
            //case kCCControlSwitchTest:return CCControlSwitchTest::sceneWithTitle(s_testArray[m_nCurrentControlSceneId]);
            case kControlButtonTest_HelloVariableSize:return ControlButtonTest_HelloVariableSize.sceneWithTitle(s_testArray[this.m_nCurrentControlSceneId]);
            case kControlButtonTest_Event:return ControlButtonTest_Event.sceneWithTitle(s_testArray[this.m_nCurrentControlSceneId]);
            case kControlButtonTest_Styling:return ControlButtonTest_Styling.sceneWithTitle(s_testArray[this.m_nCurrentControlSceneId]);
        }
        return null;
    }
});

var sharedControlSceneManager = null;

ControlSceneManager.getInstance = function() {
    if (sharedControlSceneManager == null) {
        cc.log("new Instance");
        sharedControlSceneManager = new ControlSceneManager();
    }
    return sharedControlSceneManager;
};


