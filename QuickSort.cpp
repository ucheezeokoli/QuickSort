#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int Partition (vector<int>& FreeSpace, int p, int size)
{
    int back = FreeSpace.at(size);
    int i = (p - 1);
    int j, temp;

    for (j = p; j < size; j++)
    {
        if (FreeSpace.at(j) <= back)
        {
            i++;
            temp = FreeSpace.at(i);
            FreeSpace.at(i) = FreeSpace.at(j);
            FreeSpace.at(j) = temp;
        }
    }
    temp = FreeSpace.at(i + 1);
    FreeSpace.at(i + 1) = FreeSpace.at(size);
    FreeSpace.at(size) = temp;
    return (i + 1);
}

int QuickSort(vector<int>& FreeSpace, int p, int size)
{
    int q;

    if (p < size)
    {
        q  = Partition(FreeSpace, p, size);
        QuickSort(FreeSpace, p, (q - 1));
        QuickSort(FreeSpace, (q + 1), size);    
    }
}

int main()
{
    int start = 0;
    int size;
    cin >> size;

    vector<int> FreeSpace(size); // DECLARE VECTOR WITH SIZE FROM INPUT

    // FILL VECTOR W/ VALUES
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> FreeSpace.at(i);
    }

    size--;

    QuickSort(FreeSpace, 0, size);

    for (i = 0; i < FreeSpace.size(); i++)
    {
        cout << FreeSpace.at(i) << ";";
    }
}
