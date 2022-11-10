/*
  btt_skr_mini_1.1_map.h - driver code for STM32F103RC ARM processors

  Part of grblHAL

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#if N_ABC_MOTORS > 1 || N_GANGED
#error "Axis configuration is not supported!"
#endif

#if N_AXIS == 4
#define BOARD_NAME "BTT SKR MINI V1.1 4-axis"
#else
#define BOARD_NAME "BTT SKR MINI V1.1"
#endif

#define I2C_PORT 1

#ifdef TRINAMIC
 #undef TRINAMIC_ENABLE
 #ifdef TRINAMIC_MIXED_DRIVERS
  #undef TRINAMIC_MIXED_DRIVERS
 #endif
 #define SERIAL2_MOD
 #define HAS_BOARD_INIT
 #define TRINAMIC_ENABLE 2209
 #define TRINAMIC_MIXED_DRIVERS 0
#endif

//#if EEPROM_ENABLE < 2
//#undef EEPROM_ENABLE
//#define EEPROM_ENABLE 3 // 32Kbit EEPROM, 32byte page size
//#endif

// Define step pulse output pins.
#define X_STEP_PORT             GPIOC
#define X_STEP_PIN              6 //PC6
#define Y_STEP_PORT             GPIOB
#define Y_STEP_PIN              13 //PB13
#define Z_STEP_PORT             GPIOB
#define Z_STEP_PIN              10 //PB10
#define STEP_OUTMODE            GPIO_BITBAND //GPIO_MAP GPIO_BITBAND

// Define step direction output pins.
#define X_DIRECTION_PORT        GPIOC
#define X_DIRECTION_PIN         7  //PC7
#define Y_DIRECTION_PORT        GPIOB
#define Y_DIRECTION_PIN         14 //PB14
#define Z_DIRECTION_PORT        GPIOB
#define Z_DIRECTION_PIN         11 //PB11 //********
#define DIRECTION_OUTMODE       GPIO_BITBAND

// Define stepper driver enable/disable output pin.
#define X_ENABLE_PORT           GPIOB
#define X_ENABLE_PIN            15 //PB15
#define Y_ENABLE_PORT           GPIOB
#define Y_ENABLE_PIN            12 //PB12
#define Z_ENABLE_PORT           GPIOB
#define Z_ENABLE_PIN            2  //PB2

// Define homing/hard limit switch input pins.
#define LIMIT_PORT              GPIOC
#define X_LIMIT_PIN             2 //PC2
#define Y_LIMIT_PIN             1 //PC1
#define Z_LIMIT_PIN             0 //PC0
#define LIMIT_INMODE            GPIO_BITBAND

// Define ganged axis or A axis step pulse and step direction output pins.
#if N_ABC_MOTORS == 1
#define M3_AVAILABLE
#define M3_STEP_PORT            GPIOC
#define M3_STEP_PIN             5
#define M3_DIRECTION_PORT       GPIOB
#define M3_DIRECTION_PIN        0
#define M3_ENABLE_PORT          GPIOC
#define M3_ENABLE_PIN           4
#endif

  // Define spindle enable and spindle direction output pins.
#define SPINDLE_ENABLE_PORT     GPIOC
#define SPINDLE_ENABLE_PIN      9 //PA8
#define SPINDLE_DIRECTION_PORT  GPIOA
#define SPINDLE_DIRECTION_PIN   1 //PA8

// Define spindle PWM output pin.
#define SPINDLE_PWM_PORT_BASE   GPIOA_BASE
#define SPINDLE_PWM_PIN         8 //PC7

// Define flood and mist coolant enable output pins.
#define COOLANT_FLOOD_PORT      GPIOC
#define COOLANT_FLOOD_PIN       8 //PC9
#define COOLANT_MIST_PORT       GPIOC
#define COOLANT_MIST_PIN        8 //PC9

// Define user-control controls (cycle start, reset, feed hold) input pins.
#define CONTROL_PORT            GPIOC
#define RESET_PIN               15 //PC15
#define FEED_HOLD_PIN           13 //PC13
#define CYCLE_START_PIN         3 //PC3
#if SAFETY_DOOR_ENABLE
 #define SAFETY_DOOR_PIN         14 //PC14
#endif
#define CONTROL_INMODE GPIO_MAP

// Define probe switch input pin.
#define PROBE_PORT              GPIOA
#define PROBE_PIN               2 //PC3

#if KEYPAD_ENABLE
 #define KEYPAD_PORT             GPIOA
 #define KEYPAD_STROBE_PIN       1 //PA1
#endif

#if SDCARD_ENABLE
 #define SD_CS_PORT  GPIOA
 #define SD_CS_PIN   4 //PA4
// The following defines are not used but defined for reference
// Port init is done by HAL_SPI_MspInit() in stm32f1xx_hal_msp.c
 #define SD_IO_PORT  GPIOA
 #define SD_SCK_PIN  5 //PA5
 #define SD_MISO_PIN 6 //PA6
 #define SD_MOSI_PIN 7 //PA7
#endif
