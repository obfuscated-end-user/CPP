// https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes

#include <cmath>
#include <string_view>

class IErrorLog {
public:
	virtual bool openLog(std::string_view filename) = 0;
	virtual bool closeLog() = 0;

	virtual bool writeError(std::string_view errorMessage) = 0;

	virtual ~IErrorLog() {} // make a virtual destructor in case we delete an IErrorLog pointer, so the proper derived destructor is called
};

double mySqrt(double value, IErrorLog& log) {
	if (value < 0.0) {
		log.writeError("Tried to take square root of value less than 0");
		return 0.0;
	}

	return std::sqrt(value);
}