// while (�ݺ���)

/* �ݺ���
- do~whle��: ������ �ѹ��� ����
 do {
		���๮
 } while(���ǹ�);
 
 - while��
 while(���ǹ�)
 {
	���๮
 }

 - for��
 for(�ʱ⹮;���ǹ�;������)
 {
	���๮
 }

 */

#include <stdio.h>

int main()
{
	// �ʱ⹮
	int n = 0;

	//do {
	//	printf("n : %d\n", ++n);
	//} while (n < 10);

	bool isCheck = false; // true(1) or false(0)

	while (true) // ���ѹݺ���
	{
		n++;

		if (n % 2 == 0)
			continue;
		printf("n : %d\n", n);

		if (n > 10)
			break;
	}

	return 0;
}