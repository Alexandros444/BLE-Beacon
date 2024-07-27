#include "BLEDevice.h"
#include <Arduino.h>
#include "esp_clk.h"
#include "soc/cpu.h"

#define REC_PIN 26
#define SND_PIN 25
#define LED_PIN 27


// ulong rec_time_stamp = 0;


// uint32_t start_cycle_counts = 0;
// uint32_t end_cycle_counts = 0;

// bool has_send_ping = false;

// void maybe_send_ping() {
// 	static ulong snd_time_stamp = 0;
// 	static ulong snd_wait_time = 1000 + (random() % 10000);

// 	if (millis() < snd_time_stamp + snd_wait_time)
// 		return;
	
// 	snd_wait_time = 1000 + (random() % 10000);
// 	has_send_ping = true;

// 	digitalWrite(SND_PIN, HIGH);
// 	delay(500);
// 	digitalWrite(SND_PIN, LOW);
// 	RSR(CCOUNT, start_cycle_counts);
// }

// void loop() {
// 	int rec = digitalRead(REC_PIN);
// 	if (rec)
// 		RSR(CCOUNT, end_cycle_counts);
// 	else {
// 		maybe_send_ping();
// 		return;
// 	}


// 	Serial.println(rec);

// 	printf("Diff: %llu nsec\n", ((uint64_t)(cycle_counts - cycle_counts_last)*1000000000) / clock_freq);
// 	cycle_counts_last = cycle_counts;

// 	digitalWrite(LED_PIN, rec);

	
// 	delay(wait_ms);


	


// }


void setup() {
	Serial.begin(115200);

	Serial.printf("Current Clock Speed: %d", esp_clk_cpu_freq());
	
	pinMode(REC_PIN, INPUT);
	pinMode(SND_PIN, OUTPUT);
	pinMode(LED_PIN, OUTPUT);

}


void loop() {
	int rec = digitalRead(REC_PIN);
	if (rec) {
		digitalWrite(LED_PIN, HIGH);
		delay(500);
		digitalWrite(LED_PIN, LOW);
	}

	static ulong snd_wait_time = 1000 + (random() % 10000);
	static ulong snd_last_time = 0;
	if (millis() < snd_last_time + snd_wait_time)
		return;

	snd_wait_time = 1000 + (random() % 10000);
	snd_last_time = millis();

	digitalWrite(SND_PIN, HIGH);
	delay(500);
	digitalWrite(SND_PIN, LOW);

}