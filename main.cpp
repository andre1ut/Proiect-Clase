#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

void clearScreen() {
    (void)system("cls"); 
}

struct elev {
    string nume;
    string numarCatalog;
    vector<vector<int>> note;
    vector<vector<string>> absente;

    elev(const vector<string>& subjects) {
        note.resize(subjects.size());
        absente.resize(subjects.size());
    }

    elev& addNota(int subjectIndex, int nota) {
        this->note[subjectIndex].push_back(nota);
        return *this;
    }

    elev& addAbsenta(int subjectIndex, const string& dataAbsenta) {
        this->absente[subjectIndex].push_back(dataAbsenta);
        return *this;
    }

    void afiseazaNote(const vector<string>& subjects) const {
        for (size_t i = 0; i < subjects.size(); ++i) {
            cout << CYAN << subjects[i] << " pentru " << nume << ": " << RESET;
            for (const auto& n : note[i]) {
                cout << n << " ";
            }
            cout << "\n";
        }
    }

    void afiseazaAbsente(const vector<string>& subjects) const {
        for (size_t i = 0; i < subjects.size(); ++i) {
            cout << YELLOW << "Absente la " << subjects[i] << " pentru " << nume << ": " << RESET;
            for (const auto& abs : absente[i]) {
                cout << abs << " ";
            }
            cout << "\n";
        }
    }
};

class catalog {
private:
    vector<elev> copil;
    vector<string> subjects;

public:
    catalog(const vector<string>& subjects) : subjects(subjects) {}

    void addStudent(const elev& student) {
        copil.push_back(student);
    }

    void informatieElev() {
        clearScreen();
        cout << BLUE << "Introdu numarul de ordine al elevului: " << RESET;
        int choice;
        cin >> choice;
        if (choice > 0 && choice <= copil.size()) {
            cout << GREEN << "\n--- Informatii Elev ---\n" << RESET;
            cout << "Nume: " << copil[choice - 1].nume << "\n";
            copil[choice - 1].afiseazaNote(subjects);
            copil[choice - 1].afiseazaAbsente(subjects);
            cout << GREEN << "----------------------\n" << RESET;
        } else {
            cout << RED << "Numar invalid.\n" << RESET;
        }
    }

    void enumerare() {
        clearScreen();
        cout << MAGENTA << "\n--- Lista Elevi ---\n" << RESET;
        for (const auto& student : copil) {
            cout << student.numarCatalog << ": " << student.nume << "\n";
        }
        cout << MAGENTA << "--------------------\n" << RESET;
    }

    void adaugaNotaElevului() {
        clearScreen();
        cout << BLUE << "Introdu numarul de ordine al elevului: " << RESET;
        int choice;
        cin >> choice;
        if (choice > 0 && choice <= copil.size()) {
            cout << BLUE << "Introdu materia (0 - Matematica, 1 - Romana, 2 - Informatica): " << RESET;
            for (size_t i = 0; i < subjects.size(); ++i) {
                cout << i << " - " << subjects[i] << ", ";
            }
            cout << "\n";
            int materie;
            cin >> materie;
            if (materie >= 0 && materie < subjects.size()) {
                cout << BLUE << "Introdu nota: " << RESET;
                int nota;
                cin >> nota;
                copil[choice - 1].addNota(materie, nota);
                cout << GREEN << "Nota adaugata cu succes.\n" << RESET;
            } else {
                cout << RED << "Materia invalida.\n" << RESET;
            }
        } else {
            cout << RED << "Numar invalid.\n" << RESET;
        }
    }

    void adaugaAbsentaElevului() {
        clearScreen();
        cout << BLUE << "Introdu numarul de ordine al elevului: " << RESET;
        int choice;
        cin >> choice;
        if (choice > 0 && choice <= copil.size()) {
            cout << BLUE << "Introdu materia (0 - Matematica, 1 - Romana, 2 - Informatica): " << RESET;
            for (size_t i = 0; i < subjects.size(); ++i) {
                cout << i << " - " << subjects[i] << ", ";
            }
            cout << "\n";
            int materie;
            cin >> materie;
            if (materie >= 0 && materie < subjects.size()) {
                cout << BLUE << "Introdu data absentei (zz/ll/aaaa): " << RESET;
                string dataAbsenta;
                cin >> dataAbsenta;
                copil[choice - 1].addAbsenta(materie, dataAbsenta);
                cout << GREEN << "Absenta adaugata cu succes.\n" << RESET;
            } else {
                cout << RED << "Materia invalida.\n" << RESET;
            }
        } else {
            cout << RED << "Numar invalid.\n" << RESET;
        }
    }
};

void defineElev(const string& nume, const string& numarCat, elev& Copil) {
    Copil.nume = nume;
    Copil.numarCatalog = numarCat;
}

