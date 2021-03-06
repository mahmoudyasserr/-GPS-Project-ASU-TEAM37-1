#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535

double degtorad(double deg);
double radtodeg(double rad);
double deg_DD(int degree,double min);

// get 2 coordinates from GPS function in Degrees Decimal Minutes (DDM) and return the distance

int distance(int degree_lat1, double min_lat1, int degree_lon1, double min_lon1, int degree_lat2, double min_lat2, int degree_lon2, double min_lon2) {
    double lon;
    double dist;
    double Latitude1, long1 , Latitude2 , long2;

    Latitude1 = deg_DD(degree_lat1 , min_lat1);
    long1 = deg_DD(degree_lon1 , min_lon1);
    Latitude2 = deg_DD(degree_lat2 , min_lat2);
    long2 = deg_DD(degree_lon2 , min_lon2);

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



// this function convert from degree to radian
double degtorad(double deg) {
    return (deg * PI / 180);
}
// this function convert from radian to degree
double radtodeg(double rad) {
    return (rad * 180 / PI);
}
    // this function convert from Degrees Decimal Minutes (DDM) to Degrees Decimal (DD)
double deg_DD(int degree,double min) {
    double deg;
    deg = degree +(min/60);
    return deg;
}


    // test distance function
    int main() {

      int z = distance( 31,  13.802,  30,  25.84 , 31,  13.6872,  30,  25.057 );  //dummy data

       printf("distance is %d meters\n" , z);

        return 0;
    }
