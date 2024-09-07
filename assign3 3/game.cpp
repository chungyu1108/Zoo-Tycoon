/******************************************************
** Program: game.cpp
** Author: chung yu yang
** Date: 2/14/2021
**Description:  class's data and methods
**Input: class animal and functions for running the program
** Output: the detail for the zoo tycoon game
******************************************************/
#include <iostream>
#include <cstdlib>

#include "animal.h"
#include "sealion.h"
#include "tiger.h"
#include "bear.h"
#include "game.h"

using namespace std;
/******************************************************
 * Function: Game
 * Description: Default constructor for class Game
 * Parameters: None
 * Pre-conditions: None
 * Post-conditions:  presets money to 100000, and sets month to 0.
 ******************************************************************/
Game::Game()
{
	month = 0;
	money = 100000;
	month_food_cost = 80;
	bankrupt = false;

	num_sealion = 0;
	total_sealion = new sealion[num_sealion];
	num_tiger = 0;
	total_tiger = new tiger[num_tiger];
	num_bear = 0;
	total_bear = new bear[num_bear];
}

// Function: ~Game
// Description: Default destructor for class animal
Game::~Game()
{
	//cout << "in game destructor!" << endl;	
	delete [] total_sealion;
	delete [] total_tiger;
	delete [] total_bear;
}

int & Game::get_month()
{
	return month;
}

float &Game::get_money()
{
	return money;
}

float Game::get_monthly_food_cost()
{
	return month_food_cost;
}

bool Game::get_bankrupt()
{
	return bankrupt;
}

void Game::set_bankrupt(bool x)
{
	if (x == false)
    {
		bankrupt = false;
	}
	if (x == true)
    {
		bankrupt = true;
	}
}

sealion & Game::get_specific_sealion(int x)
{
    return total_sealion[x];
}

void Game::add_sealion()
{
	sealion temp_array[num_sealion];
	for(int i = 0; i < num_sealion; i++)
    {
		temp_array[i] = total_sealion[i];
	}
	num_sealion = num_sealion + 1;
	delete [] total_sealion;//Deletes old array 

	total_sealion = new sealion[num_sealion];//Should create 2 

	for(int i = 0; i < num_sealion - 1; i++)
    {
		total_sealion[i].set_age(temp_array[i].get_age());
		total_sealion[i].set_cost(temp_array[i].get_cost());
		total_sealion[i].set_babies(temp_array[i].get_babies());
		total_sealion[i].set_food_cost(temp_array[i].get_food_cost());
		total_sealion[i].set_revenue(temp_array[i].get_revenue());
	}		
}

//Function: remove sealion
//Description: remove a sealion to the array
void Game::remove_sealion(int removed)
{
	sealion temp_array[num_sealion];
	for(int i = 0; i < removed; i++)
	{ 
		temp_array[i] = total_sealion[i];
	}
	for(int i = removed + 1; i < num_sealion; i++)
	{//transfered to temporary array 
		temp_array[i-1] = total_sealion[i];
	}
	num_sealion --; //Change array size
	delete [] total_sealion;//Deletes old array 
	total_sealion = new sealion[num_sealion];//Should create array size of 1 less
	cout << num_sealion << endl;

	for(int i = 0; i < num_sealion; i++){//For loop is to copy old one
		total_sealion[i].set_age(temp_array[i].get_age());
		total_sealion[i].set_babies(temp_array[i].get_babies());
		total_sealion[i].set_cost(temp_array[i].get_cost());
		total_sealion[i].set_food_cost(temp_array[i].get_food_cost());
		total_sealion[i].set_revenue(temp_array[i].get_revenue());
	}

}

void Game::display_sealion()
{
	for(int i = 0; i < num_sealion;i++)
	{
		cout << "sealion " << i + 1 << endl;
		cout << "Age: " <<(total_sealion[i]).get_age() << endl;
		cout << "Cost: " <<(total_sealion[i]).get_cost() << endl;
		cout << "Babies: " <<(total_sealion[i]).get_babies() << endl;
		cout << "Food Cost: " <<(total_sealion[i]).get_food_cost() << endl;
		cout << "Revenue: " <<(total_sealion[i]).get_revenue() << endl;
		cout << endl;
	}
	cout << endl;
}

int Game::get_num_sealion()
{
	return num_sealion;
}

tiger & Game::get_specific_tiger(int x)
{ 
	return total_tiger[x];	
}

