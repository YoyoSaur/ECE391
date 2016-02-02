// Benjamin J Miller bjmillr2
// Ted Culbertson tculber2
// Grant Everett geveret2
// Liuren Wang lwang108
// Olivia Mitchell ozmitch2
// Branden Youssef byousse2
// Sindhu Gudala gudala2

typedef struct op_list {
	struct op_list *next;
	int type;
	int val;
	int (*opfunc)(int c);
};
//switch gets turned into jump table
//better names
//everything can be in one line
//ebx should be a pointer
int eval(struct op_list * head, int inst){ //probably the head
  if(head == NULL)
    return 0;
  op_list curr = head; //is dis gud
  while(curr != NULL){ //pool
    int type = curr->type;

    switch (type) {
			case 0:
	      //T0
	      inst = inst - curr->val;
				break;
			case 1:
	      //T1
	      inst = inst & ~((cur->val & 0x1f) << 1);
				break;
	  	case 2:
	      //T2
	      return inst = (curr->opfunc)(inst);
				break;
			default:
	      inst = inst * curr->val;
				break;
		}
    curr = curr->next; //is this right
  }
  return inst;
}
