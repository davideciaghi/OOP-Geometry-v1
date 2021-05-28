
#include "geometry.h"
#include "iostream"

using namespace std;

class Point {

    private:
        int x;
        int y;
    public:
        Point(int x=0, int y=0){  // Costruttore con parametri di default in caso di chiamata dal main al costruttore senza agomenti  (  Point p2;  )
            this->x;
            this->y;
        }

        string as_string(){

            return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + ")";
        }

};


class PointArray {

    private:
        int size;
        Point* points; // Puntatore points
    public:
        PointArray(){ // Costruttore
            this->size;
            this->points = NULL; // Se abbiamo 0 punti l'array dinamico lo settiamo a NULL
        }

        PointArray(const Point points[], const int size){ // Costruttore
            this->points = new Point[size];
            this->size = size;

            for (int i=0; i<size; i++){  // Copio i punti dentro l'array dinamico
                this->points[i] = points[i];
            }
        }
        
        /* RIDONDANTE
        PointArray::PointArray(const PointArray& pv){

            this->points = new Point[pv.size];
            
            for (int i=0; i<pv.size; i++){  // Copio i punti dentro l'array dinamico
                this->points[i] = pv.points[i];
            }

            this->size = pv-size;
        } */


        PointArray::PointArray(const PointArray& pv): PointArray(pv.points, pv.size){ // Chiamo il costruttore che si prende l'array di punti e la size

        }




        
}