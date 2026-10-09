#include <zephyr/drivers/sensor.h>

void trigger_handler(const struct device *dev, const struct sensor_trigger *trig);
void test_trigger_mode(const struct device *dev);
void test_polling_mode(const struct device *dev);