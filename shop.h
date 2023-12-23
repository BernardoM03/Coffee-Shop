#ifndef SHOP_H
#define SHOP_H

#include <string>
#include <fstream>
#include <iostream>
#include "menu.h"
#include "order.h"

using namespace std;

class Shop {
  private:
    Menu m;
    string phone;
    string address; 
    float revenue;      //shop revenue
    Order *order_arr;   //order array
    int num_orders;     //number or orders
  public:
  
    // default constructor
    Shop();
    //destructor
    ~Shop();
    //AOO
    Shop& operator=(const Shop& s);
    // CC
    Shop(const Shop &s); 

    /* name: load_data
     * description: Populate shop object by reading in menu.txt file
     * parameters: ifstream object
     * pre-condition: shop obeject is declared
     * post-conditon: shop object is populated
     */
    void load_data(ifstream &reader); //reads from files to correctly populate coffee, menu, etc.
    
    /* name: view_shop_detail
     * description: Print shop onject information, including the entire menu and history of orders
     * parameters: none
     * pre-condition: none
     * post-conditon: shop information is printed to console
     */
    void view_shop_detail();

    /* name: add_to_menu
     * description: Creates new coffee object, take inputs of values and sets the coffee object's information to the inputted values, and adds that new coffee object to menu
     * parameters: none
     * pre-condition: this option was chosen
     * post-conditon: New menu with coffee object is created.
     */
    void add_to_menu();

    /* name: remove_from_menu
     * description: Takes input and removes specified coffee object from the menu
     * parameters: this option was chosen
     * pre-condition: none
     * post-conditon: New menu without specified coffee object is created
     */
    void remove_from_menu();
    
    /* name: search_by_name
     * description: Displays coffee info by searching name trough user input 
     * parameters: none
     * pre-condition: this option was chosen
     * post-conditon: specified coffee object printed to console
     */
    void search_by_name();
    
    /* name: search_by_price
     * description: Displays all coffees and prices under a specified budget
     * parameters: none
     * pre-condition: this option was chosen
     * post-conditon: Menu of coffee object with price under budget is printed
     */
    void search_by_price();
    
    /* name: get_valid_price
     * description: Checks whether the budget is a non-negative number returns if it is.
     * parameters: none
     * pre-condition: none
     * post-conditon: returns non negative number
     */
    float get_valid_price();
    
    /* name: place_order
     * description: =
     * parameters: 
     * pre-condition: 
     * post-conditon: 
     */
    void place_order();
    
    /* name: print_orders
     * description: Takes information of an order object and adds it to an order array
     * parameters: none
     * pre-condition: this option was chosen
     * post-conditon: An order array with new order object is created
     */
    void print_orders();
    
    /* name: get_coffee_name
     * description: takes in a name input of a coffee that exists in the menu
     * parameters: none
     * pre-condition: none
     * post-conditon: returns valid coffee name
     */
    string get_coffee_name();
    
    /* name: get_coffee_size
     * description: Takes in a char size input that is S, M, or L
     * parameters: none
     * pre-condition: none
     * post-conditon: valid char size is returned
     */
    char get_coffee_size();
    
    /* name: get_coffee_quantity
     * description: takes in a order quantity input that is atleast 1
     * parameters: none
     * pre-condition: none
     * post-conditon: returns a coffee quantity that is at least 1
     */
    int get_coffee_quantity();
    
    /* name: clone_shop
     * description: //Uses the big three to create two new copies of the shop
     * parameters: none
     * pre-condition: this option was chosen
     * post-conditon: two new shop objects are created and cloned
     */
    Shop clone_shop();
    
};

#endif
