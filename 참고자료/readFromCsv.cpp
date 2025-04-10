#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("client.csv");
    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    string line;
    getline(file, line);  // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, age, address, phone, hobby;

        // Read each field (comma-separated)
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, age, ',');
        getline(ss, address, ',');
        getline(ss, phone, ',');
        getline(ss, hobby, ',');

        // Output the read data
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age
            << ", Address: " << address << ", Phone: " << phone
            << ", Hobby: " << hobby << endl;
    }

    file.close();
    return 0;
}
