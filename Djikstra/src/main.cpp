#include <Arduino.h>
#include <iostream>
#include "chemin.h"
#include "donnee.h"

using namespace std;

#define INF 100
#define ALREADY_USE -1

Chemin plan[11] = {Chemin("Start", "6", 6), Chemin("6", "7", 2),
                   Chemin("7", "A", 3), Chemin("7", "8", 3),
                   Chemin("8", "B", 3), Chemin("8", "9", 2),
                   Chemin("8", "10", 5), Chemin("6", "10", 1),
                   Chemin("7", "10", 3), Chemin("9", "C", 2),
                   Chemin("10", "D", 3)};

vector<vector<Donnee>> liste = {{Donnee("Start", INF), Donnee("A", INF),
                        Donnee("B", INF), Donnee("C", INF),
                        Donnee("D", INF), Donnee("6", INF),
                        Donnee("7", INF), Donnee("8", INF),
                        Donnee("9", INF), Donnee("10", INF)}};

string depart = "Start";
string position = depart;
string arrivee = "D";

void afficher_liste(){
  for(int k=0;k<liste.size();k++){
    for(Donnee donnee : liste[k]){
      cout << donnee.from << " " << donnee.distance << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  afficher_liste();
}

void loop() {
  // put your main code here, to run repeatedly:
  afficher_liste();
  delay(10000);
}