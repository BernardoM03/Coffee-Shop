#include "order.h"

using namespace std;

//default constructor
Order::Order() : id(0), coffee_name(""), coffee_size(0), quantity(0){

}
//Setters
void Order::set_id(const int c_id){
	id = c_id;
}

void Order::set_coffee_name(const string name){
	coffee_name = name;
}

void Order::set_coffee_size(const char size){
	coffee_size = size;
}

void Order::set_quantity(const int c_quantity){
	quantity = c_quantity;
}

//Getters
int Order::get_id() const {
	return id;
}

string Order::get_coffee_name() const {
	return coffee_name;
}

char Order::get_coffee_size() const {
	return coffee_size;
}

int Order::get_quantity() const {
	return quantity;
}