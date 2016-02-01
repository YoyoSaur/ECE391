// Benjamin J Miller
// Ted Culbertson
// Grant Everett
// Liuren Wang (Jettairlines)
// Olivia Mitchell
// Branden Youssef

typedef struct op_list {
	struct op_list *next;
	int type;
	int val;
	int (*opfunc)(int c);
};

int eval(struct op_list * curr, int eax){
  // ebx is op_list
  // eax is int
  // skip eval not important
  // deref first function
  if(curr == NULL)
    return 0;
  op_list ebx = *curr;
  while(ebx != NULL){ //pool
    int edx = ebx.type;
    
    if(edx > 2)
    {
      //Td
      eax = eax * ebx.val;
    }
    else if(edx == 2)
    {
      //T2
      *(ebx.opfunc)(eax);
    }
    else if(edx == 1)
    {
      //T1
      int ecx = ebx.val;
      ecx = ecx & 0x1f;
      edx = 1;
      edx = edx << ecx;
      eax = eax & ~edx;
    }
    else{
      //T0
      eax = eax - ebx.val;
    }
    //pool
    ebx = ebx.next; //movl (%ebx), %ebx
  }
  return eax;
<<<<<<< HEAD
}
=======
}
>>>>>>> origin/master
