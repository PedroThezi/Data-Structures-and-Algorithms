#include <stdio.h>
#include <stdlib.h>

int* create_array(int* array,int size);
void read_array(int* array, int size);
int* update_array(int* array, int size, int value, int index);
int* delete_array(int* array, int size, int index);
void search_value_array(int* array, int size, int value);
void search_index_array(int* array, int size, int index);
void stats_array(int* array, int size);
int* sorted_array(int* array, int size);

int main() {
    int* array = NULL;
    int op, size, value, index;

    do {
        printf("\n---Menu---\n");
        printf("1 - Create\n");
        printf("2 - Read\n");
        printf("3 - Update\n");
        printf("4 - Delete\n");
        printf("5 - Search by value\n");
        printf("6 - Search by index\n");
        printf("7 - Stats\n");
        printf("8 - Sorted\n");
        printf("0 - Exit\n");
        printf("Choose:");
        scanf("%i", &op);

        switch (op) {
        case 1:
            printf("\nCreate\n");
            printf("What's the size of the array: ");
            scanf("%i", &size);
            array = create_array(array,size);
            break;
        case 2:
            printf("\nRead\n");
            read_array(array, size);
            break;
        case 3:
            printf("\nUpdate\n");
            printf("What's the index: ");
            scanf("%i", &index);
            printf("\nWhat's the value: ");
            scanf("%i", &value);
            update_array(array, size, value, index);
            break;
        case 4:
            printf("\nDelete\n");
            printf("What's the index: ");
            scanf("%i", &index);
            delete_array(array, size, index);
            break;
        case 5:
            printf("\nSearch by value\n");
            printf("What's the value to search: ");
            scanf("%d", &value);
            search_value_array(array, size, value);
            break;
        case 6:
            printf("\nSearch by index\n");
            printf("What's the index to search: ");
            scanf("%d", &index);
            search_index_array(array, size, index);
            break;
        case 7:
            printf("\nStats");
            stats_array(array, size);
            break;
        case 8:
            printf("\nSorted array\n");
            array = sorted_array(array, size);
            break;
        case 0:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (op != 0);

    free(array);
    return 0;
}

int* create_array(int* array,int size) {
    if (array != NULL)
        free(array);

    int* array = (int*)calloc(size, sizeof(int));
    array = (int*)calloc(size, sizeof(int));
    if (array == NULL)
        exit(EXIT_FAILURE);
    return array;
}

void read_array(int* array, int size) {
    printf("\nArray:");
    for (int i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

int* update_array(int* array, int size, int value, int index) {
    if (index >= size || index < 0)
        printf("\nInvalid index");
    else
        array[index] = value;
    return array;
}

int* delete_array(int* array, int size, int index) {
    if (index >= size || index < 0)
        printf("\nInvalid index");
    else
        array[index] = 0;
    return array;
}

void search_value_array(int* array, int size, int value) {
    int cont = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == value)
            cont++;
    }
    if (cont >= 1)
        printf("\nThe value %i was found %i times", value, cont);
    else
        printf("\nThe value %i wasn't found", value);
}

void search_index_array(int* array, int size, int index) {
    if (index >= size || index < 0)
        printf("\nInvalid index");
    else
        printf("\nThe value %i was found in this index", array[index]);
}

void stats_array(int* array, int size) {
    int min, max, mode;
    min = max = mode = array[0];

    int sum = 0, cont_max = 0;

    // getting min, max and sum
    for (int i = 0; i < size; i++) {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];

        sum += array[i];
    }

    // getting mean
    float mean = (float)sum / size;

    // getting median
    float median = 0;
    if (size % 2 == 0)
        median = (array[size / 2 - 1] + array[size / 2]) / 2.0;
    else
        median = array[size / 2];

    // getting mode
    for (int i = 0; i < size; i++) {
        int cont = 0;
        for (int j = 0; j < size; j++) {
            if (array[j] == array[i])
                cont++;

            if (cont > cont_max) {
                cont_max = cont;
                mode = array[i];
            }
        }
    }
    printf("\nMin: %i\nMax: %i\nSum: %i\nMean: %.2f\nMedian: %.2f\nMode: %i", min, max, sum, mean, median, mode);
}

int* sorted_array(int* array, int size) {
    int trade;
    for (int i = 0; i < size - 1; i++) {
        trade = 0;
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                trade = 1;
            }
        }
        if (trade == 0) {
            break;
        }
    }
    return array;
}
