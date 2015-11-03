#include "IProduct.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

/* Class responsible for holding Product info like price, code, volume price */
class Product : public IProduct
{
private :
	double unitPrice;
	std::string code;
	double volumePrice;
	int volumeFactor;
public :
	Product(std::string productCode);
	virtual ~Product();

	/* setUnitPrice for the Product */
	void setUnitPrice(double price);

	/* setVlumePrice for product */
	void setVolumePrice(int volume, double price);
	
	/* return correct price of the product for n items, define the interface function */
	virtual double getPrice(int volume);

	virtual const std::string& getCode() const
	{
		return code;
	}

	/* toString() for std::cout */
        virtual std::string toString() const
        {
		std::ostringstream displayString;
                displayString <<  "\nProduct Code: " << code ;
                displayString << "\nPrice: " <<  unitPrice << " Per One unit.";
                if(volumeFactor > 1)
                {
                        displayString << "\nPrice: " <<  volumePrice << " per " << volumeFactor << " units.\n";
                }
                return std::string(displayString.str());
        }

	/* toString() for std::cout */
	friend ostream &operator<< (ostream &output, const Product &product)
	{
		output << "\nProduct Code: " << product.code ;
		output << "\nPrice: " <<  product.unitPrice << " Per One unit.";
		if(product.volumeFactor > 1)
		{
			output << "\nPrice: " <<  product.volumePrice << " per " << product.volumeFactor << " units.\n";
		}
	        return output;
	}
};

#endif
