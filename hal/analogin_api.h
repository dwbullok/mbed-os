
/** \addtogroup hal */
/** @{*/
/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_ANALOGIN_API_H
#define MBED_ANALOGIN_API_H

#include "device.h"
#include "pinmap.h"

#if DEVICE_ANALOGIN

#ifdef __cplusplus
extern "C" {
#endif

/** Analogin hal structure. analogin_s is declared in the target's hal
 */
typedef struct analogin_s analogin_t;

/**
 * \defgroup hal_analogin Analogin hal functions
 * @{
 */

/** Initialize the analogin peripheral
 *
 * Configures the pin used by analogin.
 * @param obj The analogin object to initialize
 * @param pin The analogin pin name
 * @param gain The gain to use.  Encoded as a 2 byte hex number: A B.  
 * The gain is the fraction A/B  For example:
 *      1/4: gain = 0x0104.
 *      2/3: gain = 0x0203.
 *        4: gain = 0x0401.
 * The fraction must reduced to lowest terms (i.e. 0x0204 is an invalid
 * gain - you should use 0x0102 instead).
 * 
 * @param v_ref The voltage reference to use, encoded as a 3 byte
 * integer:  T, A, B.  T specifies the type of voltage reference:
 * 
 * T = 0x00: fixed internal voltage reference. Bytes A and B are a 
 * binary coded decimal representation of the voltage reference.  The
 * decimal occurs after the first BCD.
 *      0.1V  : v_ref = 0x000100
 *      0.6V  : v_ref = 0x000600
 *      3.3V  : v_ref = 0x003300
 *      1.95V : v_ref = 0x001a50
 *      2.125 : v_ref = 0x002125 
 * 
 * T = 0x01: relatve to supply voltage VDD.  Bytes A and B are encoded
 * as gain above.
 *      VDD: v_ref = 0x010101
 *      VDD/4: v_ref = 0x010104
 * 
 * T = 0x02: external voltage reference.  Byte A selects the index of
 * the external reference.
 *      external reference 1: 0x020100
 *      external reference 3: 0x020300
 * 
 * Note that a given MCU usually only supports a small number of gains
 * and voltage references.  Asking for an unsupported gain or voltage
 * reference is an error.
 */
void analogin_init(analogin_t *obj, PinName pin, uint16_t gain, uint32_t v_ref);

/** Read the input voltage, represented as a float in the range [0.0, 1.0]
 *
 * @param obj The analogin object
 * @return A floating value representing the current input voltage
 */
float analogin_read(analogin_t *obj);

/** Read the value from analogin pin, represented as an unsigned 16bit value
 *
 * @param obj The analogin object
 * @return An unsigned 16bit value representing the current input voltage
 */
uint16_t analogin_read_u16(analogin_t *obj);

/** Get the pins that support analogin
 *
 * Return a PinMap array of pins that support analogin. The
 * array is terminated with {NC, NC, 0}.
 *
 * @return PinMap array
 */
const PinMap *analogin_pinmap(void);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif

#endif

/** @}*/
