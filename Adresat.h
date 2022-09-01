#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id;
    int idUzytkownika;
    int idUsuwanegoAdresata;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:
    Adresat(int id=0, int idUzytkownika=0, int idUsuwanegoAdresata=0, string imie="", string nazwisko="", string numerTelefonu="", string email="", string adres="")
    {
        this->id = id;
        this->idUzytkownika = idUzytkownika;
        this->idUsuwanegoAdresata = idUsuwanegoAdresata;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }
    void ustawId(int noweId);
    void ustawIdUzytkownika(int noweIdUzytkownika);
    void ustawIdUsuwanegoAdresata(int noweIdUsuwanegoAdresata);
    void ustawImie(string noweImie);
    void ustawNazwisko(string noweNazwisko);
    void ustawNumerTelefonu(string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres(string nowyAdres);

    int pobierzId();
    int pobierzIdUzytkownika();
    int pobierzIdUsuwanegoAdresata();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

    void wyswietlDaneAdresata(Adresat adresat);
};

#endif
