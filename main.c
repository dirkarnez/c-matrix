#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct matrix {
    int* data;
    int row;
    int col;
    int capacity;
};

struct matrix *init_unknown_size(int initial_capacity) {
    struct matrix* m = (struct matrix *)malloc(sizeof(struct matrix));
    m->capacity = initial_capacity;
    m->data = (int *)malloc(m->capacity);
    m->row = 0;
    m->col = 0;
    return m;
}

struct matrix *init_known_size(int row, int col) {
    struct matrix* m = (struct matrix *)malloc(sizeof(struct matrix));
    m->capacity = row * col;
    m->data = (int *)malloc(m->capacity);
    m->row = row;
    m->col = col;
    return m;
}

void set_data(struct matrix *m, int* data, int row, int col) {
    m->data = data;
    m->row = row;
    m->col = col;
}

// bool multiply(struct matrix *a, struct matrix *b, struct matrix *output) {
   


// }

int main() {
    struct matrix a = {
        .data = ((int[]){1, 2, 3, 4}),
        .row = 2,
        .col = 2
    };

    struct matrix b = {
        .data = ((int[]){5, 6, 7, 8}),
        .row = 2,
        .col = 2
    };

    struct matrix c = {0};

    {
        //multiply
        if (a.col != b.row) {
           printf("Cannot multiply");
        } else {
            int data[a.row * b.col];
            c.row = a.row;
            c.col = b.col;
            c.data = data;

            // c[0, 0] c[0, 1]
            // c[0, 0] c[0, 0]

           // 19 22 43 50
            // a[0] * b[0] + a[1] * b[2]
            

            // int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
    
            for (int i = 0; i < (a.row * b.col); i++) {
                c.data[i] = 0;
            }
            
            // 0:0 1
            // 1:0 1 
            for (int i = 0; i < a.row; i++) {
                for (int j = 0; j < b.col; j++) {
                     c.data[(i * 2) + j] =  a.data[(i * 2)] * b.data[j] +  a.data[(i * 2) + 1] * b.data[j + 2];
                }
            }

            // c.data[0] = a.data[0] * b.data[0] + a.data[1] * b.data[2];
            // c.data[1] = a.data[0] * b.data[1] + a.data[1] * b.data[3];
            // c.data[2] = a.data[2] * b.data[0] + a.data[3] * b.data[2];
            // c.data[3] = a.data[2] * b.data[1] + a.data[3] * b.data[3];


            printf("%d,", c.data[0]);
            printf("%d,", c.data[1]);
            printf("%d,", c.data[2]);
            printf("%d,", c.data[3]);

            printf("\n");

            for (int i = 0; i < c.row; i++) {
                for (int j = 0; j < c.col; j++) {
                    printf("%d,", c.data[(i * 2) + j]);
                }
                 printf("\n");
            }



            // a[row] * b[col]
        }
    }
    // if (multiply(&a, &b, &c)) {

    // } else {
    //     printf("Cannot multiply");
    // }
}
