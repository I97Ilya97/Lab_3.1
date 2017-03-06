#include "TVector.h"

TVector::~TVector()
{
	if (Vector != nullptr) delete[] Vector;
}

TVector::TVector()
{
	Vector = nullptr;
	N = 0;
}

TVector::TVector(const size_t n, const double *vector)
{
	N = n;
	Vector = new double[n];
	memcpy(Vector, vector, N * sizeof(double));
}

TVector& TVector::operator =(const TVector &vector)
{
	N = vector.N;
	if (Vector != nullptr) delete[] Vector;
	Vector = new double[N];
	memcpy(Vector, vector.Vector, N * sizeof(double));
	return *this;
}

double& TVector::operator[](size_t index)
{
	return Vector[index];
}

double TVector::operator *(const double *vector) const
{
	double result = 0;
	for (int i = 0; i < N; i++) result += Vector[i] * vector[i];
	return result;
}

void TVector::Print()
{
	std::cout << '{';
	for (int i = 0; i < N; i++)
	{
		std::cout << Vector[i];
		if (i != N - 1) std::cout << "; ";
	}
	std::cout << '}' << std::endl;
}

std::ostream& operator <<(std::ostream &out, const TVector &vector)
{
	out << '{';
	for (int i = 0; i < vector.N; i++)
	{
		out << vector.Vector[i];
		if (i != vector.N - 1) out << "; ";
	}
	out << '}';
	return out;
}
