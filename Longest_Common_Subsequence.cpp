/**********************************************************************************

# What is LCS ?
  Longest Common Subsequence is an algorithm that helps us find a subsequence which
  is common in two different sequences and is longest among all the common subsequences.
  
# Example
  It can be understood more clearly with the following example-
  sequence1 = ADCB
  sequence2 = DAC
  subsequences of sequence1 : {A, D, C, B, AD, AC, AB, DC, DB, CB, ADC, ADB, ACB, DCB, ADCB}
  subsequences of sequence2 : {D, A, C, DA, DC, AC, DAC}
  common subsequences are : {A, D, C, AC, DC}
  longest common subsequence : {AC, DC}
  
# Working
  Dynamic Programming is used to find the LCS.
  This algorithm has a time complexity of O(m*n); where m, n is the length of the two sequences.
  Steps to follow :-
  
  Step1: Creating LCS Table
         The table would look like this for the two sequences-
                  D   A   C                          A   D   C   B
              0   0   0   0                      0   0   0   0   0
          A   0   _   _   _                  D   0   _   _   _   _
          D   0   _   _   _        OR        A   0   _   _   _   _
          C   0   _   _   _                  C   0   _   _   _   _
          B   0   _   _   _                
           
  Step2: Filling the table
         1) If the current cell(i, j) has same row and column name,
            then current cell value = {cell(i-1, j-1) + 1} and point it diagonally↖️.
            ex. for cell(1, 2)
                row = A, column = A
                valueAt(1, 2) = valueAt(0, 1) + 1
                              = 0 + 1 = 1
         2) If the current cell(i, j) does not have same row and column name,
            then current cell value = {max(cell(i, j-1), cell(i-1, j)} and point it upward⬆️ if(valueAt(i, j-1) < valueAt(i-1, j)) else point it left⬅️.
            ex. for cell(1, 1)
                row = A, column = D
                valueAt(1, 1) = max(valueAt(1, 0), valueAt(0, 1))
                              = max(0, 0) = 0
                     D      A      C
              0      0      0      0
          A   0    0⬆️   1↖️    0⬆️
          D   0    1↖️   1⬆️    1⬅️
          C   0    1⬆️   1⬆️    2↖️
          B   0    1⬆️   1⬆️    2⬆️
           
  Step3: Finding LCS
         The last value in the LCS table is the length of the LCS.
         Now we will create a path from last cell using arrows.
         The path will be-
                     D       A      C
              0      0       0      0
          A   0    0🟥    1↖️    0🟥
          D   0    1🟥    1⬆️    1🟥
          C   0    1🟥    1🟥    2↖️
          B   0    1🟥    1🟥    2⬆️
          The cells with diagonal arrow is our answer.
          So, the result is AC.
           
NOTE:- If you take ADCB as row and DAC as column, then LCS will be AC
       And if you take DAC as row and ADCB as column, then LCS will be DC
       But still the length of LCS will be same.
       
***********************************************************************************/

// The C++ implementation of the LCS algorithm is as follows--

#include <iostream>
#include <cstring>
using namespace std;

void lcsAlgo(char *S1, char *S2, int m, int n)
{
  int LCS_table[m + 1][n + 1];
  
  // Building the matrix in bottom-up way
  for (int i = 0; i <= m; i++) 
  {
    for (int j = 0; j <= n; j++) 
    {
      if (i == 0 || j == 0)
        LCS_table[i][j] = 0;
      else if (S1[i - 1] == S2[j - 1])
        LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
      else
        LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]);
    }
  }

  int index = LCS_table[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) 
  {
    if (S1[i - 1] == S2[j - 1]) 
    {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }
    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }
  
  // Printing the sub sequences
  cout << "S1 : " << S1 << "\nS2 : " << S2 << "\nLCS: " << lcsAlgo << "\n";
}

int main()
{
  char S1[] = "CBDA";
  char S2[] = "ACADB";
  int m = strlen(S1);
  int n = strlen(S2);
  lcsAlgo(S1, S2, m, n);
}
