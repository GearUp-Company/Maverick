#ifndef _VARIANT_RAK4630_
#define _VARIANT_RAK4630_

#define RAK4630

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

#define USE_LFXO // Board uses 32khz crystal for LF

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (6)
#define NUM_ANALOG_OUTPUTS (0)

// LEDs
#define PIN_LED1 (39) // P1.07 (32 + 7) Blue
#define LED_BLUE PIN_LED1
#define PIN_LED2 (11) // P0.11 (Green)
#define LED_GREEN PIN_LED2
#define PIN_LED3 (36) // P1.04 (Red)
#define LED_RED PIN_LED3


#define LED_BUILTIN LED_BLUE
#define LED_CONN LED_GREEN
#define LED_POWER LED_RED
#define USER_LED LED_RED

#define LED_STATE_ON 1 // State when LED is litted

/*
 * Buttons
 */

#define PIN_BUTTON1 37
#define BUTTON_NEED_PULLUP

/*
 * Analog pins
 */
#define PIN_A0 (2) // P0.02 (battery sense)
#define PIN_A1 (0xff)
#define PIN_A2 (28)
#define PIN_A3 (29)
#define PIN_A4 (30)
#define PIN_A5 (0xff)
#define PIN_A6 (0xff)
#define PIN_A7 (0xff)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
#define ADC_RESOLUTION 14

// Other pins
#define PIN_AREF (2)

static const uint8_t AREF = PIN_AREF;

/*
 * Serial interfaces
 */
#define PIN_SERIAL1_RX (15)
#define PIN_SERIAL1_TX (16)

#define HAS_GPS 1
#define PIN_GPS_RX PIN_SERIAL1_RX
#define PIN_GPS_TX PIN_SERIAL1_TX 
#define PIN_GPS_PPS (17) // Pulse per second input from the GPS

// Connected to Jlink CDC
#define PIN_SERIAL2_RX (8)
#define PIN_SERIAL2_TX (6)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 2

#define PIN_SPI_MISO (45)
#define PIN_SPI_MOSI (44)
#define PIN_SPI_SCK (43)

#define PIN_SPI1_MISO (29)
#define PIN_SPI1_MOSI (30)
#define PIN_SPI1_SCK (11)

static const uint8_t SS = 42;
static const uint8_t MOSI = PIN_SPI1_MOSI;
static const uint8_t MISO = PIN_SPI1_MISO;
static const uint8_t SCK = PIN_SPI1_SCK;

#define PIN_LSM6DS3TR_C_INT1 (9) // PO.9 connected to INT1 of LSM6DS3TR-C

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA (4)
#define PIN_WIRE_SCL (5)

#define DETECTION_SENSOR_EN 7 // Active pin of the detection sensor P0.07

#define USE_SX1262 // E22-900M30S uses SX1262
// #define USE_SX1268 // E22-400M30S uses SX1268
#define SX126X_MAX_POWER                                                                                                         \
    22 // Outputting 22dBm from SX1262 results in ~30dBm E22-900M30S output (module only uses last stage of the YP2233W PA)
#define SX126X_CS (42) // P1.10
#define SX126X_SCK   PIN_SPI_SCK 
#define SX126X_MOSI  PIN_SPI_MOSI
#define SX126X_MISO  PIN_SPI_MISO
#define SX126X_DIO1 (47)
#define SX126X_BUSY (46)
#define SX126X_RESET (38)
#define SX126X_DIO2_AS_RF_SWITCH // Note for E22 modules: DIO2 is not attached internally to TXEN for automatic TX/RX switching,
                                 // so it needs connecting externally if it is used in this way
#define SX126X_DIO3_TCXO_VOLTAGE 1.8 // Was 1.8 in manual it says 2.2 for E22-400M30S
// #define SX126X_TXEN  RADIOLIB_NC        // no MCU pin
// #define SX126X_RXEN  23                 // nRF P0.23 to E22 RX

#define LORA_CS SX126X_CS     // Compatibility with variant file configuration structure
#define LORA_SCK SX126X_SCK   // Compatibility with variant file configuration structure
#define LORA_MOSI SX126X_MOSI // Compatibility with variant file configuration structure
#define LORA_MISO SX126X_MISO // Compatibility with variant file configuration structure
#define LORA_DIO1 SX126X_DIO1 // Compatibility with variant file configuration structure

#define TCXO_OPTIONAL     // make it so that the firmware can try both TCXO and XTAL
extern float tcxoVoltage; // make this available everywhere

// Testing USB detection
#define NRF_APM

// enables 3.3V periphery like GPS, sensors, and OLed
// Do not toggle this for GPS power savings
#define PIN_3V3_EN (31) // 0.31
#define PIN_5V_EN (25) // E22 Has 5V power supply, do not toggle

// Battery
// The battery sense is hooked to pin A0 (5)
#define BATTERY_PIN PIN_A0
// and has 12 bit resolution
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
#undef AREF_VOLTAGE
#define AREF_VOLTAGE 3.0
#define VBAT_AR_INTERNAL AR_INTERNAL_3_0
#define ADC_MULTIPLIER 2

#define HAS_RTC 0

#define HAS_ETHERNET 1

#define RAK_4631 1

#define PIN_ETHERNET_RESET 21
#define PIN_ETHERNET_SS 12
#define ETH_SPI_PORT SPI1
#define AQ_SET_PIN 36 // P1.04, on extension header
// Diasble EINK display support
#define PIN_EINK_CS (-1)
#define PIN_EINK_BUSY (-1)
#define PIN_EINK_DC (-1)
#define PIN_EINK_RES (-1)
#define PIN_EINK_SCLK (-1)
#define PIN_EINK_MOSI (-1)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif