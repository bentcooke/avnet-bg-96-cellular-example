#include "AppPower.h"
#include "platform/mbed_debug.h"
#include "DigitalOut.h"
#include "platform/mbed_wait_api.h"

mbed::DigitalOut BG96_RESET(D7, 1);
mbed::DigitalOut BG96_PWRKEY(D10, 0);
mbed::DigitalOut BG96_VBAT_3V8_EN(D11, 0);

void init_cellular_power(void)
{
	printf("init_cellular_power()\n");
	BG96_VBAT_3V8_EN = 1;
	BG96_PWRKEY = 1;

	wait_ms(300);

	BG96_RESET = 0;

	wait_ms(20000);

	printf("done\n");
}

extern "C" void mbed_main(void)
{
	printf("mbed_main\n");
	init_cellular_power();
}
