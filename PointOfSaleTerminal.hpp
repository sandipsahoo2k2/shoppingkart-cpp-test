#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Product.hpp"
#include "Inventory.hpp"
#include "PriceManager.hpp"
using namespace std;

#ifndef _POINT_OF_SALE_H_
#define _POINT_OF_SALE_H_

/* PointOfSaleTerminal class, This class is main interface class for scan, totalPrice */
class PointOfSaleTerminal
{
	private:
		Inventory &inventory ;
		PriceManager &priceManager;

		std::map<IProduct*, int> billingProducts; //customer bought products
	public:
		PointOfSaleTerminal(Inventory &inventory, PriceManager &priceManager);
		~PointOfSaleTerminal();

		int getTotalItems() const
		{
			return billingProducts.size();
		}

		const std::map<IProduct*, int>& getCartItems() const
		{
			return billingProducts;
		}
	
		/* Scan the product with a Code */
		void scan(std::string aCode);

		/* Calculate all total prices for the cart */
		double calculateTotal();
};

#endif

