/*
 * Copyright (c) 2019 Sprint
 * Copyright (c) 2020 T-Mobile
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "../include/sv_ies_decoder.h"
#include "../include/enc_dec_bits.h"

/**
* Decodes stn_sr to buffer.
* @param buf
*   buffer to store decoded values.
* @param value
    stn_sr
* @return
*   number of encoded bytes.
*/
int decode_gtp_stn_sr_ie(uint8_t *buf,
    gtp_stn_sr_ie_t *value)
{
    uint16_t total_decoded = 0;
    uint16_t decoded = 0;

    value->nanpi = decode_bits(buf, total_decoded, 8, &decoded);
    total_decoded += decoded;
    value->filler = decode_bits(buf, total_decoded, 4, &decoded);
    total_decoded += decoded;
    value->number_digit = decode_bits(buf, total_decoded, 4, &decoded);
    total_decoded += decoded;

    return total_decoded/CHAR_SIZE;
}

