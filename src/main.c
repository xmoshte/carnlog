#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/usb/usbd.h>
#include <zephyr/usb/usb_device.h>
#include <stdio.h>
#include <zephyr/sys/printk.h>

#include <lsm6ds0/lsm6ds0.h>
#include <led/led.h>

int main(void)
{
	const struct device *const dev1 = DEVICE_DT_GET_ONE(st_lsm6dso);
	const struct device *const dev2 = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	uint32_t dtr =0;

	if (!device_is_ready(dev1)) {
		printk("%s: device not ready.\n", dev1->name);
		return 0;
	}

	#ifdef CONFIG_LSM6DSO_TRIGGER
	printf("Testing LSM6DSO sensor in trigger mode.\n\n");
	test_trigger_mode(dev1);
	#else
	printf("Testing LSM6DSO sensor in polling mode.\n\n");
	test_polling_mode(dev1);
	#endif
	
	ledblink();

	/* Wait for Data Terminal Ready signal */
	while (!dtr) 
	{
		uart_line_ctrl_get(dev2, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}

	return 0;
}