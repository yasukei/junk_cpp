#include <cstdio>

#include <bitset>

template <unsigned int N>
void __printBitset(std::bitset<N> bitset)
{
	printf("size():       [%zu]\n", bitset.size());
	printf("count():      [%zu]\n", bitset.count());
	printf("all():        [%u]\n", bitset.all());
	printf("any():        [%u]\n", bitset.any());
	printf("none():       [%u]\n", bitset.none());
	printf("to_string():  [%s]\n", bitset.to_string().c_str());
	for (int i = 0; i < bitset.size(); i++)
	{
		printf("[%d]: [%u]\n", i, (bool)bitset[i]);
	}
}

int main()
{
	std::bitset<8> bitset8;
	printf("\n[Initial state]\n");
	__printBitset<bitset8.size()>(bitset8);

	printf("\n[After flip]\n");
	bitset8.flip();
	__printBitset<bitset8.size()>(bitset8);

	return 0;
}
