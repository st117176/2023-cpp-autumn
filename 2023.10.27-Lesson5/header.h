#pragma once

void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
void contractArray(int*& a, int& len);
bool indexValid(int index, int len);
int extractElement(int*& a, int& len, int index);
void printArrayInAscendingOrder(int* a, int len);
void printReverseArray(int* a, int len);
void swapElements(int* a, int len, int index1, int index2);
void replaceMaxAndMin(int* a, int len);
void deleteRepeatableElements(int*& a, int& len);
int findIndexOfMinElement(int* a, int len);
int findIndexOfMaxElement(int* a, int len);
void AddRandomNumbers(int*& a, int& len, int n);
void printMenu();