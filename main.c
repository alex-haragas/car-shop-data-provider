#include <stdio.h>
#include <stdlib.h>

#define MAX_BRAND_NAME 10
#define MAX_MODEL_NAME 20
#define MAX_LINE 10
void readModel(char * model);

int main() {
    //read no brands
    int nobrands;
    printf("Please input number of brands:\n");
    scanf("%d", &nobrands);
    //read brand
    char ** brands;
    brands=(char**)malloc(nobrands*sizeof(char*));
    printf("Please input name of brands:\n");
    for(int i=0;i<nobrands;i++)
    {
        //read brands
        brands[i]=(char*)malloc(MAX_BRAND_NAME* sizeof(char));
        scanf("%s", brands[i]);
    }
    //read no models
    int * nomodels=(int*)malloc(nobrands* sizeof(int));
    char *** models=(char***)malloc(nobrands* sizeof(char**));
    double ** prices=(double **)malloc(nobrands* sizeof(double *));
    for(int i=0; i<nobrands;i++)
    {
        //read no models
        printf("Pleas input no of models for brand %s\n", brands[i]);
        scanf("%d",&nomodels[i]);
        getchar();
        //read model & prices
        printf("Please input model & price: each line model,price");
        models[i]=(char **)malloc(nomodels[i]* sizeof(char*));
        prices[i]=(double*)malloc(nomodels[i]* sizeof(double));
        for(int j=0;j<nomodels[i];j++)
        {
            models[i][j]=(char*)malloc(MAX_MODEL_NAME* sizeof(char));
            readModel(models[i][j]);
            char line[MAX_LINE];
            gets(line);
            sscanf(line, "%1f", &prices[i][j]);
        }
    }
    //display data
    printf("Data is:\n");
    for(int i=0;i<nobrands;i++) {
        // display brand
        printf("%s: ", brands[i]);
        for(int j=0;j<nomodels[i];j++) {
            printf("(%s, %.2lf) ",models[i][j],prices[i][j]);
        }
        printf("\n");
    }
    //free mem
    for(int i=0;i<nobrands;i++)
    {
        for(int j=0;j<nomodels;j++)
        {
            free(models[i][j]);
        }
        free(models[i]);
        free(prices[i]);
        free(brands[i]);
    }
    free(models);
    free(prices);
    free(brands);
    free(nomodels);

    return 0;
}
void readModel(char * model) {
    char c = getchar();
    int i=0;
    while(c!=',') {
        model[i] = c;
        c = getchar();
        i++;
    }
    model[i] = '\0';
}