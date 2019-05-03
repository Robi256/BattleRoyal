#include <iostream>
#include <string>

class Player
{

public:
	Player(int positionX, int positionY, int currentVelocity, int hitPoints)
	{
		x = positionX;
		y = positionY;
		velocity = currentVelocity;
		hp = hitPoints;
	}

	int x, y, velocity, hp, strength;
	std::string userName;

	void move()
	{
		x += velocity;
		y += velocity;
	}

	void damage(int ammount)
	{
		hp -= ammount;
	}
};


void move(int& x, int& y, int& velocity)
{
	x += velocity;
	y += velocity;
}

int main()
{
	std::string userName1, userName2, userName3;
	std::cout << "Welcome to the BattleRoyale!\n\nPlayer one, please enter your username: ";
	std::cin >> userName1;

	std::cout << "Second player, please enter your username: ";
	std::cin >> userName2;

	std::cout << "End finally, third player, enter your username: ";
	std::cin >> userName3;


	Player playerOne = Player(0, 0, 10, 30);
	playerOne.userName = userName1;
	playerOne.strength = 10;


	Player playerTwo = Player(10, 15, 10, 30);
	playerTwo.userName = userName2;
	playerTwo.strength = 15;

	Player playerThree = Player(10, 15, 10, 30);
	playerThree.userName = userName3;
	playerThree.strength = 20;

	playerOne.move();
	playerTwo.move();
	playerThree.move();


	std::string losingPlayer;
	std::string winningPlayer;
	std::string winningPlayer2;

	while (playerOne.hp > 0 && playerTwo.hp > 0 && playerThree.hp > 0)
	{
		int startsFirst;
		std::cout << std::endl;
		std::cout << "Which player is on the move? Pick a number!\n 1. " << userName1 << "\n 2. " << userName2 << "\n 3. " << userName3 << "? " << std::endl;
		std::cin >> startsFirst;
		std::cout << std::endl;

		std::cin.ignore(1000, '\n');
		std::cin.clear();

		int check;
		std::cout << "Choose which player you want to hit: ";
		std::cin >> check;
		std::cout << std::endl;

		std::cin.ignore(1000, '\n');
		std::cin.clear();

		if (startsFirst == 1)
		{
			switch (check)
			{
			case 2:
				playerTwo.damage(playerOne.strength);
				std::cout << "Player two lost " << playerOne.strength << " hitpoints" << std::endl;
				break;
			case 3:
				playerThree.damage(playerOne.strength);
				std::cout << "Player three lost " << playerOne.strength << " hitpoints" << std::endl;
				break;
			default:
				break;
			}
		}
		else if (startsFirst == 2)
		{
			switch (check)
			{
			case 1:
				playerOne.damage(playerTwo.strength);
				std::cout << "Player two lost " << playerTwo.strength << " hitpoints" << std::endl;
				break;
			case 3:
				playerThree.damage(playerTwo.strength);
				std::cout << "Player three lost " << playerTwo.strength << " hitpoints" << std::endl;
				break;
			default:
				break;
			}
		}
		else if (startsFirst == 3)
		{
			switch (check)
			{
			case 1:
				playerOne.damage(playerThree.strength);
				std::cout << "Player two lost " << playerThree.strength << " hitpoints" << std::endl;
				break;
			case 2:
				playerTwo.damage(playerThree.strength);
				std::cout << "Player three lost " << playerThree.strength << " hitpoints" << std::endl;
				break;
			default:
				break;
			}
		}


		std::cout << "Player one hitpoints: " << playerOne.hp << std::endl;
		std::cout << "Player two hitpoints: " << playerTwo.hp << std::endl;
		std::cout << "Player three hitpoints: " << playerThree.hp << std::endl;



		std::cout << std::endl;

		if (playerOne.hp <= 0)
		{
			losingPlayer = playerOne.userName;
			winningPlayer = playerTwo.userName;
			winningPlayer2 = playerThree.userName;
		}
		else if (playerTwo.hp <= 0)
		{
			losingPlayer = playerTwo.userName;
			winningPlayer = playerOne.userName;
			winningPlayer2 = playerThree.userName;
		}
		else if (playerThree.hp <= 0)
		{
			losingPlayer = playerThree.userName;
			winningPlayer = playerOne.userName;
			winningPlayer2 = playerTwo.userName;
		}
	}

	std::cout << winningPlayer << " and " << winningPlayer2 << " continues to the next round! Congratulations!" << std::endl;
	std::cout << losingPlayer << " is going home! Better luck next time!" << std::endl;

	// Napraviti treceg playera, te postaviti mogucnost za biranje usernamea (korisnik sam unosi 
	// username).
	// Prosiriti mogucnost damageanja playera tako da se bira koji ce kojeg udariti.

	std::cin.get();
}