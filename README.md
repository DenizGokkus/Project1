# Description
 This is a algorithm and data sturctures project that involves the implementation of a sequence class using a single-linked list. The class,
 named Sequence, is a template class that can store elements of any type for both the key and information.
The project involves a external function Produce . The function produce creates a new sequence by interleaving elements from two sequences seq1 and seq2 (where starting positions are specified by indicies)


--------------- an example of the produce function --------


seq1={1,2,3,4,5,6,7,8,9,0} 

seq2={10,20,30,40,50,60,70,80,90,11,12}

seqres= produce (seq1, 2, 3, seq2, 1, 4, 4)

i.e. start1=2, length1=3, start2=1, length2=4, repeat=4

seqres={3,4,5,20,30,40,50,6,7,8,60,70,80,90,9,0,11,12}
