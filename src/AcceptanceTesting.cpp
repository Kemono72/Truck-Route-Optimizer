#include "pch.h"
#include "CppUnitTest.h"
#include "finder_r.h"
#include "mapping_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AcceptanceTesting
{
	TEST_CLASS(AcceptanceTesting)
	{
	public:
		struct Truck trucks[3];
		struct Map baseMap;
		struct Route blueRoute, greenRoute, yellowRoute;

		// Initialize test data before each test
		TEST_METHOD_INITIALIZE(Setup)
		{
			trucks[0] = { BLUE, 0, 0, NULL, 0 };
			trucks[1] = { GREEN, 0, 0, NULL, 0 };
			trucks[2] = { YELLOW, 0, 0, NULL, 0 };
			baseMap = populateMap();
			blueRoute = getBlueRoute();
			greenRoute = getGreenRoute();
			yellowRoute = getYellowRoute();
		}

		// Test blue truck selection with no diversion
		TEST_METHOD(TestBlueTruckWithNoDiversion)
		{
			int weight = 150;
			int size = 1;
			char destination[] = "10J";

			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			Assert::IsNotNull(truckChoice);
			Assert::AreEqual((int)BLUE, (int)truckChoice->truckSymbol);
			Assert::AreEqual(weight, truckChoice->actualWeight);
			Assert::AreEqual(size, truckChoice->actualVolume);
			Assert::AreEqual(0, truckChoice->shipments[0].divertedRoute.numPoints);
		}

		// Test blue truck selection with diversion
		TEST_METHOD(TestBlueTruckWithDiversion)
		{
			int weight = 450;
			int size = 3;
			char destination[] = "11M";

			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			Assert::IsNotNull(truckChoice);
			Assert::AreEqual((int)BLUE, (int)truckChoice->truckSymbol);
			Assert::IsTrue(truckChoice->shipments[0].divertedRoute.numPoints > 0);
		}

		// Test green truck selection with no diversion
		TEST_METHOD(TestGreenTruckWithNoDiversion)
		{
			int weight = 300;
			int size = 1;
			char destination[] = "5L";

			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			Assert::IsNotNull(truckChoice);
			Assert::AreEqual((int)GREEN, (int)truckChoice->truckSymbol);
			Assert::AreEqual(weight, truckChoice->actualWeight);
			Assert::AreEqual(size, truckChoice->actualVolume);
			Assert::AreEqual(0, truckChoice->shipments[0].divertedRoute.numPoints);
		}

		// Test green truck selection with diversion
		TEST_METHOD(TestGreenTruckWithDiversion)
		{
			int weight = 600;
			int size = 5;
			char destination[] = "8V";

			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			Assert::IsNotNull(truckChoice);
			Assert::AreEqual((int)GREEN, (int)truckChoice->truckSymbol);
			Assert::IsTrue(truckChoice->shipments[0].divertedRoute.numPoints > 0);
		}

		// Test yellow truck selection with diversion
		TEST_METHOD(TestYellowTruckWithDiversion)
		{
			int weight = 350;
			int size = 5;
			char destination[] = "25F";

			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			Assert::IsNotNull(truckChoice);
			Assert::AreEqual((int)YELLOW, (int)truckChoice->truckSymbol);
			Assert::IsTrue(truckChoice->shipments[0].divertedRoute.numPoints > 0);
		}

		// Test no truck available for the given shipment
		TEST_METHOD(TestNoTruckAvailable)
		{
			trucks[0].actualWeight = 2400;
			trucks[0].actualVolume = 0;
			trucks[1].actualWeight = 0;
			trucks[1].actualVolume = 98;
			trucks[2].actualWeight = 2400;
			trucks[2].actualVolume = 0;

			int weight = 600;
			int size = 4;
			char destination[] = "18G";

			struct Truck* truckChoice = findBestTruckShipment(trucks, weight, size, destination);

			Assert::IsNull(truckChoice);
		}

		// Test invalid shipment weight
		TEST_METHOD(TestInvalidWeight)
		{
			int weight = 2600;
			int size = 5;
			int result = isValidShipment(weight, size);

			Assert::IsFalse(result);
		}

		// Test invalid shipment size
		TEST_METHOD(TestInvalidSize)
		{
			int weight = 400;
			int size = 10;
			int result = isValidShipment(weight, size);

			Assert::IsFalse(result);
		}

		// Test invalid destination
		TEST_METHOD(TestInvalidDestination)
		{
			char destination[] = "30Z";
			int result = isValidDestination(destination);

			Assert::IsFalse(result);
		}

		// Test best truck available for the given shipment
		TEST_METHOD(TestBestTruckAvailable)
		{
			trucks[0].actualWeight = 700;
			trucks[0].actualVolume = 3;
			trucks[1].actualWeight = 1200;
			trucks[1].actualVolume = 4;
			trucks[2].actualWeight = 600;
			trucks[2].actualVolume = 2;

			struct Truck* truck1 = &trucks[0];
			struct Truck* truck2 = &trucks[2];

			int result = findBetterCapacityTruck(truck1, truck2);

			Assert::AreEqual(0, result);
		}
	};
}
