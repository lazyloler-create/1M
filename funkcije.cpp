#include <string>
#include <cctype>
#include <iostream>
#include <cmath>

#include "funkcije.h"

//1 zadatak
void odvoji(std::string recenica, std::string* odvojeni){
    int j = 0;
    std::string rijec = "";

    for(int i = 0; i < recenica.size(); i++){
        if(!isspace(recenica[i])){
            rijec += recenica[i];
        } else if(!rijec.empty()){
            odvojeni[j] = rijec;
            j++;
            rijec.clear();
        }
    }

    if(!rijec.empty()){
        odvojeni[j] = rijec;
    }
}

void insertujNaPocetakListe(Node** lista, std::string str){
    Node* novi = new Node;
    novi->vrijednost = str;
    novi->next = *lista;
    *lista = novi;
}

void insertujNaPocetakListe(Node*& lista, std::string str){
    Node* novi = new Node{lista, str};
    lista = novi;
}

void insertujNaKrajListe(Node** lista, Node** kraj, std::string str){
    Node* novi = new Node{nullptr, str};

    if(*lista != nullptr){
        *lista = novi;
    } else{
        (*kraj)->next = novi;
    }
    *kraj = novi;
}

void insertujNaKrajListe(Node*& lista, Node*& kraj, std::string str){
    Node* novi = new Node{nullptr, str};
    if(lista == nullptr){
        lista = novi;
    } else{
        kraj->next = novi;
    }
    kraj = novi;
}

//dodatak 1 zadatka
Node* odvojiUlistu(std::string str){
    Node* lista{nullptr};
    std::string rijec = "";
    for(int i = 0; i < str.size(); i++){
        if(!isspace(str[i])){     
            rijec += str[i];
        } else{
            insertujNaPocetakListe(lista, rijec);
            rijec.clear();
        }
    }

    if(!rijec.empty())
        insertujNaPocetakListe(lista, rijec);
    return lista;
}

//2 zadatak
bool parkiraj(double arr[]){
    for(int i = 0; i < 4; i++){
        if(i < 2){
            std::cout<<"Prednji senzor: " << i + 1 << '\n'; 
        } else{
            std::cout<<"Zadnji senzor: " << i + 1 << '\n';
        }

        if(arr[i] <= 0.05){
            std::cout<<"Auto je udario u objekat!" << std::endl;
            return false;
        } else if(arr[i] <= 1.5){
            std::cout<<"Auto je jako blizu objekta! \n";
        } else if(arr[i] <= 3.0){
            std::cout<<"Auto je blizu objekta! \n";
        } else{
            std::cout<<"Senzor nije aktiviran \n";
        }
    }
    return true;
}

//3 zadatak
std::string dekadniU(int broj, int baza){
    if(broj == 0) 
        return "0";

    if(baza < 2 || baza > 16){
        std::cout<<"Netacna baza!\n Mora biti u opsegu izmedju 2 i 16!" << std::endl;
        return "";
    }

    if(broj < 0){
        broj = abs(broj);
    }

    const std::string cifre = "0123456789ABCDEF";
    std::string rez = "";

    while(broj > 0){
        int ostatak = broj % baza;
        rez += cifre[ostatak];
        broj /= baza;
    }

    std::string rezultat = "";
    for(int i = rez.size() - 1; i >= 0; i--){
        rezultat += rez[i];
    }

    return rezultat;
}


//6 zadatak
std::string sortirajString(std::string str){
    int n = str.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(str[j + 1] < str[j]){
                std::swap(str[j + 1], str[j]);
            }
        }
    }
    return str;
}

//6 zadatak
std::string* anagram(std::string str[]){
    auto rezultat = new std::string[100];
    int brojRijeci = 0;

    while(brojRijeci < 100 && !str[brojRijeci].empty()){
        rezultat[brojRijeci] = str[brojRijeci];
        brojRijeci++;
    }

    for(int i = 0; i < brojRijeci - 1; i++){
        for(int j = 0; j < brojRijeci - 1 - i; j++){
            if(sortirajString(rezultat[j]) > sortirajString(rezultat[j + 1])){
                std::swap(rezultat[j], rezultat[j + 1]);
            }
        }
    }

    return rezultat;
}

