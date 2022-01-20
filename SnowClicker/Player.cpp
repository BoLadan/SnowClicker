#include "Player.h"

Player::Player()
{
	score = 0;
}

//add amount to score
void Player::addToScore(float amount)
{
	/*std::cout << this << std::endl;
	std::cout << "score from before adding:" << score << std::endl;*/
	score += amount;
	/*std::cout << "score from after adding:" << score << std::endl;*/
}

void Player::subtractFromScore(float amount)
{
	//std::cout << this << std::endl;
	//std::cout << "score from before subtraction:" << score << std::endl;
	score -= amount;
	//std::cout << "score from after subtraction:" << score << std::endl;
}

//Get the score of the player
float Player::getScore()
{
	return score;
}
