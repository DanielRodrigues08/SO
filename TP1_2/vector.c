#include <math.h>
#include <malloc.h>

#include "vector.h"

vector* vector_new(double x, double y, double z){
    vector* result = (vector*) malloc(sizeof(vector));
    result->x=x;
    result->y=y;
    result->z=z;
    return result;
}

vector* vector_add(vector* v1, vector* v2){
    return vector_new(v1->x+v2->x, v1->y+v2->y, v1->z+v2->z);
}

vector* vector_sub(vector* v1, vector* v2){
    return vector_new(v1->x-v2->x, v1->y-v2->y, v1->z-v2->z);
}

vector* vector_scale(double n, vector* v1){
    return vector_new(v1->x*n, v1->y*n, v1->z*n);
}

vector* vector_vprod(vector* v1, vector* v2){
    return vector_new(v1->y*v2->z-v1->z*v2->y, v1->x*v2->z - v1->z*v2->x, v1->x*v2->y - v1->y*v2->x);
}

double vector_sprod(vector* v1, vector* v2){
    return v1->x*v2->x + v1->y*v2->y + v1->z*v2->z;
}

double vector_mod(vector* v1){
    return sqrt(v1->x*v1->x + v1->y*v1->y + v1->z*v1->z);
}