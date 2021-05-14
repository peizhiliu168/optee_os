#include <string.h>
#include <optee_msg.h>
#include <kernel/thread.h>
#include <kernel/tee_benchmark.h>

TEE_Result tee_ta_add_sctrace(uint64_t id, uint64_t delta, uint32_t allocated){
    struct optee_msg_param params;

    memset(&params, 0, sizeof(params));
    params.attr = OPTEE_MSG_ATTR_TYPE_VALUE_OUTPUT;
    DMSG("id: %ld, delta: %ld, alloc: %ld \n", id, delta, allocated);
    params.u.value.a = id;
    params.u.value.b = delta;
    params.u.value.c = allocated;

    TEE_Result res = thread_rpc_cmd(OPTEE_MSG_RPC_CMD_ADD_SCTRACE, 1, &params);

    return res;
}

/*TEE_Result tee_ta_get_sctrace(unsigned long return_trace){


}*/

TEE_Result tee_ta_reset_sctrace(void){
    struct optee_msg_param params;

    memset(&params, 0, sizeof(params));
    params.attr = OPTEE_MSG_ATTR_TYPE_VALUE_OUTPUT;

    TEE_Result res = thread_rpc_cmd(OPTEE_MSG_RPC_CMD_RESET_SCTRACE, 0, &params);

    return res;
}