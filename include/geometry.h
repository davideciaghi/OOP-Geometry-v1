#ifndef GEOMETRY_H
#define GEOMETRY_H

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


class PointArray





#endif // GEOMETRY_H