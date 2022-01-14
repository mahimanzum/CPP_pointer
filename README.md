# CPP_pointer
Some basic codes for understanding pointer clearly.
One thing to keep in mind. <br>
You need explicit declaration of NULL or nullPtr if you want a pointer to be null. <br>
For deletion from a linked list there needs to be a check because head is a special case. Not if we are using pointer to pointer <br>
in that case we can just update the addresses using pointer to pointer because that is a higher level of abstraction and we can use that to update other things as we are not using those variables like head explicitly. As we are pointing to the head pointer using another pointer to pointer we can update that and no need to update head with explicit check. that will be done automatically. This is what is done in the linkedlist.cpp file. 
