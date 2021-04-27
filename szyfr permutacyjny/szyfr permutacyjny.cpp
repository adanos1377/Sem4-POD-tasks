


#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
#include <streambuf>
using namespace std;
int klucz[6] = { 3,6,1,4,2,5 };
char temp[6];

void kodowanie(string &napis)
{

	for (int i = 0; i < napis.length(); i+=6) 
	{
		for (int j = 0; j < 6; j++) {
			temp[j] = napis[i+klucz[j] - 1]; //każdą kolejną literą szyfru jest litera na pozycji wskazanej przez klucz
		}
		napis.replace(i, 6, temp);

	}
}
void dekodowanie(string &napis)
{


	for (int i = 0; i < napis.length(); i+=6)
	{
		for (int j = 0; j < 6; j++) {
			temp[klucz[j] - 1] = napis[j+i]; //każda kolejna litera szyfru trafia na pozycję wskazaną przez klucz
		}
		napis.replace(i, 6, temp);
	}
}
int main()
{
	fstream plik;
	fstream tekst;
	string napis;



	int czynnosc;
	string odp;
	//std::cout << "wybierz operacje" << std::endl;
	//std::cout << "0 = koniec programu" << std::endl;
	//std::cout << "1 = szyfruj tekst z konsoli" << std::endl;
	//std::cout << "2 = deszyfruj tekst z konsoli" << std::endl;
	//std::cout << "3 = szyfruj tekst z pliku" << std::endl;
	//std::cout << "4 = deszyfruj tekst z pliku" << std::endl;

	do {
	//	std::cin >> czynnosc;
	//	switch (czynnosc) {
	//	case 1: {
			cout << "Podaj napis do zaszyfrowania: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, napis);
			int a = napis.length() % 6;
			if (a > 0) {
				for (int i = 0; i < (6 - a); i++)
				{
					napis += "x";
				}
			}
			kodowanie(napis);
			cout << "Szyfrogram: ";
			cout <<napis << endl;
	//		cout << "zapisac do pliku?(y/n)" << endl;
	//		cin >> odp;
	//		if (odp == "y" || odp == "Y") {
	//			plik.open("szyfrogram.txt");
	//			if (plik.is_open()) {
	//				plik << napis;

	//			}
	//		}
	//		plik.close();
	//		cout << "zadanie wykonane, podaj nowe polecenie" << endl;
	//		break;
	//	}
	//	case 2: {
	//		if (napis.empty()) {
	//			cout << "podaj szyfr" << endl;
	//			cin >> napis;
	//		}
	//		int a = napis.length() % 6;
	//		if (a > 0) {
	//			for (int i = 0; i < (6 - a); i++)
	//			{
	//				napis += "x";
	//			}
	//		}
	//		cout << "szyfrogram: ";
	//		cout << napis << endl;
	//		//deszyfrujemy
	//		dekodowanie(napis);
	//		cout << "Tekst zdeszyfrowany: ";
	//		cout << napis << endl;
	//		cout << "zapisac do pliku?(y/n)" << endl;
	//		cin >> odp;
	//		if (odp == "y" || odp == "Y") {
	//			tekst.open("tekst.txt");
	//			if (plik.is_open()) {
	//				tekst << napis;

	//			}
	//		}
	//		tekst.close();
	//		cout << "zadanie wykonane, podaj nowe polecenie" << endl;
	//		break;
	//	}
	//	case 3: {//szyfruj z pliku
	//		tekst.open("tekst.txt");
	//		plik.open("szyfrogram.txt");
	//		if (plik.is_open()) {
	//			std::string napis((std::istreambuf_iterator<char>(tekst)),
	//			std::istreambuf_iterator<char>());
	//			tekst >> napis;
	//			int a = napis.length() % 6;
	//			if (a > 0) {
	//				for (int i = 0; i < (6 - a); i++)
	//				{
	//					napis += "x";
	//				}
	//			}
	//			cout << "Przed szyfrowaniem: ";
	//			cout << napis << endl;
	//			kodowanie(napis);
	//			cout << "Szyfrogram: ";
	//			cout << napis << endl;
	//			plik << napis;
	//		}
	//		cout << "zadanie wykonane, podaj nowe polecenie" << endl;
	//		tekst.close();
	//		plik.close();
	//		break;
	//	}
	//	case 4: {//deszyfruj z pliku
	//		plik.open("szyfrogram.txt");
	//		tekst.open("tekst.txt");
	//		if (plik.is_open()) {
	//			std::string napis((std::istreambuf_iterator<char>(plik)),
	//				std::istreambuf_iterator<char>());
	//			plik >> napis;
	//			int a = napis.length() % 6;
	//			if (a > 0) {
	//				for (int i = 0; i < (6 - a); i++)
	//				{
	//					napis += "x";
	//				}
	//			}
	//			cout << "Przed deszyfrowaniem: ";
	//			cout << napis << endl;
	//			dekodowanie(napis);
	//			cout << "odszyfrowany tekst: ";
	//			cout << napis << endl;
	//			//tekst << napis;
	//		}
	//		cout << "zadanie wykonane, podaj nowe polecenie" << endl;
	//		plik.close();
	//		tekst.close();
	//		break;
	//	}
	//	}
	} while (1);
	//std::cout << "Do zobaczenia" << std::endl;
	
	return 0;
}


