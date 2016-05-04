//
//  main.cpp
//  Ermolovich.FileLab1
//
//  Created by Evgeny on 04.05.16.
//  Copyright © 2016 Evgeny. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

void CreateFile(char* , int );
void CreateNewFile(char* , char* );
void ShowContentsFile(char* );

const int N = 100;

int main()
{
    char fileName[N] = "";
    cout << "Enter the name of file: ";
    cin >> fileName;
    int n;
    cout << "Enter count of numbers:" << endl;
    cin >> n;
    CreateFile(fileName, n);
    char newFileName[N] = "";
    cout << "Enter the name of new file: ";
    cin >> newFileName;
    cout << "SOURCE FILE" << endl;
    ShowContentsFile(fileName);
    CreateNewFile(fileName, newFileName);
    cout << "NEW FILE" << endl;
    ShowContentsFile(newFileName);
    cout << endl;
    return 0;
}

void CreateFile(char* fileName, int n)
{
    ofstream streamOut(fileName);
    if (!streamOut.is_open())
    {
        cout << "Cannot open file to write!" << endl;
        main();
    }
    cout << "Enter the elements of array" << endl;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cout << "enter temp variable:";
        cin >> temp;
        streamOut.width(5);
        streamOut << temp;
    }
    streamOut.close();
}
void CreateNewFile(char* fileName, char* newFileName)
{
    ifstream streamIn(fileName);
    ofstream streamOut(newFileName);
    if (!streamIn.is_open())
    {
        cout << " Cannot open file " << fileName << " to read!" << endl;
        main();
    }
    if (!streamOut.is_open())
    {
        cout << " Cannot open file " << newFileName << " to write!" << endl;
        main();
    }
    while (!streamIn.eof())
    {
        int temp = 0;
        streamIn >> temp;
        streamOut << temp << endl;
    }
    streamIn.close();
    streamOut.close();
}
void ShowContentsFile(char* fileName)
{
    ifstream streamIn;
    streamIn.open(fileName);
    if (!streamIn.is_open())
    {
        cout << " Cannot open file " << fileName << " to read!" << endl;
        main();
    }
    char String[N] = "";
    while (!streamIn.eof())
    {
        streamIn.getline(String, N, '\n');
        cout << String << endl;
    }
}
