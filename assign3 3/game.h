/******************************************************
** Program: game.h
** Author: chung yu yang
** Date: 2/14/2021
**Description: game class's data and methods
**Input: class game
** Output: game data
******************************************************/
#ifndef GAME_H
#define GAME_H

using namespace std;

class Game{
	private:
		int month;
		float money;
		float month_food_cost;
		bool bankrupt;

		sealion * total_sealion;
		tiger * total_tiger;
		bear * total_bear;
		int num_sealion;
		int num_tiger;
		int num_bear;

	public:
		Game();
		~Game();

		int &get_month();
		float &get_money();
		float get_monthly_food_cost();
		bool get_bankrupt();
		void set_bankrupt(bool x);

		//sealion functions
		sealion &get_specific_sealion(int x);
		void add_sealion();
		void remove_sealion(int removed);
		void display_sealion();
		int get_num_sealion();

		//tiger functions
		tiger &get_specific_tiger(int x);
		void add_tiger();
		void remove_tiger(int removed);
		void display_tiger();
		int get_num_tiger();

		//bear Functions
		bear &get_specific_bear(int x);
		void add_bear();
		void remove_bear(int removed);
		void display_bear();
		int get_num_bear();

		//Game functions
		void recieve_revenue(int bonus);
		void subtract_food_cost();
		void increase_month();

};
#endif
