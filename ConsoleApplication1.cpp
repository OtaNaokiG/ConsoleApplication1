#include <iostream>
using namespace std;

struct DynamicObject
{
	char name[20];
	float currentPlaceX, currentPlaceY;
	float pictureId;
};

struct MainCharacter
{
	DynamicObject dynamicObject;
	int Lv;
	float Hp;
	float Mp;
	float Power;
};

struct NPC {
	DynamicObject dynamicObject;
	float conversationId;
};

struct Player {
	MainCharacter mainCharacter;
	int job;
};

struct Enemy {
	MainCharacter mainCharacter;
	bool dropChest;
	bool boosFlag;
};
void Show(const Player* pointer) {
	// (*pointer).name << endl;って書いても
	//「Player構造体に直接nameというメンバーがある」と仮定していますが、実際には 
	//name は Player.mainCharacter.dynamicObject.name に存在します。
		//正しい書き方は下の方
	cout << "名前 : " << pointer->mainCharacter.dynamicObject.name << endl			//DynamicObject
		<< "X座標 : " << pointer->mainCharacter.dynamicObject.currentPlaceX << endl//DynamicObject
		<< "Y座標 : " << pointer->mainCharacter.dynamicObject.currentPlaceY << endl//DynamicObject
		<< "PictureId : " << pointer->mainCharacter.dynamicObject.pictureId << endl//DynamicObject
		<< "Lv : " << pointer->mainCharacter.Lv << endl
		<< "Hp : " << pointer->mainCharacter.Hp << endl
		<< "Mp :" << pointer->mainCharacter.Mp << endl
		<< "Power : " << pointer->mainCharacter.Power << endl
		<< "jobNum : " << pointer->job << endl;
}
int main() {
	Player  firstPlayer[] = {
		{
			{
				{"ああああ",0,0,1234},//DynamicObject
				99,					  //Lv
				9999,				  //Hp
				5000,				  //Mp
				5000				  //Power
		},
		4321						  //job
	}
	};
	int size = sizeof firstPlayer / sizeof * firstPlayer;
	for (int i = 0; i < size; ++i) {
		Show(&firstPlayer[i]);
	}

	Enemy slime[] = {
		{{"スライム",1,1,1235},//DynamicObject
		 1,					   //Lv
		 5,						//Hp

}