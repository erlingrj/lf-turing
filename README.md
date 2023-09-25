# Lingua Franca Turing Machine
This simple projects demonstrate the already known fact that the Lingua Franca
(LF) langauge is turing complete. I demonstrate three different ways in which LF
is turing complete by implementing a Turing Machine as described in "On
Computable Numbers, with an Application to the Entscheidungsproblem"
[link](https://www.cs.virginia.edu/~robins/Turing_Paper_1936.pdf).

## TODOs
- [ ] Implement the Static TM
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
and have bounded event queues. So its an analyzable LF program that is Turing
Complete. I view it as the Turing Machine being "emergent" and not encoded
directly in LF.
TODO: Implement a simple example of this.

## Turing Machine
Finally, what we want to show is that the structures of the LF model is turing
complete. And particularily the concept of the event queue. The Turing Machine
has its tape encoded in the event queue. This requires a little trickery, but it
is nice since it shows that finding a bound for the maximum size of the event
queue, is undecidable. This was already known, but here is a demonstration of it.

## To run it:
- Install the Lingua Franca Compiler (LFC): `curl -Ls
  https://install.lf-lang.org | sh -s cli`
- Compile and run a simple program `lfc src/TuringMachine.lf && bin/TuringMachine`

## Write your own program
The program its going to run is encoded in the startup-reaction of the
Transition reactor. The encoding is pretty straight forward. We use binary
symbols and each m-configuration (i.e. instruction) contains two `action_t` one
for the case when the read symbol is `1` and one of its `0`. If the instruction
does not depend on the value of the symbol in the current square, then we
copy the same action to both cases.