#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<random>
#include<math.h>

using namespace std;

class Warrior {
private:

	int atkMax;
	int blockMax;



public:
	string name;
	int health;
	int Attack() {
		return rand() % this->atkMax;
	};

	int Block() {
		return rand() % this->blockMax;
	};

	Warrior();
	Warrior(string, int, int, int);
	//~Warrior();

};

/*Warrior::Warrior() {
	this->name = "";
	this->health = 0;
	this->atkMax = 0;
	this->blockMax = 0;
}*/

Warrior::Warrior(string name, int health, int atkMax, int blockMax) {
	this->name = name;
	this->health = health;
	this->atkMax = atkMax;
	this->blockMax = blockMax;
}



class Battle {
public:
	static void startFight(Warrior& warrior1, Warrior& warrior2) {
		while (true) {
			if (Battle::getAttackResult(warrior1, warrior2).compare("Game Over") == 0) {
				cout << "Game Over" << endl;
				break;
			}

			if (Battle::getAttackResult(warrior2, warrior1).compare("Game Over") == 0) {
				cout << "Game Over" << endl;
				break;
			}
		}

	}


	static string getAttackResult(Warrior& warriorA, Warrior& warriorB) {
		int warriorAAtkAmnt = warriorA.Attack();
		int warriorBBlockAmnt = warriorB.Block();
		int damage2warriorB = ceil(warriorAAtkAmnt - warriorBBlockAmnt);
		damage2warriorB = (damage2warriorB <= 0) ? 0 : damage2warriorB;
		warriorB.health = warriorB.health - damage2warriorB;
		//warriorB.setHealth(warriorBHealth);

		printf("%s attacks %s  and deals %d damage \n", warriorA.name.c_str(), warriorB.name.c_str(), damage2warriorB);

		printf("%s is down to %d health \n", warriorB.name.c_str(), warriorB.health);

		if (warriorB.health <= 0) {
			printf("%s has died and  %s is victorius \n", warriorB.name.c_str(), warriorA.name.c_str());
			return "Game Over";
		}
		else {
			return "Fight Again";
		}
	}
};

int main() {

	srand(time(NULL));

	Warrior thor("thor", 100, 30, 15);
	Warrior hulk("hulk", 135, 25, 10);

	Battle::startFight(thor, hulk);

	return 0;

}

//new comment added sssss 
//new changes made