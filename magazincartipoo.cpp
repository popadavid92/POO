#include <iostream>
#include <string>
using namespace std;

class MagazinCarte {
public:
    string titlu;
    float pret;
    int nr_pagini;
    int cantitate;

    MagazinCarte(string titlu, float pret, int nr_pagini, int cantitate) {
        this->titlu = titlu;
        this->pret = pret;
        this->nr_pagini = nr_pagini;
        this->cantitate = cantitate;
    }

    float calculeaza_total() {
        return pret * cantitate;
    }

    void afiseaza() {
        cout << "Titlu: " << titlu << ", Pret: " << pret << " lei, Numar Pagini: " << nr_pagini << ", Cantitate: " << cantitate << endl;
        cout << "Pretul total pentru aceasta carte: " << calculeaza_total() << " lei" << endl;
        cout << "----------------------------------------" << endl;
    }
};

int main() {
    cout << "Bine ati venit la magazinul de carti!\n";
    cout << "Stocul de carti este deja definit.\n";
    cout << "----------------------------------------" << endl << endl;

    MagazinCarte carti[] = {
        MagazinCarte("Cartea 1", 25.0, 150, 10),
        MagazinCarte("Cartea 2", 30.0, 200, 5),
        MagazinCarte("Cartea 3", 18.0, 120, 15),
        MagazinCarte("Cartea 4", 22.0, 250, 7)
    };

    int n = sizeof(carti) / sizeof(carti[0]);

    cout << "----------------------------------------" << endl;
    cout << "Cartile disponibile sunt: " << endl;
    float total_magazin = 0;

    for (int i = 0; i < n; i++) {
        carti[i].afiseaza();
        total_magazin += carti[i].calculeaza_total();
    }

    cout << "================================================================" << endl;
    cout << "Pretul total al tuturor cartilor din magazin este: " << total_magazin << " lei" << endl;

    return 0;
}