void Game::add_tiger()
{
	tiger temp_array[num_tiger];
	for(int i = 0; i < num_tiger;i++)
	{
		temp_array[i] = total_tiger[i];
	}
	num_tiger++;
	delete [] total_tiger;//Deletes old array 
	total_tiger = new tiger[num_tiger];//Should create 

	for(int i = 0; i < num_tiger - 1; i++)
	{//For loop is to assign 
		total_tiger[i].set_age(temp_array[i].get_age());
		total_tiger[i].set_cost(temp_array[i].get_cost());
		total_tiger[i].set_babies(temp_array[i].get_babies());
		total_tiger[i].set_food_cost(temp_array[i].get_food_cost());
		total_tiger[i].set_revenue(temp_array[i].get_revenue());
	}		
}

void Game::remove_tiger(int removed)
{
	tiger temp_array[num_tiger];
	for(int i = 0; i < removed; i++)
	{ //All tiger up to removed temporary array
		temp_array[i] = total_tiger[i];
	}

	for(int i = removed + 1; i < num_tiger;i++)
	{ 
		temp_array[i - 1] = total_tiger[i];
	}
	num_tiger--; //Change array size

	delete [] total_tiger;//Deletes old array 
	total_tiger = new tiger [num_tiger];//Should create array
	cout << num_tiger << endl;

	for(int i = 0; i < num_tiger;i++)
	{//For loop is to copy old one
		total_tiger[i].set_age(temp_array[i].get_age());
		total_tiger[i].set_babies(temp_array[i].get_babies());
		total_tiger[i].set_cost(temp_array[i].get_cost());
		total_tiger[i].set_food_cost(temp_array[i].get_food_cost());
		total_tiger[i].set_revenue(temp_array[i].get_revenue());
	}
}

void Game::display_tiger()
{
	for(int i = 0; i < num_tiger; i++){
		cout << " tiger " << i + 1 <<endl;
		cout << " Age: " << (total_tiger[i]).get_age() << endl;
		cout << "Cost: " << (total_tiger[i]).get_cost() << endl;
		cout << "Babies: "<< (total_tiger[i]).get_babies() << endl;
		cout << "Food Cost: "<< (total_tiger[i]).get_food_cost() << endl;
		cout << "Revenue: "<< (total_tiger[i]).get_revenue() << endl;
		cout << endl;
	}
	cout << endl;
}

int Game::get_num_tiger()
{
	return num_tiger;
}

bear & Game::get_specific_bear(int x)
{ 
	return total_bear[x];
}

void Game::add_bear()
{
	bear temp_array[num_bear];
	for(int i = 0; i < num_bear; i++)
	{
		temp_array[i] = total_bear[i];
	}
	num_bear ++;
	delete [] total_bear;//Deletes old array 
	total_bear = new bear[num_bear];//Should create 2 

	for(int i = 0; i < num_bear - 1; i++)
	{//For loop is to assign 
		total_bear[i].set_age(temp_array[i].get_age());
		total_bear[i].set_cost(temp_array[i].get_cost());
		total_bear[i].set_babies(temp_array[i].get_babies());
		total_bear[i].set_food_cost(temp_array[i].get_food_cost());
		total_bear[i].set_revenue(temp_array[i].get_revenue());
	}		
}

void Game::remove_bear(int removed)
{
	bear temp_array[num_bear];
	for(int i = 0; i< removed;i++)
	{ 
		temp_array[i]=total_bear[i];
	}

	for(int i = removed+1; i < num_bear;i++)
	{//All bear after removed 
		temp_array[i-1] = total_bear[i];
	}
	num_bear--; //Change array size
	delete [] total_bear;
	total_bear = new bear [num_bear];//Should create array size of 1 less
	cout << num_bear << endl;

	for(int i = 0; i < num_bear;i++)
	{
		total_bear[i].set_age(temp_array[i].get_age());
		total_bear[i].set_babies(temp_array[i].get_babies());
		total_bear[i].set_cost(temp_array[i].get_cost());
		total_bear[i].set_food_cost(temp_array[i].get_food_cost());
		total_bear[i].set_revenue(temp_array[i].get_revenue());
	}
}

