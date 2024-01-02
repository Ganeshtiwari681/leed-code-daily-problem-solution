#define MAX(a,b)((a)>(b)?(a):(b))

int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int *table = calloc(201, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++){
        table[nums[i]]++;
        *returnSize = MAX(*returnSize, table[nums[i]]);
    }

    int **ret = malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = calloc(*returnSize, sizeof(int));
    
    for (int i = 0; i < *returnSize; i++)
        ret[i] = calloc(numsSize, sizeof(int));
    
    for (int i = 0; i <= 200; i++){
        int row = 0;
        while (table[i] > 0){
            ret[row][((*returnColumnSizes))[row]++] = i;
            table[i]--;
            row++;
        }
    }
    free(table);
    return ret;
}