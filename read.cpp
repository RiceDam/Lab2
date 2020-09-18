//
// Created by ericd on 2020-09-15.
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include "read.hpp"
using namespace std;

double median(int n) {
    double nums[n];
    ifstream text("Readings.txt");
    string line;
    int ind = 0;

    while (getline(text, line)) {
        double holder;
        string num;
        int pos = line.length();
        for (int i = 0; i < line.length(); i++) {
            if (line.at(i) == ' ') {
                pos = i;
            }
            else if (i > pos) {
                num += line.at(i);
            }
        }
        holder = stod(num);
        nums[ind] = holder;
        ind++;
    }
    sort(nums, nums + n);
    if (n % 2 == 0)
        return (nums[n/2] + nums[n/2+1]) / 2;
    else {
        float f = n/2.0f;
        f += 0.5;
        int half = (int) f;
        return nums[half];
    }
}

void readFile() {
    int readings = 0;
    double average = 0;
    double highest = 0;
    double lowest = 1025;
    double med;
    ifstream text("Readings.txt");
    string line;

    while (getline(text, line)) {
        double holder;
        string num;
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
    cout << "There are " << readings << " readings in the file" << endl;
    cout << "The average reading is " << average << endl;
    cout << "The highest reading is " << highest << endl;
    cout << "The lowest reading is " << lowest << endl;
    med = median(readings);
    cout << "The median reading is " << med << endl;
}
