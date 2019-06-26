/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM xen

#if !defined(LTTNG_TRACE_XEN_H) || defined(TRACE_HEADER_MULTI_READ)
#define LTTNG_TRACE_XEN_H

#include <probes/lttng-tracepoint-event.h>
#include <linux/tracepoint.h>

LTTNG_TRACEPOINT_EVENT(xen_mc_entry,

	    TP_PROTO(struct multicall_entry *mc, unsigned nargs),

	    TP_ARGS(mc, nargs),

	    TP_FIELDS(
		    ctf_integer(unsigned int, op, mc->op)
		    ctf_integer(unsigned int, nargs, nargs)
		    ctf_array(unsigned long, args, mc->args, 6)
		    )
)

LTTNG_TRACEPOINT_EVENT(xen_mc_callback,
	    TP_PROTO(xen_mc_callback_fn_t fn, void *data),

	    TP_ARGS(fn, data),

	    TP_FIELDS(
		    ctf_integer_hex(void *, callback, fn)
		    ctf_integer_hex(void *, data, data)
		    )
)

#endif /*  LTTNG_TRACE_XEN_H */

/* This part must be outside protection */
#include <probes/define_trace.h>
