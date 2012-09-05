/*
 * ControlButtonTest.m
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

require("CCControlScene.js");

// Get the sceensize
var screenSize = cc.Director.getInstance().getWinSize();


var ControlButtonTest_HelloVariableSize = ControlScene.extend({
    ctor: function() {
        var parent = new cc.Layer();
        __associateObjWithNative(this, parent);
        this.init();
    },

    init: function() {
        this._super();
        // Defines an array of title to create buttons dynamically
        var stringArray = ["Hello","Variable","Size","!"];
        
        var layer = cc.Node.create();
        this.addChild(layer, 1);
        
        var total_width = 0, height = 0;
        
        // For each title in the array
        for (var i = 0; i < stringArray.length; i++)
        {
            // Creates a button with this string as title
            var button = this.standardButtonWithTitle(stringArray[i]);
            button.setPosition(cc.p (total_width + button.getContentSize().width / 2, button.getContentSize().height / 2));
            layer.addChild(button);

            // Compute the size of the layer
            height = button.getContentSize().height;
            total_width += button.getContentSize().width;
        }

        layer.setAnchorPoint(cc.p (0.5, 0.5));
        layer.setContentSize(cc.size(total_width, height));
        layer.setPosition(cc.p(screenSize.width / 2.0, screenSize.height / 2.0));
        
        // Add the black background
        var background = cc.Scale9Sprite.create("extensions/buttonBackground.png");
        background.setContentSize(cc.size(total_width + 14, height + 14));
        background.setPosition(cc.p(screenSize.width / 2.0, screenSize.height / 2.0));
        this.addChild(background);
    },

    standardButtonWithTitle: function(title) {
        /** Creates and return a button with a default background and title color. */
        var backgroundButton = cc.Scale9Sprite.create("extensions/button.png");
        var backgroundHighlightedButton = cc.Scale9Sprite.create("extensions/buttonHighlighted.png");
        
        var titleButton = cc.LabelTTF.create(title, "Marker Felt", 30);

        titleButton.setColor(cc.c3(159, 168, 176));
        
        var button = cc.ControlButton.create(titleButton, backgroundButton);
        button.setBackgroundSpriteForState(backgroundHighlightedButton, cc.ControlStateHighlighted);
        button.setTitleColorForState(cc.WHITE, cc.ControlStateHighlighted);
        
        return button;
    }
});


var ControlButtonTest_Event = ControlScene.extend({
    m_pDisplayValueLabel: null,

    ctor: function() {
        var parent = new cc.Layer();
        __associateObjWithNative(this, parent);
        this.init();

               // Add a label in which the button events will be displayed
        m_pDisplayValueLabel = cc.LabelTTF.create("No Event", "Marker Felt", 32);
        m_pDisplayValueLabel.setAnchorPoint(cc.p(0.5, -1));
        m_pDisplayValueLabel.setPosition(cc.p(screenSize.width / 2.0, screenSize.height / 2.0));
        this.addChild(m_pDisplayValueLabel, 1);
        
        // Add the button
        var backgroundButton = cc.Scale9Sprite.create("extensions/button.png");
        var backgroundHighlightedButton = cc.Scale9Sprite.create("extensions/buttonHighlighted.png");
        
        var titleButton = cc.LabelTTF.create("Touch Me!", "Marker Felt", 30);

        titleButton.setColor(cc.c3(159, 168, 176));
        
        var controlButton = cc.ControlButton.create(titleButton, backgroundButton);
        controlButton.setBackgroundSpriteForState(backgroundHighlightedButton, cc.ControlStateHighlighted);
        controlButton.setTitleColorForState(cc.WHITE, cc.ControlStateHighlighted);
        
        controlButton.setAnchorPoint(cc.p(0.5, 1));
        controlButton.setPosition(cc.p(screenSize.width / 2.0, screenSize.height / 2.0));
        this.addChild(controlButton, 1);

        // Add the black background
        var background = cc.Scale9Sprite.create("extensions/buttonBackground.png");
        background.setContentSize(cc.size(300, 170));
        background.setPosition(cc.p(screenSize.width / 2.0, screenSize.height / 2.0));
        this.addChild(background);
        
        // Sets up event handlers
        controlButton.addTargetWithActionForControlEvents(this, this.touchDownAction, cc.ControlEventTouchDown);
        controlButton.addTargetWithActionForControlEvents(this, this.touchDragInsideAction, cc.ControlEventTouchDragInside);
        controlButton.addTargetWithActionForControlEvents(this, this.touchDragOutsideAction, cc.ControlEventTouchDragOutside);
        controlButton.addTargetWithActionForControlEvents(this, this.touchDragEnterAction, cc.ControlEventTouchDragEnter);
        controlButton.addTargetWithActionForControlEvents(this, this.touchDragExitAction, cc.ControlEventTouchDragExit);
        controlButton.addTargetWithActionForControlEvents(this, this.touchUpInsideAction, cc.ControlEventTouchUpInside);
        controlButton.addTargetWithActionForControlEvents(this, this.touchUpOutsideAction, cc.ControlEventTouchUpOutside);
        controlButton.addTargetWithActionForControlEvents(this, this.touchCancelAction, cc.ControlEventTouchCancel);
    },

    touchDownAction: function(sender, controlEvent) {
        cc.log("touchDownAction");
        m_pDisplayValueLabel.setString("Touch Down");
    },

    touchDragInsideAction: function(sender, controlEvent) {
        cc.log("touchDragInsideAction");
        m_pDisplayValueLabel.setString("Drag Inside");
    },

    touchDragOutsideAction: function(sender, controlEvent) {
        cc.log("touchDragOutsideAction");
        m_pDisplayValueLabel.setString("Drag Outside");
    },

    touchDragEnterAction: function(sender, controlEvent) {
        cc.log("touchDragEnterAction");
        m_pDisplayValueLabel.setString("Drag Enter");
    },

    touchDragExitAction: function(sender, controlEvent) {
        cc.log("touchDragExitAction");
        m_pDisplayValueLabel.setString("Drag Exit");
    },

    touchUpInsideAction: function(sender, controlEvent) {
        cc.log("touchUpInsideAction");
        m_pDisplayValueLabel.setString("Touch Up Inside.");
    },

    touchUpOutsideAction: function(sender, controlEvent) {
        cc.log("touchUpOutsideAction");
        m_pDisplayValueLabel.setString("Touch Up Outside.");
    },

    touchCancelAction: function(sender, controlEvent) {
        cc.log("touchCancelAction");
        m_pDisplayValueLabel.setString("Touch Cancel");
    }
});


