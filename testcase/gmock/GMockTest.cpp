#include "../../Inventory.hpp"
#include "gtest/gtest.h"

namespace {

	class InventoryTest : public ::testing::Test {
	protected:
		Inventory *inventory ;	

		InventoryTest() {
			inventory = new Inventory();	
		}

		virtual ~InventoryTest() {
			delete inventory;
		}

		virtual void SetUp() {
		}

		virtual void TearDown() {
		}
};

TEST_F(InventoryTest, HandleInitialise) {
	EXPECT_EQ(4, inventory->getStoreProducts().size());
}

TEST_F(InventoryTest, HandleAddProducts) {
	inventory->addProduct("007");
	EXPECT_EQ(5, inventory->getStoreProducts().size());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

}
