// Problem: Two Sum
/*
Description:
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
 and you may not use the same element twice.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int randNumber()
{
    int random_number = rand() % 10;
    return random_number;
}

void fillArray(int *array)
{
    for (int i = 0; i < 10; i++)
    {
        array[i] = randNumber();
    }
}

int main()
{
    const int __TARGET__ = 10;

    int array[10];

    cout << "array after filling\n";

    fillArray(array);
    for (int i = 0; i < 10; i++)
    {
        cout << array[i];
        cout << "\n";
    }

    srand(time(0));
    return 0;
}

int twoSum(int array[], int target)
{
    for (int i = 0; i < 10; i++)
    {
        if (array[i] + array[i + 1] == target)
        {
            cout << "found";
        
        }
    }
}
