#include <iostream>
#include <fstream>

using namespace std;


int main() {

	ofstream file("testdb.csv");


	file << "number, id, name, phone\n";
	file << 1 << "," << 2323 << "," << "cherlhee" << "," << "010-3333-4444" << endl;
	file << 2 << "," << 1111 << "," << "jcradar" << "," << "010-1111-2222" << endl;



	file.close();

	return 0;
}