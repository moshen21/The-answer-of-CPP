#include <iostream>
#include "Thirteen.h"
using namespace std;
/*13_1
void Bravo(const Cd & disk);
int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                        "Alfred Brendel", "Philips", 2, 57.17);
    Cd * pcd = & c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    cout << "Using type cd * pointer to object:\n";
    pcd->Report();
    pcd = & c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}
void Bravo(const Cd & disk){
    disk.Report();
}
*/
/*13_2*/
void Bravo(const Exercise2::Cd & disk);
int main() {
    Exercise2::Cd c1("Beatles", "Capitol", 14, 35.5);
    Exercise2::Classic c2 = Exercise2::Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Exercise2::Cd * pcd = & c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    cout << "Using type cd * pointer to object:\n";
    pcd->Report();
    pcd = & c2;
    pcd->Report();
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Exercise2::Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}
void Bravo(const Exercise2::Cd & disk){
    disk.Report();
}












