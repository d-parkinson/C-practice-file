/************************************************************************************************************
								Created 4/04/2016 by Darren Parkinson
				This is a two player simulation fight game between two characters:
										a Villian and a Hero
							Each Character has four features respectively:
					Name(string), health(integer), kick(integer), punch(integer)
*************************************************************************************************************/
#include <iostream>
#include <string>
//Superclass holding details of regarding the features of the characters
class Character{
public:
	std::string name;
	static int health;
	int kick;
	int punch;
	Character(std::string name, int health, int kick, int punch){
		this -> health = health;
		this -> name = name;
		this -> kick = kick;
		this -> punch = punch;
	}
	~Character(){}
};
//Subclass displaying features of heroes
class Hero : public Character{
public:
	Hero(std::string name, int health, int kick, int punch) : Character(name, health, kick, punch){
		std::cout << name << ": Joker giving trouble again" << std::endl;
	}
	~Hero(){}
};
//Subclass displaying features of villians
class Villian : public Character{
public:
	Villian(std::string name, int health, int kick, int punch) : Character(name, health, kick, punch){
		std::cout << name << ": Hey there hehehe" << std::endl;
	}
	~Villian(){}
};
//Function of Villian inflicting damage on Hero with a punch
void VillianPunch(Hero *hero, Villian *villian){
	hero -> health -= villian -> punch;
	std::cout << villian -> name << ": take this(punch)" << std::endl;
}
void VillianKick(Hero *hero, Villian *villian){
	hero -> health -= villian -> kick;
	std::cout << villian -> name << ": take this(kick)" << std::endl;
}
void HeroPunch(Hero *hero, Villian *villian){
	villian -> health -= hero -> punch;
	std::cout << hero -> name << ": take this(punch)" << std::endl;
}
void HeroKick(Hero *hero, Villian *villian){
	villian -> health -= hero -> kick;
	std::cout << hero -> name << ": take this(kick)" << std::endl;
}int main(void){
	Hero *batman;
	Villian *joker;
	joker = new Villian("Joker",1000,90,63);
	batman = new Hero("Batman",1100,93,60);
	std::cout << "Fight!!!" << std::endl;
	do{
		HeroPunch(batman, joker);
		VillianPunch(batman, joker);
		VillianKick(batman, joker);
		HeroKick(batman, joker);
		if(batman -> health == 0)
			std::cout << joker -> name << ": You won't catch me today hehehe" << std::endl;
		else if(joker -> health == 0)
			std::cout << batman -> health << ": How many times do I have to defeat you" << std::endl;
	}while(!(batman -> health == 0) | !(joker -> health == 0));
	delete joker;
	delete batman;
	return 0;
}
