# Lingua Franca Turing Machine
This simple projects demonstrate the already known fact that the Lingua Franca
(LF) langauge is turing complete. I demonstrate three different ways in which LF
is turing complete by implementing a Turing Machine as described in "On
Computable Numbers, with an Application to the Entscheidungsproblem"
[link](https://www.cs.virginia.edu/~robins/Turing_Paper_1936.pdf).

## TODOs
- [ ] Implement the Static TM
- [ ] Implement the trivial TM
- [ ] Read out the event queue when the machine halts
- [ ] Implement a more complicated program. (A universal TM?)

## Trivial Turing Machine
Since each reaction in LF can encapsulate an arbitrary C function, a trivial
proof is just implementing a Turing Machine in a reaction body using a while
loop. This is not of interest to us.

## Static Turing Machine
There is a straightforward way of implementing a Turing Machine without needing
any loops in a reaction body. We instead use a `timer` to repeat a sequence of
reactions over and over again. This is also a trivial solution and is not what
we are after. This program would fall in the category of "static" LF programs
and have bounded event queues.

## Turing Machine
Finally, what we want to show is that the structures of the LF model is turing
complete. And particularily the concept of the event queue. The Turing Machine
has its tape encoded in the event queue. This requires a little trickery, but it
is nice since it shows that finding a bound for the maximum size of the event
queue, is undecidable. This was already known, but here is a demonstration of it.
