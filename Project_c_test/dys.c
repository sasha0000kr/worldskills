#include "libschsat.h"
 
  /*
  ** Lab 3: get a raw data from a hyro
  */
  void control(void)
  {
  	int i;
  	const int num = 1;	/* hyro #1 */
  	printf("Enable hyro #%d\n", num);
  	hyro_turn_on(num);
      	Sleep(1);
  	printf("Get RAW data from hyro #%d\n", num);
  	for (i = 0; i < 10; i++) {
  		int16_t x, y, z;
  		if (LSS_OK == hyro_request_raw(num, &x, &y, &z)) {
  			printf("%d: x=%d y=%d z=%d\n", i, x, y, z);
  		} else {
  			puts("Fail!");
  		}
    		Sleep(1);
  	}
  	printf("Disable hyro #%d\n", num);
  	hyro_turn_off(num);
  }