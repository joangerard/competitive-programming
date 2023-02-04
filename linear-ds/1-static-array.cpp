#include <iostream>
using namespace std;
 
int main()
{
    const int SIZE = 4;
    const int NUMBER_OF_STUDENTS = 3;
    const int NUMBER_OF_EXAMS = 4;
    
    // FIRST FORM   
    int staticArray[SIZE];
    staticArray[0] = 100;
    staticArray[1] = 58;
    staticArray[2] = 24;
    staticArray[3] = 5;

    cout << "FIRST STATIC ARRAY: "<<endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << staticArray[i] << " ";
    }

    // SECOND FORM
    int otherStaticArray[SIZE] = {1, 3, 4, 5};

    cout <<endl<< "SECOND STATIC ARRAY: "<<endl;
    for(int i = 0; i < SIZE; i++)
    {
        cout << otherStaticArray[i] << " ";
    }

    // MULTI DIM
    float staticExamScores2[NUMBER_OF_STUDENTS][NUMBER_OF_EXAMS];
 
    // Student 1's exam scores.
    staticExamScores2[0][0] = 99.5;
    staticExamScores2[0][1] = 90.3;
    staticExamScores2[0][2] = 93.1;
    staticExamScores2[0][3] = 89.5;
 
    // Student 2's exam scores.
    staticExamScores2[1][0] = 85.3;
    staticExamScores2[1][1] = 95.2;
    staticExamScores2[1][2] = 88.7;
    staticExamScores2[1][3] = 85.2;
 
    // Student 3's exam scores.
    staticExamScores2[2][0] = 76.5;
    staticExamScores2[2][1] = 82.3;
    staticExamScores2[2][2] = 73.4;
    staticExamScores2[2][3] = 70.3;
 
    cout<<endl<<"Multi DIM:"<<endl;
    // Print the second set of exam grades.
    for(int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        for(int j = 0; j < NUMBER_OF_EXAMS; j++)
            cout << staticExamScores2[i][j] << " ";
        cout << endl;
    }
    cout << endl;

}