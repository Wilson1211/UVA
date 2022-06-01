//first example

Class A{
	Bool Operator () (int x, int y){
		return x*y<a;
	}
private:
	int a;
	int b;
}

A X;
X(a, b); // 括號最左邊的 operand X的 type 是 A，因此 operator function 裡面可以看到 private member

//second example
Class B{
	B operator +(B a){
		B tmp;
		tmp.x = x+a.x; // 因為此時operator + 是 member function 不是 global function，因此不需要設 friend 就可以直接 access private member
		return tmp;
	}
Private:
	Int x;
	Int y;
}


//third example

class Count{
	friend void setX(Count &, int);
public:
	Count() :x(0) // initialize x to 0
	{
		// empty body
	} // end constructor Count
	
	void print() const
	{
		cout << x <endl;
	}
private:
	int x;
;}

void setX(Count &c, int val){
	c.x = val; // allowed because setX is a friend of Count
}