# shoppingkart-cpp-test

Consider a grocery market where items have prices per unit but also volume prices. For example, doughnuts may be $1.25 each or 3 for $3 dollars.

Here are the products listed by code and the prices to use (there is no sales tax):
Implement a point-of-sale scanning API that accepts an arbitrary ordering of products (similar to what would happen when actually at a checkout line) then returns the correct total price for an entire shopping cart based on the per unit prices or the volume prices as applicable.

The program should be an API implemented using Java. You can opt to put a user interface on it or not, but we will only be looking at the API portion. You do not need to provide any form of persistence in this program. Your project should contain some way of running automated tests to prove it works, for example using JUnit.

The interface at the top level PointOfSaleTerminal service object should look something like this:

PointOfSaleTerminal terminal = new PointOfSaleTerminal(); terminal.setPricing(...);

terminal.scan("A1");

terminal.scan("45K11");

... etc.

BigDecimal result = terminal.calculateTotal();

You are free to design/implement the rest of the code however you wish, including how you specify the prices in the system.
Here are the minimal inputs you should use for your test cases. These test cases must be shown to work in your program:
* Scan these items in this order and Verify the total price is $13.25: A1
3-Q 45K11 X1
A1 3-Q A1
* Scan these items in this order and Verify the total price is $6.00: 45K11
45K11 45K11 45K11 45K11 45K11 45K11
* Scan these items in this order and Verify the total price is $7.25: A1
3-Q 45K11 X1
￼
Product Code
￼
Price
A1
$1.25 each or 3 for $3.00
3-Q
$4.25
45K11
$1.00 or $5 for a six pack
X1
￼$0.75
- Please send us the complete Java project package that we can import in Eclipse IDE to look at your solution. Also, accompany the solution with a concise status document.
- The evaluation criteria are:
- Understanding of problem statement and ability to meet the requirements o Clarity of thought with approach chosen for solution
- Simple, Clean, Well-factored, OO, Complete Code
- Complete test coverage
- Clarity & completeness of communication

# Running the program

- Run the makefile
- It will create an executable PointOfSale.out
- Now execute this program with input product codes in command line e.g ./PointOfSale.out A1 3-Q 45K11 X1
- You can also run this program in intercative mode by uncommenting line #define INTERACTIVE_MODE 1 in main.cpp file and recompiling
- In intercative mode you need not have to pass the codes in commandline just run it e.g  ./PointOfSale.out

# Testing the program
- shoppingkart-cpp-test/testcases folder contains gmock and cppunit folders with testcases
- gmock folder contains testcases for Inventory class compiled against gmock-1.7.0, execute ./GMock.out and see the result
- cppunit folder contains testcases for PriceManager class with TEST-CODE-XYZ compiled against cppunit-1.12.1, execute ./CPPUnit.out and see the result
