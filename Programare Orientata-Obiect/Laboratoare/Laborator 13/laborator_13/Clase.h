#pragma once

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <filesystem>
#include <functional>


using namespace std;


class Contact
{
protected:
	string nume;

public:
	Contact() : nume("Ion Sacal") {}

	string GetNume() 
	{
		return nume;
	}
	virtual string GetTip() = 0;
};


class Prieten : public Contact
{
	string data_nastere;
	string adresa;
	string nr_telefon;

public:
	Prieten() : data_nastere("12-04-1994"), adresa("Iasi"), nr_telefon("0752789214") { nume = "John Revolt"; }

	string GetAdresa()
	{
		return adresa;
	}
	string GetDataNastere()
	{
		return data_nastere;
	}
	string GetNrTelefon()
	{
		return nr_telefon;
	}
	string GetTip() override
	{
		return "Prieten";
	}
};

class Cunoscut : public Contact
{
	string nr_telefon;

public:
	Cunoscut() : nr_telefon("0233735637") { nume = "Carl Sagan"; }

	string GetNrTelefon()
	{
		return nr_telefon;
	}
	string GetTip() override
	{
		return "Cunoscut";
	}
};

class Coleg : public Contact
{
	string serviciu;
	string adresa;
	string nr_telefon;

public:
	Coleg() : serviciu("Programator"), adresa("Roman"), nr_telefon("0763199042") { nume = "James Webb"; }

	string GetServiciu()
	{
		return serviciu;
	}
	string GetNrTelefon()
	{
		return nr_telefon;
	}
	string GetAdresa()
	{
		return adresa;
	}

	string GetTip() override
	{
		return "Coleg";
	}
};


class Agenda
{
	int nr;
	vector<Contact*> contacte;

public:
	Agenda() : nr(0) {}

	Contact* Cauta(string nume)
	{
		int gasit = 0;
		for (int i = 0; i < nr && !gasit; i++)
		{
			if (contacte[i]->GetNume() == nume)
			{
				gasit = 1;
				return contacte[i];
			}
		}
	}

	vector<Contact*> GetPrieteni()
	{
		vector<Contact*> prieteni;
		

		return prieteni;
	}

	void Sterge(string nume)
	{
		int k = 0;
		for (auto i = contacte.begin(); i != contacte.end(); i++)
		{
			if ((*i)->GetNume() == nume)
			{
				contacte.erase(contacte.begin() + k);
				nr--;
				break;
			}
			k++;
		}

		//for (int i = 0; i < nr - 1; i++)
		//{
		//	if (contacte[i]->GetNume() == nume)
		//	{
		//		for (int j = i + 1; j < nr; j++)
		//		{
		//			contacte[j - 1] = contacte[j];
		//		}
		//		nr--;
		//	}
		//}
	}

	void adauga(Contact* c)
	{
		contacte.push_back(c);
		nr++;
	}

	void Afiseaza()
	{
		//for (auto it = contacte.begin(); it != contacte.end(); it++)
		//{
		//	cout << (*it)->GetNume() << ' ';
		//}

		for (int i = 0; i < nr; i++)
		{
			cout << contacte[i]->GetNume() << ' ';
		}
		cout << "\n";
	}

	void Save(const char* filename)
	{
		fstream fisier;
		fisier.open(filename, ios::out);

		for (auto it = contacte.begin(); it != contacte.end(); it++)
		{
			fisier << (*it)->GetNume() << "   " << (*it)->GetTip() << '\n';
		}
	}

};