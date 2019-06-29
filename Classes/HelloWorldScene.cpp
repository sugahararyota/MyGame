/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

	//{//0629やってみよう1
	//	// Spriteの生成
	//	Sprite* spr = Sprite::create("neko.png");
	//	this->addChild(spr);
	//	spr->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 100));
	//	spr->setScale(0.2f);

	//	// 移動アクションの生成
	//	MoveTo* moveLeft = MoveTo::create(5.0f, Vec2(100, visibleSize.height - 100));
	//	MoveTo* moveRight = MoveTo::create(5.0f, Vec2(visibleSize.width - 100, visibleSize.height - 100));

	//	// 連続アクションの生成
	//	Sequence* seq = Sequence::create(moveLeft, moveRight, nullptr);

	//	// アクションの実行
	//	spr->runAction(seq);
	//}
	//{//0629やってみよう2
	//	Sprite* spr1 = Sprite::create("neko.png");
	//spr->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 100));
	//	this->addChild(spr1);
	//	MoveTo* moveLeft = MoveTo::create(5.0f, Vec2(100, visibleSize.height - 100));
	//	MoveTo* moveRight = MoveTo::create(5.0f, Vec2(visibleSize.width - 100, visibleSize.height - 100));
	//	Sequence* seq1 = Sequence::create(moveLeft, moveRight, nullptr);

	//	// フェードアクションの生成
	//	FadeOut* fadeOut = FadeOut::create(5.0f);
	//	FadeIn* fadeIn = FadeIn::create(5.0f);

	//	// 連続アクションの生成
	//	Sequence* seq2 = Sequence::create(fadeOut, fadeIn, nullptr);

	//	// 同時アクションの生成
	//	Spawn* allAction = Spawn::create(seq1, seq2, nullptr);

	//	spr1->runAction(allAction);
	//}
	//{//0629やってみよう3
	//	Sprite* spr1 = Sprite::create("neko.png");
	//	spr1->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 100));
	//	this->addChild(spr1);
	//	MoveTo* moveLeft = MoveTo::create(5.0f, Vec2(100, visibleSize.height - 100));
	//	MoveTo* moveRight = MoveTo::create(5.0f, Vec2(visibleSize.width - 100, visibleSize.height - 100));
	//	Sequence* seq1 = Sequence::create(moveLeft, moveRight, nullptr);

	//	// フェードアクションの生成
	//	FadeOut* fadeOut = FadeOut::create(5.0f);
	//	FadeIn* fadeIn = FadeIn::create(5.0f);

	//	// 連続アクションの生成
	//	Sequence* seq2 = Sequence::create(fadeOut, fadeIn, nullptr);

	//	// 同時アクションの生成
	//	Spawn* spawn = Spawn::create(seq1, seq2, nullptr);

	//	// 繰り返しアクションの生成
	//	Repeat* allAction = Repeat::create(spawn, 5);

	//	spr1->runAction(allAction);
	//}
	//{//0629やってみよう4
	//	Sprite* spr1 = Sprite::create("neko.png");
 //       spr1->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 100));
	//	this->addChild(spr1);
	//	MoveBy* moveLeft = MoveBy::create(1.0f, Vec2(-(visibleSize.width - 200), 0));
	//	MoveBy* moveDown = MoveBy::create(1.0f, Vec2(0, -(visibleSize.height - 200)));
	//	MoveBy* moveRight = moveLeft->reverse();
	//	MoveBy* moveUp = moveDown->reverse();

	//	Sequence* seq1 = Sequence::create(moveLeft, moveDown, moveRight, moveUp, nullptr);

	//	spr1->runAction(seq1);
	//}

	{//0629やってみよう5
		Sprite* spr1 = Sprite::create("neko.png");
		spr1->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 100));
		this->addChild(spr1);
		MoveBy* moveLeft = MoveBy::create(1.0f, Vec2(-(visibleSize.width - 200), 0));
		MoveBy* moveDown = MoveBy::create(1.0f, Vec2(0, -(visibleSize.height - 200)));
		MoveBy* moveRight = moveLeft->reverse();
		MoveBy* moveUp = moveDown->reverse();

		Sequence* seq1 = Sequence::create(moveLeft, moveDown, moveRight, moveUp, nullptr);

		RepeatForever* repeat = RepeatForever::create(seq1);

		spr1->runAction(repeat);
	}
	

	//sprite[0]->setPosition(Vec2(1280 / 2.0f, 720 / 2.0f));
	//乱数の初期化//Random r = new Rondom();と同じ
	//srand(time(nullptr));
	//{0629
	//	//移動アクション
	//	//Sprite* spr = Sprite::create("neko.png");
	//	Sprite* spr = Sprite::create("sinku.png");
	//	this->addChild(spr);

	//	JumpTo* action1 = JumpTo::create(0.5f, Vec2(100.0f, 100.0f), 100, 1);

	//	//ToggleVisibility* action2 = ToggleVisibility::create();

	//	//DelayTime* action2 = DelayTime::create(1.0);

	//	MoveTo* action2 = MoveTo::create(2.0f, Vec2(600.0f, 300.0f));


	//	//必ず最後に組み込む（自信を削除する
	//	RemoveSelf* action3 = RemoveSelf::create();

	//	Sequence* action4 = Sequence::create(action1, action2, action3, nullptr);

	//	/*Repeat* action4 = Repeat::create(action3, 3);*/
	//	//無限に繰り返す
	//	RepeatForever* action5 = RepeatForever::create(action4);
	//	spr->runAction(action5);
	//	////MoveToの後にJumpToとTinToを同時発動させる

	//	//MoveTo* action1 = MoveTo::create(2.0f, Vec2(600.0f, 300.0f));

	//	//JumpTo* action2 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
	//	//TintTo* action3 = TintTo::create(2.0f, Color3B(255, 255, 0));

	//	////JumoToとTintToの同時委発動
	//	//Spawn* action4 = Spawn::create(action2, action3, nullptr);
	//	//Sequence* action5 = Sequence::create(action1, action4, nullptr);
	//	//spr->runAction(action5);
	//}0629
	//for(int i = 0;i<5;i++)
	//{
	//	sprite[i] = Sprite::create("sinku1.png");
	//	this->addChild(sprite[i]);
	//	sprite[i]->setPosition(Vec2(300*i, visibleSize.height/2.0f));
	//	//sprite[i]->setScale(2.0f);

	//	float mx, my;
	//	mx = (float)rand()/RAND_MAX*700-300;
	//	my = (float)rand() / RAND_MAX*700-300;

	//	MoveBy* action1 = MoveBy::create(3.0f, Vec2(mx, my));
	//	sprite[i]->runAction(action1);
	//}
	/*sprite[0] = Sprite::create("sinku.png");
	this->addChild(sprite[0]);
	sprite[0]->setPosition(Vec2(100 * 2, visibleSize.height / 2.0f));
	sprite[0]->setScale(2.0f);
	MoveBy* action1 = MoveBy::create(1.0f, Vec2(200, 100));
	sprite[0]->runAction(action1);*/


	sprite = Sprite::create("neko.png");
	spriteB = Sprite::create("sinku.png");
	////sprite = Sprite::create("sample04.png");
	//this->addChild(sprite);
	//this->addChild(spriteB);

	////アクションの作成
	//{
	//	MoveBy* action1 = MoveBy::create(1.0f, Vec2(200, 100));
	//	EaseOut* action2 = EaseOut::create(action1, 2.0f);
	//	EaseBounceIn* action3 = EaseBounceIn::create(action1);
	//	sprite->runAction(action2);
	//}
	//{
	//	MoveBy* action1 = MoveBy::create(1.0f, Vec2(-200, 100));
	//	EaseOut* action2 = EaseOut::create(action1, 2.0f);
	//	EaseBounceIn* action3 = EaseBounceIn::create(action1);
	//	spriteB->runAction(action2);
	//	//spriteB->runAction(action2->clone());上のやつを複製できる
	//}
	//ScaleTo* action1 = ScaleTo::create(1.0f, 3.0f);
	//JumpTo* action1 = JumpTo::create(1.5f, Vec2(200, 100), 500, 1);
	/*ccBezierConfig conf;
	conf.controlPoint_1 = Vec2(500, 500);
	conf.controlPoint_2 = Vec2(-700, -700);
	conf.endPosition = Vec2(700, 700);
	BezierTo* action1 = BezierTo:: create(3.0f, conf);*/
	/*sprite->setOpacity(0);
	FadeIn* action1 = FadeIn::create(1.0f);*/





	//this->addChild(spriteB);
	//spriteB->setScale(2.0f, 2.0f);

	////表示座標を指定
	//sprite->setPosition(Vec2(1280/2.0f, 720/2.0f));
	//spriteB->setPosition(Vec2(1280 / 2.0f, 720 / 2.0f));
	//回転角を指定（45度
	//sprite->setRotation(45.0f);
	//拡縮を指定（45
	//sprite->setScale(3.0f, 4.0f);
	//左右反転
	//sprite->setFlippedX(true);
	//上下反転
	//sprite->setFlippedY(true);
	//非表示にする
	//sprite->setVisible(false);
	//色合いを設定
	//sprite->setColor(Color3B(0xff, 0x00, 0x00));
	//不透明度を設定
	//sprite->setOpacity(255);

	//画像の左下が（0,0）
	//画像の右上が（1,0）
	//基準点を指定する
	//sprite->setAnchorPoint(Vec2(0.0f, 1.0f));
	//spriteB->setAnchorPoint(Vec2(0.0f, 1.0f));

	//sprite->setRotation(45.0f);

	//色指定
	//sprite->setColor(Color3B(0,0,0));

	//sprite->setFlippedX(true);
	//sprite->setTextureRect(Rect(0, 32, 32, 32));

	this->scheduleUpdate();         //変更

	//counter = 0;

	/*state = 0;

	fot = 0;

	blue = 0;

	opacity = 0;*/


    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
	/*opacity += 1.0f;
	spriteB->setOpacity(opacity);
	sprite->setOpacity(255.0f - opacity);
	if (opacity >= 255.0f)
	{
		opacity = 255.0f;
	}*/


	/*blue += 255.0f/180.0f;
	if (blue > 255.0f)
	{
		blue = 255.0f;
	}
	sprite->setColor(Color3B(255-blue, 0, blue));
	
	fot += 5.0f;
	sprite->setRotation(fot);*/

	//Vec2 pos;
	
	//switch (state)
	//{
	//	//左移動
	//case0:
	//	pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// 左端に達したら
	//	if (pos.x <= 100)
	//	{
	//		state = 1; // 下移動に切り替える
	//	}
	//	break;
	//case1:
	//	//下移動
	//	pos = sprite->getPosition();
	//	pos += Vec2(0.0f, -5.0f);
	//	sprite->setPosition(pos);
	//	if (pos.y <= 100)
	//	{
	//		state = 2;
	//	}
	//	break;
	//case2:
	//	break;
	//default:
	//	break;
	//}
	//switch (state)
	//{
	//	//opacity = 0.0f;
	//case 0:
	//	// 左移動
	//	pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// 左端に達したら
	//	if (pos.x <= 100)
	//	{
	//		state = 1; // 下移動に切り替える
	//	}
	//	break;
	//case 1:
	//	// 下移動
	//	pos = sprite->getPosition();
	//	pos += Vec2(0.0f, -5.0f);
	//	sprite->setPosition(pos);
	//	// 下端に達したら
	//	if (pos.y <= 100)
	//	{
	//		state = 2; // 右移動に切り替える
	//	}
	//	break;
	//case 2:
	//	// 右移動
	//	pos = sprite->getPosition();
	//	pos += Vec2(5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// 左端に達したら
	//	if (pos.x >= 1080)
	//	{
	//		state = 3; // 下移動に切り替える
	//	}
	//	break;
	//case 3:
	//	pos = sprite->getPosition();
	//	pos += Vec2(0.0f, 5.0f);
	//	sprite->setPosition(pos);
	//	// 下端に達したら
	//	if (pos.y >= 620)
	//	{
	//		state = 0; // 右移動に切り替える
	//	}
	//	break;

	//default:
	//	// 上移動
	//	break;
	//}
	//反転移動
	//switch (state)
	//{
	//	//opacity = 0.0f;
	//case 0:
	//	// 左移動
	//	pos = sprite->getPosition();
	//	pos += Vec2(-5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// 左端に達したら
	//	if (pos.x <= 100)
	//	{
	//		sprite->setFlippedX(true);
	//		state = 1; // 下移動に切り替える
	//	}
	//	break;
	//case 1:
	//	// 下移動
	//	pos = sprite->getPosition();
	//	pos += Vec2(5.0f, 0.0f);
	//	sprite->setPosition(pos);
	//	// 下端に達したら
	//	if (pos.x >= 1180)
	//	{
	//		sprite->setFlippedX(false);
	//		state = 0; // 右移動に切り替える
	//	}
	//	break;
	//
	//default:
	//	// 上移動
	//	break;
	//}

	// スプライトの現在座標を取得
	//Vec2 pos = sprite->getPosition();
	// 座標を移動させる
	//pos += Vec2(-1.0f, 0.0f);
	// 移動後の座標を反映
	//sprite->setPosition(pos);
	//透明にする
	//counter++;
	//float opacity = 255 - (counter / 300.0f * 255.0f);
	//if (opacity < 0)
	//{
		//opacity = 0.0f;
	//}
	//sprite->setOpacity(opacity);



}
