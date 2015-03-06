#
# Makefile for miscellaneous I2C chip drivers.
#

obj-$(CONFIG_BOSCH_BMA250)      += bma250_bosch.o
obj-$(CONFIG_KIONIX_KXTJ2)      += kxtj2.o
obj-$(CONFIG_YAMAHA_YAS532)      += yas532.o
obj-$(CONFIG_BOSCH_BMA250)      += bma250_bosch.o
ifeq ($(CONFIG_I2C_DEBUG_CHIP),y)
EXTRA_CFLAGS += -DDEBUG
endif

