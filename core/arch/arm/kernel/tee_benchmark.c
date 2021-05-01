
#include <string.h>
#include <optee_msg.h>
#include <kernel/thread.h>
#include <kernel/tee_benchmark.h>

TEE_Result tee_ta_add_sctrace(unsigned long id){
    struct optee_msg_param params;

    memset(&params, 0, sizeof(params));
    params.attr = OPTEE_MSG_ATTR_TYPE_VALUE_OUTPUT;
    params.u.value.a = id;

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