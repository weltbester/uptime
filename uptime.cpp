/*
 * Copyright 2019: Georg Pohl, 70174 Stuttgart
 * Filename: uptime.cpp
 */
#include <cctype>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <vector>
#include <string>
using namespace std;

 /* CONSTANTS */


/* Instance Variables */

/* Prototypes */
int uptimeCisco(string filename);

int main() {
    ifstream infile;

    uptimeCisco("uptime.txt");

    cout << endl;
    return 0;
} // main

/* Functions */
/*
 * Function: uptimeCisco
 * Usage: int n = uptimeCisco(string &filename);
 * ---------------------------------------------
 * This function reads the file "show version" in every folder with a Cisco Router.
 * It extracts the different uptime values (year, weeks, days, hours) and then calculates
 * the whole uptime in days. If a routers uptime is less than 24 hours, this is handled as
 * an uptime of 1 day.
 */
int uptimeCisco(string filename) {
    vector<int> periods;
    vector<string> times;
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
                periods.push_back(digit1);
                uptLine >> time1;
                times.push_back(time1);
                uptLine >> digit2;
                periods.push_back(digit2);
                uptLine >> time2;
                times.push_back(time2);
                uptLine >> digit3;
                periods.push_back(digit3);
                uptLine >> time3;
                times.push_back(time3);
                uptLine >> digit4;
                periods.push_back(digit4);
                uptLine >> time4;
                times.push_back(time4);
                uptLine >> digit5;
                periods.push_back(digit5);
                uptLine >> time5;
                times.push_back(time5);
                }
            }
            for (int i = 0; i < periods.size() - 1; i++) {
                    cout << periods[i] << " ";
                }
                cout << endl;
                 for (int i = 0; i < times.size() - 1; i++) {
                    cout << times[i] << " ";
                }
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
    return -1;
}
