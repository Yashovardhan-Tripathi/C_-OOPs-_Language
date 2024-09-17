#include <bits/stdc++.h>

using namespace std;

class Point_set_2;
class Point_set_1

{
    int a_1, b_1;

public:
    Point_set_1(int x1 , int y1)
    {
        a_1 = x1;
        b_1 = y1;
    }
    void displayPoint()
    {
        cout << "The Point is (" << a_1 << "," << b_1<<")" << endl;
    }
    friend float distance_of_points(Point_set_1 P1, Point_set_2 P2);
};

class Point_set_2
{
    int a_2, b_2;

public:
    Point_set_2(int x2,int y2)
    {
        a_2 = x2;
        b_2 = y2;
    }
 void displayPoint()
    {
        cout << "The Point is (" << a_2 << "," << b_2<<")" << endl;
    }
    friend float distance_of_points(Point_set_1 P1, Point_set_2 P2);
};

float distance_of_points(Point_set_1 P1, Point_set_2 P2)
{
    int X = pow((P2.a_2 - P1.a_1), 2);
    int Y = pow((P2.b_2 - P1.b_1), 2);
    return sqrt(X + Y);
}

int main()
{
    
    int x3, y3, x4, y4;
    cout << "Enter Point 1 (x y): ";
    cin >> x3 >> y3;

    cout << "Enter Point 2 (x y): ";
    cin >> x4 >> y4;
    
    Point_set_1 x(x3 , y3);
    Point_set_2 y(x4 , y4);

    x.displayPoint();
    y.displayPoint();

    float dist = distance_of_points(x, y);
    cout << "Distance between the points: " << dist << endl;

    return 0;
}
//     Point_set_1 X();
//     X.Input_a_1();
//     Y.Input_b_1();

//     Point_set_2 Y();
//     Y.Input_a_2();
//     Y.Input_b_2();

//     distance_of_points(X, Y);

//     return 0;
// }
// }
/*
#include <iostream>
#include <cmath> // Include cmath for sqrt function

using namespace std;

class Point_set_2; // Forward declaration

class Point_set_1
{
    int a_1, b_1;

public:
    Point_set_1(int x, int y) : a_1(x), b_1(y) {} // Constructor with initialization
    void displayPoint()
    {
        cout << "Point 1: (" << a_1 << "," << b_1 << ")" << endl;
    }
};

class Point_set_2
{
    int a_2, b_2;

public:
    Point_set_2(int x, int y) : a_2(x), b_2(y) {} // Constructor with initialization
    void displayPoint()
    {
        cout << "Point 2: (" << a_2 << "," << b_2 << ")" << endl;
    }
    friend float distance_of_points(Point_set_1 P1, Point_set_2 P2);
};

float distance_of_points(Point_set_1 P1, Point_set_2 P2)
{
    int X = pow((P2.a_2 - P1.a_1), 2);
    int Y = pow((P2.b_2 - P1.b_1), 2);
    return sqrt(X + Y); // Return the calculated distance
}

int main()
{
    int x1, y1, x2, y2;
    cout << "Enter Point 1 (x y): ";
    cin >> x1 >> y1;

    cout << "Enter Point 2 (x y): ";
    cin >> x2 >> y2;

    Point_set_1 X(x1, y1);
    Point_set_2 Y(x2, y2);

    X.displayPoint();
    Y.displayPoint();

    float dist = distance_of_points(X, Y);
    cout << "Distance between the points: " << dist << endl;

    return 0;
}
*/