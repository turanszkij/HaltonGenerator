// Based on: http://people.sc.fsu.edu/~jburkardt/cpp_src/halton/halton.html

#include <iostream>
#include <string>

using namespace std;

static const int PRIMES[] = { 2, 3, 5, 7 };

int __sum(int n, int a[])
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	return sum;
}

double *halton(int i, int dim)
{
	int d;
	int j;
	double *prime_inv;
	double *r;
	int *t;

	prime_inv = new double[dim];
	r = new double[dim];
	t = new int[dim];

	for (j = 0; j < dim; j++)
	{
		t[j] = i;
	}

	for (j = 0; j < dim; j++)
	{
		prime_inv[j] = 1.0 / (double)(PRIMES[j]);
	}

	for (j = 0; j < dim; j++)
	{
		r[j] = 0.0;
	}

	while (0 < __sum(dim, t))
	{
		for (j = 0; j < dim; j++)
		{
			d = (t[j] % PRIMES[j]);
			r[j] = r[j] + (double)(d)* prime_inv[j];
			prime_inv[j] = prime_inv[j] / (double)(PRIMES[j]);
			t[j] = (t[j] / PRIMES[j]);
		}
	}

	delete[] prime_inv;
	delete[] t;

	return r;
}

int main()
{
	const int dimension = 4;
	const int count = 32;

	cout.precision(4);

	for (int i = 1; i <= count; ++i)
	{
		double* results = halton(i, dimension);
		for (int j = 0; j < dimension; ++j)
		{
			cout << fixed << results[j] << "\t";
		}
		cout << endl;
		delete[] results;
	}

	cin.get();

    return 0;
}

