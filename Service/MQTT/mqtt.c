/*
 * mqtt.c
 *
 * Created: 7/19/2020 11:12:07 AM
 *  Author: H
 */ 
#include "mqtt.h"

const U_8 proName[] = "MQTT";
U_16 packetIdent = 1;

void MQTT_Init(void)
{
	uart_init(UART_0,9600);
}

void MQTT_Connect(U_8* pu8ID)
{
	U_8 remLength = ( 2 + strlen(proName) ) + 1 + 1 + 2 + ( 2 + strlen(pu8ID) );
	
	uart_send_byte(UART_0,0x10);					/*Packet type*/
	uart_send_byte(UART_0,remLength);				/*Rem. length*/
	encodeUTFStr(proName);							/*Protocol name*/
	uart_send_byte(UART_0,0x04);					/*Protocol level*/
	uart_send_byte(UART_0,0x02);					/*flags*/
	uart_send_byte(UART_0,0xff);					/*KAT MSB*/
	uart_send_byte(UART_0,0xff);					/*KAT LSB*/
	encodeUTFStr(pu8ID);							/*client ID*/
}

void MQTT_Sbscribe(U_8* topic)
{
	U_8 remLength = 2 + ( 2 + strlen(topic) ) + 1;
	
	uart_send_byte(UART_0,0x82);					/*Packet type*/
	uart_send_byte(UART_0,remLength);				/*Rem. length*/
	uart_send_byte(UART_0,(packetIdent>>8));		/*packet id MSB*/
	uart_send_byte(UART_0,packetIdent);				/*packet id LSB*/
	packetIdent ++;
	encodeUTFStr(topic);							/*list of topic*/
	uart_send_byte(UART_0, 0x01);					/*Req. QoS*/
}

void MQTT_Publish(U_8* topic, U_8* pu8msg,U_8 msgSize,U_8 QOS)
{
	U_8 count = 0;
	U_8 remLength = (2 + strlen(topic)) + msgSize ;
	if (QOS > 0)
	{
		uart_send_byte(UART_0,0x32);				/*Packet type and Quality of service_1*/
		remLength = remLength + 2;
	} 
	else 
	{
		uart_send_byte(UART_0,0x30);				/*Packet type and Quality of service_0*/
	}
	uart_send_byte(UART_0,remLength);				/*Rem. length*/
	encodeUTFStr(topic);							/*list of topic*/
	if (QOS > 0)
	{
		uart_send_byte(UART_0,(packetIdent>>8));	/*packet id MSB*/
		uart_send_byte(UART_0,packetIdent);			/*packet id LSB*/
		packetIdent ++;
	} 	
	for (count =0; count < msgSize ;count ++)
	{
		uart_send_byte(UART_0,pu8msg[count]);		/*Msg send*/
	}
}

void encodeUTFStr(U_8* pu8str)
{
	uart_send_byte(UART_0, 0x00);					/*Len MSB*/
	uart_send_byte(UART_0, strlen(pu8str));			/*Len LSB*/
	uart_send_str(UART_0, pu8str);
}