#include "Score.h"

Score::Score(int score,char* detail, Label label) :ID(Score::ID_generator) {
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;

}
Score::Score(int score, const char* detail, Label label) : ID(ID_generator)
{
	this->score = score;
	this->label = label;
	this->detail = detail;

	ID_generator++;
}
Score::Score() : ID(-1)
{
	this->score = 0;
	this->label = BAD;
	this->detail = "";
}
void Score::setID_generator(int input)
{
	if (ID_generator < input)
		ID_generator += input - ID_generator;
	else
		ID_generator -= ID_generator - input;
}
Score Score::operator =(const Score s)
{
	this->score = s.score;
	this->detail = s.detail;
	this->label = s.label;
	return *this;
}
void print(const Score& score)
{
	cout << score.score << " ";
}
int Score::ID_generator = 0;

