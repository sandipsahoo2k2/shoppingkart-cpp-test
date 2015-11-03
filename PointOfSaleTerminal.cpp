#include "PointOfSaleTerminal.hpp"

PointOfSaleTerminal::PointOfSaleTerminal(Inventory &inventory):inventory(inventory)
{
	totalPrice = 0;
}

PointOfSaleTerminal::~PointOfSaleTerminal()
{
}

void PointOfSaleTerminal::scan(std::string code)
{
	IProduct *product = inventory.getProduct(code);
	if(product != NULL) //Found
	{
		std::cout << "\nScanning Product code " << code << std::endl;
		/* Add for billing */
		std::map<IProduct*, int>::iterator itr = billingProducts.find(product);
		if(itr == billingProducts.end()) //not found
		{
			billingProducts[product] = 1;
		}
		else //update the count
		{
			billingProducts[product]++;
		}
	}
	else
	{
		std::cout << "\nProduct code " << code << " not found in store !!" << std::endl;
	}
}

double PointOfSaleTerminal::calculateTotal()
{
	for(std::map<IProduct*, int>::iterator itr = billingProducts.begin(); itr != billingProducts.end(); itr++)
	{
		IProduct *product = itr->first;
		int productCount = itr->second;
		totalPrice += product->getPrice(productCount);	
	}
	std::cout << "\n\nAllTotal for " << billingProducts.size() << " items is $" << totalPrice << std::endl;
	return totalPrice;
}

