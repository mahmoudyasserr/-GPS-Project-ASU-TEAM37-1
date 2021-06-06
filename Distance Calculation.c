#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// get 2 coordinates from GPS function in Degrees Decimal Minutes (DDM) and return the distance

int distance(int degree_lat1, double min_lat1, int degree_lon1, double min_lon1, int degree_lat2, double min_lat2, int degree_lon2, double min_lon2) {
    double lon;
    double dist;
    double Latitude1, long1 , Latitude2 , long2;

    Latitude1 = deg(degree_lat1 , min_lat1);
    long1 = deg(degree_lon1 , min_lon1);
    Latitude2 = deg(degree_lat2 , min_lat2);
    long2 = deg(degree_lon2 , min_lon2);

    if ((Latitude1 == Latitude2) && (long1 == long2)) {
        return 0;
        }
    else {
        lon = long1 - long2;
        dist = (sin(degtorad(Latitude1)) * sin(degtorad(Latitude2))) + (cos(degtorad(Latitude1)) * cos(degtorad(Latitude2)) * cos(degtorad(lon)));
        dist = acos(dist);
        dist = radtodeg(dist);
        dist = dist * 60 * 1.1515;
        dist = dist * 1.609344 * 1000;

        return (dist);
        }
    }

//this function take the coordinates from gps and return its degree

int Deg(double x) {
int Deg_lat;
x = x /100;
Deg_lat = (int)x;
return Deg_lat;
}

//this function take the coordinates from gps and return its minutes

double Min(double x) {
double Min_lat;
int Deg_lat = Deg(x);
Min_lat = x - (Deg_lat*100);
return Min_lat;

}
