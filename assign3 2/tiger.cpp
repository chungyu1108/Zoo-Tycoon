/******************************************************
** Program: tiger.cpp
** Author: chung yu yang
** Date: 2/14/2021
**Description: tiger class's data and methods
**Input: class tiger
** Output: tiger data
******************************************************/
#include <iostream>
#include "animal.h"
#include "tiger.h"

using namespace std;

tiger::tiger()
{
    set_age(48);
	set_cost(15000);
	set_babies(0);
	set_food_cost(5);
	set_revenue(1500);
}