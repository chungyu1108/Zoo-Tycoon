/*****************************************************************************************
 ** Program Filename: Zoo_tycoon
 **  Author: chung-yu yang
 **  Date: 2/14/2021
 **  Description: This program runs the game of zoo tycoon where a player starts 
 ** with 100000 and is able to by animals to make a profit.
 ** Input:User input for choices
 ** Output:Revenue of th zoo
 ***************************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>

#include "animal.h"
#include "sealion.h"
#include "tiger.h"
#include "bear.h"
#include "game.h"

using namespace std;

void sick_animal(Game&);
void babies(Game&);

int main()
{
    Game game;
	int animal_type; 
	int buy_num_animals;
	int special_event;
	int option;
	int again;
    srand(time(NULL));

    cout << "Welcome to the zoo tycoon!" << endl;

    while(game.get_bankrupt()==false){

		//Buy animal
		cout << "Month: "<< game.get_month() << endl;
		cout << "Money: "<< game.get_money()<<endl;
		cout << endl;
		cout << " Would you like to buy an animal? " << endl;
		cout << " type 1 for -> Sealion, 2 for -> Tiger, 3 for -> Black Bear " << endl;
		cin >> animal_type;
		cout << " How Many? (0-2) " << endl;
		cin >> buy_num_animals;

		for(int i = 0; i < buy_num_animals; i++)
        {
			if(animal_type == 1)
            {
				game.add_sealion();
				game.get_money() = game.get_money() - (game.get_specific_sealion(0)).get_cost();

			}
			if(animal_type == 2)
            {
				game.add_tiger();
				game.get_money()= game.get_money() - (game.get_specific_tiger(0)).get_cost(); 
			}
			if(animal_type == 3)
            {
				game.add_bear();
				game.get_money()= game.get_money() - (game.get_specific_bear(0)).get_cost();
			}
		}		
		cout << "Money after buying animals: " << game.get_money() << endl;
		cout << endl;
		cout << endl;

        //Display Animals
		cout << "Number of sealion: "<< game.get_num_sealion() << endl;
		game.display_sealion();
		cout<< "Number of Tiger: "<< game.get_num_tiger() << endl;
		game.display_tiger();
		cout<< "Number of Black Bear "<< game.get_num_bear() << endl;
		game.display_bear();

		cout<<endl;

        //Special Event
		cout<< "Type 1 to proceed to special event(random)" << endl;
		cin >> option;

		special_event=(rand() % 4) + 1;
		if (special_event==1)
        {
			sick_animal(game);
		}

		else if (special_event==2)
        {
			babies(game);
		}

		   else if (special_event==3)
           {
		        cout << "Boom in Zoo Attendance" << endl;
                cout << "Each monkey generates an extra bonus revenue of 150 - 400 dollars" << endl;
		   }
		   else if (special_event==4)
           {
		        cout << "No special event has occured" <<endl;
		   }

           //Calculate Food Cost
		cout<<endl;
		cout<<"Press 1 to proceed to subtract food cost"<<endl;
		cin.ignore();
		cin >> option;
		game.subtract_food_cost();
		cout<<"Money after food cost: "<<game.get_money()<<endl;
		cout<<endl;


		//Calculate Revenue
	
		cout << "Type 1 to proceed to recieve revenue" << endl;
		cin.ignore();
		cin >> option;
		if (special_event == 3)
        { 
		    game.recieve_revenue(2);
		}
		else if (special_event!=3)
        {
		    game.recieve_revenue(1);
		}
		cout << "Money after recieving revenue: " << game.get_money() << endl;
		cout<<endl;

        //Increment day and ask user to stop
		cout << "Type 1 to continue to next month, or press 0 to quit" << endl;
		cin.ignore();
		cin >> again;

		if(again==0)
        {
			cout<<"Thanks for playing"<<endl;
			game.set_bankrupt(true);
		}
		if(game.get_money() < 0)
        {
			cout<< "You went Bankrupt!" << endl;
			game.set_bankrupt(true);
		}
		game.increase_month();
		cout << endl;
	}

}

/*************************************************************************************
 * Function: sick animal
 * Description: Chooses an animal to make sick and lets user decide whether to save the animal or let it die
 * Parameters: Game
 * Pre-conditions: Game used for playing
 * Post-conditions: Dead animal or lost money to save it
 ***************************************************************************************/
