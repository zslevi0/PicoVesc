#ifndef PICOVESC_H_
#define PICOVESC_H_

#include "datatypes.h"
#include "buffer.h"
#include "crc.h"
#include "hardware/uart.h"

/**
 * @brief Vesc controller class
 * 
 * @author zslevi
 */
class PicoVesc {
    /**
     * @brief Package for FW version
     */
    struct Version {
        /** Major version */
        uint8_t major;
        /** Minor version */
        uint8_t minor;
    };
    public:
        /**
         * @brief Constructs a PicoVesc object
         * 
         * @param uart UART instance (default: uart0)
         * @param tx UART TX pin (default: 0)
         * @param rx UART RX pin (default: 1)
         */
        PicoVesc(uart_inst_t *uart=uart0, uint8_t tx=0, uint8_t rx=1);
        /**
         * @brief Destructor
         * 
         * Releases uart
         */
        ~PicoVesc();
        /**
         * @brief Initialize UART communication
         * 
         * @param baud baudrate (default: 115200)
         */
        void init(uint32_t baud=115200);
        /**
         * @brief Fetch VESC firmware version
         * 
         * @return version
         */
        &Version getFirmwareVersion();
    private:
        /** UART instance */
        uart_inst_t *uart;

        /**
		 * @brief Sends payload via UART
		 *
		 * @param payload  - uint8_t array
		 * @param len      - Length of payload
		 * @return number of bytes sent (-1 if error)
		 */
		int sendPayload(uint8_t * payload, uint len);

		/**
		 * @brief Receive UART message
		 *
		 * @param data - The received data as unit8_t array
		 * @return number of bytes receeived (-1 if error)
		 */
		int receiveUartMessage(uint8_t * data);

        /**
         * @brief Verify and process UART message
         * 
         * @param message UART message
         * @param len length of UART message
         * @param payload decoded payload
         * @return 0 if ok, -1 if error
         */
        int processMessage(uint8_t * message, uint len, uint8_t * payload);
};

#endif // PICOVESC_H_