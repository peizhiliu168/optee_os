#ifndef TEE_BENCHMARK_H
#define TEE_BENCHMARK_H

#include "tee_api_types.h"

TEE_Result tee_ta_add_sctrace(unsigned long id);

//TEE_Result tee_ta_get_sctrace(unsigned long return_trace);

TEE_Result tee_ta_reset_sctrace(void);

#endif