#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string input = "input.txt", output = "output.txt";
fstream inp(input);
ofstream out(output);

double distance(double x1, double y1, double x2, double y2) {
    double d;
    d = pow(pow(x2-x1, 2) + pow(y2-y1, 2), 0.5);
    return d;
}

void Check_Intersections(double x1, double y1, double x2, double y2, 
                        double x3, double y3, double x4, double y4, 
                        double B1, double B2, double A1, double A2,
                        double C1, double C2) {
    double x, y;
    if ((B1 * A2 - B2 * A1) && A1) {
        y = (C2*A1 - C1*A2) / (B1*A2 - B2*A1);
        x = (-C1 - B1*y) / A1;
    }
    else if (B1*A2 - B2*A1 && A2) {
        y = (C2*A1 - C1*A2) / (B1*A2 - B2*A1);
        x = (-C2 - B2*y) / A2;
    }
    if ((y != 0) || (x != 0))
        out << 0;
        exit(0);
}
void Check_Parallelism(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    //Ax+By+C=0
    double A1, B1, A2, B2, C1, C2;
    //first line
    A1 = y2 - y1;
    B1 = x1 - x2;
    C1 = (x1 - x2) * y1 - (y2 - y1) * x1;
    //second line
    A2 = y4 - y3;
    B2 = x3 - x4;
    C2 = (x3 - x4) * y1 - (y4 - y3) * x1;
    

    if ((A1 / A2) == (B1 / B2)) {

        if (distance(x1, y1, x4, y4) > distance(x1, y1, x3, y3))
            out << distance(x1, y1, x3, y3);
        else out << distance(x1, y1, x4, y4);
        exit(0);
    }
    Check_Intersections(x1, y1, x2, y2, x3, y3, x4, y4, B1, B2, A1, A2, C1, C2);
}



int main() {

    double x1, y1, x2, y2;
    double x3, y3, x4, y4;

    inp >> x1 >> y1 >> x2 >> y2;
    inp >> x3 >> y3 >> x4 >> y4;

    Check_Parallelism(x1, y1, x2, y2, x3, y3, x4, y4);

    double distances [] = {
        distance(x1, y1, x3, y3),
        distance(x1, y1, x4, y4),
        distance(x2, y2, x3, y3),
        distance(x2, y2, x4, y4),

    };

    double minDist = distances[0];
    for (int i; i < sizeof(distances); i++)
        if (distances[i] < minDist)
            minDist = distances[i];

    
    

    out << minDist;
    
}
