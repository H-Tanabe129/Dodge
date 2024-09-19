https://github.com/H-Tanabe129/Dodge

〇ゲーム名
Dodge！

〇ゲーム概要
作者	：東北電子専門学校 ゲームエンジニア科 3年　田邊ひなの
ジャンル：ジャンプ横スクロールゲーム
概要　　：DirectXのエンジンを使用したFlappy Bird風のゲームです。
	シンプルなキー操作で誰でも簡単にプレイできます。

〇ビルド環境
　OS 		   ： Windows10以上
　開発環境  	   ： Visual Studio 2022
　必要ライブラリ : FBXSDK、DirectXTex、DirectXToolKit

〇実行環境
　	OS、DLL

〇操作方法
Spaceキー　→　スタート、ジャンプ
T →　（ゲームオーバー時）タイトルに戻る
(ESC →　強制終了)



〇フォルダ構成
D:.
├ Assets
｜　├ DebugCollision
｜　｜  ├ BoxCollider.fbx
｜　｜  └SphereCollider.fbx
｜　｜
｜　├ Model
｜　｜  ├Obstacle.fbx
｜　｜  ├Player.fbx
｜　｜  └Stage.fbx
｜　｜
｜　├ Shader
｜　｜  ├BillBoard.hlsl
｜　｜  ├Debug3D.hlsl
｜　｜  ├Simple2D.hlsl
｜　｜  └Simple3D.hlsl
｜　｜
｜　├char.png
｜　├defaultParticle.png
｜　├Dodge.png
｜　├gameover.png
｜　├setup.ini
｜　└Start.png
｜
├ Engine
｜　├Audio.cpp
｜　├Audio.h
｜　├BillBoard.cpp
｜　├BillBoard.h
｜　├BoxCollider.cpp
｜　├BoxCollider.h
｜　├Camera.cpp
｜　├Camera.h
｜　├Collider.cpp
｜　├Collider.h
｜　├CsvReader.cpp
｜　├CsvReader.h
｜　├Debug.cpp
｜　├Debug.h
｜　├Direct3D.cpp
｜　├Direct3D.h  
｜　├Fbx.cpp  
｜　├Fbx.h  
｜　├FbxParts.cpp  
｜　├FbxParts.h  
｜　├GameObject.cpp
｜　├GameObject.h
｜　├Global.h  
｜　├Image.cpp  
｜　├Image.h  
｜　├Input.cpp  
｜　├Input.h  
｜　├Main.cpp  
｜　├Model.cpp  
｜　├Model.h  
｜　├RootObject.cpp  
｜　├RootObject.h  
｜　├SceneManager.cpp  
｜　├SceneManager.h  
｜　├SphereCollider.cpp  
｜　├SphereCollider.h  
｜　├Sprite.cpp  
｜　├Sprite.h  
｜　├Text.cpp  
｜　├Text.h  
｜　├Texture.cpp  
｜　├Texture.h  
｜　├Transform.cpp  
｜　├Transform.h  
｜　├VFX.cpp  
｜　└VFX.h   
├ Dodge.sln 
├ BackGround.cpp
├ BackGround.h
├ GaneOverScene.cpp
├ GameOverScene.h
├ Item.cpp
├ Item.h
├ Player.cpp 
├ Player.h 
├ PlayScene.cpp 
├ PlayScene.h 
├ Ready.cpp
├ Ready.h
├ ScoreUp.cpp
├ ScoreUp.h
├ Stage.cpp 
├ Stage.h 
├ StageLo.cpp 
├ StageLo.h 
├ StageLoMore.cpp
├ StageLoMore.h
├ StageUp.cpp 
├ StageUp.h 
├ TitleScene.cpp
├ TitleScene.h
├ ValueManager.cpp
├ ValueManager.h
├ WaitScene.cpp
└ WaitScene.h
