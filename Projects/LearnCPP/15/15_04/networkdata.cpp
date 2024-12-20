// https://www.learncpp.com/cpp-tutorial/introduction-to-destructors

#include <string>
#include <string_view>

// This example won't compile because it is (intentionally) incomplete
class NetworkData {
private:
    std::string m_serverName {};
    DataStore m_dataQueue {};

public:
    NetworkData(std::string_view serverName) : m_serverName { serverName } {}

    ~NetworkData() {
        sendData(); // make sure all data is sent before object is destroyed
    }

    void addData(std::string_view data) {
        m_dataQueue.add(data);
    }

    void sendData() {
        // connect to server
        // send all data
        // clear data
    }
};

int main() {
    NetworkData n("someipAdress");

    n.addData("somedata1");
    n.addData("somedata2");

    return 0;
}