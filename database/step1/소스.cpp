#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string generateKoreanName() {
    vector<string> lastNames = { "김", "이", "박", "최", "정", "조", "강", "윤", "장", "임", "한", "오", "서", "신", "권", "강", "유"};
    vector<string> firstNames = { "민수", "서연", "지후", "지민", "하은", "도윤", "예은", "수빈", "현우", "지원", "혁준"
                                  "시우", "유진", "하윤", "건우", "예린", "소율", "지안", "태윤", "은우", "서준", "재영","민준","승현"};

    return lastNames[rand() % lastNames.size()] + firstNames[rand() % firstNames.size()];
}

string generateAddress() {
    vector<string> cities = {
        "서울", "부산", "대구", "인천", "광주", "대전", "울산", "세종",
        "수원", "고양", "성남", "용인", "청주", "천안", "전주", "포항",
        "창원", "김해", "평택", "안산", "안양", "남양주", "화성", "제주"
    };

    vector<string> districts = {
        "중구", "서구", "남구", "북구", "동구", "강남구", "강서구", "송파구", "성동구", "성북구",
        "해운대구", "수성구", "달서구", "유성구", "팔달구", "덕양구", "일산동구", "분당구", "기흥구",
        "흥덕구", "서북구", "덕진구", "진해구", "장유동", "신제주"
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
        "독서", "영화감상", "운동", "게임", "요리", "여행", "사진촬영", "음악감상", "등산", "수영",
        "뜨개질", "보드게임", "유튜브 보기", "자전거 타기", "드로잉", "일기 쓰기", "웹서핑", "카페 투어"
    };

    return hobbies[rand() % hobbies.size()];
}

string generatejungchi() {
    vector<string> jungchi = {
        "민주당", "국민의 힘", "개혁신당", "무소속", "관심없음"
    };

    return jungchi[rand() % jungchi.size()];
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    ofstream file("client.csv");
    if (!file.is_open()) {
        cerr << "파일 열기 실패!" << endl;
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
    cout << "client.csv 파일이 20,000명 데이터로 생성되었습니다!" << endl;

    return 0;
}
