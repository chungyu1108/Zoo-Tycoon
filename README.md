# Problem Statement
For this assignment, you will implement a small game where the player acts as the owner of the city's zoo, which has exhibits of sea lions, tigers, and black bears. As the owner, it's the player's job both to ensure the welfare of the animals and to generate as much profit as possible. They accomplish these goals by investing in animals, feeding them, caring for them when they are sick, and raising their babies when they are born.

# Each species of animal has these specific traits:

Age
For all species, an animal is a baby if it is less than 6 months old.
For all species, an animal is an adult if it is at least 4 years old.
Note: For our purposes the age range between 6 months and 4 years can be considered as adolescence. The animal is no longer a baby but is not yet capable of reproducing.
Cost
Sea Lions cost $800 each.
Tigers cost $15,000 each.
Black Bears cost $6,000 each.
Babies
Sea Lions have 1 baby at a time.
Tigers have 3 babies at a time.
Black Bears have 2 babies at a time.
Food cost
The base daily food cost varies on a month-to-month basis (see below).
Tigers have a monthly food cost of 5 times the base food cost.
Black Bears have a monthly food cost of 3 times the base food cost.
Sea Lions have a monthly food cost equal to the base food cost.
Revenue
Each animal generates monthly revenue equal to a percentage of the initial cost of one of its species.
All animals except sea lions generate 10% of the cost of one of their species (i.e. each tiger generates $1500 each month, and each black bear generates $600 each month).
Each sea lion generates 20% of the cost of a sea lion (i.e. each sea lion generates $120 each month).
On certain months, when attendance is high, each sea lion generates some amount of bonus revenue. See below for details.
# Game Flow
The game starts with the owner having no animals and $100,000 in the bank, and it proceeds one month at a time. You can think of each month as a turn for the player. During a single month, several things happen. 

The age of each animal currently in the zoo increases by 1 month (note that you can track time in days or weeks if you prefer).

A special event occurs. The special event is chosen at random from among the following options:

One randomly chosen animal gets sick. In order to care for the sick animal, the owner must pay an amount equal to half the initial cost of an animal of the same species as the sick animal (e.g. a sick tiger costs half of $15,000, i.e. $7,500). If the owner has enough money to cover this cost, it is subtracted from their bank account. If they do not have enough money, then the sick animal dies and is removed from the zoo.
A randomly chosen adult animal gives birth to the appropriate number of babies for its species (a non-adult can't have babies). Each baby starts with age 0 and is added into the zoo.
A boom in zoo attendance occurs. Each time this happens, each sea lion generates a random amount of extra bonus revenue between $150 and $400.
No special event occurs during this month.
The owner receives monthly revenue for each animal, as specified above.
The owner may buy up to two adult animals of a single species. The owner may only buy one species per month, but they do not have to buy any animals if they don't want to. Each animal that the owner buys is exactly 4 years old. When the owner buys an animal, the cost of the animal is subtracted from the owner's bank account.
The owner must pay the upcoming feeding cost for each animal in the zoo (including any they just bought). The cost of food for each animal is calculated using the base cost of food. This starts out as $80. Each month, the base cost changes to a random value between 80% and 120% of the base cost from the month before. Once the cost of food for each animal is calculated, this amount is subtracted from the owner's bank account.
In addition to the specifications above, your game must have these features:

Each animal less than 6 months old (a baby) generates twice the amount of revenue as an adult animal. These babies (who are less than 6 months old) also cost twice as much as an adult if they get sick.

If the player runs out of money at any point, the game ends with the zoo going bankrupt.

# Other Program Requirements
You must have a class for each of the following things: zoo, animal, sea lion, tiger, and bear.
You must use inheritance: the classes for sea lion, tiger, and bear must inherit some traits and behaviors from the animal class, though each of them may also have unique traits or behaviors, as well (e.g. the bonus payout for sea lions).

Within your zoo, the exhibit of each species of animal must be represented as a dynamically-allocated array of objects of the appropriate class.

Your program should implement the game flow described above. The player may play one month at a time until they choose to quit the game. At the beginning of each month, you should let the player know how much money they have in the bank and how many adults (>= 4 years old) and babies (< 6 months old) they have of each species.

Your program may not have any memory leaks. It is recommended that you use Valgrind to occasionally test your program as you develop it (even when everything seems to be working).

The Big 3 must be implemented as appropriate.
Your program must be factored into interface, implementation, and application. Specifically, you should have one header file and one implementation file for each class, and you should have a single application file containing your main() function. You should also include a Makefile that specifies compilation for your program.

No use of of the <algorithms> and <vector> libraries

Lack of correct coding style will incur an automatic 10% deduction. You must follow the spirit of the assignment.
