/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>
#include "helpers.h"
#include <stdio.h>

bool search(int value, int values[], int n)
{
	int lo, hi, mid;
	lo = 0;
	hi = n;
	mid = (lo+hi)/2;

	if (n < 0)
		return false;
	else {
		while (mid >=0 && mid <= n) {
			printf("hi: %i lo: %i mid: %i value: %i values[mid]: %i\n", hi, lo, mid, value, values[mid]);
			if (pow(value - values[mid], 2.0) < 0.0001)
				return true;
			else if (value > values[mid]) 
				lo = mid;
			else if (value < values[mid]) 
				hi = mid;
			mid = (lo + hi)/2;
		}
	}
	return false;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool searchOld(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
	if (n < 0) 
		return false;
	else {
		for (int i = 0; i < n; i++) {
			printf("value: %i values[%i]: %i\n", value, i, values[i]);
			if (value == values[i]) { 
				return true;
			}
			else 
				continue;
		}
	}
	return false;

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
	int tmp;
	for (int i = 0; i < (n-1); i++) {
		for (int j = i+1; j < n; j++) {
			if (values[i] > values[j]) {
		    	tmp = values[i];
		    	values[i] = values[j];
	    	    	values[j] = tmp;
			}
		}
	}
	return;
}
