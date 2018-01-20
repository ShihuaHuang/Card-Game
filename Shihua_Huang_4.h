/*
*  card_game.h
*  Card Game

*/

#ifndef	CARDGAME_H
#define CARDGAME_H
#include <algorithm>

class deck
{
	double **mem;
public:
	void calc_value(double r, double b)
	{
		mem = new double*[r + 1];//create a array of r+1 terms for red cards
		for (int i = 0; i <= r; i++)
		{
			mem[i] = new double[b + 1];//create a array of b+1 terms for black cards and form this with r+1 red cards to have a matrix
			for (int j = 0; j <= b; j++)
				mem[i][j] = -1;//value of the (r+1)*(b+1) matrix is set to -1
		}
	}
	
	double value(int r, int b)
  {
		if (0 == r)
			return ((double)b);//set bound that when red cards left are zero, 
		                       //the already owned money is b-r which equals to b since we have drawn all red cards and no blacks cards
		if (0 == b)
			return (0);//set bound that when black cards left are zero,
		               //the already owned money is zero since we have drawn all black cards and no red cards
		
		//I dropped the following lines and change them into the above in order to accelerate the calculation

		/*for (int j = 0; j <= b; j++)
			mem[0][j] = j;
		for (int i = 0; i <= r; i++)
			mem[i][0] = 0;*/

		if (mem[r][b] != -1)
			return mem[r][b];//using memoization to store the calculated value in order to call them in future calculation
		else
		{
			double term1 = ((double)r / (r + b)) * value(r - 1, b);//calculate the expected value of red cards left
			double term2 = ((double)b / (r + b)) * value(r, b - 1);//calculate the expected value of black cards left
			mem[r][b] = std::max((term1 + term2), (double)(b - r));//compare the expected value of continuing to play vs 
			                                                       //the amount of value already owned.(b-r)=(N/2-b)-(N/2-r)
			return mem[r][b];
		}
  }
};


#endif