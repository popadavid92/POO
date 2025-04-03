#include <iostream>
#include <string>

using namespace std;

class Vehicul {
public:
    string numar_inmatriculare;
    int ora_intrare, minut_intrare, ora_iesire, minut_iesire;
    double tarif_orar;

    Vehicul(string numar, int ora_in, int minut_in, double tarif)
        : numar_inmatriculare(numar), ora_intrare(ora_in), minut_intrare(minut_in), tarif_orar(tarif) {}

    double calculeazaTarif() {
        int total_minute = (ora_iesire - ora_intrare) * 60 + (minut_iesire - minut_intrare);
        return (total_minute / 60.0) * tarif_orar;
    }
};

class Parcare {
private:
    int locuri_disponibile;

public:
    Parcare(int locuri) : locuri_disponibile(locuri) {}

    bool areLocuri() const {
        return locuri_disponibile > 0;
    }

    void ocupaLoc() {
        if (locuri_disponibile > 0) {
            locuri_disponibile--;
        }
    }

    void elibereazaLoc() {
        locuri_disponibile++;
    }

    void afiseazaLocuri() const {
        cout << "Locuri disponibile: " << locuri_disponibile << endl;
    }
};

int main() {
    Parcare parcare(5);
    Vehicul* vehicule[5];
    int optiune, nr_vehicule = 0;

    do {
        cout << "\n1. Parcheaza un vehicul\n2. Elibereaza un vehicul\n3. Afiseaza locuri disponibile\n4. Iesire\nAlege o optiune: ";
        cin >> optiune;

        if (optiune == 1) {
            if (nr_vehicule < 5 && parcare.areLocuri()) {
                string numar;
                int ora_in, minut_in;
                double tarif;

                cout << "Introdu numarul de inmatriculare: ";
                cin >> numar;
                cout << "Introdu ora intrarii (0-23): ";
                cin >> ora_in;
                cout << "Introdu minutul intrarii (0-59): ";
                cin >> minut_in;
                cout << "Introdu tariful pe ora: ";
                cin >> tarif;

                vehicule[nr_vehicule++] = new Vehicul(numar, ora_in, minut_in, tarif);
                parcare.ocupaLoc();
                cout << "Vehiculul " << numar << " a fost parcat!" << endl;
            } else {
                cout << "Nu sunt locuri disponibile sau ai depasit limita de vehicule!" << endl;
            }
        }
        else if (optiune == 2) {
            string numar;
            cout << "Introdu numarul de inmatriculare al vehiculului: ";
            cin >> numar;

            bool gasit = false;
            for (int i = 0; i < nr_vehicule; ++i) {
                if (vehicule[i]->numar_inmatriculare == numar) {
                    int ora_iesire, minut_iesire;
                    cout << "Introdu ora iesirii: ";
                    cin >> ora_iesire;
                    cout << "Introdu minutul iesirii: ";
                    cin >> minut_iesire;

                    vehicule[i]->ora_iesire = ora_iesire;
                    vehicule[i]->minut_iesire = minut_iesire;
                    double tarif = vehicule[i]->calculeazaTarif();
                    cout << "Vehiculul " << numar << " a parasit parcarea. Tariful este: " << tarif << " lei." << endl;

                    delete vehicule[i];
                    vehicule[i] = vehicule[nr_vehicule - 1];
                    nr_vehicule--;
                    parcare.elibereazaLoc();
                    gasit = true;
                    break;
                }
            }
            if (!gasit) {
                cout << "Vehiculul nu a fost gasit!" << endl;
            }
        }
        else if (optiune == 3) {
            parcare.afiseazaLocuri();
        }
        else if (optiune != 4) {
            cout << "Optiune invalida!" << endl;
        }
    } while (optiune != 4);

    cout << "La revedere!" << endl;
    return 0;
}
