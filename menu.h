#ifndef MENU_H
#define MENU_H 

#include <string>
#include <fstream>
#include "coffee.h"

using namespace std;

class Menu {
  private:
    int num_coffee;
    Coffee* coffee_arr;
  public:
    // default constructor
    Menu();
    // non default constructor
    Menu(int size);
    //destructor
    ~Menu();
    //AOO
    Menu& operator=(const Menu& m); 
    //CC
    Menu(const Menu &m);
    
    /* name: load_coffee_array()
     * description: Reads in values and populates menu objects
     * parameters: ifstream object
     * pre-condition: menu object has been declared
     * post-conditon: menu object has been populated
     */
    void load_coffee_array(ifstream &reader);
    
    /* name: print_menu()
     * description: iterates through all objects in coffee_arr and prints them to console
     * parameters: none
     * pre-condition: none
     * post-conditon: none
     */
    void print_menu();
    
    /* name: search_coffee_by_name()
     * description: Iterates through coffee_arr, looks for an object that shares same name as the inputted coffee, and returns that object at that index as a new object with the same value
     * parameters: string of coffee name
     * pre-condition: coffee object is declared 
     * post-conditon: coffee object is returned 
     */
    Coffee search_coffee_by_name(string name);
    
    /* name: search_coffee_by_price
     * description: Iterates through coffee array, creates and returns a new menu depending on which object has a price that is lower than the specified budget.
     * parameters: float of coffee price budget
     * pre-condition: menu object is created
     * post-conditon: a menu object is returned
     */
    Menu search_coffee_by_price(float budget);
    
    /* name: print_menu_with_price
     * description: Iterates through coffee array, prints out the information of the objects on the new menu, and only the prices under the specific budget.
     * parameters: float of coffee price budget
     * pre-condition: none
     * post-conditon: none
     */
    void print_menu_with_price(float budget);
    
    /* name: add_to_menu
     * description: Creates new array of coffees, copies all existing values of the previous coffee array, and adds the newest coffee object that was passed in. Deletes old array.
     * parameters: a coffee object
     * pre-condition: a coffee object has been created/populated
     * post-conditon: a new array is created with new coffee object
     */
    void add_to_menu(Coffee& coffee_to_add); 
    
    /* name: remove_from_menu
     * description: Creates new array of coffees, copies all existing values of the previous coffee array, but skips the coffee that was specified to be removed. Deletes old array.
     * parameters: int of index of specified coffee to be deleted
     * pre-condition: none
     * post-conditon: a new array is created without old coffee object
     */
    void remove_from_menu(int index_of_coffee_on_menu); 
    
    /* name: get_valid_removal
     * description: takes input and checks if it is within the value of number of coffees in the menu. Repeat if it isnt. Return value if it is
     * parameters: none
     * pre-condition: none
     * post-conditon: an int between 1 and num_coffee
     */
    int get_valid_removal();
    
    /* name: search_coffee_by_name_order
     * description: Checks if the name of the coffee is in the menu. If yes, return 1 and break loop. If not, return 0
     * parameters: string of coffee name
     * pre-condition: a new coffee object has been declared
     * post-conditon: returns a coffee object
     */
    int search_coffee_by_name_order(string name);
    
    /* name: calculate_total_revenue
     * description: Iterates through the menu. Compares the names of each coffee in the menu to the inputted name, and if it matches, check the size. Depending on the size, set the revenue to the cost of that drink at that size, and break the loop.  Multiply the price of that drink to the number of drinks ordered, and return THAT value.
     * parameters: string of coffee name, char of coffee size, and int of number of coffees
     * pre-condition:
     * post-conditon: return float of revenue
     */
    float calculate_total_revenue(string name, char size, int quantity);
    
    /* name: write_to_file
     * description: //Rewrites menu,txt and prints out all object information in coffee_arr 
     * parameters: none
     * pre-condition: none
     * post-conditon: menu.txt is updated with new menu
     */
    void write_to_file();
};

#endif
