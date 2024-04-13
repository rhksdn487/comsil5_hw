#include <stdio.h>
#include <stdlib.h>


void subset(int n, int subsetSize,char *A,char *L,int size);
void printSubset(int subsetSize,char *A,char *L,int size);

int main() {
    
    int size;
    printf("branch3���� �߰��Ѱ� ");
    printf("Enter the number of alphabets: ");
    scanf("%d", &size);

    char* L = (char*)malloc(size * sizeof(char));
    char* A = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size; i++) {
        A[i] = 'a' + i; // ���ĺ� ������� ����
    }

    for (int i = 0; i <= size; i++) {
        subset(0, i,A,L,size);
    }
    free(A);
    free(L);
    return 0;
}

void subset(int n,int subsetSize,char *A,char *L,int size) {
    if (subsetSize == 0) {
        printSubset(subsetSize,A,L,size);
        return;
    }
    if (n == size) {
        return;
    }
    L[n] = 1;
    subset(n + 1, subsetSize - 1,A,L,size);
    L[n] = 0;
    subset(n + 1, subsetSize,A,L,size);
}

void printSubset(int subsetSize,char* A,char *L,int size){
    printf("{");
    int printed = 0; // printed ���� �߰�
    for (int i = 0; i < size; i++) {
        if (L[i] == 1) {
            if (printed > 0) { // ��� ���̿� ���� ���
                printf(" ");
            }
            printf("%c", A[i]);
            printed++; // ��µ� ����� �� ����
        }
    }
    printf("} ");
   
}
