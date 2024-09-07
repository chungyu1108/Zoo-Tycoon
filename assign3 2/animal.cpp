/******************************************************
** Program: animal.cpp
** Author: chung yu yang
** Date: 2/14/2021
**Description: Animal class's data and methods
**Input: class animal
** Output: animal data
******************************************************/
#include <iostream>
#include "animal.h"

using namespace std;

Animal::Animal()
{
	/*Animal( const Animal & new_animal)
    {
	    age = new_animal.age;
	    cost = new_animal.cost;
	    babies = new_animal.babies;
	    food_cost = new_animal.food_cost;
	    revenue = new_animal.revenue;
	}*/
}

/*Function: get age
 * Description: returns age of animal*/
int Animal::get_age()
{
	return age;
}

/*Function: get cost
 * Description: returns cost of animal*/
int Animal::get_cost()
{
	return cost;
}
/*Function: get babies
 * Description: returns babies of animal*/
int Animal::get_babies()
{
	return babies;
}	

/*Function: get food cost
 * Description: returns good cost of animal(x, 3x, 5x)*/
float Animal::get_food_cost()
{
	return food_cost;
}

/*Function: get revenue
 * Description: returns revenue of animal*/
int Animal::get_revenue()
{
	return revenue;
}

/*Function: set age
 * Description: preset the age of an animal*/
void Animal::set_age(int x)
{
	age = x;
}	

/*Function: set cost
 * Description: preset the cost of an animal*/
void Animal::set_cost(int x)
{
	cost = x;
}
/*Function: set babies
 * Description: preset the babies of an animal*/
void Animal::set_babies(int x)
{
	babies = x;
}

/*Function: set food cost
 * Description: preset the food cost of an animal*/
void Animal::set_food_cost(float x)
{
	food_cost = x;
}
/*Function: set revenue
 * Description: preset the revnue of an animal*/
void Animal::set_revenue(int x)
{
	revenue = x;
}

/*Function: set babies
 * Description: preset the babies of an animal*/
void Animal::add_babies(int x)
{
	babies = babies + x;
}