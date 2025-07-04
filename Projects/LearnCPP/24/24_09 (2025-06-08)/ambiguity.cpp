// https://www.learncpp.com/cpp-tutorial/multiple-inheritance

#include <iostream>

class USBDevice {
private:
	long m_id {};

public:
	USBDevice(long id) : m_id { id } {}

	long getID() const {
		return m_id;
	}
};

class NetworkDevice {
private:
	long m_id {};

public:
	NetworkDevice(long id) : m_id { id } {}

	long getID() const {
		return m_id;
	}
};

class WirelessAdapter : public USBDevice, public NetworkDevice {
public:
	WirelessAdapter(long usbID, long networkID)
		: USBDevice { usbID }, NetworkDevice { networkID } {}
};

int main() {
	WirelessAdapter c54G { 5442, 181742 };
	// std::cout << c54G.getID();	// Which getID() do we call?

	std::cout << c54G.USBDevice::getID();

	return 0;
}