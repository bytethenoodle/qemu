/*
 * Raspberry Pi emulation (c) 2012 Gregory Estrade
 * Upstreaming code cleanup [including bcm2835_*] (c) 2013 Jan Petrous
 *
 * Rasperry Pi 2 emulation and refactoring Copyright (c) 2015, Microsoft
 * Written by Andrew Baumann
 *
 * This code is licensed under the GNU GPLv2 and later.
 */

#ifndef BCM2835_PERIPHERALS_H
#define BCM2835_PERIPHERALS_H

#include "qemu-common.h"
#include "hw/sysbus.h"

#define TYPE_BCM2835_PERIPHERALS "bcm2835_peripherals"
#define BCM2835_PERIPHERALS(obj) \
    OBJECT_CHECK(BCM2835PeripheralState, (obj), TYPE_BCM2835_PERIPHERALS)

typedef struct BCM2835PeripheralState {
    /*< private >*/
    SysBusDevice parent_obj;
    /*< public >*/

    MemoryRegion peri_mr, peri_mr_alias, gpu_bus_mr;
    AddressSpace gpu_bus_as;
    MemoryRegion ram_alias[4];
    qemu_irq irq, fiq;

    SysBusDevice *ic, *uart0, *uart1, *systimer, *armtimer, *usb, *mphi, *sbm,
        *power, *fb, *property, *vchiq, *emmc, *dma;
} BCM2835PeripheralState;

#endif /* BCM2835_PERIPHERALS_H */