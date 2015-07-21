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

typedef vector<punto> poligono;
//Dejar a P1 al final

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
punto Transladar(const punto & o, const punto & p){
    return punto(p.x - o.x,
                 p.y - o.y);
}

//INVIERTE POSICION DE UN PUNTO
punto Opuesto(const punto & v){
    return punto(-v.x, -v.y);
}

//ANGULO ENTRE PUNTOS
double AnguloEntre(const punto & v, const punto & w){
    double r = ( acos( Dot(v,w) / (Magnitud(v) * Magnitud(w)) ) );
    return RadAGrados(r);
}

//CAMBIAR TAMAÑO DE UN VECTOR
punto Escalar(const punto & v, double s){
    return punto(v.x * s, v.y * s);
}

bool igual(Coord a, Coord b){
    return abs(a - b) < ERR;
}

//DENTRO 1
//FUERA -1
//COLINEAL 0
int ManoDerecha(const punto & o,
                const punto & v,
                const punto & w){
    double cruz = Cruz(Transladar(o,v),Transladar(o,w));
    if(igual(cruz , 0)) return 0;
    return (cruz < 0)? -1 : 1;
}

bool PuntoEnPConvexo(poligono P, punto p){
    int dir = ManoDerecha(P[0],P[1],p);
    int tam = P.size();
    for(int i = 1; i <= tam; i++){
        if(abs(ManoDerecha(P[i],P[i + 1],p) - dir) == 2)
            return false;
    }
    return true;
}

int main(){
    return 0;
}
