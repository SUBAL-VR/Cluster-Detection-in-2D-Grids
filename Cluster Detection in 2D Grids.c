#include <stdio.h>

#define MAX 100

// Directions for moving in the grid (down, up, right, left)
int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Function to find connected components and mark them
void markBlock(int Grid[MAX][MAX], int p, int q, int x, int y, int blockNum) {
    // Initialize a queue for BFS
    int queue[MAX * MAX][2];
    int front = 0, rear = 0;
    
    // Start from the initial position
    queue[rear][0] = x;
    queue[rear][1] = y;
    rear++;
    
    while (front < rear) {
        // Get the current position from the queue
        int currX = queue[front][0];
        int currY = queue[front][1];
        front++;
        
        // Mark the current cell
        Grid[currX][currY] = blockNum;
        
        // Check all 4 possible directions
        for (int d = 0; d < 4; d++) {
            int newX = currX + directions[d][0];
            int newY = currY + directions[d][1];
            
            // If the new position is valid and is a '1'
            if (newX >= 0 && newX < p && newY >= 0 && newY < q && Grid[newX][newY] == 1) {
                // Mark the new position and add to the queue
                queue[rear][0] = newX;
                queue[rear][1] = newY;
                rear++;
            }
        }
    }
}

int main() {
    int p, q, a = 2;

    // User input for number of rows and columns (with validation)
retry1:
    printf("Enter no. of rows(1-50):");
    scanf("%d", &p);
    if (p <= 0 || p > 50) {
        printf("Invalid input. Please enter a value between 1 and 50.\n");
        goto retry1; // Jump back to prompt if input is invalid
    }
retry2:
    printf("Enter no. of columns(1-50):");
    scanf("%d", &q);
    if (q <= 0 || q > 50) {
        printf("Invalid input. Please enter a value between 1 and 50.\n");
        goto retry2; // Jump back to prompt if input is invalid
    }

    int Grid[MAX][MAX]; // Declaring a grid based on MAX dimensions
    
    // Input elements of the grid from the user
    printf("Enter the elements of the Grid (0 or 1):\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
retry3:
            printf("Enter Grid[%d][%d]:", i, j);
            scanf("%d", &Grid[i][j]);
            // Validate user input: only accept 0 or 1
            if (Grid[i][j] != 1 && Grid[i][j] != 0) {
                printf("Invalid input. Please enter 0 or 1.\n");
                goto retry3; // Jump back to prompt if input is invalid
            }
        }
    }

   /* // Pre-defined grid values (commented out, replaced by manual input)
    int p = 8, q = 13, a = 2;
    int Grid[MAX][MAX] = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };
    // */

    // Identify different blocks of 1 and assign a unique number to each block
    for (int k = 0; k < p; k++) {
        for (int l = 0; l < q; l++) {
            if (Grid[k][l] == 1) { // Check if current element is 1
                markBlock(Grid, p, q, k, l, a); // Use the marking function
                a++; // Increment block number for the next block
            }
        }
    }

    // If no blocks are found, the program returns 0
    if (a == 2) {
        printf("No blocks (1's) found in the grid.\n");
        return 0;
    }

    // Printing the modified grid
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("%4d", Grid[i][j]);
        }
        printf("\n");
    }

    // Finding the area of each block
    int area[a - 2]; // Array to store area of blocks
    for (int k = 2; k < a; k++) {
        int b = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                if (Grid[i][j] == k) {
                    b++;
                }
            }
        }
        area[k - 2] = b;
    }

    // Finding the Max Area
    int max_area = 0;
    for (int i = 0; i < a - 2; i++) {
        if (max_area < area[i]) {
            max_area = area[i];
        }
    }

    // Print the maximum area of blocks
    printf("\nMax Area: %d", max_area);
    return 0;
}