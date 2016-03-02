#include <iostream>
#include "genetic.h"

int main()
{
    unsigned int *population = initialPopulation();
    unsigned char *fitnesses = (unsigned char*) malloc(POP_SIZE*sizeof(unsigned char));

    unsigned int parent_x, parent_y, child;

    if (!fitnesses || !population){
        return 1;
    }
    unsigned int *new_population;

    while (!fitEnough(population)){
        new_population = (unsigned int*) malloc(POP_SIZE*sizeof(unsigned int));

        if (!new_population){
            return 1;
        }

        calculateFitnesses(population, fitnesses);
        printPopulation(population);
        printFitnesses(fitnesses);
        printMostFitBin(population, fitnesses);

        for (int i = 0; i < POP_SIZE; i++){
        //TODO Parents can't be same individual?
            parent_x = selectParent(population, fitnesses);
            parent_y = selectParent(population, fitnesses);
            child = reproduce(parent_x, parent_y);
            child = mutate(child);
            new_population[i] = child;
        }
        free(population);
        population = new_population;
    }

    return 0;
}
