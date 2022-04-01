#ifndef COBS_H_
#define COBS_H_

#include <stdint.h>
#include <stdlib.h>

#define COBS_ENCODE_DST_BUF_LEN_MAX(SRC_LEN) \
	((SRC_LEN) + ((SRC_LEN) / 254u) + 1)

#define COBS_DECODE_DST_BUF_LEN_MAX(SRC_LEN) \
	(((SRC_LEN) == 0) ? 0 : ((SRC_LEN) - 1))

typedef enum {
	COBS_ENCODE_OK = 0x00,
	COBS_ENCODE_NULL_POINTER = 0x01,
	COBS_ENCODE_OUT_BUFFER_OVERFLOW = 0x02
} cobs_encode_status;

typedef struct {
	size_t out_len;
	cobs_encode_status status;
} cobs_encode_result;

typedef enum {
	COBS_DECODE_OK = 0x00,
	COBS_DECODE_NULL_POINTER = 0x01,
	COBS_DECODE_OUT_BUFFER_OVERFLOW = 0x02,
	COBS_DECODE_ZERO_BYTE_IN_INPUT = 0x04,
	COBS_DECODE_INPUT_TOO_SHORT = 0x08
} cobs_decode_status;

typedef struct {
	size_t out_len;
	cobs_decode_status status;
} cobs_decode_result;

cobs_encode_result cobs_encode(uint8_t * dst_buf_ptr,
			       size_t dst_buf_len,
			       const uint8_t * src_ptr, size_t src_len);
cobs_decode_result cobs_decode(uint8_t * dst_buf_ptr,
			       size_t dst_buf_len,
			       const uint8_t * src_ptr, size_t src_len);



#endif
