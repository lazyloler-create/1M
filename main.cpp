#include <iostream>
#include <string>

#include "funkcije.h"

int main(){

    std::cout << "Test odvojiUlistu:\n";
    Node* lista = odvojiUlistu("dobar dan svima");
    for (Node* trenutni = lista; trenutni != nullptr; trenutni = trenutni->next) {
        std::cout << trenutni->vrijednost << '\n';
    }

    while (lista != nullptr) {
        Node* zaBrisanje = lista;
        lista = lista->next;
        delete zaBrisanje;
    }

    //std::string recenica = "pas auto bicikl";
    //std::cout << "Prosjek duzina parnih rijeci u \"" << recenica << "\": "
    //          << prosjekParnihCh(recenica) << '\n';

    /*
    std::cout << "Test odvoji:\n";
    std::string odvojeneRijeci[100];
    odvoji("dobar dan svima", odvojeneRijeci);
    for (int i = 0; i < 100 && !odvojeneRijeci[i].empty(); i++) {
        std::cout << odvojeneRijeci[i] << '\n';
    }

    

    std::cout << "\nTest parkiraj:\n";
    double udaljenostiBezUdara[4] = {2.5, 1.2, 4.0, 3.0};
    std::cout << "Svi senzori bez udara: "
              << (parkiraj(udaljenostiBezUdara) ? "da" : "ne") << "\n";

    double udaljenostiSaUdarom[4] = {4.0, 2.0, 0.03, 4.0};
    std::cout << "Svi senzori bez udara: "
              << (parkiraj(udaljenostiSaUdarom) ? "da" : "ne") << "\n";

    std::cout << "\nTest dekadniU:\n";
    std::cout << "358 u bazi 13 = " << dekadniU(358, 13) << '\n';

    std::cout << "\nTest sortirajString:\n";
    std::cout << "listen -> " << sortirajString("listen") << '\n';
    */
    std::cout << "\nTest anagram:\n";
    std::string rijeciZaAnagram[100] = {"listen", "dog", "silent", "enlist"};
    std::string* grupisaneRijeci = anagram(rijeciZaAnagram);
    for (int i = 0; i < 100 && !grupisaneRijeci[i].empty(); i++) {
        std::cout << grupisaneRijeci[i] << '\n';
    }
    
    /*
    std::cout << "\nTest prefiks:\n";
    std::string rijeciZaPrefiks[100] = {"auto", "autobus", "autogram"};
    std::cout << "Zajednicki prefiks: "
              << prefiks(rijeciZaPrefiks) << '\n';
    */
              
    //delete[] grupisaneRijeci;
    return 0;
}