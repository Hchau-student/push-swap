//
// Created by Hugor Chau on 4/28/21.
//

#include "header.h"
//	SA,
//	SB,
//	SS,
//	PA,
//	PB,
//	RA,
//	RB,
//	RR,
//	RRA,
//	RRB,
//	RRR

t_command		command(int which)
{
	static t_command	commands[COMMAND_NUM] = {
			(t_command){&sa, NULL, "sa"},
			(t_command){&sb, NULL, "sb"},
			(t_command){NULL, &ss, "ss"},
			(t_command){NULL, &pa, "pa"},
			(t_command){NULL, &pb, "pb"},
			(t_command){&ra, NULL, "ra"},
			(t_command){&rb, NULL, "rb"},
			(t_command){NULL, &rr, "rr"},
			(t_command){&rra, NULL, "rra"},
			(t_command){&rrb, NULL, "rrb"},
			(t_command){NULL, &rrr, "rrr"}
	};
	return commands[which];
}