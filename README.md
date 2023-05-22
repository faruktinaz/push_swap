# push_swap
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.

The possible actions are:

pa (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
pb (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
sa (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
sb (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
ss: sa and sb at the same time.
ra (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
rb (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
rr: ra and rb at the same time.
rra (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
rrb (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.
