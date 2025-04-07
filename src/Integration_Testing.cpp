#include "pch.h"
#include "CppUnitTest.h"
#include "finder_r.h"
#include "mapping_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntegrationTesting
{
	TEST_CLASS(IntegrationTesting)
	{
	public:

		struct Point start = { 0, 0 };
		struct Point prev = { -1, -1 };

		// Initialize all trucks 
		struct Truck trucks[3] =
		{
			{
				BLUE, 0,0, NULL,0
			},
			{
				GREEN, 0,0, NULL,0
			},
			{
				YELLOW, 0,0, NULL,0
			}
		};

		struct Map baseMap = populateMap();
		struct Route blueRoute = getBlueRoute();
		struct Route greenRoute = getGreenRoute();
		struct Route yellowRoute = getYellowRoute();

		// Test case to verify Blue truck delivery without any route diversion.
		TEST_METHOD(Test1BlueDeliveryNoDiversion)
		{
			// Reset truck weights and volumes
			trucks[0].actualWeight = 0;
			trucks[0].actualVolume = 0;

			trucks[1].actualWeight = 0;
			trucks[1].actualVolume = 0;

			trucks[2].actualWeight = 0;
			trucks[2].actualVolume = 0;

			int weight = 20;
			int size = 1;
			char destination[] = "12L";
			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			// Check if the Blue truck is selected for the delivery with the correct weight and size.
			char ExpectedTruckSymbol = 2;
			Assert::AreEqual(ExpectedTruckSymbol, truckChoice->truckSymbol);
			Assert::AreEqual(weight, truckChoice->actualWeight);
			Assert::AreEqual(size, truckChoice->actualVolume);
		}

		// Test case to verify Blue truck delivery with route diversion.
		TEST_METHOD(Test2BlueDeliveryWithDiversion)
		{
			// Reset truck weights and volumes
			trucks[0].actualWeight = 0;
			trucks[0].actualVolume = 0;

			trucks[1].actualWeight = 0;
			trucks[1].actualVolume = 0;

			trucks[2].actualWeight = 0;
			trucks[2].actualVolume = 0;

			int weight = 500;
			int size = 1;
			char destination[] = "12N";
			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			// Check if the Blue truck is selected for the delivery with diversion in route.
			char ExpectedTruckSymbol = 2;
			struct Shipment shipment = truckChoice->shipments[truckChoice->numberOfshipments - 1];
			Assert::AreEqual(ExpectedTruckSymbol, truckChoice->truckSymbol);
			Assert::IsTrue(shipment.divertedRoute.numPoints > 0);
		}

		// Test case to verify Green truck delivery without any route diversion.
		TEST_METHOD(Test3GreenDeliveryNoDiversion)
		{
			// Set Blue truck's weight to be high to force Green truck selection
			trucks[0].actualWeight = 700;
			trucks[0].actualVolume = 0;

			trucks[1].actualWeight = 0;
			trucks[1].actualVolume = 0;

			trucks[2].actualWeight = 0;
			trucks[2].actualVolume = 0;

			int weight = 200;
			int size = 1;
			char destination[] = "2U";
			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			// Check if the Green truck is selected for the delivery with the correct weight and size.
			char ExpectedTruckSymbol = 4;
			Assert::AreEqual(ExpectedTruckSymbol, truckChoice->truckSymbol);
			Assert::AreEqual(weight, truckChoice->actualWeight);
			Assert::AreEqual(size, truckChoice->actualVolume);
		}

		// Test case to verify Green truck delivery with route diversion.
		TEST_METHOD(Test4GreenDeliveryWithDiversion)
		{
			// Reset truck weights and volumes
			trucks[0].actualWeight = 0;
			trucks[0].actualVolume = 0;

			trucks[1].actualWeight = 0;
			trucks[1].actualVolume = 0;

			trucks[2].actualWeight = 0;
			trucks[2].actualVolume = 0;

			int weight = 500;
			int size = 1;
			char destination[] = "12T";
			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			// Check if the Green truck is selected for the delivery with diversion in route.
			char ExpectedTruckSymbol = 4;
			struct Shipment shipment = truckChoice->shipments[truckChoice->numberOfshipments - 1];
			Assert::AreEqual(ExpectedTruckSymbol, truckChoice->truckSymbol);
			Assert::IsTrue(shipment.divertedRoute.numPoints > 0);
		}

		// Test case to verify Yellow truck delivery without any route diversion.
		TEST_METHOD(Test5YellowDeliveryNoDiversion)
		{
			// Reset truck weights and volumes
			trucks[0].actualWeight = 0;
			trucks[0].actualVolume = 0;

			trucks[1].actualWeight = 0;
			trucks[1].actualVolume = 0;

			trucks[2].actualWeight = 0;
			trucks[2].actualVolume = 0;

			int weight = 2000;
			int size = 1;
			char destination[] = "19G";
			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			// Check if the Yellow truck is selected for the delivery with the correct weight and size.
			char ExpectedTruckSymbol = 8;
			Assert::AreEqual(ExpectedTruckSymbol, truckChoice->truckSymbol);
			Assert::AreEqual(weight, truckChoice->actualWeight);
			Assert::AreEqual(size, truckChoice->actualVolume);
		}

		// Test case to verify Yellow truck delivery with route diversion.
		TEST_METHOD(Test6YellowDeliveryWithDiversion)
		{
			// Reset truck weights and volumes
			trucks[0].actualWeight = 0;
			trucks[0].actualVolume = 0;

			trucks[1].actualWeight = 0;
			trucks[1].actualVolume = 0;

			trucks[2].actualWeight = 0;
			trucks[2].actualVolume = 0;

			int weight = 100;
			int size = 5;
			char destination[] = "25K";
			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			// Check if the Yellow truck is selected for the delivery with diversion in route.
			char ExpectedTruckSymbol = 8;
			struct Shipment shipment = truckChoice->shipments[truckChoice->numberOfshipments - 1];
			Assert::AreEqual(ExpectedTruckSymbol, truckChoice->truckSymbol);
			Assert::IsTrue(shipment.divertedRoute.numPoints > 0);
		}

		// Test case to verify that no truck is available for delivery due to weight and volume constraints.
		TEST_METHOD(Test7NoTruckAvailable)
		{
			// Set high weights and volumes to ensure no truck can handle the shipment.
			trucks[0].actualWeight = 2400;
			trucks[0].actualVolume = 0;

			trucks[1].actualWeight = 0;
			trucks[1].actualVolume = 98;

			trucks[2].actualWeight = 2400;
			trucks[2].actualVolume = 0;

			int weight = 500;
			int size = 3;
			char destination[] = "12l";
			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			// Check that no truck is available.
			Assert::IsNull(truckChoice);
		}

		// Test case to verify that shipment with invalid weight is rejected.
		TEST_METHOD(Test8InvalidWeight)
		{
			int weight = 2600;
			int size = 5;
			int result = isValidShipment(weight, size);

			// Check that the shipment is invalid due to weight.
			Assert::IsFalse(result);
		}

		// Test case to verify that shipment with invalid size is rejected.
		TEST_METHOD(Test9InvalidSize)
		{
			int weight = 650;
			int size = 2;
			int result = isValidShipment(weight, size);

			// Check that the shipment is invalid due to size.
			Assert::IsFalse(result);
		}

		// Test case to verify that shipment with invalid destination is rejected.
		TEST_METHOD(Test10InvalidDestination)
		{
			char destination[] = "8Z";
			bool result = isValidDestination(destination);

			// Check that the destination is invalid.
			Assert::IsFalse(result);
		}

		// Test case to verify that the best truck with the highest capacity is selected for shipment.
		TEST_METHOD(Test11BestTruckAvailable)
		{
			// Set weights and volumes to compare two trucks.
			trucks[0].actualWeight = 600;
			trucks[0].actualVolume = 2;

			trucks[1].actualWeight = 1000;
			trucks[1].actualVolume = 2;

			trucks[2].actualWeight = 300;
			trucks[2].actualVolume = 1;

			struct Truck* truck1 = &trucks[0];
			struct Truck* truck2 = &trucks[1];

			int result = findBetterCapacityTruck(truck1, truck2);

			// Check that the truck with lesser capacity is not selected.
			Assert::AreEqual(0, result);
		}

	};
}