var ControlButtonTest_Styling = ControlScene.extend({
    ctor: function() {
        var parent = new cc.Layer();
        __associateObjWithNative(this, parent);
        this.init();

        var layer = cc.Node.create();
        this.addChild(layer, 1);
        
        var space = 10; // px
        
        var max_w = 0, max_h = 0;
        for (var i = 0; i < 3; i++)
        {
            for (var j = 0; j < 3; j++)
            {
                // Add the buttons
                var button = this.standardButtonWithTitle(parseInt(Math.random() * 30));
                button.setAdjustBackgroundImage(false);  // Tells the button that the background image must not be adjust
                                                    // It'll use the prefered size of the background image
                button.setPosition(cc.p (button.getContentSize().width / 2 + (button.getContentSize().width + space) * i,
                                       button.getContentSize().height / 2 + (button.getContentSize().height + space) * j));
                layer.addChild(button);
                
                max_w = Math.max(button.getContentSize().width * (i + 1) + space  * i, max_w);
                max_h = Math.max(button.getContentSize().height * (j + 1) + space * j, max_h);
            }
        }
        
        layer.setAnchorPoint(cc.p (0.5, 0.5));
        layer.setContentSize(cc.size(max_w, max_h));
        layer.setPosition(cc.p(screenSize.width / 2.0, screenSize.height / 2.0));
        
        // Add the black background
        var backgroundButton = cc.Scale9Sprite.create("extensions/buttonBackground.png");
        backgroundButton.setContentSize(cc.size(max_w + 14, max_h + 14));
        backgroundButton.setPosition(cc.p(screenSize.width / 2.0, screenSize.height / 2.0));
        this.addChild(backgroundButton);
    },


    standardButtonWithTitle: function(title)
    {
        /** Creates and return a button with a default background and title color. */
        var backgroundButton = cc.Scale9Sprite.create("extensions/button.png");
        backgroundButton.setPreferredSize(cc.size(45, 45));  // Set the prefered size
        var backgroundHighlightedButton = cc.Scale9Sprite.create("extensions/buttonHighlighted.png");
        backgroundHighlightedButton.setPreferredSize(cc.size(45, 45));  // Set the prefered size
        
        var titleButton = cc.LabelTTF.create(title, "Marker Felt", 30);

        titleButton.setColor(cc.c3(159, 168, 176));
        
        var button = cc.ControlButton.create(titleButton, backgroundButton);
        button.setBackgroundSpriteForState(backgroundHighlightedButton, cc.ControlStateHighlighted);
        button.setTitleColorForState(cc.WHITE, cc.ControlStateHighlighted);
        
        return button;
    }

});

ControlButtonTest_HelloVariableSize.sceneWithTitle = function(title) {
    var pScene = cc.Scene.create();
    var controlLayer = new ControlButtonTest_HelloVariableSize();
    controlLayer.m_pSceneTitleLabel.setString(title);
    pScene.addChild(controlLayer);
    return pScene;
};

ControlButtonTest_Event.sceneWithTitle = function(title) {
    var pScene = cc.Scene.create();
    var controlLayer = new ControlButtonTest_Event();
    controlLayer.m_pSceneTitleLabel.setString(title);
    pScene.addChild(controlLayer);
    return pScene;
};

ControlButtonTest_Styling.sceneWithTitle = function(title) {
    var pScene = cc.Scene.create();
    var controlLayer = new ControlButtonTest_Styling();
    controlLayer.m_pSceneTitleLabel.setString(title);
    pScene.addChild(controlLayer);
    return pScene;
};