void sick_animal(Game& game)
{
	int animal_type;
	int specific_animal;
	int pay_fee;
	int sick_cost;

	animal_type = (rand() % 3) + 1;
	if(animal_type == 1 &&game.get_num_sealion()>0)
    {
		cout<< "A sealion has become sick" << endl;
		cout<< "Press 1 to heal animal (Pay half of original) or press 2 to let it die" << endl;
		cin >> pay_fee;
		if (pay_fee ==1)
        {
			game.get_money()=game.get_money()- 400;
			cout<< "Money after sick animals: "<< game.get_money() << endl;
		}
		else if(pay_fee=2)
        {
			cout<< "The animal died" << endl;
			specific_animal = (rand()% game.get_num_sealion());
			game.remove_sealion(specific_animal);
		}	
	}
	else if (animal_type==2 &&game.get_num_tiger()>0)
    {
		cout<< "A tiger has become sick" << endl;
		cout<< "Press 1 to heal animal (Pay half of original) or press 2 to let it die"<<endl;
		cin >> pay_fee;
		if (pay_fee==1)
        {
			game.get_money()=game.get_money()- 7500;
			cout<<"Money after sick animals: "<< game.get_money()<<endl;
		}
		else if(pay_fee=2)
        {
			cout << "The animal died"<<endl;
			specific_animal = (rand() % game.get_num_tiger());
			game.remove_tiger(specific_animal);

		}	
	}
	else if (animal_type == 3 && game.get_num_bear() > 0)
    {
		cout << "A black bear has become sick" << endl;
		cout << "Press 1 to heal animal (Pay half of original) or press 2 to let it die"<<endl;
		cin >> pay_fee;
		if (pay_fee == 1)
        {
			game.get_money()=game.get_money() -3000;
			cout<<"Money after sick animals: "<< game.get_money() << endl;
		}
		else if(pay_fee=2)
        {
			cout<< "The animal died"<<endl;
			specific_animal = (rand() % game.get_num_bear());
			game.remove_bear(specific_animal);

		}	
	}
	else{
		cout<<"No special event has occured"<<endl;	
	}
}

/*************************************************************************
 * Function: babies
 * Description: Chooses an adult animal to choose to give birth
 * Parameters: Game
 * Pre-conditions: Game used for playing
 * Post-conditions: Add animal to array 
 ************************************************************************/
void babies(Game& game)
{
	int animal_type;
	animal_type = (rand() % 3) + 1;
	int specific_animal;
	if (animal_type ==1 && game.get_num_sealion()> 0)
    {   
		specific_animal = (rand() % game.get_num_sealion());
		if( (game.get_specific_sealion((specific_animal)).get_age()) >= 48)
        {
			cout<< "A sealion had a baby!" << endl;
			cout << endl;		
			game.get_specific_sealion((specific_animal)).add_babies(1);
			game.add_sealion();
			game.get_specific_sealion((game.get_num_sealion()) - 1).set_age(0);

		}
		else
        {
			cout<<"No special event has occured"<< endl;
		}	

	}	
	else if (animal_type== 2 && game.get_num_tiger() > 0)
    {
		specific_animal = (rand() % game.get_num_tiger());
		if((game.get_specific_tiger((specific_animal)).get_age()) >= 48)
        {
			cout<<"A tiger had babie!"<<endl;
			cout<<endl;	
			for(int i = 0; i < 3; i++)
            {
				game.get_specific_tiger((specific_animal)).add_babies(1);
				game.add_tiger();
				game.get_specific_tiger((game.get_num_tiger())-1).set_age(0);
			}
		}
		else
        {
			cout<<"No special event has occured"<< endl;
		}	
	}	
	else if (animal_type == 3 && game.get_num_bear() > 0)
    {
		specific_animal = (rand() % game.get_num_bear());
		if( (game.get_specific_bear((specific_animal)).get_age()) >= 48)
        {
			cout<<"A bear had babies!"<<endl;	
			cout<<endl;	
			for(int i = 0; i < 2; i++){
				game.get_specific_bear((specific_animal)).add_babies(1);
				game.add_bear();
				game.get_specific_bear((game.get_num_bear()) - 1).set_age(0);
			}
		}
		else{
			cout<<"No special event has occured"<< endl;
		}	
	}
	else{
		cout<<"No special event has occured"<< endl;
	}	
}



