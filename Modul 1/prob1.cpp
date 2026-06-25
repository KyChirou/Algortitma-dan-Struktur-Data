#include <iostream>
#include "line.h"
using namespace std;

int main() {
    Line l;
    Point p;

    cin >> l.a >> l.b >> l.c >> p.x >> p.y;

    double result = gradient(&l, &p);

    cout << CheckPointPosition(result) << endl;

    return 0;
}