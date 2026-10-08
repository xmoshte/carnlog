#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/sys/printk.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/gpio.h>


#define LED_NODE0 DT_ALIAS(led0)
#define SLEEP_TIME_MS  1500

void trigger_handler(const struct device *dev, const struct sensor_trigger *trig);
void test_trigger_mode(const struct device *dev);
void test_polling_mode(const struct device *dev);
int ledblink(void);