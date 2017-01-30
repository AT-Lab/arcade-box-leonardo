// The digital pins are grounded when they are pressed.
//
// NOTE: This sketch file is for use with Arduino Leonardo and
//       Arduino Micro only.
//
// by Matthew Heironimus 2016-11-24 (Library) &
// @pazpi, @martinotu, @aletorri team ATLab
// link utili: https://github.com/retropie/retropie-setup/wiki/retroarch-configuration  joypad configurazione usata Super Nintendo
//             https://github.com/MHeironimus/ArduinoJoystickLibrary pagina ufficiale della librerie usata
//             https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/ piedinatura del chip Arduino, purtoppo la cineseria
//                                                                                  è un misto fra il Leonardo e il Pro Micro
//--------------------------------------------------------------------
#define LETTER_BUTTON 8
#include <Joystick.h>

// nome bottoni
typedef enum butt {A, B, X, Y, START, SELECT, RIGHT_SHOULDER, LEFT_SHOULDER, UP, RIGHT, DOWN, LEFT, NUM_BUTT} enm_butt;

// numero pin dei bottoni
int butt_index[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 15, 16};

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
                   LETTER_BUTTON, 0,      // Button Count, Hat Switch Count
                   true, true, false,     // X and Y, but no Z Axis
                   false, false, false,   // No Rx, Ry, or Rz
                   false, false,          // No rudder or throttle
                   false, false, false);  // No accelerator, brake, or steering


void setup() {
  // Initialize Button Pins
  for (int index = 0; index < NUM_BUTT; index++)
  {
    pinMode(butt_index[index], INPUT_PULLUP);
  }
  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
}

// Last state of the buttons
int lastButtonState[NUM_BUTT] = {0};

void loop() {
  // Read pin values
  for (int index = 0; index < NUM_BUTT; index++)
  {
    int currentButtonState = !digitalRead(butt_index[index]);
    if (currentButtonState != lastButtonState[index])
    {
      switch (index) {
        case A:
          Joystick.setButton(index, currentButtonState);
          break;
        case B:
          Joystick.setButton(index, currentButtonState);
          break;
        case X:
          Joystick.setButton(index, currentButtonState);
          break;
        case Y:
          Joystick.setButton(index, currentButtonState);
          break;
        case START:
          Joystick.setButton(index, currentButtonState);
          break;
        case SELECT:
          Joystick.setButton(index, currentButtonState);
          break;
        case RIGHT_SHOULDER:
          Joystick.setButton(index, currentButtonState);
          break;
        case LEFT_SHOULDER:
          Joystick.setButton(index, currentButtonState);
          break;
        case UP:
          if (currentButtonState == 1) {
            Joystick.setYAxis(-1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case RIGHT:
          if (currentButtonState == 1) {
            Joystick.setXAxis(1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case DOWN:
          if (currentButtonState == 1) {
            Joystick.setYAxis(1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case LEFT:
          if (currentButtonState == 1) {
            Joystick.setXAxis(-1);
          } else {
            Joystick.setXAxis(0);
          }
          break;

      }
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(10);
}

