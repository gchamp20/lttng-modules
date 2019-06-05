#if !defined(LTTNG_TRACE_XEN_H) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_TRACE_XEN_H

#include <probes/lttng-tracepoint-event.h>
#include <asm/paravirt_types.h>
#include <asm/xen/trace_types.h>
#include <xen/interface/xen.h>

#undef TRACE_SYSTEM
#define TRACE_SYSTEM xen

//struct multicall_entry;

/* Multicalls */

LTTNG_TRACEPOINT_EVENT(xen_mc_entry,

	    TP_PROTO(struct multicall_entry *mc, unsigned int nargs),

	    TP_ARGS(mc, nargs),

	    TP_FIELDS(
		    ctf_integer(unsigned int, op, mc->op)
		    ctf_integer(unsigned int, nargs, nargs)
		    ctf_array(unsigned long, args, mc->args, 6)
		    )
)

#endif /*  LTTNG_TRACE_XEN_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
