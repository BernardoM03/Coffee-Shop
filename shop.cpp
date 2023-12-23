#include "shop.h"

using namespace std;

//function defintions from shop.h goes here

//Default constructor
Shop::Shop() : m(), phone(""), address(""), revenue(0.0f), order_arr(nullptr), num_orders(0){
	cout << "Shop()" << endl;
}

//Destructor
Shop::~Shop() {
	cout << "~Shop()" << endl << endl;
	if(this->order_arr != NULL) {
		delete [] this-> order_arr;
		this->order_arr = NULL;
	}
}

//Assignment Overload Operator
Shop& Shop::operator=(const Shop& s){
	cout << "AOO" << endl << endl;
	if (this == &s){
		return *this;
	}

	if (this->order_arr != NULL){
		delete [] order_arr;
	}

	this->num_orders = s.num_orders;
	this->order_arr = new Order[this->num_orders];
	for (int i = 0; i < this->num_orders; i++){
		this->order_arr[i] = s.order_arr[i];
	}
	return *this;
}

//Copy Constructor
Shop::Shop(const Shop& s){
	cout << "CC" << endl << endl;
	this->num_orders = s.num_orders;
	this->order_arr = new Order[this->num_orders];
	for (int i = 0; i < this->num_orders; i++){
		this->order_arr[i] = s.order_arr[i];
	}
}

//Populate shop data function
void Shop::load_data(ifstream &reader){
	reader.open("shop_info.txt");
	reader >> address >> phone;
	reader.close();

	//calls function to populate menu object
	m.load_coffee_array(reader);

	return;
}

//Print shop info function
void Shop::view_shop_detail(){
	cout << "Address: " << address << endl;
	cout << "Phone: " << phone << endl;

	//Prints out info of array of coffee objects in the menu
	cout << endl << "--MENU--" << endl;
	m.print_menu();
	
	//Prints out info of order objects
	cout << endl << "--ORDERS--" << endl;
 	print_orders();
 	cout << endl << "Revenue: $" << revenue << endl;
	return;
}

//Print all order objects in order array
void Shop::print_orders() {
	for (int i = 0; i < num_orders; i++) {
		cout << "Order ID: " << order_arr[i].get_id() << endl;
		cout << "Coffee Name: " << order_arr[i].get_coffee_name() << endl;
		cout << "Coffee Size: " << order_arr[i].get_coffee_size() << endl;
		cout << "# of Coffees: " << order_arr[i].get_quantity() << endl;
	}
}

//Add new coffee object to menu
void Shop::add_to_menu(){ 
	//creates new object and takes input for name and prices
	Coffee new_coffee;
	string name;
	cout << "What is the name of the coffee you would like to add?" << endl;
	cin >> name;
	cout << "What is the price of the small size?" << endl;
	float small_cost = get_valid_price();
	cout << "What is the price of the medium size?" << endl;
	float medium_cost = get_valid_price();
	cout << "What is the price of the large size?" << endl;
	float large_cost = get_valid_price();
	
	//sets values of new coffee object to inputted values
	new_coffee.set_name(name);
	new_coffee.set_small_cost(small_cost);
	new_coffee.set_medium_cost(medium_cost);
	new_coffee.set_large_cost(large_cost);

	//creates a new array with new coffee object
	m.add_to_menu(new_coffee);
	
	//Reprints coffee array to menu.txt
	m.write_to_file();
	return;
}

//Remove a coffee object from the menu
void Shop::remove_from_menu(){
	//gets valid input
	cout << "Which Coffee would you like to delete?" << endl;
	int input = m.get_valid_removal();
	
	//creates a new array without chosen coffee object
	m.remove_from_menu(input);
	
	//Reprints coffee array to menu.txt
	m.write_to_file();
	return;
}

