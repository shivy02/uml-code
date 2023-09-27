/**
 * @file edistance.cpp
 * @author Shivam Patel (Shivam_Patel3@student.uml.edu)
 * @brief 
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "edistance.h"

EDistance::EDistance(std::string s1, std::string s2) {
    this->s1 = s1;
    this->s2 = s2;
    cols = 2;
    rows = static_cast<size_t>(s1.size());
    matrix = new std::string[cols * rows];
}

int EDistance::penalty(char a, char b) {
    if (a == b) {
        return 0;
    } else if (a != b) {
        return 1;
    }
    return 1;
}

int EDistance::min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= c && b <= a) {
        return b;
    } else {
        return c;
    }
}

int EDistance::optDistance() {
    int i, j;
    int N = s1.size();
    int M = s2.size();

    for (i = 0; i <= N; i++) {
        matrix[0][i] = 0;
    }

    for (j = 0; j <= M; j++) {
        matrix[1][j] = 0;
    }

//ENDED HERE
  // Start by filling out the bottom row
  for(i = 0; i <= M; i++)
  {
    // Very bottom row
    matrix[i][N] = 2 * (M - i);
  }

  // Now fill out the side row.
  for(j = 0; j <= N; j++)
  {
    // Very right most column
    matrix[M][j] = 2 * (N - j);
  }

  // Now that we have the initial sides, we can go ahead and calculate the rest
  // of the sub problems.
  for(i = M - 1; i >= 0; i--)
  {
    for(j = N - 1; j >= 0; j--)
    {
      // Using Princeton's formula, we can just calculate every single row!
      /*
       * Note - min of 3 numbers, which we must get from using the penalty method.
       *
       */
      int opt1 = matrix[i+1][j+1] + penalty(s1[j], s2[i]);
      int opt2 = matrix[i+1][j] + 2;
      int opt3 = matrix[i][j+1] + 2;

      matrix[i][j] = min(opt1, opt2, opt3);
    }
  }

  return matrix[0][0];
}

std::string EDistance::alignment() {
    int i = 0, j = 0, score, opt1, opt2, opt3;
    int N = s1.size();
    int M = s2.size();
    std::ostringstream retStr;
    std::string retString;

    while (i < N || j < M) {
        try {
            score = penalty(s1[i], s2[j]);
            opt1 = matrix[j+1][i+1] + score;
        } catch(const std::out_of_range &err) {
            opt1 = -1;
        }
        try {
            opt2 = matrix[j+1][i] + 2;
        } catch(const std::out_of_range &err) {
            opt2 = -1;
        }
        try {
            opt3 = matrix[j][i+1] + 2;
        } catch(const std::out_of_range &err) {
            opt3 = -1;
        }

        if (matrix[j][i] == opt1) {
            retStr << s1[i] << " " << s2[j] << " " << score << std::endl;
            i++;
            j++;
        } else if (matrix[j][i] == opt2) {
            retStr << "- " << s2[j] << " 2\n";
            j++;
        } else if (matrix[j][i] == opt3) {
            retStr << s1[i] << " -" << " 2\n";
            i++;
        }
    }
    retString = retStr.str();
    return retString;
}
