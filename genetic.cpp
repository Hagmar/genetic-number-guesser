#include <cmath>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <climits>
#include "genetic.h"

unsigned int* initialPopulation(){
    unsigned int *population = (unsigned int*) malloc(POP_SIZE*sizeof(unsigned int));
    if (!population){
        return NULL;
    }
    srand(time(NULL));
    for (int i = 0; i < POP_SIZE; i++){
        population[i] = rand();
    }
    return population;
}

void calculateFitnesses(unsigned int* population, unsigned char* fitnesses){
    for (int i = 0; i < POP_SIZE; i++){
        fitnesses[i] = fitness(300, population[i]);
    }
}

unsigned char fitness(unsigned int target, unsigned int x) {
    unsigned int match = target ^ x;
    unsigned char fitness_score = 8*sizeof(unsigned int);
    while (match){
        if (match & 1){
            fitness_score -= 1;
        }
        match >>= 1;
    }
    return fitness_score;
}

unsigned int reproduce(unsigned int x, unsigned int y){
    int n = sizeof(unsigned int) * 8 - 1;
    // Random number between 1 and 31
    int c = rand() % n + 1;

    unsigned int mask = (1 << c) - 1;
//    std::cout << "Parents: " << x << "   " << y << std::endl;
//    std::cout << "c: " << c << " mask: " << mask << std::endl;

    unsigned int xpart = x & mask;
    unsigned int ypart = y & ~mask;
//    std::cout << "x: " << xpart << " y: " << ypart << std::endl;
//    std::cout << "offspring: " << xpart + ypart << std::endl << std::endl;
    return xpart + ypart;
}

unsigned int selectParent(unsigned int* population, unsigned char* fitnesses){
    unsigned int max_rand = 0;
    for (int i = 0; i < POP_SIZE; i++){
        max_rand += fitnesses[i];
    }
    unsigned int choice = rand() % max_rand;
    unsigned int fitness_sum = 0;
    for (int i = 0; i < POP_SIZE; i++){
        fitness_sum += fitnesses[i];
        if (choice <= fitness_sum){
            return population[i];
        }
    }
    return population[POP_SIZE-1];
}

unsigned int mutate(unsigned int individual){
    unsigned int mask = 0;
    for (int i = 0; i < 8*sizeof(unsigned int); i++){
        o
    }
    unsigned char mutation = rand() % 100;
    if (mutation < MUTATION_CHANCE){
        int n = sizeof(int) * 8 - 1;
        // Random number between 1 and 31
        int c = rand() % n;

        unsigned int mask = (1 << c);
        return individual ^ mask;
    }
    return individual;
}

//TODO
bool fitEnough(unsigned int* population){
    return false;
}

void printPopulation(unsigned int* population){
    for (int i = 0; i < POP_SIZE; i++){
        std::cout << population[i] << " ";
    }
    std::cout << std::endl;
}
void printFitnesses(unsigned char* population){
    for (int i = 0; i < POP_SIZE; i++){
        std::cout << (unsigned int) population[i] << " ";
    }
    std::cout << std::endl;
}