//Displays coffee info by searching name 
void Shop::search_by_name(){
	//takes input for name
	cout << "What coffee are you looking for?" << endl;
	string name;
	cin >> name;
	
	//loops through menu array and returns object with the same name
	Coffee found = m.search_coffee_by_name(name);

	//print out all info of returned object;
	cout << "Coffee Name: " << found.get_name() << endl;
 	cout << "Small Price: " << found.get_small_cost() << endl;
	cout << "Medium Price: " << found.get_medium_cost() << endl;
	cout << "Large Price: " << found.get_large_cost() << endl << endl;
	return;
}

//Displays all coffees and prices under a specified budget
void Shop::search_by_price(){
	//takes input for valid budget
	cout << "What is your budget?" << endl;
	float budget = get_valid_price();

	//loops through menu and returns all coffee objects with coffee prices under specified budget
	Menu result_menu = m.search_coffee_by_price(budget);

	//prints out all coffees and sizes with prices under budget
	result_menu.print_menu_with_price(budget);	
	return;
}

//Checks whether the budget is a non-negative number returns if it is.
float Shop::get_valid_price(){
	float input  = 0.0f;
	cin >> input;
	while (input <= 0) {
		cout << "The price must be a non-negative number!" << endl;
		cout << "We need to make money somehow" << endl;
		cin >> input;
	}
	return input;	
}

//Takes information of an order object and adds it to an order array
void Shop::place_order() {
	num_orders = num_orders + 1;
	Order new_order;
	int id = num_orders;
 	
	//takes input for coffee name, coffee size, and the number of coffees
	cout << "What is the name of the coffee you want to order?" << endl;
	string coffee_name = get_coffee_name();
	cout << "What size coffee would you like to order?" << endl;
	char coffee_size = get_coffee_size();
	cout << "How many coffees would you like to order?" << endl;
	int quantity = get_coffee_quantity();

	//calculates revenue
	revenue += m.calculate_total_revenue(coffee_name, coffee_size, quantity);
	cout << "Total Order Price: $" << revenue << endl;

	//sets values of the new order object to the inputted values
	new_order.set_id(id);
	new_order.set_coffee_name(coffee_name);
	new_order.set_coffee_size(coffee_size);
	new_order.set_quantity(quantity);
	

	//creates new array of orders and adds the newest order object
	Order* new_arr = new Order[num_orders];
	for (int i = 0; i < num_orders - 1; i++) {
		new_arr[i] = order_arr[i];
	}
	new_arr[num_orders - 1] = new_order;

	//deletes old array and sets pointer to the new array
	delete [] order_arr;
	order_arr = new_arr;
	return;
}

//Takes in a name input of a coffee that exists in the menu
string Shop::get_coffee_name(){
	int found = 0;
	string name = "";
	cin >> name;
	found = m.search_coffee_by_name_order(name);

	while (found == 0) {
		cout << "That is not on our menu! Choose another!" << endl;
		cin >> name;
		found = m.search_coffee_by_name_order(name);
	}
	return name;
}

//Takes in a size input that is S, M, or L
char Shop::get_coffee_size(){
	char size;
	cin >> size;
	while (size != 'S' && size != 'M' && size != 'L'){
		cout << "That is not one of our sizes. Use the capitalized letters 'S' or 'M' or 'L'. It is case sensitive!" << endl;
		cin >> size;
	}
	return size;
}

//takes in a order quantity input that is atleast 1
int Shop::get_coffee_quantity(){
	int quantity;
	cin >> quantity;
	while (quantity <= 0) {
		cout << "The quantity must be at least 1 drink." << endl;
		cout << "You must order something!" << endl;
		cin >> quantity;
	}
	return quantity;
}

//Uses the big three to create two new copies of the shop
Shop Shop::clone_shop() {
	Shop cloned_shop;
	cloned_shop = *this; // test AOO        
	Shop cloned_shop2 = *this; // test CC 
	cout << "Shop cloned successfully!" << endl; 
	return cloned_shop;
}
