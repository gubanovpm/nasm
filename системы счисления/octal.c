#include <stdio.h>

int main() {
        FILE *input = fopen("input.txt", "r");
        if (input == NULL)
                return 0;
        FILE *output = fopen("output.txt", "w");
        if (output == NULL)
                return 0;
        unsigned long long int d = 0;
        fscanf(input, "%llu", &d);
        fclose(input);
        fprintf(output,"%llo\n", d);
        fclose(output);
        return 0;
}
