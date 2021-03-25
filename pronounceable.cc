#include <string>
#include <iostream>
#include <random>

#define vowels "aeiou"
#define consonants "bcdfghjklmnpqrstvwxyz"

char random_vowel () { return vowels[rand()%5]; }
char random_consonant () { return consonants[rand()%21]; }

std::string random_element () {
    int mode = rand()%4;
    std::string output = "";
    switch (mode) {
        case 0: // CV
        output += random_consonant();
        output += random_vowel();
        break;
        case 1: // CVC
        output += random_consonant();
        output += random_vowel();
        output += random_consonant();
        break;
        case 2: // V
        output += random_vowel();
        break;
    }
    return output;
}

std::string random_name () {
    std::string result = "";
    for (int i = 0; i < 3; i++) result += random_element();
    while (rand()%4) result += random_element();
    return result;
}

int main (int argc, char *argv[]) {
    if (argc < 1) srand (time(NULL));
    else srand (std::stoi(argv[1]));

    int i = 0;
    int lim = 1;
    if (argc > 1) {
        lim = std::stoi(argv[2]);
    }
    while (i < lim) { 
        std::cout << random_name () << ", " << std::endl;
        i++;
    }
}