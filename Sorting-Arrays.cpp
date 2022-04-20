
#include <iostream>
#include <iomanip> 

using namespace std;

// Const 
const int SIZE = 20;

// Function Prototypes 
void outputArray ( int [], int SIZE );
int bubbleSort ( int [], int SIZE );
int selectionSort ( int [], int SIZE );

int arrayA[SIZE] = { 3, 5, 7, 1, 7, -3, 0, 5, -5, 2, 11,
                        -4, 13, -6, 9, 12, -1, 24, 3, 10 };
    
int arrayB[SIZE] = { 3, 5, 7, 1, 7, -3, 0, 5, -5, 2, 11,
                        -4, 13, -6, 9, 12, -1, 24, 3, 10};  

int main ()
{

    int swapCountA;
    int swapCountB;

    //cout << "Bubble sorted ascending array: " << endl;
    //outputArray ( arrayA, SIZE );

    //cout << "Selection sorted ascending array: " << endl;
    //outputArray ( arrayB, SIZE );
    
    swapCountA = bubbleSort ( arrayA, SIZE );

    swapCountB = selectionSort ( arrayB, SIZE );
    

    cout << "Number of exchanges for the Bubble sort: " << swapCountA << endl;
    cout << "Number of exchanges for the Selection sort: " << swapCountB << endl;

    return 0;

}

void outputArray ( int [], int SIZE ) // Output Function 
{
    
    
    cout << "Bubble sorted ascending array: " << endl;
    for ( int i = 0; i < SIZE; i++ )
    {
        cout << arrayA[i] << "  ";
    }
    cout << endl;

    cout << "Selection sorted ascending array: " << endl;
    for ( int i = 0; i < SIZE; i++ )
    {
        cout << arrayB[i] << "  ";
    } 
    cout << endl;
    
    
}

int bubbleSort ( int arrayA[], int SIZE ) // Bubble Sort Method *ascending* 
{
    bool swap;
    int swapCountA = 0;  
    int temp; 

    do
    {
        swap = false;
        for ( int i = 0; i < ( SIZE - 1 ); i++ )
        {
            if ( arrayA[i] > arrayA[ i + 1 ] )
            {
                temp = arrayA[i];
                arrayA[i] = arrayA[ i + 1];
                arrayA[ i + 1 ] = temp;
                swap = true;
                swapCountA++;
            }
        }
    } while ( swap );

    //outputArray ( arrayA, SIZE );

    return swapCountA;
}

int selectionSort ( int arrayB[], int SIZE ) // Selection Sort *descending*   
{
    int startScan, maxIndex, maxValue;
    int  swapCountB = 0;

    for ( startScan = 0; startScan < ( SIZE - 1 ); startScan++ )
    {
        maxIndex = startScan;
        maxValue = arrayB[startScan];
        for ( int i = startScan + 1; i < SIZE; i++ )
        {
            if ( arrayB[i] > maxValue )
            {
                maxValue = arrayB[i];
                maxIndex = i;
                swapCountB++;
            }
        }
        arrayB[maxIndex] = arrayB[startScan];
        arrayB[startScan] = maxValue;
    }

    outputArray ( arrayB, SIZE );

    return swapCountB;
}

