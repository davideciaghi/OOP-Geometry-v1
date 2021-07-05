
#include <geometry.h>
#include "iostream"
#include <string>


using namespace std;


Point::Point(int x=0, int y=0){  // Costruttore con parametri di default in caso di chiamata al costruttore senza agomenti  (  Point p2;  )
    this->x;
    this->y;
};

string Point::as_string(){
        
    string str = "(" + to_string(this->x) + "," + std::to_string(this->y) + ")";
    return str;
};

int Point::get_x() {

    return this->x;
};

int Point::get_y(){

    return this->y;
};

void Point::set_x(const int x){

    this->x = x;
};

void Point::set_y(const int y){

    this->y = y;
};



PointArray::PointArray() {  // Cstruttore di default

    this->size;
    this->points = NULL; // Crea un array di dimensione 0
}


PointArray::PointArray(const Point points[], const int size) {  // Costruttore con argomenti

    if (size < 0) {
        throw std::invalid_argument("Size is a negative number");

    } else if (size == 0) {
        this->points = NULL;

    } else {
        this->size = size;
        this->points = new Point[size];

        for (int i=0; i<size; i++) {
            this->points[i] = points[i];
        }
    }  
}


PointArray::PointArray(const PointArray& pv) : PointArray(pv.points, pv.size) {  // Costruttore copia

    cout << "DEBUG: copy constructor" << endl;
} 



PointArray::~PointArray() { // Distruttore

    cout << "DEBUG: PointArray destructor." << endl;
    delete [] this->points;
}


void PointArray::resize(int n) {

    cout << "DEBUG: resizing from" << this->size << "to" << n << endl;

    if (n < 0) {
        throw std::invalid_argument("Negative size !");

    } else if (n == 0) {
        delete [] this->points;
        this->points = NULL;

    } else {
        Point* old_points = this->points;
        this->points = new Point[n];

        for (int i = 0; i < std::min(n, this->size); i++) {

            this->points[i] = old_points[i];
        }

        this->size = n;
        delete [] old_points;
    }
}




string PointArray::as_string() {

    string str = string("size: ") + to_string(this->size) + string(" points:");

    for (int i=0; i < this->size; i++) {

        str += "    " + this->points[i].as_string();
    }

    return str;
}



void PointArray::push_back(Point &p){

    cout << "DEBUG: pushing back: " << p.as_string() << endl;

    resize(this->size + 1);
    this->points[this->size - 1] = p;
}



void PointArray::insert(int pos, Point &p) {

    if (pos < 0) {
        throw std::invalid_argument("Position is negative");
    
    } else if(pos > this->size) {
        throw std::invalid_argument("Position bigger than size");

    } else {
        resize(this->size + 1);

        for (int i = this->size-1; i > pos; i--) {

            this->points[i] = this->points[i-1];
        }

        this->points[pos] = p;

    }
}


void PointArray::remove(int pos) {

    if (pos < 0) {
        throw std::invalid_argument("Position is negative");
    
    } else if(pos >= this->size) {
        throw std::invalid_argument("Position bigger than size");

    } else {
        
        for (int i = pos; i < this->size; i++) {

            this->points[i] = this->points[i+1];
        }

        resize(this->size -1);

    }
}


int PointArray::get_size() {

    return this->size;
}


void PointArray::clear() {

    resize(0);
}


Point * PointArray::get(const int pos) {

    if (pos < 0) {
        throw std::invalid_argument("Position is negative");
    
    } else if(pos >= this->size) {
        throw std::invalid_argument("Position bigger than size");

    } else {
        return &(this->points[pos]);
    
    }
}











