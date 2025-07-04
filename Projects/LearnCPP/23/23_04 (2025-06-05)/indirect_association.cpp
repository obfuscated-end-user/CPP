// https://www.learncpp.com/cpp-tutorial/association

#include <iostream>
#include <string>
#include <string_view>

class Car {
private:
	std::string m_name {};
	int m_id {};

public:
	Car(std::string_view name, int id)
		: m_name { name }, m_id { id } {}

	const std::string& getName() const {
		return m_name;
	}

	int getId() const {
		return m_id;
	}
};

// Our CarLot is essentially just a static array of Cars and a lookup function to retrieve them.
// Because it's static, we don't need to allocate an object of type CarLot to use it
namespace CarLot {
	Car carLot[4] { { "Prius", 4 }, { "Corolla", 17 }, { "Accord", 84 }, { "Matrix", 62 } };

	Car* getCar(int id) {
		for (auto& car : carLot) {
			if (car.getId() == id) {
				return &car;
			}
		}

		return nullptr;
	}
};

class Driver {
private:
	std::string m_name {};
	int m_carId {}; // we're associated with the Car by ID rather than pointer

public:
	Driver(std::string_view name, int carId)
		: m_name { name }, m_carId { carId } {}

	const std::string& getName() const {
		return m_name;
	}

	int getCarId() const {
		return m_carId;
	}
};

int main() {
	Driver d { "Franz", 17 };	// Franz is driving the car with ID 17

	Car* car { CarLot::getCar(d.getCarId()) };	// Get that car from the car lot

	if (car)
		std::cout << d.getName() << " is driving a " << car->getName() << '\n';
	else
		std::cout << d.getName() << "couldn't find his car\n";

	return 0;
}