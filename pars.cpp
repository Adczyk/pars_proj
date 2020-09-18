#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>

using namespace std;

void wgranie_pliku(ifstream&);
char spr_pliku(ifstream&);
vector<string> wyszukanie_logu_keyword(string, ifstream&);
vector<string> wyszukanie_logu_tag(string, ifstream&);
void zapis_pliku(vector<string>);

int main(int argc, char **argv)
{
	char menu_val;
	ifstream file;
	vector<string> find_line;

	cout << "*** program do parsowania logow ***";

	while (1)
	{
		cout << endl << "wybierz co chcesz zrobic:" << endl
			 << "1. wgraj plik z logami" << endl
			 << "2. wyszukaj log z pomoca keyworda" << endl
			 << "3. wyszukaj log za pomoca tagu" << endl
			 << "4. zapisz log do pliku" << endl
			 << "5. wyjdz z programu" << endl;

		cin >> menu_val;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

			switch (menu_val)
			{
				case '1':
				{
					char t = spr_pliku(file);
					if (t != 'n')
					wgranie_pliku(file);
					break;
				}
				case '2':
				{
					string search_words = "";
					cout << "wprowadz szukane slowa, oddzielajac je ';':" << endl;

					getline(cin, search_words);

					find_line = wyszukanie_logu_keyword(search_words,file);


					char znak;
					cout << endl << "Czy chcesz zapisac logi do pliku? [t/n]" << endl;
					cin >> znak;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (znak == 't' || znak == 'T') zapis_pliku(find_line);
					else if (znak == 'n' || znak == 'N') break;
					else cout << "znak nierozpoznany" << endl;

					break;
				}
				case '3':
				{
					string search_words = "";
					cout << "wprowadz szukany tag a nastepnie keyword np. [ala] kot, tagi oddzielaj poprzez: ';':" << endl;

					getline(cin, search_words);

					find_line = wyszukanie_logu_tag(search_words,file);

					char znak;
					cout << endl << "Czy chcesz zapisac logi do pliku? [t/n]" << endl;
					cin >> znak;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					if (znak == 't' || znak == 'T') zapis_pliku(find_line);
					else if (znak == 'n' || znak == 'N') break;
					else cout << "znak nierozpoznany" << endl;

					break;
				}
				case '4':
				{
					zapis_pliku(find_line);
					break;
				}
				case '5':
				{
					file.close();
					return(0);
				}
				default:
				{
					cout << endl << "ta wartosc nie jest obslugiwana" << endl;
				}
			}
	}

	return EXIT_SUCCESS;

}


void wgranie_pliku(ifstream& file)
{
	while(1)
	{
		string sciezka;
		cout << endl << "podaj nazwe pliku, plik musi znajdowac sie w tym samym folderze co program: " << endl;
		cin >> sciezka;

		file.open(sciezka, ios::out);
		if (file.is_open())
		{
			cout << endl << "plik wgrany pomyslnie!" << endl << endl;
			return;
		}
		else
		{
			cout << endl << "nie udalo sie wgrac pliku!" << endl << endl;
				cout << "Czy chcesz ponownie sprobowac wgrac plik? [t/n]" << endl;
				char val;
				cin >> val;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			switch(val)
			{
			case 't':
				{
					break;
				}
			case 'n':
				{
					return;
				}
			default:
				{
					cout << "nierozpoznana wartosc prosze wybrac 't' lub 'n'" << endl;
					continue;
				}
			}
		}
	}
}

char spr_pliku (ifstream& file) // sprawdza czy jakiœ plik by³ ju¿ otwarty, upewnia siê czy podmienic na nowy
{
	char ans;
	if (file.is_open())
		{
			bool i = true;
			while (i)
			{
				cout << endl << "czy chcesz zamienic plik na nowy? [t/n]" << endl;
				cin >> ans;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				switch (ans)
				{
				case 't':
					file.close();
					cout << endl << "poprzedni plik zostal zamkniety" << endl;
					i = false;
					break;
				case 'n':
					cout << endl << "powrot do menu" << endl << endl;
					return 'n';
				default:
					cout << endl << "niepoprawny znak" << endl;
				}
			}
		}
	return ans;
}

vector<string> wyszukanie_logu_keyword(string search_words, ifstream& file)
{
	vector<string> find_line;
	string line = "", word = "";
	bool found = false;
	int counter = 0;

	while(getline(file, line))
	{
		counter ++;
		istringstream s1(search_words);
		found = false;

		while(!found && getline(s1,word,';'))
		{
			if(line.find(word) != string::npos)
			{
			line = to_string(counter) + " " + line;
			find_line.push_back(line);
			cout << endl << line << endl;
			found = true;
			}
		}
	}

	file.clear();
	file.seekg(0, ios::beg);
	return find_line;

}

vector<string> wyszukanie_logu_tag(string search_words, ifstream& file)
{
	vector<string> find_line;
	string line = "", word = "", word2 = "";
	int counter = 0;
	istringstream s1(search_words);
	vector<string> search_vec, search_vec2;
	int i = 0;
	while(getline(s1,word,';'))
	{
		istringstream s2(word);
		getline(s2,word2,']');
		word2.erase(word2.begin(), find(word2.begin(), word2.end(), '[')+1);
		word.erase(word.begin(), find(word.begin(), word.end(), ']')+1);
		// nie wiem dlaczego, ale tak dzia³a, inaczej nie dzia³a, wysypuje program
		search_vec.push_back(word2);
		search_vec.push_back(word);

		search_vec2.push_back(word);
		search_vec2.push_back(word2);
		// ***
		i++;
	}

	while(getline(file, line))
	{
		counter ++;
		for (int j=0; j<=i; j++)
		{
			if(line.find(search_vec[j]) != string::npos)
			{
				if(line.find(search_vec2[j]) != string::npos)
				{
					line = to_string(counter) + " " + line;
					find_line.push_back(line);
					cout << endl << line;
					break;
				}

			}
		}
	}

	file.clear();
	file.seekg(0, ios::beg);
	return find_line;
}

void zapis_pliku(vector<string> find_line)
{
	char odp;

	string nazwa_pliku;
	cout << endl << "podaj nazwe pliku:" << endl;
	cin >> nazwa_pliku;

	ofstream new_file;
	new_file.open(nazwa_pliku+".txt");

	if(new_file.is_open())
	{

		cout << "Pozostawic stara numeracje czy przeiterowac logi od poczatku?" << endl
			 << "p - pozostawic stara numeracje" << endl
			 << "n - prziterowac od nowa" << endl;

		cin >> odp;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (odp)
		{
		case 'p':
			for (unsigned int i=0; i<find_line.size(); i++)
			{
				new_file << find_line[i] << endl;
			}

			cout << endl << "plik utworzony pomyslnie!" << endl;
			break;

		case 'n':

			for (unsigned int i=0; i<find_line.size(); i++)
			{
				find_line[i].erase(find_line[i].begin(), find(find_line[i].begin(), find_line[i].end(), ' '));
				new_file << i+1 << find_line[i] << endl;
			}

			cout << endl << "plik utworzony pomyslnie!" << endl;
			break;
		}
	}
	else
	{
		cout << endl << "nie udalo sie zapisac logow";
		return;
	}

	new_file.close();
}
