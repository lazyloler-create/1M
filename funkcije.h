#pragma once

#include <string>

struct Node{
    Node* next;
    std::string vrijednost;
};

void odvoji(std::string recenica, std::string* o);
Node* odvojiUlistu(std::string str);
bool parkiraj(double arr[]);
std::string dekadniU(int broj, int baza);
std::string sortirajString(std::string str);
std::string* anagram(std::string str[]);
std::string prefiks(std::string str[]);
double prosjekParnihCh(std::string str);