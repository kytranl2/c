#include <wiringPi.h>
#include <stdio.h>

int pins[10] = {0,1,2,3,4,5,6,8,9,10};
int main(void) {
	if (wiringPiSetup() == -1) {
		printf("failed setup");
		return 1;
	}	
//	for (int i=0; i<10;i++) {
//		pinMode(pins[i], OUTPUT);
//		digitalWrite(pins[i], LOW);
//	}
	while(1) {
		int pin;
		int s;
		scanf("%d %d", &pin, &s);
		pinMode(pin, OUTPUT);
		digitalWrite(pin, s);
	}
	return 0;
}
