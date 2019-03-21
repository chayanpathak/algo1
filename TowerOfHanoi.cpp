#include <iostream>
#include <math.h>
using namespace std;

void towersofhanoi(char from_peg, char aux_peg, char to_peg, int num_disks){
    if (num_disks >= 2) {
        cout << "\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
        cout << "\n transferring" << num_disks - 1 << " disks from " << from_peg << " to " << aux_peg;
        towersofhanoi(from_peg, to_peg, aux_peg, num_disks - 1);
        cout << "\n transferring" << 1 << " disk from " << from_peg << " to " << to_peg;
        towersofhanoi(from_peg, aux_peg, to_peg, 1);
        cout << "\n transferring" << 1 << " disk from " << from_peg << " to " << to_peg;
        towersofhanoi(aux_peg, to_peg, from_peg, num_disks - 2);
        cout << "\n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
    }
}
int main() {
    // your code goes here
    char a,b,c;
    a = 'A';
    b = 'B';
    c = 'C';
    int number_of_disks = 11;
    towersofhanoi(a,b,c,number_of_disks);
    return 0;
}
