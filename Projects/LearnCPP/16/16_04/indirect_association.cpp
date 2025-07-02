// https://www.learncpp.com/cpp-tutorial/association

#include <iostream>
#include <string>

class Car {
private:
	std::string m_name;
	int m_id;

public:
	Car(const std::string& name, int id): m_name { name }, m_id { id } {}

	const std::string& getName() const {
		return m_name;
	}

	int getId() const {
		return m_id;
	}
};

class CarLot {
private:
	// static (belongs to this class, not the instance) array of 4 Cars
	static Car s_carLot[4];

public:
	CarLot() = delete;

	static Car* getCar(int id) {
		for (int count = 0; count < 4; ++count) {
			if (s_carLot[count].getId() == id)
				return &(s_carLot[count]);
		}
		return nullptr;
	}
};

Car CarLot::s_carLot[4] {
	{ "Prius", 4 },
	{ "Corolla", 17 },
	{ "Accord", 84 },
	{ "Matrix", 62 }
};

class Driver {
private:
	std::string m_name;
	int m_carId;

public:
	Driver(const std::string& name, int carId): m_name { name }, m_carId { carId } {}

	const std::string& getName() const {
		return m_name;
	}

	int getCardId() const {
		return m_carId;
	}
};

int main() {
	Driver d { "Franz", 17 };
	Car* car { CarLot::getCar(d.getCardId()) };

	if (car)
		std::cout << d.getName() << " is driving a " << car->getName() << '\n';
	else
		std::cout << d.getName() << " couldn't find his car\n";

	return 0;
}