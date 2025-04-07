#include "pch.h"
#include "mapping_r.h"
#include "finder_r.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*The purpose of this document is to test the our code with the WhiteBox Test method with sets of data in order to determine and find all the bugs to proceed to the debugging part*/

namespace WhiteBoxTest
{
	TEST_CLASS(WhiteBoxTest)
	{
	public:

		TEST_METHOD(Test1_Truck_validCapacity)
		{
			int weight = 200;
			double size = 1;
			struct Point dest = { 7, 24 };
			struct Shipment shipment = { weight, size, dest };
			Truck trucks[3] = {
			{
				BLUE, 2500,0, NULL
			},
			{
				GREEN, 0,0, NULL
			},
			{
				YELLOW, 700,0, NULL
			}
			};

			int* truckIndxs = getCapacity(trucks, 3, shipment);

			Assert::IsTrue(truckIndxs[0] == 0);
			Assert::IsTrue(truckIndxs[1] == 1);
			Assert::IsTrue(truckIndxs[1] == 1);
		}

		TEST_METHOD(Test2_BLUE_TRUCK_betterCapacity)
		{
			Truck trucks[3] = {
					{
						BLUE, 200,0, NULL
					},
					{
						GREEN, 500,0, NULL
					},
					{
						YELLOW, 700,0, NULL
					}
			};

			int betterCapacity = findBetterCapacityTruck(&trucks[0], &trucks[1]);

			Assert::AreEqual(0, betterCapacity);
		}

		TEST_METHOD(DestinationDistanceTest1_)
		{
			Truck trucks[3] = {
					{
						BLUE, 0,0, NULL
					},
					{
						GREEN, 0,0, NULL
					},
					{
						YELLOW, 0,0, NULL
					}
			};

			struct Point dest = { 5, 15 };
			double distance = getDistanceToDestination(getRoute(trucks[0].truckSymbol), dest);

			Assert::IsTrue(distance > 0);
		}

		TEST_METHOD(DestinationDistanceTest2_)
		{
			Truck trucks[3] = {
					{
						BLUE, 0,0, NULL
					},
					{
						GREEN, 0,0, NULL
					},
					{
						YELLOW, 0,0, NULL
					}
			};

			struct Point dest = { 10, 20 };
			double distance = getDistanceToDestination(getRoute(trucks[1].truckSymbol), dest);

			Assert::IsTrue(distance > 0);
		}

		TEST_METHOD(DiversionPathTest1_)
		{
			Truck trucks[3] = {
					{
						BLUE, 2500,0, NULL
					},
					{
						GREEN, 2500,0, NULL
					},
					{
						YELLOW, 2500,0, NULL
					}
			};

			struct Point dest = { 8, 18 };
			struct Route diversion = handleDiversion(getRoute(trucks[2].truckSymbol), dest);

			Assert::IsTrue(diversion.numPoints > 0);
		}
	};
}
