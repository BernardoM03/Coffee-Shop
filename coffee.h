#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Coffee {
  private:
    string name;
    float small_cost;
    float medium_cost;
    float large_cost;
    
  public:
    //default constructor
    Coffee();  
    
    /* name: load_coffee
     * description: Reads in and populates values of name and prices into the coffee object
     * parameters: ifstream object
     * pre-condition: coffee_arr of i objects has been initialized
     * post-conditon: coffee_arr of i objects has been populated
     */
    void load_coffee(ifstream &reader);
    
    //Setters
    void set_name(const string c_name);
    void set_small_cost(const float cost);
    void set_medium_cost(const float cost);
    void set_large_cost(const float cost);
    
    //Getters
    string get_name() const;
    float get_small_cost() const;
    float get_medium_cost() const;
    float get_large_cost() const;
};

#endif
