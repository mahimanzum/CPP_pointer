# CPP_pointer
Some basic codes for understanding pointer clearly.
One thing to keep in mind. <br>
You need explicit declaration of NULL or nullPtr if you want a pointer to be null. <br>
For deletion from a linked list there needs to be a check because head is a special case. Not if we are using pointer to pointer <br>
in that case we can just update the addresses using pointer to pointer because that is a higher level of abstraction and we can use that to update other things as we are not using those variables like head explicitly. As we are pointing to the head pointer using another pointer to pointer we can update that and no need to update head with explicit check. that will be done automatically. This is what is done in the linkedlist.cpp file.  <br>

Valgrind is a tool for cpp that checks for memory leaks malloc calloc(Anytime one of these us used the programmar is responsible to free the memory). <br>

Anything declared in the main function gives memory in the stack memory(Each line is also known as frame) which doesn't need to be freed. but heap memory which is allocated using the malloc library needs to be freed manually. <br>

int main(){
  char s[4]; //uses stack memory
  char *s = malloc(4); //uses heap memory which is needed to be freed
}
