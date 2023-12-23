#include "menu.h"

using namespace std;

//function defintions from menu.h goes here

//default constructor
Menu::Menu() : coffee_arr(nullptr), num_coffee(0) {
	cout << "menu()" << endl << endl;	
}

//non default constructor
Menu::Menu(int size) {
	this->num_coffee = size;
	this->coffee_arr = new Coffee[size];
	cout << "menu(int)" << endl << endl;
}

//destructor
Menu::~Menu() {
	cout << "~Menu()" << endl << endl;
	if(this->coffee_arr != NULL){
		delete [] this->coffee_arr;
		this->coffee_arr = NULL;
	}
}

//Assignment Operator Overload
Menu& Menu::operator=(const Menu& m){
	cout << "AOO" << endl << endl;
	if (this == &m){
		return *this;
	}

	if (this->coffee_arr != NULL){
		delete [] this->coffee_arr;
	}

	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee[this->num_coffee];
	for (int i = 0; i < this->num_coffee; i++){
		this->coffee_arr[i] = m.coffee_arr[i];
	}
	return *this;
}
//Copy Constructor
Menu::Menu(const Menu& m){
	cout << "CC" << endl << endl;;
	this->num_coffee = m.num_coffee;
	this->coffee_arr = new Coffee[this->num_coffee];
	for (int i = 0; i < this->num_coffee; i++) {
		this->coffee_arr[i] = m.coffee_arr[i];
	}
}

void Menu::load_coffee_array(ifstream &reader){
	//opens menu.txt and reads in info
  reader.open("menu.txt");
	reader >> num_coffee;
	cout << "coffee number: " << num_coffee << endl;
  
  // populates coffee_arr with dynamic memory and all the info stored in the menu.txt file. 
	coffee_arr = new Coffee[num_coffee];
	for (int i = 0; i < num_coffee; i++){
		coffee_arr[i].load_coffee(reader);
	}
}

void Menu::print_menu(){
	for (int i = 0; i < num_coffee; i++){
		cout << "Coffee #: " << i + 1 << endl;
		cout << "Coffee Name: " << coffee_arr[i].get_name() << endl;
		cout << "Small Price: " << coffee_arr[i].get_small_cost() << endl;
		cout << "Medium Price: " << coffee_arr[i].get_medium_cost() << endl;
		cout << "Large Price: " << coffee_arr[i].get_large_cost() << endl << endl;
	}
}

Coffee Menu::search_coffee_by_name(string name) {
	Coffee found; 
	for (int i = 0; i < num_coffee; i++) {
		if (coffee_arr[i].get_name().compare(name) == 0) {
			found = coffee_arr[i];
			break;
		}
	}
	return found;
}

Menu Menu::search_coffee_by_price(float budget){
	Menu temp;
	for (int i = 0; i < num_coffee; i++){
		float small_cost = coffee_arr[i].get_small_cost();
		float medium_cost = coffee_arr[i].get_medium_cost();
		float large_cost = coffee_arr[i].get_large_cost();

		if (small_cost <= budget || medium_cost <= budget || large_cost <= budget) {
			temp.add_to_menu(coffee_arr[i]);
		}
	}
	return temp;
}

void Menu::print_menu_with_price(float budget){
	for (int i = 0; i < num_coffee; i++) {
		cout << "Coffee #: " << i + 1 << endl;
		cout << "Coffee Name: " << coffee_arr[i].get_name() << endl;
		if (coffee_arr[i].get_small_cost() <= budget){
			cout << "Small Cost: $" << coffee_arr[i].get_small_cost() << endl;
			if (coffee_arr[i].get_medium_cost() <= budget) {
				cout << "Medium Cost: $" << coffee_arr[i].get_medium_cost() << endl;
				if (coffee_arr[i].get_large_cost() <= budget) {
					cout << "Large Cost: $" << coffee_arr[i].get_large_cost() << endl;
				}
			}
		}
		cout << endl;
	}
}

void Menu::add_to_menu(Coffee& coffee_to_add){
	Coffee* new_arr = new Coffee[num_coffee + 1];
	for (int i = 0; i < num_coffee; i++) {
		new_arr[i] = coffee_arr[i];
	}

	num_coffee = num_coffee + 1;
	new_arr[num_coffee - 1] = coffee_to_add;

	delete [] coffee_arr;
	coffee_arr = new_arr;	
	return;
} 

void Menu::remove_from_menu(int index_of_coffee_on_menu){
	num_coffee = num_coffee - 1;
	Coffee* new_arr = new Coffee[num_coffee];
	for (int i = 0, j = 0; i < num_coffee + 1; i++){
		if (i != index_of_coffee_on_menu - 1) {
			new_arr[j++] = coffee_arr[i];
		}
	}
	delete [] coffee_arr;
	coffee_arr = new_arr;
	return;
} 

int Menu::get_valid_removal() {
	int input = 0;
	cin >> input;
	while (input <= 0 || input > num_coffee){
		cout << "There isn't a coffee object there! Try again" << endl;
		cin >> input;
	}
  return input;
}

void Menu::write_to_file(){
	ofstream writer;
	writer.open("menu.txt");
	writer << num_coffee << endl;
	for (int i = 0; i < num_coffee; i++) {
		writer << coffee_arr[i].get_name() << " ";
		writer << coffee_arr[i].get_small_cost() << " ";
		writer << coffee_arr[i].get_medium_cost() << " ";
		writer << coffee_arr[i].get_large_cost() << endl;
	}
	writer.close();
}

int Menu::search_coffee_by_name_order(string name) { 
	int found = 0;
	for (int i = 0; i < num_coffee; i++) {
		if (coffee_arr[i].get_name().compare(name) == 0) {
			found = 1;
			break;
		}
	}
	return found;
}


float Menu::calculate_total_revenue(string name, char size, int quantity) {
	float revenue;
	for (int i = 0; i < num_coffee; i++){
		if (coffee_arr[i].get_name().compare(name) == 0) {
			if (size == 'S') {
				revenue = coffee_arr[i].get_small_cost();
			}
			else if (size == 'M') {
				revenue = coffee_arr[i].get_medium_cost();
			}
			else {
				revenue = coffee_arr[i].get_large_cost();
			}
      break;
		}
	}
	revenue = revenue * quantity;	
	return revenue;
}
