#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
int studentCounter = 0, lessonCounter = 0;
vector <class Student> studentList;
vector <class Lesson> lessonList;

class Lesson {
private:
	int note;
	string lessonsName;
	string lessonsCode;
	int credit;
public:
	Lesson(string name, string code, int credit) : credit(credit), lessonsCode(code), lessonsName(name) {}
	int noteGetter() {
		return note;
	}
	string lessonsNameGetter() {
		return lessonsName;
	}
	string lessonsCodeGetter() {
		return lessonsCode;
	}
	int creditGetter() {
		return credit;
	}
	void showInfo() {
		cout << endl << "Dersin bilgileri : " << endl << endl;
		cout << "Dersin ismi:" << lessonsName << endl;
		cout << "Dersin Kodu:" << lessonsCode << endl;
		cout << "Dersin kredisi:" << credit << endl;

	}
	void setNote(int note) {
		this->note = note;
	}

};
class Student {
private:
	string studentName;
	int studentAge;
	vector <class Lesson> studentLessons;
	int lessonsCounter = 0;
	double OBP = 0;
public:
	Student(string name, int age) : studentName(name), studentAge(age) {}
	void showInfo() {
		cout << endl << "Ogrencinin bilgileri:" << endl;
		cout << "Ogrencinin ismi:" << studentName << endl;
		cout << "Ogrencinin yasi:" << studentAge << endl;
		cout << "Ogrencinin Notlari:" << endl << endl;
		for (int i = 0; i < lessonsCounter; i++) {
			cout << studentLessons.at(i).lessonsNameGetter() << " " << studentLessons.at(i).noteGetter() << endl;
		}
		calculateObp();
		cout << "Ogrencinin Ortalama basari Puani:" << OBP << endl;
		if (OBP < 50) {
			cout << "Ogrenci sinifta kaldi" << endl;
		}
		else if (OBP < 64 && OBP >= 50) {
			cout << "Ogrenci Sartli gecti" << endl;
		}
		else if (OBP >= 65) {
			cout << "Ogrenci siniftan gecti" << endl;
		}

	}
	void calculateObp() {
		double totalNotes = 0, totalCredit = 0;
		for (int i = 0; i < lessonsCounter; i++) {
			totalCredit += studentLessons.at(i).creditGetter();
			totalNotes += (studentLessons.at(i).noteGetter()) * (studentLessons.at(i).creditGetter());
		}
		if (totalNotes > 0 && totalCredit > 0) {
			OBP = (totalNotes / totalCredit);
		}
	}
	void addStudentsLessons(class Lesson &newLesson) {
		studentLessons.push_back(newLesson);
		lessonsCounter++;
	}
	string studentNameGetter() {
		return studentName;
	}
	void setNote(int note,int lessonsNumber) {
		lessonList.at(lessonsNumber).setNote(note);

	}
};
int Input();
void Engine();

int main(){
	Engine();
}

int Input() {
	int input;
	cout << "************* Hosgeldiniz ! *************" << endl << endl;
	cout << "Ogrenci eklemek icin 1;" << endl;
	cout << "ders eklemek icin 2;" << endl;
	cout << "Ogrenci bilgilerini listelemek icin 3;" << endl;
	cout << "Ders Bilgilerini listelemek icin 4;" << endl;
	cout << "Ogrenciye ders eklemek icin 5;" << endl;
	cout << "cikmak icin 6'yi tuslayiniz:";
	cin >> input;
	system("CLS");
	return input;
}
void Engine() {
	int x = 0;
	while (x != 6) {
		x = Input();
		if (x == 1) {
			string studentName;
			int studentAge;
			cout << "Ogrencinin ismini giriniz:";
			cin.ignore();
			getline(cin, studentName);
			cout << "Ogrencinin Yasini giriniz:";
			cin >> studentAge;
			Student newStudent(studentName, studentAge);
			studentList.push_back(newStudent);
			studentCounter++;
			cout << endl << "Ogrenci basariyla eklendi" << endl;

		}
		else if (x == 2) {
			string lessonName, lessonCode;
			int lessonCredit;
			cout << "Dersin ismini giriniz:";
			cin.ignore();
			getline(cin, lessonName);
			cout << "ders kodunu giriniz:";
			cin >> lessonCode;
			cout << "Dersin kredi puanini giriniz:";
			cin >> lessonCredit;
			Lesson newLesson(lessonName, lessonCode, lessonCredit);
			lessonList.push_back(newLesson);
			lessonCounter++;
			cout << endl << "Ders basariyla eklendi" << endl;
		}
		else if (x == 3) {
			for (int i = 0; i < studentCounter; i++) {
				studentList.at(i).showInfo();
			}

		}
		else if (x == 4) {
			for (int i = 0; i < lessonCounter; i++) {
				lessonList.at(i).showInfo();
			}
		}
		else if (x == 5) {
			string code,studentsName;
			int note;
			int i, j;
			int check = 0;
			cout << "Hangi Ogrenciye ders eklemek istiyorsunuz:";
			cin.ignore();
			getline(cin, studentsName);
			for (j = 0; j < studentCounter; j++) {
				if (studentList.at(j).studentNameGetter() == studentsName) {
					check++;
					break;
				}
			}
			if (check == 0) {
				cout << "Boyle bir ogrenci yoktur!" << endl;
				return Engine();
			}
			else {
				cout << "Ogrenciye eklemek istediginiz dersin kodunu giriniz:";
				cin >> code;
				for (i = 0; i < lessonCounter; i++) {
					if (lessonList.at(i).lessonsCodeGetter() == code) {
						check++;
						break;
					}
				}
				if (check == 1) {
					cout << "Boyle bir ders yoktur !" << endl;
					return Engine();
				}
				else {
					cout << "Ogrencinin dersten aldigi notu giriniz:";
					cin >> note;
					studentList.at(j).setNote(note, i);
					studentList.at(j).addStudentsLessons(lessonList.at(i));
				}
			}
		}
		else if (x != 6) {


		}
	}

}
