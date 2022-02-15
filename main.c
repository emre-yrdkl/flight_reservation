/*
Emre Yurdakul
150190030

*/

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#define Maxrow 100
#define Maxcolumn 26

int aisorder[5];

int arrwnumber[Maxrow][Maxcolumn];
/* help to calculate the score

 first row and column are trivial and equal to 5,
 empty set equal to 0,
 recent reserve equal to 1,
 complete reserve equal to -1,
 aisle equal to 2

*/

char arrchar[Maxrow][Maxcolumn];

double distance(double i1, double j1, double i2, double j2) { //function that to calculate distance

  double dist = abs(i1 - i2) + (abs(j1 - j2) / 2.0);

  return dist;
}

double adj_distance(double distance) { //function that to calculate adjusted distance

  if (distance == 0) {

    return 0;
  } else {
    double power = 1.0 / distance;

    double adj_dist = 100.0 - pow(100.0, power);
    return adj_dist;
  }

}

void firstorder(int numrow, int numseat, int numaisle, int aisorder[]) { //function that to print first seat map

  int numcolumn = numaisle + numseat;

  for (int a = 0; a < numrow + 1; a++) {

    if (a == 0) {
      printf("   ");
    } else if (a != 0 && a < 10) {
      printf("%d  ", a);

    } else {
      printf("%d ", a);
    }

    char m = 65;

    for (int b = 0; b < numcolumn; b++) {
      if (a == 0) {

        int change = 0;

        for (int c = 0; c < numaisle; c++) {

          if (c == 0 && b == aisorder[c]) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          } else if (c == 1 && b == aisorder[c] + 1) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          } else if (c == 2 && b == aisorder[c] + 2) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          } else if (c == 3 && b == aisorder[c] + 3) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          } else if (c == 4 && b == aisorder[c] + 4) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          }

        }
        if (change == 0) {
          printf("%c ", m);
          m++;
        }
      } else {
        int change = 0;

        for (int c = 0; c < numaisle; c++) {

          if (c == 0 && b == aisorder[c]) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          } else if (c == 1 && b == aisorder[c] + 1) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          } else if (c == 2 && b == aisorder[c] + 2) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          } else if (c == 3 && b == aisorder[c] + 3) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          } else if (c == 4 && b == aisorder[c] + 4) {
            printf("| | ");
            change++;
            arrwnumber[a][b + 1] = 2;
          }
        }
        if (change == 0) {
          printf("- ");
        }
      }

    }
    printf("\n");
  }

}

void lastorder(int numrow, int numseat, int numaisle, int aisorder[]) { //function that to print recent reservation map

  int numcolumn = numaisle + numseat;

  for (int a = 0; a < numrow + 1; a++) {

    if (a == 0) {
      printf("   ");
    } else if (a != 0 && a < 10) {
      printf("%d  ", a);

    } else {
      printf("%d ", a);
    }

    char m = 65;

    for (int b = 0; b < numcolumn; b++) {
      if (a == 0) {

        int change = 0;

        for (int c = 0; c < numaisle; c++) {

          if (c == 0 && b == aisorder[c]) {
            printf("| | ");
            change++;
          } else if (c == 1 && b == aisorder[c] + 1) {
            printf("| | ");
            change++;
          } else if (c == 2 && b == aisorder[c] + 2) {
            printf("| | ");
            change++;
          } else if (c == 3 && b == aisorder[c] + 3) {
            printf("| | ");
            change++;
          } else if (c == 4 && b == aisorder[c] + 4) {
            printf("| | ");
            change++;
          }

        }
        if (change == 0) {
          printf("%c ", m);
          m++;
        }
      } else {
        int change = 0;

        for (int c = 0; c < numaisle; c++) {

          if (c == 0 && b == aisorder[c]) {
            printf("| | ");
            change++;
          } else if (c == 1 && b == aisorder[c] + 1) {
            printf("| | ");
            change++;
          } else if (c == 2 && b == aisorder[c] + 2) {
            printf("| | ");
            change++;
          } else if (c == 3 && b == aisorder[c] + 3) {
            printf("| | ");
            change++;
          } else if (c == 4 && b == aisorder[c] + 4) {
            printf("| | ");
            change++;
          }
        }
        if (change == 0) {
          printf("%c ", arrchar[a][b + 1]);
          m++;
        }
      }

    }
    printf("\n");
  }

}

