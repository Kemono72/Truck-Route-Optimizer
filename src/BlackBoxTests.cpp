#include "pch.h"
#include "mapping_r.h"
#include "finder_r.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*The purpose of this document is to test the our code with the BlackBox Test method with sets of data in order to determine and find all the bugs to proceed to the debugging part*/

/*Testing Hook script*/

namespace BlackBox
{
	TEST_CLASS(BlackBoxShipmentTest)
	{
	public:
		TEST_METHOD(Test1_Invalid_Weight)
		{

			int weight = -1;
			bool expected = false;
			bool result = isWeight(weight);
			Assert::AreEqual(expected, result);

		}

		TEST_METHOD(Test2_Weight_TOO_MUCH)
		{
			int weight = 2600;
			bool expected = false;
			bool result = isWeight(weight);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Test3_Weight_ZERO)
		{
			int weight = 0;
			bool expected = false;
			bool result = isWeight(weight);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Test4_Weight_VALID)
		{
			int weight = 100;
			bool expected = true;
			bool result = isWeight(weight);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Test5_Size_Invalid)
		{
			double size = -1;
			bool expected = false;
			bool result = isSize(size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Test6_Size_Valid)
		{
			double size = 3;
			bool expected = true;
			bool result = isSize(size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Test7_Weight_Size_inValid)
		{
			int weight = 0;
			double size = 10;
			bool expected = false;
			bool result = isValidShipment(weight, size);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(Test8_Weight_Size_Valid)
		{
			int weight = 100;
			double size = 5;
			bool expected = true;
			bool result = isValidShipment(weight, size);
			Assert::AreEqual(expected, result);
		}

	};
}
