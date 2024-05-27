#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int randNumber()
{
    int random_number = rand() % 100 - 50;
    return random_number;
}

void fillArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = randNumber();
    }
}

int *removeNegativeValue(int *array, int size, int &newSize)
{
    newSize = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            newSize++;
        }
    }

    int *arrayWithoutNegativeValue = new int[newSize];

    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            arrayWithoutNegativeValue[index++] = array[i];
        }
    }

    return arrayWithoutNegativeValue;
}

int main()
{
    srand(time(0));

    const int size = 20;
    int numbers[size];

    fillArray(numbers, size);

    cout << "Original array:\n";
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    int newSize;
    int *newArray = removeNegativeValue(numbers, size, newSize);

    cout << "New array without negative values:\n";
    for (int i = 0; i < newSize; i++)
    {
        cout << newArray[i] << " ";
    }
    cout << endl;

    delete[] newArray;

    return 0;
}
