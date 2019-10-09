/*
 * Copyright: Georg Pohl, 70174 Stuttgart, et al.
 * Filename: Aufg_5.19_MorseCode.cpp
 */
 #include <iostream>
 #include <map>
 using namespace std;

 /* CONSTANTS */


/* Instance Variables */

/* Prototypes */
void fillMapWithMorseCode(map<char, string> &m);

int main() {
    map<char, string> morseCode;


    cout << endl;
    return 0;
} // main

/* Functions */
void fillMapWithMorseCode(map<char, string> &m) {
    m.put('A', "._");
}