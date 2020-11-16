/* ***********************************************

Copyright, 1997 AT&T Corporation.  All rights
reserved.  Permission is granted for individuals
to use this material for educational purposes
in connection with the book Ruminations on C++,
Addison-Wesley, 1997, ISBN 0-201-42339-1.

************************************************** */


template<class In, class Out>
Out copy(In start, In end, Out dest)
{
	while (start != end)
		*dest++ = *start++;
	return dest;
}
