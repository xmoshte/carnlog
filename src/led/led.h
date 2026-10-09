#include <zephyr/drivers/gpio.h>

#define LED_NODE0 DT_ALIAS(led0)
#define SLEEP_TIME_MS  1500

int ledblink(void);