#include "PlikTekstowy.h"


bool PlikTekstowy::czyPlikJestPusty()
{
    bool status = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good())
    {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            status = false;
    }
    plikTekstowy.close();
    return status;
}

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}
