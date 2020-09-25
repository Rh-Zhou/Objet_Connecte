#include <iostream>
using namespace std;

class Donnee{
  public:

    Donnee(string point_A, int distances); //Constructeur
    string from;
    int distance;
};

Donnee::Donnee(string point_A, int distances){ //Constructeur
  from = point_A;
  distance = distances;
}