#include <Arduino.h>
#include <iostream>
#include "chemin.h"
#include "donnee.h"

using namespace std;

#define INF 100
#define ALREADY_USE -1

string DEPART = "A";
string ARRIVEE = "C";

Chemin plan[12] = {Chemin("S", "6", 6), Chemin("6", "7", 2),
                   Chemin("7", "A", 3), Chemin("7", "8", 3),
                   Chemin("8", "B", 3), Chemin("8", "9", 4),
                   Chemin("8", "10", 5), Chemin("6", "10", 1),
                   Chemin("7", "10", 2), Chemin("9", "C", 2),
                   Chemin("10", "9", 3), Chemin("10", "D", 3)};

vector<vector<Donnee>> liste = {{Donnee("S", INF), Donnee("A", INF),
                        Donnee("B", INF), Donnee("C", INF),
                        Donnee("D", INF), Donnee("6", INF),
                        Donnee("7", INF), Donnee("8", INF),
                        Donnee("9", INF), Donnee("10", INF)}};

void afficher_liste(){
  for(int k=0;k<liste.size();k++){
    for(Donnee donnee : liste[k]){
      cout << donnee.from << " " << donnee.distance << " ";
      if(donnee.distance < 100){
        cout << " ";
        if(donnee.distance > 0){
          cout << " ";
        }
      }
      if(donnee.from != "10"){
        cout << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void afficher_trajet(vector<string> trajet){
  for(string point : trajet){
    cout << "-> " << point;
  }
  cout << endl;
}

int chercher_distance(string point_A, string point_B){
  int distance = INF;

  for(Chemin chemin : plan){
    if((chemin.point_A == point_A && chemin.point_B == point_B) || (chemin.point_A == point_B && chemin.point_B == point_A)){
      distance = chemin.poid;
    }
  }
  return distance;
}

Donnee new_position(){
  Donnee minimum = Donnee("", INF);
  int derniere_ligne = liste.size()-1;

  for(int k=0;k<liste[derniere_ligne].size();k++){
    if(liste[derniere_ligne][k].distance < minimum.distance && liste[derniere_ligne][k].distance > 0){
      minimum.distance = liste[derniere_ligne][k].distance;
      minimum.from = liste[0][k].from;
    }
  }
  return minimum;
}

bool it_is_smaller_distance(int new_distance, int k){
  for(int n=0;n<liste.size();n++){
    if(liste[n][k].distance < new_distance && liste[n][k].distance > 0){
      return false;
    }
  }
  return true;
}

bool has_a_distance(int k){
  for(int n=0;n<liste.size();n++){
    if(liste[n][k].distance != INF && liste[n][k].distance > 0){
      return true;
    }
  }
  return false;
}

Donnee calculer_chemin(string depart, string arrivee){
  Donnee position = Donnee(depart, 0);
  vector<Donnee> new_ligne = {};
  int derniere_ligne = liste.size()-1;
  int new_distance;

  while(position.from != arrivee){
    for(int k=0;k<liste[derniere_ligne].size();k++){
      if(liste[0][k].from == position.from || liste[derniere_ligne][k].from == "~"){
        new_ligne.insert(new_ligne.end(), Donnee("~", ALREADY_USE));
      }else{
        new_distance = chercher_distance(position.from, liste[0][k].from);
        if(new_distance != INF){
          new_distance += position.distance;
          if(it_is_smaller_distance(new_distance, k)){
            new_ligne.insert(new_ligne.end(), Donnee(position.from, new_distance));
          }else{
            new_ligne.insert(new_ligne.end(), liste[derniere_ligne][k]);
          }
        }else{
          if(has_a_distance(k)){
            new_ligne.insert(new_ligne.end(), liste[derniere_ligne][k]);
          }else{
            new_ligne.insert(new_ligne.end(), Donnee("I", INF));
          }
        }
      }
    }
    liste.insert(liste.end(), new_ligne);
    derniere_ligne = liste.size()-1;
    new_ligne = {};
    position = new_position();
  }

  return position;
}

vector<string> retrouver_chemin(Donnee position, string depart){
  vector<string> trajet = {};
  int n;
  int k = 0;
  trajet.insert(trajet.begin(), position.from);

  while(position.from != depart){
    for(int m=0;m<liste[0].size();m++){
      if(liste[0][m].from == position.from){
        k = m;
      }
    }
    n = liste.size()-1;
    while(liste[n][k].from == "~"){
      n--;
    }
    position = liste[n][k];
    trajet.insert(trajet.begin(), position.from);
  }

  return trajet;
}

void djikstra(string depart, string arrivee){  
  Donnee position = Donnee("", INF);
  vector<string> trajet = {};

  afficher_liste();
  position = calculer_chemin(depart, arrivee);
  afficher_liste();
  trajet = retrouver_chemin(position, depart);
  afficher_trajet(trajet);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  djikstra(DEPART, ARRIVEE);
}

void loop() {
  // put your main code here, to run repeatedly:
}