void score(int numrow, int numseat, int numaisle, int resvnum) { //function that to calculate the score

  for (int k = numrow + 1; k <= numrow + 2; k++) {

    for (int m = 1; m <= numseat + numaisle; m++) {
      arrwnumber[k][m] = 6;
    }
  }
  for (int k = 1; k <= numrow; k++) {

    for (int m = numseat + numaisle + 1; m <= numseat + numaisle + 2; m++) {
      arrwnumber[k][m] = 6;
    }
  }

  if (resvnum == 1) { // if reservation number is 1

    int choose = 0;

    for (int i = 1; i <= numrow; i++) {

      for (int j = 1; j <= numseat + numaisle; j++) {
        if (arrwnumber[i][j] == 0) {
          choose++;
        }
      }
    }
    for (int k = 1; k <= numrow; k++) {

      for (int m = 1; m <= numseat + numaisle; m++) {

        if (arrwnumber[k][m] == 1) {

          arrwnumber[k][m] = -1;

          arrchar[k][m] = 'X';
        }
      }
    }

    if (choose != 0) {

      double score[Maxcolumn][Maxcolumn] = {
        {
          0
        }
      };

      for (int i = 1; i <= numrow; i++) {

        for (int j = 1; j <= numseat + numaisle; j++) {

          if (arrwnumber[i][j] == 0) {

            for (int a = 1; a <= numrow; a++) {

              for (int b = 1; b <= numseat + numaisle; b++) {

                if (arrwnumber[a][b] == 1 || arrwnumber[a][b] == -1) {

                  double x = distance((double) i, (double) j, (double) a, (double) b);
                  score[i][j] += adj_distance(x);
                }

              }

            }
          }

        }
      }
      double maks = -30000;
      int a = 1;
      int b = 1;

      for (int i = 1; i <= numrow; i++) {
        for (int j = 1; j <= numseat + numaisle; j++) {

          if (arrwnumber[i][j] != 1 && arrwnumber[i][j] != -1 && arrwnumber[i][j] != 2) {

            if (score[i][j] > maks) {

              maks = score[i][j];
              a = i;
              b = j;
            }
          }
        }

      }
      arrwnumber[a][b] = 1;
      arrchar[a][b] = '+';

      int k = 0;
      for (int i = 1; i < b; i++) {
        if (arrwnumber[a][i] == 2) {
          k++;
        }
      }
      int m = 64;

      printf("Reserved seats: %d%c\n", a, m + b - k);

    } else {
      printf("No available seats for the requested reservation!\n");

    }

  }

  //-------------------------------------------------------------------------------------
  else { // if reservation number is bigger than 1
    if (resvnum <= numseat) {

      for (int k = 1; k <= numrow; k++) {

        for (int m = 1; m <= numseat + numaisle; m++) {

          if (arrwnumber[k][m] == 1) {

            arrwnumber[k][m] = -1;

            arrchar[k][m] = 'X';
          }
        }
      }

      double score[Maxrow][Maxcolumn] = {
        {
          0
        }
      };

      for (int i = 1; i <= numrow; i++) {

        for (int j = 1; j <= numseat + numaisle; j++) {

          int resvcheck = 0;

          if (arrwnumber[i][j] == 0) {
            int aisnum = 0;

            for (int m = j; m <= j + resvnum + numaisle; m++) {

              if (arrwnumber[i][m] == 2) {
                aisnum++;
              }
            }

            for (int m = j + resvnum + 1; m < j + resvnum + numaisle; m++) {

              if (arrwnumber[i][m] == 2) {
                aisnum--;
              }
            }

            for (int a = j; a < j + resvnum + aisnum; a++) {

              if (arrwnumber[i][a] == 0) {

                resvcheck++;
              } else if (arrwnumber[i][a] == 1 || arrwnumber[i][a] == -1)
                resvcheck -= 10;
            }
          }

          if (resvcheck >= resvnum) {

            int aisnum = 0;

            for (int m = j; m <= j + resvnum + numaisle; m++) {

              if (arrwnumber[i][m] == 2) {
                aisnum++;
              }
            }

            for (int m = j + resvnum + 1; m <= j + resvnum + numaisle; m++) {

              if (arrwnumber[i][m] == 2) {
                aisnum--;
              }
            }

            for (int k = j; k < j + resvnum + aisnum; k++) {

              if (arrwnumber[i][k] == 0) {

                for (int a = 1; a <= numrow; a++) {

                  for (int b = 1; b <= numseat + numaisle; b++) {

                    if (arrwnumber[a][b] == 1 || arrwnumber[a][b] == -1) {

                      double x = distance((double) i, (double) k, (double) a, (double) b);

                      score[i][j] += adj_distance(x);
                    }

                  }
                }
              }
            }
          }
        }
      }

      double maks = -30000;
      int a = 1;
      int b = 1;

      for (int i = 1; i <= numrow; i++) {
        for (int j = 1; j <= numseat + numaisle; j++) {

          if (arrwnumber[i][j] != 1 && arrwnumber[i][j] != -1 && arrwnumber[i][j] != 2) {

            if (score[i][j] > (maks + 0.00001) && score[i][j] != 0) {

              maks = score[i][j];
              a = i;
              b = j;
            }
          }
        }

      }
      int howaisle = 0;

      for (int o = b; o <= b + resvnum; o++) {
        if (arrwnumber[a][o] == 2 && arrwnumber[a][o] != 1 && arrwnumber[a][o] != -1) {
          howaisle++;
        }
      }

      int check = 0;
      for (int o = b; o <= b + resvnum + howaisle; o++) {
        if (arrwnumber[a][o] == 0) {
          check++;
        }
      }
      if (resvnum <= check) {

        for (int o = b; o < b + resvnum + howaisle; o++) {

          if (arrwnumber[a][o] != 2) {

            arrwnumber[a][o] = 1;
            arrchar[a][o] = '+';
          }

        }

        int m = 64;

        int k = 0;
        for (int i = 1; i < b; i++) {
          if (arrwnumber[a][i] == 2) {
            k++;
          }
        }
        printf("Reserved seats: ");

        for (int o = b; o < b + resvnum; o++) {

          printf("%d%c ", a, m + o - k);
        }
        printf("\n");

      } else
        printf("No available seats for the requested reservation!\n");

    } else
      printf("No available seats for the requested reservation!\n");
  }

}

