// https://www.learncpp.com/cpp-tutorial/association

#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>

// since Doctor and Patient have circular dependency, forward declare Patient
class Patient;

class Doctor {
private:
    std::string m_name;
    std::vector<std::reference_wrapper<const Patient>> m_patient;

public:
    Doctor(const std::string& name): m_name{name} {}

    void addPatient(Patient& patient);

    // Patient needs to be defined at this point
    friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

    const std::string& getName() const {
        return m_name;
    }
};

class Patient {
private:
    std::string m_name;
    std::vector<std::reference_wrapper<const Doctor>> m_doctor; // Doctor defined above so we can do this here

    // use Doctor::addPatient() instead
    void addDoctor(const Doctor& doctor) {
        m_doctor.push_back(doctor);
    }

public:
    Patient(const std::string& name): m_name{name} {}

    friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

    const std::string& getName() const {
        return m_name;
    }

    // friend so it can acccess the privatec function Patient::addDoctor()
    friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient) {
    m_patient.push_back(patient);
    // patient will add this doctor
    patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor) {
    if (doctor.m_patient.empty()) {
        out << doctor.m_name << " has no patients right now.";
        return out;
    }
    out << doctor.m_name << " is seeing patients: ";
    for (const auto& patient : doctor.m_patient)
        out << patient.get().getName() << ' ';
    return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient) {
    if (patient.m_doctor.empty()) {
        out << patient.getName() << " has no doctors right now";
        return out;
    }
    out << patient.m_name << " is seeing doctors: ";
    for (const auto& doctor : patient.m_doctor)
        out << doctor.get().getName() << ' ';
    return out;
}

int main() {
    Patient dave {"Dave"};
    Patient frank {"Frank"};
    Patient betsy {"Betsy"};

    Doctor james {"James"};
    Doctor scott {"Scott"};

    james.addPatient(dave);

    scott.addPatient(dave);
    scott.addPatient(betsy);

    std::cout << james << '\n';
    std::cout << scott << '\n';
    std::cout << dave << '\n';
    std::cout << frank << '\n';
    std::cout << betsy << '\n';

    return 0;
}