void Game::display_bear()
{
	for(int i = 0; i < num_bear;i++)
	{
		cout << "Bear " << i + 1 << endl;
		cout << "Age: " << (total_bear[i]).get_age() << endl;
		cout << "Cost: " << (total_bear[i]).get_cost() << endl;
		cout << "Babies: " << (total_bear[i]).get_babies() << endl;
		cout << "Food Cost: " << (total_bear[i]).get_food_cost() << endl;
		cout << "Revenue: " << (total_bear[i]).get_revenue() << endl;
		cout << endl;
	}
	cout << endl;
}

int Game::get_num_bear()
{
	return num_bear;
}

/*******************************************************************************
 * Function: subtract food cost 
 * Description: displays information about the cost of food per animal species and
 * removes cost from money
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: money-food cost
 ********************************************************************************/
void Game::subtract_food_cost()
{
	float base_percent;
	float sealion_cost;
	float tiger_cost;
	float bear_cost;

	srand(time(NULL));

	base_percent = (float)((rand() % 41) + 80) / (float)100; //Gives percentage for food cost 80 -120
	month_food_cost = month_food_cost * base_percent; 
	cout << "Base Food Cost: " << month_food_cost << endl;

	sealion_cost = ((month_food_cost * total_sealion[0].get_food_cost()) * num_sealion); 
	tiger_cost = ((month_food_cost * total_tiger[0].get_food_cost())*num_tiger); 
	bear_cost = ((month_food_cost * total_bear[0].get_food_cost())*num_bear);

	cout << "Overall Monkey Food Cost: "<< sealion_cost << endl;	
	cout << "Overall Sloth Food Cost: " << tiger_cost << endl;	
	cout << "Overall Sea Otter Food Cost: " <<	bear_cost << endl;
	cout << "Overall Food Cost: " << sealion_cost + tiger_cost + bear_cost << endl;

	money = money - (sealion_cost + tiger_cost + bear_cost); //Subtract from money 
}

/******************************************************************************
 * Function: recieve revenue 
 * Description: displays information about the revenue per animal species and
 * adds profit to money
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: money + revenue
 *****************************************************************************/
void Game::recieve_revenue(int bonus)
{
		int sealion_revenue;
		int tiger_revenue;
		int bear_revenue;
		int sealion_bonus;
		srand(time(NULL));

	if(bonus == 1)
	{
		sealion_revenue = ((total_sealion[0].get_revenue()) * num_sealion);  
		tiger_revenue = ((total_tiger[0].get_revenue()) * num_tiger); 
		bear_revenue = ((total_bear[0].get_revenue()) * num_bear);

		cout << " Monkey Revenue: "<< sealion_revenue << endl;	
		cout << " Sloth Revenue: " << tiger_revenue << endl;	
		cout << " Sea Otter Revenue: "<< bear_revenue << endl;
		cout << " Revenue: " << sealion_revenue + tiger_revenue + bear_revenue << endl;
		money = money + (sealion_revenue + tiger_revenue + bear_revenue);
	}
	else if(bonus == 2)
	{
		sealion_revenue = ((total_sealion[0].get_revenue()) * num_sealion);
		tiger_revenue = ((total_tiger[0].get_revenue()) * num_tiger); 
		bear_revenue = ((total_bear[0].get_revenue()) * num_bear);
		sealion_bonus = ((rand () % 250) + 150);

		cout << "Overall sealion Revenue: " << sealion_revenue << endl;
		cout << "Bonus sealion Revenue: " << sealion_bonus << endl;	
		//cout << "Overall tiger Revenue: " < tiger_revenue << endl;	
		cout << "Overall bear Revenue: "<< bear_revenue << endl;
		cout << "Overall Revenue: " << sealion_revenue + tiger_revenue + bear_revenue + sealion_bonus<<endl;
		money = money + (sealion_revenue + tiger_revenue + bear_revenue + sealion_bonus);
	}
}
/*************************************************************************************
 * Function: increase month
 * Description: the number of month is incremented along with the age of the animals
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: days +1, and age+1 for all animals
 *************************************************************************************/
void Game::increase_month()
{
	month ++;
	for(int i = 0; i < num_sealion; i++)
	{
		total_sealion[i].set_age(total_sealion[i].get_age () + 1);
	}
	for(int i = 0; i < num_tiger; i++)
	{
		total_tiger[i].set_age(total_tiger[i].get_age() + 1);
	}
	for(int i = 0; i < num_bear; i++)
	{
		total_bear[i].set_age(total_bear[i].get_age() + 1);
	}
}
