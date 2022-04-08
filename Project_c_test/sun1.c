#include "libschsat.h"

/*
** Lab 4: get a raw data from a sun sensor
*/
void control(void)
{
    int i;
    const int num = 1; /* sun sensor #1 */
    printf("Enable sensor #%d\n", num);
    sun_sensor_turn_on(num);
    Sleep(1);
    printf("Started arduino main code");
    arduino_send(0, 1, NULL, NULL, 100);
    Sleep(1);
    printf("Get RAW data from sun sensor #%d\n", num);
    for (i = 0; i < 10; i++)
    {
        uint16_t value1;
        uint16_t value2;
        if (LSS_OK == sun_sensor_request_raw(num, &value1, &value2))
        {
            printf("%d: raw=%d ; %d\n", i, value1, value2);
        }
        else
        {
            puts("Fail!");
        }
        Sleep(1);
    }
    printf("Disable sensor #%d\n", num);
    sun_sensor_turn_off(num);
}