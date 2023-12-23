#ifndef ORDER_H
#define ORDER_H 

#include <string>

using namespace std;

class Order
{
private:
	int id;
	string coffee_name;
	char coffee_size;
	int quantity;

public:
  //default constructor
	Order();
	
  //Setters
	void set_id(const int c_id);
	void set_coffee_name(const string name);
	void set_coffee_size(const char size);
	void set_quantity(const int c_quantity);
 
  //Getters
	int get_id() const;
	string get_coffee_name() const;
	char get_coffee_size() const;
	int get_quantity() const;	
};
#endif
