#include <Arduino.h>
#include <iostream>
#include "chemin.h"

using namespace std;

Chemin plan[11] = {Chemin("Start", "6", 6), Chemin("6", "7", 2),
                   Chemin("7", "A", 3), Chemin("7", "8", 3),
                   Chemin("8", "B", 3), Chemin("8", "9", 2),
                   Chemin("8", "10", 5), Chemin("6", "10", 1),
                   Chemin("7", "10", 3), Chemin("9", "C", 2),
                   Chemin("10", "D", 3)};

string depart = "Start";
string arrivee = "D";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(Chemin chemin : plan){
    cout << chemin.point_A << chemin.point_B << chemin.poid << endl;
  }
  delay(2000);
}