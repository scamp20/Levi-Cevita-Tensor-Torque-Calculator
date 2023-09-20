#include <iostream>
using namespace std;

int calculateTensorNode(int sequence[3]) {
    int swaps_count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (sequence[j] == sequence[j+1]) { return 0; }
            if (sequence[j] > sequence[j+1]) {
                int swap = sequence[j+1];
                sequence[j+1] = sequence[j];
                sequence[j] = swap;
                ++swaps_count;
            }
        }
    }
    if (swaps_count % 2 == 0) { return 1; }
    else { return -1; }
}

int main() {
    float momentArm[3];
    float force[3];
    cout << "Welcome to the Torque calculator!\n\n";
    cout << "Enter Moment Arm vector X component\n";
    cin >> momentArm[0];
    cout << "Enter Moment Arm vector Y component\n";
    cin >> momentArm[1];
    cout << "Enter Moment Arm vector Z component\n";
    cin >> momentArm[2];
    cout << "Enter Force vector X component\n";
    cin >> force[0];
    cout << "Enter Force vector Y component\n";
    cin >> force[1];
    cout << "Enter Force vector Z component\n";
    cin >> force[2];

    cout << "\nCalculating Torque using a Levi-Civita Tensor...\n\n";
    float torque[3] = {0,0,0};
    int leviCivitaTensor[3][3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                int array[3] = {i,j,k};
                leviCivitaTensor[i][j][k] = calculateTensorNode(array);
            }
        }
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                torque[k] += (momentArm[i] * force[j] * (float)leviCivitaTensor[i][j][k]);
            }
        }
    }

    cout << "X component of Torque is: " << torque[0] << endl;
    cout << "Y component of Torque is: " << torque[1] << endl;
    cout << "Z component of Torque is: " << torque[2] << endl;

    return 0;
}