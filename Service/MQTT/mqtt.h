/*
 * mqtt.h
 *
 * Created: 7/19/2020 11:12:22 AM
 *  Author: H
 */ 


#ifndef MQTT_H_
#define MQTT_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "avr/interrupt.h"
#include "avr/io.h"
#include "data_types.h"
#include "bit_handle.h"
#include "uart.h"
#include "string.h"

void MQTT_Init(void);
void MQTT_Connect(U_8* pu8ID);
void MQTT_Sbscribe(U_8* topic);
void MQTT_Publish(U_8* topic, U_8* pu8msg,U_8 msgSize,U_8 QOS);

void encodeUTFStr(U_8* pu8str);


#endif /* MQTT_H_ */