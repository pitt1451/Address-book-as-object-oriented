#include "AdresatMenedzer.h"

void AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
    {
        cout << "Adresat zostal dodany" << endl;
    }
    else
    {
        cout << "Nie udalo sie dodac nowego adresata do pliku" << endl;
    }
    system("pause");
}

void AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata;
    int numerLiniiUsuwanegoAdresata;
    char znak;
    bool czyIstniejeAdresat = false;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj ID adresata, ktorego chcesz usunac: ";

    idUsuwanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    for (int i = 0; i < (int) adresaci.size(); i++)
    {
        if (idUsuwanegoAdresata == adresaci[i].pobierzId())
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();

            if (znak == 't')
            {
                plikZAdresatami.usunAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(adresaci.begin() + i);
                cout << endl << "Adresat o wybranym ID zostal usuniety" << endl;
                system("pause");
            }
            else
            {
                cout << endl << "Nie udalo sie usunac adresata" << endl;
                system("pause");
            }
        }
    }
    if (!czyIstniejeAdresat)
    {
        cout << endl << "Adresat o takim ID nie istnieje w ksiazce adresowej" << endl;
        system("pause");
    }
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    string daneOstaniegoAdresataWPliku = "";
    Adresat adresat;
    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
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
        for (int i = 0; i < (int) adresaci.size(); i++)
        {
            cout << "Id: " << adresaci[i].pobierzId() << endl;
            cout << "Imie: " << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko: " << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu: " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email: " << adresaci[i].pobierzEmail() << endl;
            cout << "Adres: " << adresaci[i].pobierzAdres() << endl << endl;
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

        int licznikImion = 0;

        for (int i = 0; i < (int) adresaci.size(); i++)
        {
            if ( imiePoszukiwanegoAdresata == adresaci[i].pobierzImie())
            {
                cout << "Id: " << adresaci[i].pobierzId() << endl;
                cout << "Imie: " << adresaci[i].pobierzImie() << endl;
                cout << "Nazwisko: " << adresaci[i].pobierzNazwisko() << endl;
                cout << "Numer telefonu: " << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << "Email: " << adresaci[i].pobierzEmail() << endl;
                cout << "Adres: " << adresaci[i].pobierzAdres() << endl << endl;
                licznikImion++;
            }
        }
        if (licznikImion == 0)
        {
            cout << "Nie ma osoby o podanym imieniu" << endl;
        }
        system("pause");
    }
    else
    {
        cout << endl << "Plik nie istnieje lub ksiazka adresowa jest pusta." << endl << endl;
        system("pause");
    }
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

        int licznikNazwisk = 0;

        for (int i = 0; i < (int) adresaci.size(); i++)
        {
            if ( nazwiskoPoszukiwanegoAdresata == adresaci[i].pobierzNazwisko())
            {
                cout << "Id: " << adresaci[i].pobierzId() << endl;
                cout << "Imie: " << adresaci[i].pobierzImie() << endl;
                cout << "Nazwisko: " << adresaci[i].pobierzNazwisko() << endl;
                cout << "Numer telefonu: " << adresaci[i].pobierzNumerTelefonu() << endl;
                cout << "Email: " << adresaci[i].pobierzEmail() << endl;
                cout << "Adres: " << adresaci[i].pobierzAdres() << endl << endl;
                licznikNazwisk++;
            }
        }
        if (licznikNazwisk == 0)
        {
            cout << "Nie ma osoby o podanym nazwisku" << endl;
        }
        system("pause");
    }
    else
    {
        cout << endl << "Plik nie istnieje lub ksiazka adresowa jest pusta." << endl << endl;
        system("pause");
    }
}