int main() {
    vector<string> subjects = {"Matematica", "Romana", "Informatica"};
    catalog unsprezece_i(subjects);

    elev Arteni_Eduard(subjects);
    elev Bujor_Alexandru(subjects);
    elev Ciubotaru_Rares(subjects);
    elev Constantin_Daniel(subjects);
    elev Cristache_Carol(subjects);
    elev Croitoru_Luiza(subjects);
    elev Demetriad_Andreea(subjects);
    elev Dumitrescu_Radu(subjects);
    elev Dumitru_Andrei(subjects);
    elev Florea_Nikolas(subjects);
    elev Frone_Mihai(subjects);
    elev Gargaz_Rares(subjects);
    elev Graure_Alexia(subjects);
    elev Lupascu_Eric(subjects);
    elev Martin_Matei(subjects);
    elev Matei_Razvan(subjects);
    elev Musat_Teodor(subjects);
    elev Nicula_Andrei(subjects);
    elev Niculaie_Adrian(subjects);
    elev Oanta_Irina(subjects);
    elev Rosca_Serban(subjects);
    elev Sorescu_Victor(subjects);
    elev Stinga_David(subjects);
    elev Vasilache_Andrei(subjects);

    defineElev("Arteni Eduard", "01", Arteni_Eduard);
    defineElev("Bujor Alexandru", "02", Bujor_Alexandru);
    defineElev("Ciubotaru Rares", "03", Ciubotaru_Rares);
    defineElev("Constantin Daniel", "04", Constantin_Daniel);
    defineElev("Cristache Carol", "05", Cristache_Carol);
    defineElev("Croitoru Luiza", "06", Croitoru_Luiza);
    defineElev("Demetriad Andreea", "07", Demetriad_Andreea);
    defineElev("Dumitrescu Radu-Traian-Stefan", "08", Dumitrescu_Radu);
    defineElev("Dumitru-Munteanu Andrei", "09", Dumitru_Andrei);
    defineElev("Florea Nikolas-Simion", "10", Florea_Nikolas);
    defineElev("Frone Mihai", "11", Frone_Mihai);
    defineElev("Gargaz Rares", "12", Gargaz_Rares);
    defineElev("Graure Alexia", "13", Graure_Alexia);
    defineElev("Lupascu Eric-Andrei", "14", Lupascu_Eric);
    defineElev("Martin Matei-Cristian", "15", Martin_Matei);
    defineElev("Matei Razvan", "16", Matei_Razvan);
    defineElev("Musat Teodor", "17", Musat_Teodor);
    defineElev("Nicula Andrei", "18", Nicula_Andrei);
    defineElev("Niculaie Adrian-Ioan", "19", Niculaie_Adrian);
    defineElev("Oanta Irina", "20", Oanta_Irina);
    defineElev("Rosca-Cotofana Serban", "21", Rosca_Serban);
    defineElev("Sorescu Victor", "22", Sorescu_Victor);
    defineElev("Stinga David", "23", Stinga_David);
    defineElev("Vasilache Andrei", "24", Vasilache_Andrei);

    unsprezece_i.addStudent(Arteni_Eduard);
    unsprezece_i.addStudent(Bujor_Alexandru);
    unsprezece_i.addStudent(Ciubotaru_Rares);
    unsprezece_i.addStudent(Constantin_Daniel);
    unsprezece_i.addStudent(Cristache_Carol);
    unsprezece_i.addStudent(Croitoru_Luiza);
    unsprezece_i.addStudent(Demetriad_Andreea);
    unsprezece_i.addStudent(Dumitrescu_Radu);
    unsprezece_i.addStudent(Dumitru_Andrei);
    unsprezece_i.addStudent(Florea_Nikolas);
    unsprezece_i.addStudent(Frone_Mihai);
    unsprezece_i.addStudent(Gargaz_Rares);
    unsprezece_i.addStudent(Graure_Alexia);
    unsprezece_i.addStudent(Lupascu_Eric);
    unsprezece_i.addStudent(Martin_Matei);
    unsprezece_i.addStudent(Matei_Razvan);
    unsprezece_i.addStudent(Musat_Teodor);
    unsprezece_i.addStudent(Nicula_Andrei);
    unsprezece_i.addStudent(Niculaie_Adrian);
    unsprezece_i.addStudent(Oanta_Irina);
    unsprezece_i.addStudent(Rosca_Serban);
    unsprezece_i.addStudent(Sorescu_Victor);
    unsprezece_i.addStudent(Stinga_David);
    unsprezece_i.addStudent(Vasilache_Andrei);

    unsprezece_i.enumerare();

    char optiune;
    do {
        cout << "\n" << BLUE << "--- Meniu ---\n" << RESET;
        cout << "1. Afiseaza informatii despre un elev\n";
        cout << "2. Adauga nota unui elev\n";
        cout << "3. Adauga absenta unui elev\n";
        cout << "4. Iesire\n";
        cout << BLUE << "Introdu optiunea: " << RESET;
        cin >> optiune;

        clearScreen();

        switch (optiune) {
            case '1':
                unsprezece_i.informatieElev();
                break;
            case '2':
                unsprezece_i.adaugaNotaElevului();
                break;
            case '3':
                unsprezece_i.adaugaAbsentaElevului();
                break;
            case '4':
                cout << RED << "Iesire...\n" << RESET;
                break;
            default:
                cout << RED << "Optiune invalida.\n" << RESET;
                break;
        }
    } while (optiune != '4');

    return 0;
}
