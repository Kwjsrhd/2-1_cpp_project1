#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateKoreanName() {
    vector<string> lastNames = { "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��"};
    vector<string> firstNames = { "�μ�", "����", "����", "����", "����", "����", "����", "����", "����", "����", "����"
                                  "�ÿ�", "����", "����", "�ǿ�", "����", "����", "����", "����", "����", "����", "�翵","����","����"};

    return lastNames[rand() % lastNames.size()] + firstNames[rand() % firstNames.size()];
}

string generateAddress() {
    vector<string> cities = {
        "����", "�λ�", "�뱸", "��õ", "����", "����", "���", "����",
        "����", "���", "����", "����", "û��", "õ��", "����", "����",
        "â��", "����", "����", "�Ȼ�", "�Ⱦ�", "������", "ȭ��", "����"
    };

    vector<string> districts = {
        "�߱�", "����", "����", "�ϱ�", "����", "������", "������", "���ı�", "������", "���ϱ�",
        "�ؿ�뱸", "������", "�޼���", "������", "�ȴޱ�", "���籸", "�ϻ굿��", "�д籸", "���ﱸ",
        "�����", "���ϱ�", "������", "���ر�", "������", "������"
    };

    return cities[rand() % cities.size()] + " " + districts[rand() % districts.size()] + " 123-45";
}

string generatePhoneNumber() {
    int second = rand() % 9000 + 1000;
    int third = rand() % 9000 + 1000;
    return "010-" + to_string(second) + "-" + to_string(third);
}

string generateHobby() {
    vector<string> hobbies = {
        "����", "��ȭ����", "�", "����", "�丮", "����", "�����Կ�", "���ǰ���", "���", "����",
        "�߰���", "�������", "��Ʃ�� ����", "������ Ÿ��", "�����", "�ϱ� ����", "������", "ī�� ����"
    };

    return hobbies[rand() % hobbies.size()];
}

string generatejungchi() {
    vector<string> jungchi = {
        "���ִ�", "������ ��", "�����Ŵ�", "���Ҽ�", "���ɾ���"
    };

    return jungchi[rand() % jungchi.size()];
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    ofstream file("client.csv");
    if (!file.is_open()) {
        cerr << "���� ���� ����!" << endl;
        return 1;
    }

    file << "id,name,age,address,cell phone,hobby,color\n";

    for (int i = 1; i <= 20000; ++i) {
        string name = generateKoreanName();
        int age = rand() % 60 + 20;
        string address = generateAddress();
        string phone = generatePhoneNumber();
        string hobby = generateHobby();
        string jungchi = generatejungchi();

        file << i << "," << name << "," << age << "," << address << "," << phone << "," << hobby << "," << jungchi << "\n";
    }

    file.close();
    cout << "client.csv ������ 20,000�� �����ͷ� �����Ǿ����ϴ�!" << endl;

    return 0;
}
