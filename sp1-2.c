/* HI GROUP
 * make sure all this is translated correctly before trying to make sense of it
 * 1. x86 -> human language		; approved by Jett & Branden
 * 2. *pending* human language -> logically simplified human language
 */

//	n + mem[r1] + mem[r2]*c
//	32bit arch

struct op_list {
	struct op_list *next;
	int type;
	int val;
	int (*opfunc)(int c);
};

int eval(struct op_list *, int){ 
	//push bp to stack
	//bp = sp
	//push b to stack
	//b = 8+m[b]
	//a = m[ 12+m[b] ]		//something is 4 bits/bytes?

	//POOL
		//b = 0?

		//if 0
			//pop to b
		//else
			//LOOP
				// d = m[ 4+m[b] ]
				// if d > 2 (unsigned)
					//Td
						// a *= m[ 8+m[b] ]
						// LOOP FROM POOL
				// else
					// go to table[d] (simplified all bit mults)
		//return



		//table: is array of functions
		//T0
			// a -= m[ 8+m[b] ]
			// LOOP FROM POOL
		//T1
			//c = m[ 8+m[b] ]
			//c = c & x1f
			//d = 1
			//d = d >> m[ last 8 bits(1/4) of c ]
			//d = !d
			//a = a & d
			//LOOP FROM POOL
		//T2
			//push a
			//call func at m[ m[b]+12 ] 
			//sp += 4
			//LOOP FROM POOL

}
