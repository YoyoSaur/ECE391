struct op_list {
	struct op_list *next;
	int type;
	int val;
	int (*opfunc)(int c);
};

int eval(struct op_list *, int){ 
	//store bp somewhere
	//sp = bp
	//store b
	//b = bp+8
	//a = [bp+12]		//something is 4 bits/bytes?

	//call pool
	//b= mem[b]
	//
	//if 0
	//b is useless now
	//else
		//loop
		// d = mem[4+b]
		// cmp d - 2
		// if d > 2
			//Td
			//
		// else
			// go to mem[table + d*4]



	//i think we just leave

}