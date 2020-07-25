#include "i2cEncoderLibV2.h"
#include "encoder.h"

void encoder_update_kb(uint8_t index, bool clockwise) {
    encoder_update_user(index, clockwise);
}
