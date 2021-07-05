#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;


class Point {

    private:

        int x;
        int y;

    public:
        
        Point(int x=0, int y=0); // Costruttore che se non gli si passa
                                 //  inizializza x e y = 0.

        string as_string(); 

        int get_x();

        int get_y();

        void set_x(const int x);

        void set_y(const int y);

};



class PointArray {

    private:

        int size; // Dimensione dell'array
        Point* points; // Puntatore points che punta alla classe Point

    protected:

        void resize(int n);

    public:

        PointArray(); // Costruttore di default

        PointArray(const Point points[], const int size); // Costruttore
        
        PointArray(const PointArray& pv); // Costruttore copia

        ~PointArray();

        string as_string();

        void push_back(Point &p);

        void insert(int pos, Point &p);

        void remove(int pos);

        int get_size();

        void clear();

        Point * get(const int pos);


};



#endif // GEOMETRY_H