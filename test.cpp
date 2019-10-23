/*
 * Copyright: Georg Pohl, 70174 Stuttgart
 * Filename: uptime.cpp
 */
#include <cctype>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <map>
#include <string>
using namespace std;

 /* CONSTANTS */


/* Instance Variables */

/* Prototypes */
void readUptimeCisco(string filename);
int uptimeCisco(string filename);

int main() {
    ifstream infile;

    uptimeCisco("uptime.txt");

    cout << endl;
    return 0;
} // main

/* Functions */
void readUptimeCisco(string filename) {
    ifstream infile;
    string line;
    string word;
    infile.open(filename);
    if (infile.fail()) {
        cout << "Cannot open file!" << endl;
    }
    while (getline(infile, line)) {
        int uptime;
        int digit1, digit2, digit3, digit4, digit5;
        string time1, time2, time3, time4, time5;

        if (line.find("uptime is") != string::npos) {
            istringstream uptLine(line);
            while (uptLine >> word) {
                if (word == "is") {
                uptLine >> digit1;
                uptLine >> time1;
                uptLine >> digit2;
                uptLine >> time2;
                uptLine >> digit3;
                uptLine >> time3;
                uptLine >> digit4;
                uptLine >> time4;
                uptLine >> digit5;
                uptLine >> time5;
                }
            }
            cout << digit1 << endl;
        }
        /*
        if (time1 == "years") {
            uptime = digit1 * 365;
        }
        else if (time1 == "weeks") {
            uptime = digit1 * 30;
        }
        */
    }
}
int upperiodCisco(string filename) {
    readUptimeCisco(filename);

}
