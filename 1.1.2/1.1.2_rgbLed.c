/**********************************************************************
* Filename    : 1.1.2_rgbLed.c
* Description : Make a RGB LED emits various color.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Update      : Daisy    2019/08/02
**********************************************************************/
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#define uchar unsigned char
#define LedPinRed    0
#define LedPinGreen  1
#define LedPinBlue   2

void ledInit(void){
    softPwmCreate(LedPinRed,  0, 100);
    softPwmCreate(LedPinGreen,50, 100);
    softPwmCreate(LedPinBlue, 50, 100);
}

void ledColorSet(uchar r_val, uchar g_val, uchar b_val){
    softPwmWrite(LedPinRed,   r_val);
    softPwmWrite(LedPinGreen, g_val);
    softPwmWrite(LedPinBlue,  b_val);
}

int main(void){
    if(wiringPiSetup() == -1){ //when initialize wiring failed, printf messageto screen
        printf("setup wiringPi failed !");
        return 1;
    }
    int mode;
    int r = 0;
    int g = 0;
    int b = 0;
    printf("Enter a mode 1 or 2: ");
    scanf("%d", &mode);

    ledInit();
    switch(mode) {
        case 1:
	     while(1){
		printf("Enter red green blue (ex:0 0 0) values: ");
		scanf("%d %d %d", &r, &g, &b);
		printf("r: %d, g: %d, b: %d\n", r, g, b);
                ledColorSet(r, g, b);
	     }
	     break;
        case 2:
	     while(1){
	        printf("Red\n");
	        ledColorSet(0xff,0x00,0x00);   //red
	        delay(2000);
	        printf("Green\n");
	        ledColorSet(0x00,0xff,0x00);   //green
	        delay(2000);
	        printf("Blue\n");
	        ledColorSet(0x00,0x00,0xff);   //blue
	        delay(2000);
	        printf("Yellow\n");
	        ledColorSet(0xff,0xff,0x00);   //yellow
	        delay(2000);
	        printf("Purple\n");
	        ledColorSet(0xff,0x00,0xff);   //purple
	        delay(2000);
	        printf("Cyan\n");
	        ledColorSet(0xc0,0xff,0x3e);   //cyan
	        delay(2000);
   	   }
	   break;
	default:
		return 0;
    }
    return 0;
}
