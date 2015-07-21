#include<bits/stdc++.h>
using namespace std;

const double ERR = 1e-9;
typedef double Coord;

struct punto{
    Coord x,y;

    punto(): x(0) , y(0) {}
    punto(Coord x_, Coord y_)
        : x(x_), y(x_) {}

    bool operator<(const punto & cmp) const{
        if(x == cmp.x) return y < cmp.y;
        return x < cmp.x;
    }
};

double GradosARad(double grados){
    return (grados * M_PI) / 180;
}

double RadAGrados(double radianes){
    return (radianes * 180) / M_PI;
}

//DISTANCIA ENTRE 2 PUNTOS
double Distancia(const punto & p, const punto & q){
    return hypot(p.x - q.x, p.y - q.y);
}

//DISTANCIA DEL ORIGEN A UN PUNTO
double Magnitud(const punto & v){
    return hypot(v.x, v.y);
}

//PRODUCTO PUNTO
double Dot(const punto & v, const punto & w){
    return (v.x * w.x) + (v.y * w.y);
}

//PRODUCTO CRUZ
double Cruz(const punto & v, const punto & w){
    return (v.x * w.y) - (v.y * w.x);
}

//ROTA UN PÚNTO G GRADOS
punto Rotar(const punto & p, double g){
    double r = GradosARad(g);
    return punto(p.x * cos(r) - p.y * sin(r),
                 p.x * sin(r) + p.y * cos(r));
}

//ROTA UN PUNTO CON RESPECTO A OTRO PUNTO
punto Trasnladar(const punto & o, const punto & p){
    return punto(p.x - o.x,
                 p.y - o.y);
}

//INVIERTE POSICION DE UN PUNTO
punto Opuesto(const punto & v){
    return punto(-v.x, -v.y);
}

bool igual(Coord a, Coord b){
    return abs(a - b) < ERR;
}


int main(){
    return 0;
}
