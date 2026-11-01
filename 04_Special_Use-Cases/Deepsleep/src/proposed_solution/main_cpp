#include <Arduino.h>
#include <wifi_connection.h>

// seconds > milliseconds > microseconds (*1000)
#define MICROSECONDS_TO_SECONDS 1000000

// in this example a dummy url with additional POST vars is called
#define MYURL "https://lorem.ipsum.com/api/item5"

void touchCallbackFunc() {
  // here we catch the touched pin. Note: this id represents the id of 
  // the touchpin (see pinout sheet), not GPIO id
  touch_pad_t touchedPinID = esp_sleep_get_touchpad_wakeup_status();

  Serial.println(touchedPinID);

  // touch id 0 ~> GPIO 4
  if(touchedPinID == 0) {
    callURL(MYURL, "POST", "HIGH");
  } else if(touchedPinID == 2) {
    callURL(MYURL, "POST", "LOW");
  }
}

void callback() {
  // this callback is only called if esp is awake, thus you need
  // to hold the touch pin for a long time OR (better approach) the 
  // touched pin is catched within the function touchCallbackFunc
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  initWifi();


  /**
   * 
   * Timer
   * 
   */
  //callURL(MYURL, "POST", "HIGH");
  //Serial.println("Set timer to wake esp up");
  //esp_sleep_enable_timer_wakeup(10 * MICROSECONDS_TO_SECONDS);


  /**
   * 
   * Touch Pin
   * 
   */
  // call touch callback after touchpad wakeup
  touchCallbackFunc();

  // set touchpad wakeup for next time
  touchAttachInterrupt(4, callback, 40);
  touchAttachInterrupt(2, callback, 40);
  esp_sleep_enable_touchpad_wakeup();


  delay(1000);
  Serial.println("Fall asleep");
  esp_deep_sleep_start();
}

void loop() {
}