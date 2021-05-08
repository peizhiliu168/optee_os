#include <arm.h>
#include <optee_msg.h>
#include <kernel/tee_time_us.h>

TEE_Result tee_get_time_us(uint64_t* time)
{
    uint64_t cntpct = barrier_read_cntpct();
    uint32_t cntfrq = read_cntfrq();

    *time = (cntpct * 1000000) / cntfrq;
    
    return TEE_SUCCESS;
}