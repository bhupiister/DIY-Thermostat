## This code is for relay https://wiki.52pi.com/index.php?title=EP-0099

#include "esphome.h"
#include "Wire.h"

#define WIRE Wire

#define I2C_ADD 0x10        // Default I2C address

class LinkRelay : public Component, public Switch
{
  private:
  int relay;

  public:
  LinkRelay(int i)
  {
    relay = i;
  }

  void setup() override
  {

    if(!WIRE.begin(7,6))
    {
        ESP_LOGD("Custom","Wire library could not start");
    }else
    {
        ESP_LOGD("Custom","Wire library initialized");
    }
  }

  void write_state(bool state) override
  {
    // This will be called every time the user requests a state change.
    switch(relay)
    {
      case 0:
        Wire.beginTransmission(I2C_ADD);
        Wire.write(0x01);
        Wire.write(state);
        Wire.endTransmission();
        break;

      case 1:
        Wire.beginTransmission(I2C_ADD);
        Wire.write(0x02);
        Wire.write(state);
        Wire.endTransmission();
        break;

      case 2:
        Wire.beginTransmission(I2C_ADD);
        Wire.write(0x03);
        Wire.write(state);
        Wire.endTransmission();
        break;

      case 3:
        Wire.beginTransmission(I2C_ADD);
        Wire.write(0x04);
        Wire.write(state);
        Wire.endTransmission();
        break;
    }

    // Acknowledge new state by publishing it
    publish_state(state);
    }
};
