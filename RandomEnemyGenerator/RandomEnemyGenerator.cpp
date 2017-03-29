#include <iostream>
#include <ctime>
#include <string>

enum class EnemyType
{
	zombie,
	vampire,
	ghost,
	witch,
	MAX
};



struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
};

static Enemy CreateRandomEnemy()
{
	int MaxLife = 500;
	std::string names[4] = { "Nieves" "Meri", "Oscar", "Angel" };

	return Enemy
	{
		static_cast<EnemyType>(rand() % static_cast<int>(EnemyType::MAX)),
		names[rand() % (sizeof names / sizeof std::string)],
		rand() % MaxLife
	};
}

bool operator ==(Enemy &a, Enemy &b)
{
	return a.name == b.name && a.type == b.type;
}

void main()
{
	const int MaxEnemies{ 5 };
	Enemy enemigos[MaxEnemies];

	for (int i = 0; i < MaxEnemies; i++)
	{
		enemigos[i] = CreateRandomEnemy();
		if (i >= 1)
		{
			if (enemigos[i] == enemigos[i - 1])
			{
				--i;
				break;
			 }
		}
		std::cout << enemigos[i].name << " " << " " << enemigos[i].health;
	}

	
}

