/*
 * Raspberry Pi emulation (c) 2012 Gregory Estrade
 * Upstreaming code cleanup [including bcm2835_*] (c) 2013 Jan Petrous
 *
 * Rasperry Pi 2 emulation and refactoring Copyright (c) 2015, Microsoft
 * Written by Andrew Baumann
 *
 * This code is licensed under the GNU GPLv2 and later.
 */

#ifndef BCM2836_H
#define BCM2836_H

#include "hw/arm/arm.h"
#include "bcm2835_peripherals.h"

#define TYPE_BCM2836 "bcm2836"
#define BCM2836(obj) OBJECT_CHECK(BCM2836State, (obj), TYPE_BCM2836)

#define BCM2836_NCPUS 4

typedef struct BCM2836State {
    /*< private >*/
    DeviceState parent_obj;
    /*< public >*/

    ARMCPU cpus[BCM2836_NCPUS];
    SysBusDevice *ic;
    BCM2835PeripheralState peripherals;

    uint64_t vcram_size;
} BCM2836State;

#endif /* BCM2836_H */