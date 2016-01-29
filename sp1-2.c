/* HI TA
 * WTF is the star
 */


struct op_list {
	struct op_list *next;
	int type;
	int val;
	int (*opfunc)(int c);
};

int eval(struct op_list *, int){ 
	//store bp somewhere
	//bp = sp
	//store b
	//b = 8+m[b]
	//a = m[ 12+m[b] ]		//something is 4 bits/bytes?

	//pool
		//b = m[ m[b] ]

		//if 0
			//pop to b
		//else
			//loop
				// d = m[ 4+m[b] ]
				// if d > 2 (unsigned)
					//Td
					// b *= 8
					// LOOP FROM POOL
				// else *** TODO: WTF DO WE DO HERE
					// go to mem[table + d*4] (probably reading 0,1,2 from table array)

		//i think we just leave
		//n return



		//table: arr of functions?
		//T0
			// a -= m[ 8+m[b] ]
			// LOOP FROM POOL
		//T1
			//c = m[ 8+m[b] ]
			//c = c & x1f
			//d = 1
			//d = d >> m[ cl ] ***TODO : OK WTF IS CL
			//d = !d
			//a = a & d
			//LOOP FROM POOL
		//T2
			//push a
			// TODO: SOMETHING ABOUT STAR
			// sp += 4
			// LOOP FROM POOLt

	n + mem[r1] + mem[r2]*c
}