//7 zadatak
std::string prefiks(std::string str[]){
    if(str[0].empty()) return "";

    auto pref = str[0];
    for(int i = 0; !str[i].empty(); i++){
        while(!pref.empty() && str[i].substr(0, pref.size()) != pref){
            pref.pop_back();
        }
    }
    return pref;
}

/*Zadaci od profesora^^^*/
/*ostali zadaci ↓↓↓↓*/
bool palindrom(std::string str){
    int n = str.size();
    for(int i = 0; i < n/2; i++){
        if(str[i] != str[n - 1 - i]){
            return false;
        }
    }
    return true;
}

std::string najduza(std::string str){
    std::string rijec = "", temp = "";

    for(char ch : str){
        if(!isspace(ch)){
            temp += ch;
        } else{ 
            if(temp.size() > rijec.size()){
                rijec = temp;
            }
            temp.clear();
        }
    }

    if(temp.size() > rijec.size()){
        rijec = temp;
    }

    return rijec;
}

std::string najmanja(std::string str){
    std::string rijec = "", temp = "";

    for(char ch : str){
        if(!std::isspace(ch)){
            temp += ch;
        } else{
            if(!temp.empty() && rijec.empty() || temp.size() < rijec.size()){
                rijec = temp;
            }
            temp.clear();
        }
    }

    if(!temp.empty() && rijec.empty() || temp.size() < rijec.size()){
        rijec = temp;
    }

    return rijec;
}

double prosjekParnihCh(std::string str){
    if(str.empty())
        return 0.0;
    
    int duzinaRijeci = 0;
    int zbir = 0;
    int brojRijeci = 0;

    for(char ch : str){
        if(!std::isspace(ch)){
            duzinaRijeci++;
        } else{
            if(duzinaRijeci > 0 && duzinaRijeci % 2 == 0){
                zbir += duzinaRijeci;
                brojRijeci++;
            }
            duzinaRijeci = 0;
        }
    }

    if(duzinaRijeci > 0 && duzinaRijeci % 2 == 0){
        zbir += duzinaRijeci;
        brojRijeci++;
    }

    if(brojRijeci == 0) 
        return 0.0;
    return zbir / (double)brojRijeci;
}

double dobijX(double x1, double x2){
    double rez = 0.0;
    if(x1 > x2)
        rez = x1 - x2;
    else
        rez = x2 - x1;

    return rez;
}

double dobijY(double y1, double y2){
    double rez = 0.0;
    if(y1 > y2)
        rez = y1 - y2;
    else
        rez = y2 - y1;

    return rez;
}

double povrsina(double x, double y){
    return x * y;
}

double obim(double x, double y){
    return 2 * (x + y);
}

void anagram(std::string str[], std::string* rezultat){
    int brojRijeci = 0;
    while(!str[brojRijeci].empty()){
        rezultat[brojRijeci] = str[brojRijeci];
        brojRijeci++;
    }

    for(int i = 0; i < brojRijeci - 1; i ++){
        for(int j = 0; j < brojRijeci - 1 - i; j++){
            if(sortirajString(rezultat[j]) > sortirajString(rezultat[j + 1])){
                std::swap(rezultat[j], rezultat[j + 1]);
            }
        }
    }
}

void prefiks(std::string str[], std::string& rijec){
    if(str[0].empty()){
        std::cout<<"Prva rijec je prazna!\n Funkcija se ne nastavlja!" << std::endl;
        return;
    }

    auto pref = str[0];
    for(int i = 0; !str[i].empty(); i++){
        while(!pref.empty() && str[i].substr(0, pref.size()) != pref){
            pref.pop_back();
        }
    }
    rijec = pref;
}