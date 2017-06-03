#############################################################################################################
#Implementation of Segment Tree
#Time Complexities:
#	Construction: O (n)
#	Range Minimum Query: O (logn)
#Space Complexity:
#	O (n)
#############################################################################################################

import math;

class segTree (object):
	def __init__ (self, array):
		self.segTree = [float ('inf') for i in range (self.getSize (len (array)))];
		self.input = array;
		self.construct (self.input, self.segTree, 0, len (array) - 1, 0);

	def construct (self, array, segTree, lo, hi, pos):
		if (lo == hi):
			segTree [pos] = array [lo];
			return;
		
		mid = (lo + hi) // 2;
		self.construct (array, segTree, lo, mid, pos * 2 + 1);
		self.construct (array, segTree, mid + 1, hi, pos * 2 + 2);
		segTree [pos] = min (segTree [pos * 2 + 1], segTree [pos * 2 + 2]);

	def rangeMinQuery (self, tree, qlo, qhi, lo, hi, pos):
		if (qlo <= lo and qhi >= hi):
			return (tree [pos]);
		if (qlo > hi or qhi < lo):
			return (float ('inf'));
		mid = (lo + hi) // 2;
		return (min (
			self.rangeMinQuery (tree, qlo, qhi, lo, mid, 2*pos + 1),
			self.rangeMinQuery (tree, qlo, qhi, mid + 1, hi, 2*pos + 2)
		));

	def rmq (self, qlo, qhi):
		return (self.rangeMinQuery (self.segTree, qlo, qhi, 0, len (self.input) - 1, 0));

	def getSize (self, arrSize):
		exponent = math.log (arrSize, 2);
		if (exponent.is_integer ()):
			return (arrSize * 2 - 1);
		return ( (2 ** (int (exponent) + 1)) * 2 - 1 );

	def describe (self):
		print ('Array => ', self.input);
		print ('Segment Tree => ', self.segTree);

if (__name__ == '__main__'):
	#array = [int (i) for i in input ().split ()];
	array = [1, 2, -3, -4, -18, 6, 12];
	mySegTree = segTree (array);
	mySegTree.describe ();
	print ('Minimum number from position 1 to 5: ', mySegTree.rmq (1, 5));
