#include <iostream>
#include <fstream>
#include <sstream>
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
	void displayClient();
	void saveToCSV(ofstream& file);

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

Clients::Clients() {}



void Clients::insertClient(int newId, string newName, string newTel, string newAddress) {
	this->id = newId;
	this->name = newName;
	this->tel = newTel;
	this->address = newAddress;

}

void Clients::displayClient() {
	cout << "client id; " << id << ", name: " << name;
	cout << ", client tel; " << tel << ", address; " << address << endl;
}


void Clients::saveToCSV(ofstream& file) {
	file << id << "," << name << "," << tel << "," << address << endl;
}

bool fileExists(const string& filename) {
	ifstream file(filename);
	return file.good();
}







// main
int main() {


	Menus menu;

		if(menu.display()==1) {
			int id;
			string name, tel, address;
			const int maxnumClient = 2;


			Clients client[maxnumClient];

			string filename = "clients.csv";
			ofstream outFile;
			bool isNewFile = !fileExists(filename);  // Check if the file exists

			outFile.open(filename, ios::app);
			if (!outFile) {
				cerr << "Error opening file for writing!" << endl;
				return 1;
			}
			if (isNewFile) {
				outFile << "ID,Name,Tel,Address\n";
			}



			ofstream fout;
			fout.open("db.txt");
			if (!fout) {
				cout << "file opening of db.txt failed;";
			}



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

				client[i].saveToCSV(outFile);  // Append new client data
				fout << id << '\n';
				fout << name << endl;
				fout << tel << endl;
				fout << address << endl;
			}




			cout << "\n ------ hello,	client display ------ \n";

			for (int i = 0; i < maxnumClient; i++) {
				client[i].displayClient();
			}
			outFile.close();
			fout.close();
		}



	return 0;
}
