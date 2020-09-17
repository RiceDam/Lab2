//
// Created by ericd on 2020-09-15.
//
#include <iostream>
#include <fstream>
#include "read.hpp"
using namespace std;

void readFile() {
    int readings = 0;
    double average = 0;
    double highest = 0;
    double lowest = 1025;
    double median = 0;
    ifstream text("Readings.txt");
    string line;

    while (getline(text, line)) {
        double holder;
        string num = "";
        int pos = line.length();
        for (int i = 0; i < line.length(); i++) {
            if (i == 0)
                readings++;
            else if (line.at(i) == ' ') {
                pos = i;
            }
            else if (i > pos) {
                num += line.at(i);
            }
        }
        holder = stod(num);
        if (holder > highest)
            highest = holder;
        if (holder < lowest)
            lowest = holder;
        average += holder;
    }
    average /= readings;
    cout << "There are ";
    cout << readings;
    cout << " readings in the file\n";
    cout << "The average reading is ";
    cout << average;
    cout << "\n";
    cout << "The highest reading is ";
    cout << highest;
    cout << "\n";
    cout << "The lowest reading is ";
    cout << lowest << endl;
    
}
