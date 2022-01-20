#include "Player.h"

Player::Player()
{
	score = 0;
}

//add amount to score
void Player::addToScore(float amount)
{
	score += amount;
}

void Player::subtractFromScore(float amount)
{
	score -= amount;
}

//Get the score of the player
float Player::getScore()
{
	return score;
}
