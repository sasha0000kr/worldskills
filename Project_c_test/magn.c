  #include "libschsat.h"
 
  /*
  ** Lab 2: get a raw data from a magnetometer
  */
  void control(void)
  {
  	int i;
  	const int num = 1;	/* magnetometer #1 */  
  	printf("Enable magnetometer #%d\n", num);  
  	magnetometer_turn_on(num);
  	Sleep(1);   
  	printf("Get RAW data from magnetometer #%d\n", num);  
  	for (i = 0; i < 10; i++) {
  		int16_t x, y, z;
  		if (LSS_OK == magnetometer_request_raw(num, &x, &y, &z)) {
  			printf("%d: x=%d y=%d z=%d\n", i, x, y, z);
  		} else {
  			puts("Fail!");
  		}
  		Sleep(1);
  	}
  	printf("Disable magnetometer #%d\n", num);
    	magnetometer_turn_off(num);
  }