#include <iostream>
using namespace std;

int main()
{
    int array[10] = { 5, 2, 8, 2, 6, 1, 0, 9, 1, 3 };
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10 && j != i; j++) {
            if (array[i]+array[j]==10) {
                cout << "indices" << i << "+" << j << "=10" << endl;
            }
     }
    return 0;
}