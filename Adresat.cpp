#include "Adresat.h"

void Adresat::ustawId(int noweId)
{
    id = noweId;
}
void Adresat::ustawIdUzytkownika(int noweIdUzytkownika)
{
    idUzytkownika = noweIdUzytkownika;
}
void Adresat::ustawIdUsuwanegoAdresata(int noweIdUsuwanegoAdresata)
{
    idUsuwanegoAdresata = noweIdUsuwanegoAdresata;
}
void Adresat::ustawImie(string noweImie)
{
    imie = noweImie;
}
void Adresat::ustawNazwisko(string noweNazwisko)
{
    nazwisko = noweNazwisko;
}
void Adresat::ustawNumerTelefonu(string nowyNumerTelefonu)
{
    numerTelefonu = nowyNumerTelefonu;
}
void Adresat::ustawEmail(string nowyEmail)
{
    email = nowyEmail;
}
void Adresat::ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}


int Adresat::pobierzId()
{
    return id;
}
int Adresat::pobierzIdUzytkownika()
{
    return idUzytkownika;
}
int Adresat::pobierzIdUsuwanegoAdresata()
{
    return idUsuwanegoAdresata;
}
string Adresat::pobierzImie()
{
    return imie;
}
string Adresat::pobierzNazwisko()
{
    return nazwisko;
}
string Adresat::pobierzNumerTelefonu()
{
    return numerTelefonu;
}
string Adresat::pobierzEmail()
{
    return email;
}
string Adresat::pobierzAdres()
{
    return adres;
}

void wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:         " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
