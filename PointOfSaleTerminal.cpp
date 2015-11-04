#include "PointOfSaleTerminal.hpp"

PointOfSaleTerminal::PointOfSaleTerminal(Inventory &inventory, PriceManager &priceManager):inventory(inventory), priceManager(priceManager)
{
}

PointOfSaleTerminal::~PointOfSaleTerminal()
{
}

void PointOfSaleTerminal::scan(std::string code)
{
	IProduct *product = inventory.getProduct(code);
	if(product != NULL) //Found
	{
		std::cout << "\nScanning Product code " << code;
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

		//we can call calculateTotal() to know the price here also to see it realtime with each scan
	}
	else
	{
		std::cout << "\n\n!!Product code " << code << " not found in store !!" << std::endl;
	}
}

double PointOfSaleTerminal::calculateTotal()
{
	double totalPrice = 0;
	double totalCount = 0;
	for(std::map<IProduct*, int>::iterator itr = billingProducts.begin(); itr != billingProducts.end(); itr++)
	{
		IProduct *product = itr->first;
		int productCount = itr->second;
		totalCount += productCount;
		totalPrice += priceManager.getPrice(product->getCode(), productCount); //check with price manager the actual price
	}
	std::cout << "\n\nAllTotal for " << totalCount << " items with " << billingProducts.size() << " product category is $" << totalPrice << std::endl << std::endl;
	return totalPrice;
}

