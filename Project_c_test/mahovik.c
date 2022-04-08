#include "libschsat.h"
	/*
	** Lab 5: manage motor speed
	*/
	void control(void)
	{
		const int num = 1;	/* motor number #1 */
		int16_t temp;
		int16_t rpm = -3000;	/* -3000 ... +3000 */
		printf("Enable motor #%d\n", num);
		motor_turn_on(num);
		Sleep(1);
		printf("Manage speed motor #%d\n", num);
		while (rpm <= 3000) {
			printf("<<< Set speed to %d\n", rpm);
			if (LSS_OK == motor_set_speed(num, rpm, &temp)) {
				if (temp == rpm)
					printf("\t%d confirmed\n", rpm);
			}
			Sleep(1);
			if (LSS_OK == motor_request_speed(num, &temp)) {
				printf("Got speed %d >>>\n", temp);
			} else {
				puts("Fail! >>>");
			}
			rpm += 500;
		}
		printf("<<< Set speed to 0\n");
		if (LSS_OK == motor_set_speed(num, 0, &temp)) {
			if (temp == 0)
				printf("\t%d confirmed\n", 0);
		}
		Sleep(1);
		if (LSS_OK == motor_request_speed(num, &temp)) {
			printf("Got speed %d >>>\n", temp);
		} else {
			puts("Fail! >>>");
		}
		Sleep(1);
		motor_set_speed(num, 0, &temp);
		Sleep(1);
		printf("Disable motor #%d\n", num);
		motor_turn_off(num);
	}