int main() {
  int row, seat, aisle;

  printf("Number of rows: ");
  scanf("%d", & row);
  printf("Number of seats per row: ");
  scanf("%d", & seat);
  printf("Number of aisles: ");
  scanf("%d", & aisle);

  for (int i = 0; i < aisle; i++) {
    int k;
    printf("Add aisle %d after seat:  ", i + 1);
    scanf("%d", & k);
    aisorder[i] = k;

  }

  firstorder(row, seat, aisle, & aisorder[0]);

  for (int a = 0; a <= seat + aisle; a++) {
    arrwnumber[0][a] = 5;
  }
  for (int b = 0; b <= row; b++) {
    arrwnumber[b][0] = 5;
  }

  //---------------------------------------------------------------
  int numcolumn = aisle + seat;

  for (int a = 0; a < row + 1; a++) {
    for (int b = 0; b < numcolumn; b++) {

      if (a != 0) {
        int change = 0;

        for (int c = 0; c < aisle; c++) {

          if (c == 0 && b == aisorder[c]) {
            change++;
          } else if (c == 1 && b == aisorder[c] + 1) {
            change++;
          } else if (c == 2 && b == aisorder[c] + 2) {
            change++;
          } else if (c == 3 && b == aisorder[c] + 3) {
            change++;
          } else if (c == 4 && b == aisorder[c] + 4) {
            change++;
          } else {
            arrchar[a][b + 1] = '-';

          }
        }

      }

    }
  }

  int i = 0;

  while (i < 100) {
    printf("The number of people in the reservation\n (0: print current reservations, -1: exit):");

    int x;
    scanf("%d", & x);

    if (x == -1) {
      break;
    } else if (x == 0) {

      score(row, seat, aisle, x);

      lastorder(row, seat, aisle, & aisorder[0]);
    } else {
      score(row, seat, aisle, x);

      lastorder(row, seat, aisle, & aisorder[0]);

    }

  }
}
