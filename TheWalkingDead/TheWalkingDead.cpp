#include <iostream>
#include <string>
#include <ctime>

enum class Weapon
{
	FISTS,
	GUN,
	SHOTGUN,
	REVOLVER,
	SNIPER,
	MACHINE_GUN,
	MAX
};

class Zombie;

class Player
{
	//Atributos
public:
	Weapon weapon;
	float precision;
	int life;
	std::string nameOfWeapon;

	//Constructor
	Player()
	{
		weapon = static_cast<Weapon>(rand() % static_cast<int>(Weapon::MAX));
		precision = (rand() & 10) / 10;
		life = rand() % 100;
	}

	//Métodos
	int DamageOfWeapon()
	{
		switch (weapon)
		{
		case Weapon::FISTS:
			return 0;
			break;
		case Weapon::GUN:
			return 1;
			break;
		case Weapon::SHOTGUN:
			return 2;
			break;
		case Weapon::REVOLVER:
			return 3;
			break;
		case Weapon::SNIPER:
			return 4;
			break;
		case Weapon::MACHINE_GUN:
			return 5;
			break;
		default:
			break;
		}
	}

	void NameOfWeapon()
	{
		switch (weapon)
		{
		case Weapon::FISTS:
			nameOfWeapon = "Fists";
			break;
		case Weapon::GUN:
			nameOfWeapon = "Gun";
			break;
		case Weapon::SHOTGUN:
			nameOfWeapon = "Shotgun";
			break;
		case Weapon::REVOLVER:
			nameOfWeapon = "Revolver";
			break;
		case Weapon::SNIPER:
			nameOfWeapon = "Sniper";
			break;
		case Weapon::MACHINE_GUN:
			nameOfWeapon = "Machine Gun";
			break;
		default:
			break;
		}
	}

	//Métodos
	void attack(Zombie &a);
	bool isAlive();
};

class Zombie
{
public:
	//Atributos
	int distanceToPlayer;
	float speed;
	float damage;
	int life;

	//Constructor
	Zombie()
	{
		distanceToPlayer = (rand() & 180) + 20;
		speed = ((rand() % 10) / 10) + rand() % 20;
		damage = ((rand() % 10) / 10) + rand() % 20;
		life = rand() % 100;
	}

	// Métodos
	void attack(Player &a);
	bool isAlive();
};

void Player::attack(Zombie &a)
{
	a.life -= static_cast<int>(static_cast<int>(weapon) * precision);
}

bool Zombie::isAlive()
{
	return life > 0;
}


void Zombie::attack(Player &a)
{
	if (distanceToPlayer <= 0)
	{
		a.life -= damage;
	}
	else
	{
		distanceToPlayer--;
	}
}


void main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	const int NumZombies = 10;

	Player player;
	Zombie zombies[NumZombies];
	bool zombiesAreAlive;

	do {
		zombiesAreAlive = false;
		for (int i = 0; i < NumZombies; i++)
		{
			std::cout << "Player:\n " << "	" << "Life: " << player.life << ", " << "weapon: " << player.nameOfWeapon << ", " << "Precision: " << player.precision << "\n";
			std::cout << "Zombie[ " << i << "]\n" << "	" << "Life: " << zombies[i].life << ", " << "DistanceToPlayer: " << zombies[i].distanceToPlayer << ", " << "Speed: " << zombies[i].speed << ", " << "damage: " << zombies[i].damage << "\n";

			if (zombies[i].isAlive())
			{
				player.attack(zombies[i]);
				zombies[i].attack(player);
				zombiesAreAlive = true;
			}
		}
	} while (player.life > 0 && zombiesAreAlive == true);

	if (zombiesAreAlive)
	{
		std::cout << "GAME OVER";
	}
	else
	{
		std::cout << "Player killed zombies!";
	}


}