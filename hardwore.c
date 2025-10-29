#include <stdio.h>

// Estructura de 8 bits, puertos A y B

typedef struct {
	unsigned char bit0  : 1
	unsigned char bit1  : 1
	unsigned char bit2  : 1
	unsigned char bit3  : 1
	unsigned char bit4  : 1
	unsigned char bit5  : 1
	unsigned char bit6  : 1
	unsigned char bit7  : 1
} port8b_t;

// Estructura de 16 bits, puerto D

typedef struct {
	port8b_t bits [2];
} port16b_t;

// Funciones para puertos A y B 

void bitSet8b (port8b_t* puerto, unsigned char n) {
    unsigned char* bytePtr = (unsigned char*) puerto;
    *bytePtr |= (1 << n);                             
}
	
void bitClr8b (port8b_t* puerto, unsigned char n) {
    unsigned char* bytePtr = (unsigned char*) puerto;
    *bytePtr &= ~(1 << n); 
}

unsigned char bitGet8b (port8b_t* puerto, unsigned char n) {
	unsigned char result;
	unsigned char* bytePtr = (unsigned char*) puerto;
	result = ((*bytePtr >> n) & 1);
return result;
}

void bitToggle8b (port8b_t* puerto, unsigned char n) {
    	unsigned char* bytePtr = (unsigned char*) puerto;
	*bytePtr ^= (1 << n);                             
}

// Funciones para puerto D

void bitSet16(port16b_t* puertoD, unsigned char n) {
    unsigned char* bytePtr = (unsigned char*) puertoD;

    if (n < 8) {
        bitSet8b((port8b_t*) &bytePtr[0], n);
    } else if (n >= 8 && n < 16) {
        bitSet8b((port8b_t*) &bytePtr[1], n - 8);
    }
}

void bitClr16(port16b_t* puertoD, unsigned char n) {
    unsigned char* bytePtr = (unsigned char*) puertoD;

    if (n < 8) {
        bitClr8b((port8b_t*) &bytePtr[0], n);
    } else if (n >= 8 && n < 16) {
        bitClr8b((port8b_t*) &bytePtr[1], n - 8);
    }
}

unsigned char bitGet16b(port16b_t* puertoD, unsigned char n) {
    unsigned char* bytePtr = (unsigned char*) puertoD;

    if (n < 8) {
        return bitGet8b((port8b_t*) &bytePtr[0], n); 
    } else if (n >= 8 && n < 16) {
        return bitGet8b((port8b_t*) &bytePtr[1], n - 8);  
    }
    return 0;
}

unsigned char bitGet16b(port16b_t* puertoD, unsigned char n) {
    unsigned char* bytePtr = (unsigned char*) puertoD;

    if (n < 8) {
        return bitGet8b((port8b_t*) &bytePtr[0], n);
    } else if (n >= 8 && n < 16) {
        return bitGet8b((port8b_t*) &bytePtr[1], n - 8);
    }
    return 0;  
}









