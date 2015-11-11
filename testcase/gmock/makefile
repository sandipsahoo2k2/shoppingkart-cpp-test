CPP_DIR = ../..
GTEST_LIB = ../../../gmock-1.7.0/make
GTEST_DIR = ../../../gmock-1.7.0/gtest/include
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GMock.out : Product.o Inventory.o GMockTest.o
	g++ -o GMock.out Product.o Inventory.o GMockTest.o $(GTEST_LIB)/gmock_main.a

Product.o : $(CPP_DIR)/Product.cpp $(CPP_DIR)/Product.hpp $(CPP_DIR)/IProduct.hpp
	g++ -c $(CPP_DIR)/Product.cpp

Inventory.o : $(CPP_DIR)/Inventory.cpp $(CPP_DIR)/Inventory.hpp
	g++ -c $(CPP_DIR)/Inventory.cpp

GMockTest.o : GMockTest.cpp $(CPP_DIR)/Inventory.hpp $(CPP_DIR)/Product.hpp $(CPP_DIR)/IProduct.hpp
	g++ -c GMockTest.cpp -I$(GTEST_DIR)

clean: 
	rm *.o *.out 

