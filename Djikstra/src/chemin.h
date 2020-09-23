#include <iostream>
using namespace std;

class Chemin{
  public:

    Chemin(string point_A, string point_B, int poid); //Constructeur
    string point_A;
    string point_B;
    int poid;
};

Chemin::Chemin(string A, string B, int poids){ //Constructeur
  point_A = A;
  point_B = B;
  poid = poids;
}