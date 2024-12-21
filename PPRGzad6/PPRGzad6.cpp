#include <iostream>
#include <string>
#include <vector>
using namespace std;

void zad6_1() {
	int n;
	while (true) {
		cout << "Podaj wartosc n: ";
		cin >> n;
		cout << endl;

		if (n >= 0) {
			break;
		}
		else {
			cout << "Sprobuj wpisac liczbe wieksza lub rowna 0." << endl;
		}
	}

	int ileLiczb = 0;
	for (int i = n; i >= 0; i--) {
		if (i % 5 == 0 && i % 3 != 0) {
			ileLiczb += 1;
		}
	}

	if (ileLiczb == 0) {
		cout << "Nie ma takich liczb naturalnych nie wiekszych od n, podzielnych przez 5 i niepodzielnych przez 3." << endl;
	}
	else {
		cout << "Istnieje " << ileLiczb << " liczb naturalnych nie wiekszych od n, podzielnych przez 5 i niepodzielnych przez 3." << endl;
	}
}

struct uczen {
	string imie;

	//0 - informatyka, 1 - matematyka, 2 - biologia, 3 - polski
	int oceny[4];
};

void zad6_2() {
	uczen uczniowie[6];
	string przedmioty[4] = { "[INFORMATYKA]", "[MATEMATYKA]", "[BIOLOGIA]", "[POLSKI]" };

	for (int i = 0; i < 6; i++) {
		cout << "\nPodaj imie ucznia nr " << i + 1 << ": ";
		cin >> uczniowie[i].imie;
		cout << endl;

		for (int j = 0; j < 4; j++) {
			while (true) {
				cout << "Podaj ocene ucznia nr " << i + 1 << " z " << przedmioty[j] << " (1-6): ";
				cin >> uczniowie[i].oceny[j];
				cout << endl;

				if (uczniowie[i].oceny[j] > 0 && uczniowie[i].oceny[j] <= 6) {
					break;
				}
				else {
					cout << "Ocena powinna miescic sie w zakresie od 1 do 6. Sprobuj jeszcze raz" << endl;
				}
			}
		}
	}

	int liczbaZapytan = 0;
	cout << "\nPodaj liczbe zapytan: ";
	cin >> liczbaZapytan;
	cout << endl;

	for (int i = 0; i < liczbaZapytan; i++) {
		int numerUcznia;
		int numerPrzedmiotu;

		while (true) {
			cout << "Podaj numer ucznia (1-6): ";
			cin >> numerUcznia;
			cout << endl;

			if (numerUcznia > 0 && numerUcznia <= 6) {
				break;
			}
			else {
				cout << "Numer ucznia ma byc liczba w zakresie od 1 do 6. Sprobuj jeszcze raz." << endl;
			}
		}

		while (true) {
			cout << "Podaj numer przedmiotu (0-3): ";
			cin >> numerPrzedmiotu;
			cout << endl;

			if (numerPrzedmiotu >= 0 && numerPrzedmiotu <= 3) {
				break;
			}
			else {
				cout << "Numer przedmiotu ma byc liczba w zakresie od 0 do 3. Sprobuj jeszcze raz." << endl;
			}
		}

		cout << "Uczen: " << uczniowie[numerUcznia - 1].imie << ", ocena z " << przedmioty[numerPrzedmiotu] << ": " << uczniowie[numerUcznia - 1].oceny[numerPrzedmiotu] << endl;
	}
}

struct student {
	string imie;
	string nazwisko;
	int numerIndeksu;
};

void zad6_3() {
	student s1, s2, s3, s4;

	s1.imie = "Jakub";
	s1.nazwisko = "Kowalski";
	s1.numerIndeksu = 300;

	s2.imie = "Natalia";
	s2.nazwisko = "Nowak";
	s2.numerIndeksu = 10000;

	s3.imie = "Sebastian";
	s3.nazwisko = "Kawka";
	s3.numerIndeksu = 41;

	s4.imie = "Stanislaw";
	s4.nazwisko = "Zeman";
	s4.numerIndeksu = 2;

	vector<student> studenci = { s1, s2, s3, s4 };

	cout << "Wektor przed posortowaniem:\n" << endl;
	for (int i = 0; i < studenci.size(); i++) {
		cout << studenci[i].imie << " " << studenci[i].nazwisko << " " << studenci[i].numerIndeksu << endl;
	}

	for (int i = 0; i < studenci.size(); i++) {
		for (int j = 1; j < studenci.size() - i; j++) {
			if (studenci[j].numerIndeksu < studenci[j - 1].numerIndeksu) {
				swap(studenci[j], studenci[j - 1]);
			}
		}
	}

	cout << "\nWektor po posortowaniu:\n" << endl;
	for (int i = 0; i < studenci.size(); i++) {
		cout << studenci[i].imie << " " << studenci[i].nazwisko << " " << studenci[i].numerIndeksu << endl;
	}
}

void zad6_4() {
	string tekst;
	int n;

	cout << "Podaj stringa: ";
	cin >> tekst;
	cout << endl;

	cout << "Podaj n: ";
	while (true) {
		cin >> n;
		if (n > 0) {
			break;
		}
		else {
			cout << "Nalezy podac liczbe wieksza od 0. Sprobuj jeszcze raz: ";
		}
	}

	string tekstKonkatenacja = tekst;
	for (int i = 1; i < n; i++) {
		tekstKonkatenacja += tekst;
	}
	tekst = tekstKonkatenacja;
	cout << "\n" << tekst << endl;
}

int main() {
	zad6_1();
	zad6_2();
	zad6_3();
	zad6_4();
	return 0;
}