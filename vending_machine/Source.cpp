#include <iostream>
#include <math.h>
#include <string>
#include <map>
#include <functional>
using namespace std;

struct val {
	double price;
	int stock;
};

struct money {
	const double PENNIES = 0.01;
	const double NICKELS = 0.05;
	const double DIMES = 0.10;
	const double QUARTERS = 0.25;
	const double ONES = 1.00;
	const double FIVES = 5.00;
	const double TENS = 10.00;
	const double TWENTIES = 20.00;
};

//Function Prototypes
bool is_machine_on(bool);
bool turn_on(bool);
void menu(map<string, val>);
void check_inventory(map<string, val>);
std::map<string, val> refill_inventory(map<string, val>);
string select_product();
int coin_count();


int main() {
	//initializers
	string selection;
	map<string, val> items;
	map<string, val>::iterator it;

	items.insert({ "Coke", {0.95, 20} });
	items.insert({ "Doritos", {0.75, 10} });
	items.insert({ "Snickers", {0.55, 20} });
	items.insert({ "Chex Mix", {0.60, 30} });
	items.insert({ "Pepsi", {0.90, 15} });

	//power functions
	bool power = false;
	is_machine_on(power);
	turn_on(power);
	//print menu
	menu(items);
	cout << "\n\n";
	//housekeeping
	check_inventory(items);
	cout << endl;
	map<string, val> refilled_items = refill_inventory(items);
	cout << endl;
	check_inventory(refilled_items);
	//selection process
	selection = select_product();
	cout << "You entered " << selection << endl;

}

// Function Implementation
bool is_machine_on(bool p) {
	// if machine is on return true
	if (p == true) {
		cout << "MACHINE IS ON\n";
		return p;
	}
	// else return the parameter
	else {
		cout << "...\n";
		return p;
	}
}

bool turn_on(bool p) {
	// turns on the power of the system
	cout << "Power ON\n\n";
	p = true;
	return p;
}

void menu(map<string, val> items) {
	cout << "\t--MENU--\n";
	// print out items in a menu format
	for (auto it = items.begin(); it != items.end(); ++it)
		std::cout << it->first << " => " << it->second.price << '\n';
	cout << "\t--MENU--\n";
}

void check_inventory(map<string, val> items) {
	// print out the items 
	for (auto it = items.begin(); it != items.end(); ++it) {
		cout << it->first << " => " << it->second.stock << endl;
	}
}

map<string, val> refill_inventory(map<string, val> items) {
	int rem;
	for (auto it = items.begin(); it != items.end(); ++it) {
		if (it->second.stock < 30) {
			cout << "Refilling " << it->first << endl;
			rem = 30 - it->second.stock;
			it->second.stock = rem;
		}
	}
	cout << "Stock refilled.\n";
	return items;
}

string select_product()
{
	string item;
	cout << "Select your item. \n";
	getline(cin, item);
	return item;
}

int coin_count()
{
	return 0;
}

