#include "PicoVesc.h"

PicoVesc::PicoVesc(uart_inst_t *uart_in, uint8_t tx, uint8_t rx) :
uart(uart_in) {
    gpio_set_function(tx, UART_FUNCSEL_NUM(uart, tx));
    gpio_set_function(rx, UART_FUNCSEL_NUM(uart, rx));
}

PicoVesc::~PicoVesc() {
    uart_deinit(uart);
}

void PicoVesc::init(uint32_t baud) {
    uart_init(uart, baud);
}

&Version PicoVesc::getFirmwareVersion() {

}

int PicoVesc::sendPayload(uint8_t * payload, uint len) {

}

int PicoVesc::receiveUartMessage(uint8_t * data) {

}

int PicoVesc::processMessage(uint8_t * message, uint len, uint8_t * payload) {
    
}