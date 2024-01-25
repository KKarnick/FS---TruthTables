
#include <iostream>

using namespace std;

bool A, B, C;

bool funXor(bool A, bool B);
bool funImp(bool A, bool B);
bool funNand(bool A, bool B);
bool funNor(bool A, bool B);
bool funXnor(bool A, bool B);

void display(bool);

int main() {
    int i, j, k;

    cout << "Truth table for (A nor C) xor B :\n" << endl;
    cout << "  A    B    C    OUTPUT" << endl;

    for (i = 0; i < 2; ++i) {          //A will be evaluated at 0 then 1 (false then true)
        A = i;
        for (j = 0; j < 2; ++j) {
            B = j;                     //B will be evaluated at 0 then 1 (false then true)
            for (k = 0; k < 2; ++k) {
                C = k;                 //C will be evaluated at 0 then 1 (false then true)
                bool ans1 = funNor(A, C);
                bool ans2 = funXor(ans1, B);
                display(ans2);
            }
        }
    }
    cout << "\n\n";
    cout << "Truth table for (B->C) nand (A nor B) :\n" << endl;
    cout << "  A    B    C    OUTPUT" << endl;

    for (i = 0; i < 2; ++i) {          //Same process as above, but with different truth table
        A = i;
        for (j = 0; j < 2; ++j) {
            B = j;
            for (k = 0; k < 2; ++k) {
                C = k;
                bool ans3 = funImp(B, C);
                bool ans4 = funNor(A, B);
                bool ans5 = funNand(ans3, ans4);
                display(ans5);
            }
        }
    }
    cout << "\n\n";
    cout << "Truth table for (A xor B) -> (B xnor C)  :\n" << endl;
    cout << "  A    B    C    OUTPUT" << endl;

    for (i = 0; i < 2; ++i) {          //Same process as above
        A = i;
        for (j = 0; j < 2; ++j) {
            B = j;
            for (k = 0; k < 2; ++k) {
                C = k;
                bool ans6 = funXor(A, B);
                bool ans7 = funXnor(B, C);
                bool ans8 = funImp(ans6, ans7);
                display(ans8);
            }
        }
    }
    cout << "\n\n";
    cout << "Truth table for (A->B) -> !C :\n" << endl;
    cout << "  A    B    C    OUTPUT" << endl;

    for (i = 0; i < 2; ++i) {          //Same process as above
        A = i;
        for (j = 0; j < 2; ++j) {
            B = j;
            for (k = 0; k < 2; ++k) {
                C = k;
                bool ans9 = funImp(A, B);
                bool ans10 = funImp(ans9, !C);
                display(ans10);
            }
        }
    }
}

bool funXor(bool A, bool B) {
    if (A != B) {
        return true;
    }
    else {
        return false;
    }
}
bool funImp(bool A, bool B) {
    if (!(A && !B)) {
        return true;
    }
    else {
        return false;
    }
}
bool funNand(bool A, bool B) {
    if (!(A && B)) {
        return true;
    }
    else {
        return false;
    }
}
bool funNor(bool A, bool B) {
    if (!(A || B)) {
        return true;
    }
    else {
        return false;
    }
}
bool funXnor(bool A, bool B) {
    if (A == B) {
        return true;
    }
    else {
        return false;
    }
}
void display(bool x) {
    cout << "  " << A << "    " << B << "    " << C << "    ";
    if (x) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}