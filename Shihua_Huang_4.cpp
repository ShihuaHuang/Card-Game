#include <iostream>
#include <chrono>
#include "Shihua_Huang_4.h"

using namespace std;
/*
int main(int argc, char * const argv[])
{
	int total_number_of_cards;
	deck x;
	//cin >> total_number_of_cards;
    sscanf(argv[1], "%d", &total_number_of_cards);
	cout << "Total Number of Cards = " << total_number_of_cards << endl;
	x.calc_value(total_number_of_cards / 2, total_number_of_cards / 2);
	cout << "Value of the game = " << x.value(total_number_of_cards / 2, total_number_of_cards / 2) << endl;
	return 0;
}
*/

// I dropped the above lines and change them into following in order to add time for my calculation
int main(int argc, char * const argv[])
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	std::chrono::duration<double> elapsed_time;

	start = std::chrono::system_clock::now();//start calculating the time

	int total_number_of_cards;
	deck x;
	//cin >> total_number_of_cards;
	sscanf_s(argv[1], "%d", &total_number_of_cards);//input total number of cards
	cout << "Total Number of Cards = " << total_number_of_cards << endl;//output what just typed of the total number of cards
	x.calc_value(total_number_of_cards / 2, total_number_of_cards / 2);//set r=1/2*total number of cards and b=1/2*total number of cards
	cout << "Value of the game = " << x.value(total_number_of_cards / 2, total_number_of_cards / 2) << endl;//output the expected value of the game I played
	
	end = std::chrono::system_clock::now();//stop calculating the time
	elapsed_time = end - start;//calculate the time used
	cout << "Elapsed time to find the value of the game: " << elapsed_time.count() << "s\n" << endl;//output the time
	return 0;
}

