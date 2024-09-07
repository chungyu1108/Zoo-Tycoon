/******************************************************
** Program: bear.cpp
** Author: chung yu yang
** Date: 2/14/2021
**Description: bear class's data and methods
**Input: class bear
** Output: bear data
******************************************************/
#include <iostream>
#include "animal.h"
#include "bear.h"

using namespace std;

bear::bear()
{
    set_age(48);
	set_cost(6000);
	set_babies(0);
	set_food_cost(3);
	set_revenue(600);
}