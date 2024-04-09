#include<iostream>
using namespace std;


bool isSafe(int row, int col, int arr[9][9], int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == val)
            return false;
        if (arr[i][col] == val)
            return false;
        if (arr[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool solve(int arr[][9])
{

    int n = 9;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // empty cell

            if (arr[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, arr, val))
                    {
                        arr[row][col] = val;

                        bool aage_ka_ans = solve(arr);

                        if (aage_ka_ans)
                        {
                            return true;
                        }
                        else
                        {
                            // backtrack
                            arr[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
}

int main(){

    int grid = 9;

    int arr[9][9];

    cout << endl<< endl<< "--------------------------------------- WELCOME TO SUDOKU SOLVER -----------------------------------";
    cout << endl<< endl<< "\tNOTE -> ENTER 0 WHERE CELL IS EMPTY :) " << endl;
    cout<<"\t-> READ ROW AND COL NUMBER FOR NO MISTAKE :) "<<endl<<endl;

    cout << "->enter a valid sudoku : " << endl<<endl;

    for(int i=0;i<grid;i++)
    {
        for(int j=0;j<grid;j++)
        {
            cout<<"enter the value of " << i+1 << " row and "<< j+1 <<" col : ";
            cin>>arr[i][j];
        }
    }

    cout<<endl<<endl<<"before board : "<<endl<<endl;

    for (int i = 0; i < grid; i++)
    {
        for (int j = 0; j < grid; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl<<endl;



    solve(arr);

    cout << endl  << "\t-> HERE IS THE SOLUTION :" << endl<< endl;

    for (int i = 0; i < grid; i++)
    {
        for (int j = 0; j < grid; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
