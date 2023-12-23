#include "coffee.h"

using namespace std;

//default constructor
Coffee::Coffee() : name(""), small_cost(0.0f), medium_cost(0.0f), large_cost(0.0f){

}

//Takes in values of name and prices of the coffee object
void Coffee::load_coffee(ifstream &reader){
	reader >> name >> small_cost >> medium_cost >> large_cost;

}

//Setters
void Coffee::set_name(const string c_name){
  name = c_name;
}

void Coffee::set_small_cost(const float cost){
	small_cost = cost;
}

void Coffee::set_medium_cost(const float cost){
	medium_cost = cost;
}

void Coffee::set_large_cost(const float cost){
	large_cost = cost;
}

//Getters
string Coffee::get_name() const {
	return name;
}

float Coffee::get_small_cost() const {
	return small_cost;
}

float Coffee::get_medium_cost() const {
	return medium_cost;
}

float Coffee::get_large_cost() const {
	return large_cost;
}

