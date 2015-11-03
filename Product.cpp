#include "Product.hpp"

Product::Product(std::string code)
{
	this->code = code;
	volumeFactor = 1;
	unitPrice = 0;
	volumePrice = 0;
}

Product::~Product()
{
}

void Product::setUnitPrice(double price)
{
	unitPrice = price;
	volumePrice = price;
}

void Product::setVolumePrice(int volume, double price)
{
	if(volume > 1)
	{
		volumeFactor = volume;
		volumePrice = price;
	}
}

/* price logic */
double Product::getPrice(int volume)
{
	double price = 0;
	int factor = volume / volumeFactor;
	int remainder = volume % volumeFactor;
	price = factor * volumePrice + remainder * unitPrice ;
	std::cout << "\nTotal price for " << volume << " " << code << " is " << price;
	return price;
}

