#include "thirteen.h"

int main(void)
{
	char binary[100]; //string conversion storage
	char shift[100];
	char result[100];
	int n1 = 0, n2 = 0;
	int num = 0;

	printf("%d\n", 25699 | 99);
	itob(25699, binary);
	itob(99, shift);
	printf("%s | %s\n", binary, shift);

	printf("Enter a number: ");
	scanf("%d", &n1);
	printf("Enter right shift: ");
	scanf("%d", &n2);
	num = n1 >> n2;
	itob(n1, binary);
	itob(n2, shift);
	itob(num, result);
	printf("%d >> %d = %s >> %s = %s = %d (base 10)\n\n", n1, n2, binary, shift, result, num);

	int number = 0, power = 0;
	int res = 0;

	printf("Enter a number: ");
	scanf("%d", &number);
	printf("Enter left shift: ");
	scanf("%d", &power);
	res = power2(number, power);
	itob(number, binary);
	itob(power, shift);
	itob(res, result);
	printf("%d << %d = %s << %s = %s = %d (base 10)\n\n", number, power, binary, shift, result, res);

	unsigned int packer = 0;
	char c = '\0';
	char p[100];
	int temp = 0;

	for (int i = 0; i < 2; ++i)
	{
		printf("Enter a character: "); //Enter first letter
		scanf(" %c", &c);
		packer = packCharacters(packer, c); //Pack first letter
		itob(packer, p);
		printf("Packed: %d = %s\n", packer, p); //Print number and binary representation
		printf("Enter a character: "); //Enter second letter to OR with
		scanf(" %c", &c);		
		packer = packer | c; //Bitwise OR
		packer = power2(packer, 8); //Shift by 8
		itob(packer, p);
		printf("Packed: %d = %s\n", packer, p); //Print & repeat
	}	
}
	
