#include <iostream>
#include <fstream>
#include <sstream>
#include <io.h>
using namespace std;


// class 선언
class Menus {

public:
	Menus();
	int display();
};

class Clients {
	int id;
	string name;
	string address;
	string tel;

public:
	Clients();
	void insertClient(int newId, string newName, string newTel, string newAddress);
	void deleteClient();
	int getId() { return id; }
	void displayClient();
	void saveToCSV(ofstream& file);
	void loadFromCSV(const string& line);
};


// class 구현
Menus::Menus() {}

int Menus::display() {

	int selection;

	cout << "menu" << endl;
	cout << "--------------------------------" << endl;
	cout << "1. insert clients" << endl;
	cout << "2. delete clients" << endl;
	cout << "3. display clients" << endl;
	cout << "4. list clients" << endl;
	cout << "--------------------------------" << endl;
	cout << "please input selections (1~4); ";

	cin >> selection;

	return selection;
}

Clients::Clients() { id = 0; }



void Clients::insertClient(int newId, string newName, string newTel, string newAddress) {
	this->id = newId;
	this->name = newName;
	this->tel = newTel;
	this->address = newAddress;

}

void Clients::deleteClient() {
	id = -1;
	name = "";
	tel = "";
	address = "";
}

void Clients::displayClient() {
	if (id == -1) return;

	cout << "client id; " << id << ", name: " << name;
	cout << ", client tel; " << tel << ", address; " << address << endl;
}

//csv
void Clients::saveToCSV(ofstream& file) {
	file << id << "," << name << "," << tel << "," << address << endl;
}

void Clients::loadFromCSV(const string& line) {
	stringstream ss(line);
	string temp;

	getline(ss, temp, ',');
	id = stoi(temp);
	getline(ss, name, ',');
	getline(ss, tel, ',');
	getline(ss, address, ',');
}

bool fileExists(const string& filename) {
	ifstream file(filename);
	return file.good();
}







// main
int main() {


	Menus menu;
	int selection = menu.display();
	int id;
	int exist = _access("clients.csv", 0);
	string name, tel, address;
	const int maxnumClient = 2;
	Clients client[maxnumClient];

	if (selection == 1) {
		for (int i = 0; i < maxnumClient; i++) {
			cout << "plz input id; ";
			cin >> id;
			cout << "plz input name; ";
			cin >> name;
			cout << "plz input tel; ";
			cin >> tel;
			cout << "plz input address; ";
			cin >> address;

			client[i].insertClient(id, name, tel, address);
		}




		cout << "\n ------ hello,	client display ------ \n";

		for (int i = 0; i < maxnumClient; i++) {
			client[i].displayClient();
		}

		//csv 파일 저장
		ofstream file("clients.csv", ios::app);
		if (exist == -1) {
			file << "id, name, tel, address\n";
		}
		if (file.is_open()) {
			for (int i = 0; i < maxnumClient; i++) {
				client[i].saveToCSV(file);
			}
			file.close();
		}
	}


	else if (selection == 2) {
		int deleteId;
		cout << "삭제할 클라이언트 ID를 입력하세요: ";
		cin >> deleteId;

		ifstream infile("clients.csv");
		ofstream tempFile("temp.csv");

		string line;
		bool found = false;

		while (getline(infile, line)) {
			Clients tempClient;
			tempClient.loadFromCSV(line);

			if (tempClient.getId() != deleteId) {
				tempClient.saveToCSV(tempFile);  // 삭제 대상이 아니면 저장
			}
			else {
				found = true;  // 삭제할 항목 찾음
			}
		}

		infile.close();
		tempFile.close();

		remove("clients.csv");
		rename("temp.csv", "clients.csv");

	}
}