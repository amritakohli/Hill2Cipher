/*
This program demonstrates a Hill-2 cipher

KEY:
A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

Key matrix A =
4 1
3 2
*/

#include <iostream>

using namespace std;

//function prototypes
void encrypt(int Ap[][1], int **p, int A[][2]);
void HillCipher(string pt);

//main function
int main()
{
    string input;
    cout << "Enter a word (capital letters): " << endl;
    getline(cin, input);

    cout << "Plaintext is: " << input << endl;
    HillCipher(input);

    return 0;
}

void HillCipher(string pt)
{
    //pt = plaintext string
    // A is 2x2
    int A[2][2]; //this will be our key matrix "A"
    A[0][0]=4; //1st row 1st col
    A[0][1]=1; //1st row 2nd col
    A[1][0]=3; //2nd row 1st col
    A[1][1]=2; //2nd row 2nd col


    string ct = ""; //ct = ciphertext string
    string pair=""; //pair = pairs of the input (plaintext) string

    int len = pt.length();
    int n =0;
    //Creating p vector dynamically
    int **p = new int *[2]; //rows = 2
    for (int i = 0; i < 2; i++)
    {
        p[i] = new int[1]; //cols = 1
    }
    //loop breaks when there's no more pairs
   while(n<len)
   {
       p[1][0]=0; //setting second element in the p vector to 0 just in case it's odd

       pair=pt.substr(n,2);

       cout << "Pair: " << pair << endl;

       for (int i = 0; i < 2; i++)
           p[i][0] = (pair[i] % 65); //putting numbers for the letters in the plaintext vector
       //A = 65 in ASCII, Z = 90 in ASCII - (65%65 = 0) so this operation changes the numbers associated to A=0 through Z=25

       int Ap[2][1]; //cipher vector

       //calling encrypt function to give us Ap
       encrypt(Ap, p, A);

       for(int i=0; i<2; i++)
           ct+=Ap[i][0]+65; //adding 65 gives the respective ASCII value and adding the respective letter to ciphertext string

       n+=2;
   }
   cout << "Ciphertext is " << ct << endl;

   delete [] p; // deleting p
}

//Reference source used: https://www.geeksforgeeks.org/hill-cipher/
//This function multiplies A and p and gives Ap
void encrypt(int Ap[][1], int **p, int A[][2])
{
    cout << "Ap vector = " << endl;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<1; j++)
        {
            Ap[i][j] = 0; //initializing
            for (int k = 0; k < 2; k++)
            {
                Ap[i][j] += A[i][k] * p[k][j]; //Multiplying A and p
            }
            Ap[i][j] = Ap[i][j] % 26; //we want it to be within range of letters 0-25
            cout << Ap[i][j] << endl;
        }
    }
}
































/* rip function -
int** createA()
{
    // A is 2x2
    int **A = new int*[2]; //rows = 2
    for (int i = 0; i < 2; i++)
    {
        A[i] = new int[2]; //cols = 2
    }
    //int A[2][2]; //this will be our key matrix "A"
    A[0][0]=4; //1st row 1st col
    A[0][1]=1; //1st row 2nd col
    A[1][0]=3; //2nd row 1st col
    A[1][1]=2; //2nd row 2nd col

    return A;
}*/




