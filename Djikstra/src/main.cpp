#include <Arduino.h>
#include <iostream>
#include "chemin.h"

using namespace std;

Chemin chemin("A", "B", 3);
Chemin plan[1] = {chemin};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  cout << plan[0].point_A << plan[0].point_B << plan[0].poid << endl;
  delay(500);
}