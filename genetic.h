#ifndef GENETIC_H
#define GENETIC_H

#define POP_SIZE 10
//2% chance for each individual bit to mutate
#define MUTATION_CHANCE 2

unsigned int* initialPopulation();
void calculateFitnesses(unsigned int*, unsigned char*);
unsigned char fitness(unsigned int, unsigned int);
unsigned int reproduce(unsigned int, unsigned int);
unsigned int selectParent(unsigned int*, unsigned char*);
unsigned int mutate(unsigned int);
bool fitEnough(unsigned int*);

void printPopulation(unsigned int*);
void printFitnesses(unsigned char*);
void printMostFitBin(unsigned int*, unsigned char*);

#endif
