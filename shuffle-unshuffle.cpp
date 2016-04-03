/**
 *  Written by Mohsen Shaali
 *  03/04/2016
 *  Array Shuffel an Un-shiffle
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

int GetNextRandom(int seed, int index, int size);
void GetShuffleSteps(int size, int seed, int *shuffleStepsArray);	
void Shuffle(int *array, int size, int seed);
void Unshuffle(int *array, int size, int seed);

int main()
{    
	int seed = 4;
	int size = 15;
	int array[] ={54,55,56,57,58,59,60,61,62,63, 65, 133, 12, 14, 90};
	int shuffleStepsArray[size];
	
	Shuffle(array, size, seed);
	for (int i = 0; i < size; i++)
	{		
		printf("var %d\n" , *(array +i));		
	}

	printf("_______ \n");

	Unshuffle(array, size, seed);
	for (int i = 0; i < size; i++)
	{		
		printf("var %d\n" , *(array +i));		
	}

	return 0;
}


int GetNextRandom(int seed, int index, int size){
	srand(seed);
	int min, max;
	min = index;
	max = size;		
	int result = min + (rand() % (int)(max - min));
	return result;
}

void GetShuffleSteps(int size, int seed, int *shuffleStepsArray)
{      
	for (int i = 0; i < size ; i++)
	{
		shuffleStepsArray[i] = GetNextRandom(seed, i, size);   
	}		
}


void Shuffle(int *array, int size, int seed)
{
	int shuffleStepsArray[size];
	GetShuffleSteps(size, seed, shuffleStepsArray);

	for (int i = size - 1; i > 0; i--)
	{
		int n = *(shuffleStepsArray + size - 1 - i);		
		std::swap(array[n], array[n-1]);
	}  
}

void Unshuffle(int *array, int size, int seed)
{
	int shuffleStepsArray[size];
	GetShuffleSteps(size, seed, shuffleStepsArray);

	for (int i = 1; i < size; i++)
	{
		int n = *(shuffleStepsArray + size - i - 1);		
		std::swap(array[n], array[n-1]);
	}  
}
