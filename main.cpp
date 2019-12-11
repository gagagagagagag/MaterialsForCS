#include <iostream>

int comparisonCounter = 0;

void sortujPrzezScalenie(int tablica[], int, int);
void scalDwieCzesci(int tablica[], int indeksPoczatku, int srodkowyIndeks, int indeksKonca);

int main() {
//    int tablica[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int tablica[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
//    int tablica[] = {1, 3, 2, 4, 7, 5, 6, 8, 9};
    int tablica[] = {1, 1, 2};

    int tablicaLength = 3;

    sortujPrzezScalenie(tablica, 0, tablicaLength - 1);

    for (int i = 0; i < tablicaLength; i++) {
        std::cout << tablica[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "Comparisons: " << comparisonCounter;
}

void sortujPrzezScalenie(int tablica[], int indeksPoczatku, int indeksKonca) {

    if (indeksPoczatku < indeksKonca) {
        // Krok 1 - podziel tablice na dwie częśći
        int srodkowyIndeks = (indeksKonca + indeksPoczatku) / 2;

        // Krok 2 - podziel lewą część
        sortujPrzezScalenie(tablica, indeksPoczatku, srodkowyIndeks);

        // Krok 3 - podziel prawa część
        sortujPrzezScalenie(tablica, srodkowyIndeks + 1, indeksKonca);

        // Krok 4 - scal dwie części
        scalDwieCzesci(tablica, indeksPoczatku, srodkowyIndeks, indeksKonca);
    } else {
        return;
    }
}


void scalDwieCzesci(int tablica[], int indeksPoczatku, int srodkowyIndeks, int indeksKonca) {
    int rozmiarLewejCzesci = srodkowyIndeks - indeksPoczatku + 1;
    int rozmiarPrawejCzesci = indeksKonca - srodkowyIndeks;

    int kopiaLewejCzesci[rozmiarLewejCzesci];
    int kopiaPrawejCzesci[rozmiarPrawejCzesci];

    for (int i = 0; i < rozmiarLewejCzesci; i++) {
        kopiaLewejCzesci[i] = tablica[indeksPoczatku + i];
    }
    for (int i = 0; i < rozmiarPrawejCzesci; i++) {
        kopiaPrawejCzesci[i] = tablica[srodkowyIndeks + i + 1];
    }

    int biezacyIndeksLewejCzesci = 0, biezacyIndeksPrawejCzesci = 0;
    int biezacyIndeksWOryginalnejTablicy = indeksPoczatku;


    while (biezacyIndeksLewejCzesci < rozmiarLewejCzesci && biezacyIndeksPrawejCzesci < rozmiarPrawejCzesci) {
        // COMPARISON COUNTER
        comparisonCounter++;

        if (kopiaLewejCzesci[biezacyIndeksLewejCzesci] <= kopiaPrawejCzesci[biezacyIndeksPrawejCzesci]) {
            tablica[biezacyIndeksWOryginalnejTablicy] = kopiaLewejCzesci[biezacyIndeksLewejCzesci];
            biezacyIndeksLewejCzesci++;
        } else {
            tablica[biezacyIndeksWOryginalnejTablicy] = kopiaPrawejCzesci[biezacyIndeksPrawejCzesci];
            biezacyIndeksPrawejCzesci++;
        }
        biezacyIndeksWOryginalnejTablicy++;
    }

    while (biezacyIndeksLewejCzesci < rozmiarLewejCzesci) {
        tablica[biezacyIndeksWOryginalnejTablicy] = kopiaLewejCzesci[biezacyIndeksLewejCzesci];
        biezacyIndeksLewejCzesci++;
        biezacyIndeksWOryginalnejTablicy++;
    }

    while (biezacyIndeksPrawejCzesci < rozmiarPrawejCzesci) {
        tablica[biezacyIndeksWOryginalnejTablicy] = kopiaPrawejCzesci[biezacyIndeksPrawejCzesci];
        biezacyIndeksPrawejCzesci++;
        biezacyIndeksWOryginalnejTablicy++;
    }
}