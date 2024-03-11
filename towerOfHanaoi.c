/* Develop a program to solve the mathematical puzzle "Tower of Hanoi" where we have three rods (A, B, and C) and N disks. Initially, all 
the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of 
the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules:
Only one disk can be moved at a time.
No disk may be placed on top of a smaller disk*/

// Name - Sanjay Singh Rawat, Class Roll No - 58, Section - I 

#include <stdio.h>

// Function to move disks from source rod to destination rod using auxiliary rod
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, and C are rod names
    return 0;
}
















