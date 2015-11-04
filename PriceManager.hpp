#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef _PRICE_MANAGER_H_
#define _PRICE_MANAGER_H_

/* PriceManager class */
class PriceManager
{
	private:
		/* a product code with volume is the key and price is the value */
		std::map<std::pair<std::string, int>, double, std::greater<std::pair<std::string, int> > > prices; //Act as a database for the prices for products

		/* Initialise with all prices, We could initialise prices from 
                        main.cpp but as we are already given with 4 products I am calling this in constructor for ease */
                void initialise() ;

	public:
		PriceManager();

		/** add a new price for a product code to the price manager **/
		/* if the key exist it will be over written with new price */
		void addPrice(std::string code, int volume, double price) ;

		/* remove price info for a product code */
		void removePrice(std::string code, int volume);
		
		/** calculate the actual price of a product depending upon the volume **/
		/* it may return 0 in such case caller can assume price information is missing */
		double getPrice(std::string code, int volume) ;
		
		/* Helper function for  printing all price information for  all product codes */
		std::string toString() const;
		
		/* Helper Function to list all the available pricing information for a product code may be ignored for *review */
		/* a map of volumes and corresponding price in dollar is returned */ 
		std::map<int, double> getPriceMap(std::string code) const;

};

#endif
