//
// Created by ericd on 2020-09-15.
//
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include "create.hpp"
using namespace std;

void createFile() {
    int low = 0;
    int high = 1024;
    default_random_engine generatorInt(time(0));
    uniform_int_distribution<> distributionInt(low, high);
    int lines = distributionInt(generatorInt);

    double a = 50.000;
    double b = 90.000;
    default_random_engine generatorDoub(time(0));
    uniform_real_distribution<double> distributionDoub(a, b);

    ofstream text("Readings.txt");

    for (int i = 0; i <= lines; i++) {
        double num = distributionDoub(generatorDoub);
        double rounded = floor(num*1000+0.5)/1000;
        text << i;
        text << " ";
        text << rounded;
        if (i != lines)
            text << "\n";
    }
}


