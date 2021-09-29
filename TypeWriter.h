#ifndef TYPEWRITER_H
#define TYPEWRITER_H
#include <Windows.h>
#include <iostream>

template<typename T>
void TypeWriter(T message, int time) {
	int count{ 0 };
	while (message[count] != NULL) {
		std::cout << message[count];
		Sleep(time);
		count++;
	}
}
#endif