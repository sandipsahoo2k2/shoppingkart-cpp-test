#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "IProduct.hpp"
using namespace std;

#ifndef _INVENTORY_H_
#define _INVENTORY_H_
/* template function (unary)for freeing memory  used by for_each*/

template <typename T>
void delete_ptr(T* const ptr)
{
    delete ptr;
}

/* Inventory class */
class Inventory
{
	private:
		std::map<IProduct*, int> storeProducts; //Act as a database for the store

		/* Initialise with all product, We could initialise products from  
			main.cpp but as we are already given with 4 products I am calling this in constructor for ease */
		void initialise() ;

	public:
		Inventory();
		~Inventory();

		const std::map<IProduct*, int>& getStoreProducts() const
		{
			return storeProducts;
		}
	
		/* add a new product to the store operator/user/client can call this function to add any new product, 
			we are dealing with product codes only for now otherwise we can add other details aswell*/	
		void addProduct(std::string code) ;

		/* remove product */
		void removeProduct(std::string code);

		/*  get product details return NULL if it doesn't exist*/
		IProduct* getProduct(std::string code) const;
};

#endif
