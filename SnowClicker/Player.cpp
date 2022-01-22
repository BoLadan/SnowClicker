#include "Player.h"

Player::Player()
{
	score = 0;
}

//Add amount to score
void Player::addToScore(float amount)
{
	score += amount;
}

//Subtract form the player's score. This function is calles whenever yhe player purchases something.
void Player::subtractFromScore(float amount)
{
	score -= amount;
}

//Get the score of the player
float Player::getScore()
{
	return score;
}

