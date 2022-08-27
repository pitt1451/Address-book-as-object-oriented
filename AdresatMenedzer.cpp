#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Adresat zostal dodany" << endl;
    else
        cout << "Nie udalo sie dodac nowego adresata do pliku" << endl;
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    string daneOstaniegoAdresataWPliku = "";
    Adresat adresat;
    cout << "ID przed inkrementacja: " << adresat.pobierzId() << endl;
    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    cout << "ID po inkrementacji: " << adresat.pobierzId() << endl;
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    string imie, nazwisko, numerTelefonu, email, adres;

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> ADRESACI <<<" << endl;
        cout << "----------------" << endl;
        for (int i=0; i < (int) adresaci.size(); i++)
        {
            cout << adresaci[i].pobierzImie() << endl;
            cout << adresaci[i].pobierzNazwisko() << endl;
            cout << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << adresaci[i].pobierzEmail() << endl;
            cout << adresaci[i].pobierzAdres() << endl << endl;
        }
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW PO IMIENIU <<<" << endl << endl;
        cout << "Podaj imie: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (int i=0; i < (int) adresaci.size(); i++)
        {
            if ( imiePoszukiwanegoAdresata == adresaci[i].pobierzImie())
            {
                cout << adresaci[i].pobierzImie() << endl;
                cout << adresaci[i].pobierzNazwisko() << endl;
                cout << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << adresaci[i].pobierzEmail() << endl;
                cout << adresaci[i].pobierzAdres() << endl << endl;
            }
        }
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata = "";
    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW PO NAZWISKU <<<" << endl << endl;
        cout << "Podaj nazwisko: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (int i=0; i < (int) adresaci.size(); i++)
        {
            if ( nazwiskoPoszukiwanegoAdresata == adresaci[i].pobierzNazwisko())
            {
                cout << adresaci[i].pobierzImie() << endl;
                cout << adresaci[i].pobierzNazwisko() << endl;
                cout << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << adresaci[i].pobierzEmail() << endl;
                cout << adresaci[i].pobierzAdres() << endl << endl;
            }
        }
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}
