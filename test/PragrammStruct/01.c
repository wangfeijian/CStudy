/*�������Ʒ���
��д��������ƽ��ж�ȡ�ͷ��ࡣ���е�ÿ���ƶ��л�ɫ�����飬÷�������Һͺ��ң��͵ȼ���2��3��4��5��6��7��8��9��T��J��Q��K �� A����
������ʹ�����ƣ����Ҽ��� A ����ߵȼ��ġ�һ�� 5 ���ƣ�Ȼ������е��Ʒ�Ϊ����ĳһ�ࣨ�г���˳��Ӻõ�������
ͬ��˳��˳��������ͬ��ɫ��
���ţ�4 ���Ƶȼ���ͬ��
��«��3 ���Ƶȼ�һ��������2 �ŵȼ�һ����
ͬ����5 ����ͬ��ɫ��
˳�ӣ�5 ���Ƶȼ�˳��������
���ţ�3 ���Ƶȼ�������
����
һ�ԣ�2 ���Ƶȼ�һ����
������
���һ���ƿ��Է�Ϊ���ֻ������𣬳���ѡ����õ�һ�֡�

Ϊ�˱������룬���Ƶĵȼ��ͻ�ɫ�����£�

�ȼ��� 2��3��4��5��6��7��8��9��t��j��q��k ��a
��ɫ��c d h s
����û�����Ƿ��ƻ�������ͬһ�������Σ����򽫴��ƺ��Ե�������������Ϣ��Ȼ��Ҫ��������һ���ơ��������Ϊ 0 ������һ���ƣ��ͻᵼ�³�����ֹ��*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define RANK 13
#define SUIT 4
#define CARD 5

typedef struct CardType {
	bool flush; //ͬ��
	bool straight; //˳��
	bool four; //����
	bool three; //����
	int pair; // ����
	// 0 ��ʾ���� 1 ��ʾ 1������ 2 ��ʾ��������
	bool cardInHand[SUIT][RANK]; // �жϴ����Ƿ���������
	int numRank[RANK]; // ÿ�������ĸ���
	int numSuit[SUIT]; // ÿ����ɫ�ĸ���
}CardType;

void initCardType(CardType* card); // ��ʼ��
void readCard(CardType* card); // ��ȡ����
void analyseCard(CardType* card); // ��������
void printResult(CardType* card); //��ӡ���

int main(void) {

	CardType card;

	for (; ;) {
		initCardType(&card);
		readCard(&card);
		analyseCard(&card);
		printResult(&card);
	}
}


void initCardType(CardType* card) {
	
	card->flush = false;
	card->straight = false;
	card->four = false;
	card->three = false;
	card->pair = 0;

	int i, j;

	for (i = 0; i < SUIT; i++) {
		card->numSuit[i] = 0;
		for (j = 0; j < RANK; j++) {
			card->cardInHand[i][j] = false;
		}
	}

	for (i = 0; i < RANK; i++) {
		card->numRank[i] = 0;
	}

}


void readCard(CardType* card) {

	int card_read = CARD, rank = 0, suit = 0;
	bool bad_card;
	char ch;

	while (card_read) {

		bad_card = false; // ��Ҫ�������û��Ƶı��

		printf("Enter a card : ");

		// �жϵ���
		ch = getchar();
		switch (ch) {
		case '0':			exit(0); 
		case '2':		   rank = 0; break;
		case '3':		   rank = 1; break;
		case '4':		   rank = 2; break;
		case '5':		   rank = 3; break;
		case '6':		   rank = 4; break;
		case '7':		   rank = 5; break;
		case '8':		   rank = 6; break;
		case '9':		   rank = 7; break;
		case 't':case 'T': rank = 8; break;
		case 'j':case 'J': rank = 9; break;
		case 'q':case 'Q': rank = 10; break;
		case 'k':case 'K': rank = 11; break;
		case 'a':case 'A': rank = 12; break;
		default:bad_card = true; break;
		}

		ch = getchar();
		switch (ch) {
		case 'c': case 'C': suit = 0; break;
		case 'd': case 'D': suit = 1; break;
		case 'h': case 'H': suit = 2; break;
		case 's': case 'S': suit = 3; break;
		default: bad_card = true; break;
		}

		// ��������Ƿ���������ַ�
		while ((ch = getchar()) != '\n') {
			if (ch != ' ')
				bad_card = true;
		}

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (card->cardInHand[suit][rank])
			printf("Duplicated card; ignored.\n");
		else {
			++card->numRank[rank];
			++card->numSuit[suit];
			card->cardInHand[suit][rank] = true;
			card_read--;
		}
	}
}

void analyseCard(CardType* card) {

	int i, count;

	// ͬ������������ͬ��ɫ
	for (i = 0; i < SUIT; i++) {
		if (card->numSuit[i] == 5)
			card->flush = true;
	}

	// ˳���������������ƣ��м䲻�ܸ���

	i = 0;
	// �ҵ������ֵ�һ�Ŵ��ڵ���
	while (card->numRank[i] == 0)
		i++;
	count = 0;
	for (; i < RANK && card->numRank[i] != 0; i++) {
		count++;
	}
	// ˳�ӱ���������
	if (count == CARD) {
		card->straight = true;
		return; // ˳�ӿ϶����Ƕ���
	}

	for (i = 0; i < RANK; i++) {
		if (card->numRank[i] == 4)
			card->four = true;
		if (card->numRank[i] == 3)
			card->three = true;
		if (card->numRank[i] == 2)
			++card->pair;
	}

}

void printResult(CardType* card) {

	if (card->flush && card->straight)
		printf("Stright flush\n");
	else if (card->four)
		printf("Four of a kind\n");
	else if (card->three && card->pair == 1)
		printf("Full house\n");
	else if (card->flush)
		printf("flush\n");
	else if (card->straight)
		printf("straight\n");
	else if (card->three)
		printf("Three of a kind\n");
	else if (card->pair == 2)
		printf("Two pairs\n");
	else if (card->pair == 1)
		printf("pair\n");
	else
		printf("High card\n");

	printf("\n\n");
}