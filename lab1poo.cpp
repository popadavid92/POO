#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    string foodType;
    float weight;
    string color;

public:
    Animal(string n, int a, string f, float w, string c)
        : name(n), age(a), foodType(f), weight(w), color(c) {}

    virtual void display() const {
        cout << "Nume: " << name << "\nVarsta: " << age
             << "\nMancare: " << foodType << "\nGreutate: " << weight
             << "\nCuloare: " << color << endl;
    }
};

class Mamifer : public Animal {
protected:
    string diet;

public:
    Mamifer(string n, int a, string f, float w, string c, string d)
        : Animal(n, a, f, w, c), diet(d) {}

    void display() const override {
        Animal::display();
        cout << "Tip alimentatie: " << diet << endl;
    }
};

class FaunaMarina : public Animal {
protected:
    string category;

public:
    FaunaMarina(string n, int a, string f, float w, string c, string cat)
        : Animal(n, a, f, w, c), category(cat) {}

    void display() const override {
        Animal::display();
        cout << "Categorie: " << category << endl;
    }
};

class Pasare : public Animal {
protected:
    float wingSpan;

public:
    Pasare(string n, int a, string f, float w, string c, float ws)
        : Animal(n, a, f, w, c), wingSpan(ws) {}

    void display() const override {
        Animal::display();
        cout << "Lungime aripi: " << wingSpan << " m" << endl;
    }
};

void showInstructions() {
    cout << "Alege tipul de animal:\n";
    cout << "1. Mamifer\n";
    cout << "2. Fauna marina\n";
    cout << "3. Pasare\n";
}

int main() {
    Mamifer lion("Leu", 5, "Carne", 180.0, "Auriu", "Carnivor");
    FaunaMarina turtle("Broasca testoasa", 20, "Plante", 0.75, "Verde", "Reptila");
    Pasare eagle("Vultur", 8, "Carne", 6.0, "Negru", 2.5);

    cout << "Animale predefinite:\n";
    lion.display();
    turtle.display();
    eagle.display();

    int option;
    showInstructions();
    cin >> option;

    int count;
    cout << "Introduceti numarul de animale: ";
    cin >> count;

    if (option == 1) {
        vector<Mamifer> mammals;
        for (int i = 0; i < count; ++i) {
            string name, food, color, diet;
            int age;
            float weight;

            cout << "Introduceti informatiile pentru mamiferul " << i + 1 << ":\n";
            cout << "Nume: ";
            cin >> name;
            cout << "Varsta: ";
            cin >> age;
            cout << "Mancare: ";
            cin >> food;
            cout << "Greutate: ";
            cin >> weight;
            cout << "Culoare: ";
            cin >> color;
            cout << "Tip alimentatie (Carnivor/Ierbivor/Omnivor): ";
            cin >> diet;

            mammals.push_back(Mamifer(name, age, food, weight, color, diet));
        }

        cout << "\nMamiferele introduse sunt:\n";
        for (const auto& mammal : mammals) {
            mammal.display();
        }
    }
    else if (option == 2) {
        vector<FaunaMarina> marineFauna;
        for (int i = 0; i < count; ++i) {
            string name, food, color, category;
            int age;
            float weight;

            cout << "Introduceti informatiile pentru fauna marina " << i + 1 << ":\n";
            cout << "Nume: ";
            cin >> name;
            cout << "Varsta: ";
            cin >> age;
            cout << "Mancare: ";
            cin >> food;
            cout << "Greutate: ";
            cin >> weight;
            cout << "Culoare: ";
            cin >> color;
            cout << "Categorie (Crustaceu/Molusca): ";
            cin >> category;

            marineFauna.push_back(FaunaMarina(name, age, food, weight, color, category));
        }

        cout << "\nFauna marina introdusa este:\n";
        for (const auto& fauna : marineFauna) {
            fauna.display();
        }
    }
    else if (option == 3) {
        vector<Pasare> birds;
        for (int i = 0; i < count; ++i) {
            string name, food, color;
            int age;
            float weight, wingSpan;

            cout << "Introduceti informatiile pentru pasarea " << i + 1 << ":\n";
            cout << "Nume: ";
            cin >> name;
            cout << "Varsta: ";
            cin >> age;
            cout << "Mancare: ";
            cin >> food;
            cout << "Greutate: ";
            cin >> weight;
            cout << "Culoare: ";
            cin >> color;
            cout << "Lungime aripi (m): ";
            cin >> wingSpan;

            birds.push_back(Pasare(name, age, food, weight, color, wingSpan));
        }

        cout << "\nPasarile introduse sunt:\n";
        for (const auto& bird : birds) {
            bird.display();
        }
    }

    return 0;
}

