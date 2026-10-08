#include <lsm6ds0/lsm6ds0.h>

int main(void)
{
	const struct device *const dev = DEVICE_DT_GET_ONE(st_lsm6dso);

	
	if (!device_is_ready(dev)) {
		printk("%s: device not ready.\n", dev->name);
		return 0;
	}
	
	#ifdef CONFIG_LSM6DSO_TRIGGER
	printf("Testing LSM6DSO sensor in trigger mode.\n\n");
	test_trigger_mode(dev);
	#else
	printf("Testing LSM6DSO sensor in polling mode.\n\n");
	test_polling_mode(dev);
	#endif
	
	ledblink();

	return 0;
}