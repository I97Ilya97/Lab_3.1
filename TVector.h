#include <iostream>
#include <stdlib.h>

class TVector
{
private:
	int N;
	double *Vector;
public:
	~TVector();
	TVector();
	TVector(const size_t n, const double *vector);
	TVector& operator =(const TVector &vector);
	double& operator [](const size_t index);
	double operator *(const double *vector) const;
	void Print();
	friend std::ostream& operator <<(std::ostream &out, const TVector &vector);
};

std::ostream& operator <<(std::ostream &out, const TVector &vector);
