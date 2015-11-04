#include "IProduct.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#ifndef _PRODUCT_H_
#define _PRODUCT_H_

/* Class responsible for holding Product info like name, code, details, weight*/
class Product : public IProduct
{
private :
	/* we can add other details e.g name, weight etc etc*/
	/* we are dealing with product codes only for now */	
	std::string code;
public :
	Product(std::string productCode);
	virtual ~Product();

	virtual const std::string& getCode() const
	{
		return code;
	}

	/* toString() for std::cout */
        virtual std::string toString() const
        {
		std::ostringstream displayString;
                displayString <<  "\nProduct Code: " << code ;
                return std::string(displayString.str());
        }

	/* toString() for std::cout */
	friend ostream &operator<< (ostream &output, const Product &product)
	{
		output << "\nProduct Code: " << product.code ;
	        return output;
	}
};

#endif
