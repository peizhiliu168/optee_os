#ifndef TEE_BENCHMARK_H
#define TEE_BENCHMARK_H

#include "tee_api_types.h"

TEE_Result tee_ta_add_sctrace(uint64_t id, uint64_t delta, uint32_t allocated);

TEE_Result tee_ta_get_sctrace(uint64_t return_trace);

TEE_Result tee_ta_reset_sctrace(void);

#endif