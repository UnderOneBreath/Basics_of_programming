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

// void Check_Intersections(double x1, double y1, double x2, double y2, 
//                         double x3, double y3, double x4, double y4, 
//                         double B1, double B2, double A1, double A2,
//                         double C1, double C2) {
//     double x, y;
//     if ((B1 * A2 - B2 * A1) && A1) {
//         y = (C2*A1 - C1*A2) / (B1*A2 - B2*A1);
//         x = (-C1 - B1*y) / A1;
//     }
//     else if (B1*A2 - B2*A1 && A2) {
//         y = (C2*A1 - C1*A2) / (B1*A2 - B2*A1);
//         x = (-C2 - B2*y) / A2;
//     }
//     if ((y != 0) || (x != 0))
//         out << 0;
//         exit(0);
// }


double point_to_distance(double x, double y, double A, double B, double C) {
    return abs(A*x + B*y + C)/sqrt(A*A + B*B);
}

bool LineSegmentsIntersection(double x1, double y1, double x2, double y2, 
    double x3, double y3, double x4, double y4)
{
    double _1 = x1 - x2;
    double _2 = x1 - x3;
    double _3 = x3 - x4;
    double _4 = y1 - y2;
    double _5 = y1 - y3;
    double _6 = y3 - y4;
    double d = _1 *_6 - _4 * _3;
    double t = (_2 * _6 - _5 * _3) / d;
    double u = (_2 * _4 - _5 * _1) / d;
    return t >= 0. && t <= 1. && u >= 0. && u <= 1.;
}

int main() {

    double x1, y1, x2, y2;
    double x3, y3, x4, y4;

    inp >> x1 >> y1 >> x2 >> y2;
    inp >> x3 >> y3 >> x4 >> y4;

    //CHECK PARALLELISM
    double A1, B1, A2, B2, C1, C2;
    //first line
    A1 = y1 - y2;
    B1 = x2 - x1;
    C1 = (-1)* A1 * x1 - B1 * y1;
    //second line
    A2 = y3 - y4;
    B2 = x4 - x3;
    C2 = (-1)* A2 * x3 - B2 * y3;

    const int N = 4;
    double distances [N] = {
        distance(x1, y1, x3, y3),
        distance(x1, y1, x4, y4),
        distance(x2, y2, x3, y3),
        distance(x2, y2, x4, y4),
    };

    double minDist = distances[0];
    for (int i = 0; i < N; i++)
        if (distances[i] < minDist)
            minDist = distances[i];
    
    // out << A2 << ' ' << B2 << ' ' << C2;
    if ((A1 / A2) == (B1 / B2) || ((A1 == 0 && A2 == 0) && (B1 / B2)) || ((B1 == 0 && B2 == 0) && (A1 / A2))) {
        // for (int i = 0; i < N; i++)
        //     out << distances[i] << ' ';
        out << minDist;
        exit(0);
    }
    // Check_Intersections(x1, y1, x2, y2, x3, y3, x4, y4, B1, B2, A1, A2, C1, C2);
    out << LineSegmentsIntersection(x1, y1, x2, y2, x3, y3, x4, y4);

    // if (point_to_distance(x1, y1, A2, B2, C2) < point_to_distance(x2, y2, A2, B2, C2))
    //     out << point_to_distance(x1, y1, A2, B2, C2);
    // else out << point_to_distance(x2, y2, A2, B2, C2);
}
