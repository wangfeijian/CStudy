/*程序：手牌分类
编写程序对手牌进行读取和分类。手中的每张牌都有花色（方块，梅花，红桃和黑桃）和等级（2，3，4，5，6，7，8，9，T，J，Q，K 和 A）。
不允许使用王牌，并且假设 A 是最高等级的。一手 5 张牌，然后把手中的牌分为下列某一类（列出的顺序从好到坏）。
同花顺（顺序连续且同花色）
四张（4 张牌等级相同）
葫芦（3 张牌等级一样，另外2 张等级一样）
同花（5 张牌同花色）
顺子（5 张牌等级顺序连续）
三张（3 张牌等级连续）
两对
一对（2 张牌等级一样）
其他牌
如果一手牌可以分为两种或多种类别，程序将选择最好的一种。

为了便于输入，将牌的等级和花色简化如下：

等级： 2，3，4，5，6，7，8，9，t，j，q，k ，a
花色：c d h s
如果用户输入非法牌或者输入同一张牌两次，程序将此牌忽略掉，产生错误信息，然后要求输入另一张牌。如果输入为 0 而不是一张牌，就会导致程序终止。*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define RANK 13
#define SUIT 4
#define CARD 5

typedef struct CardType {
	bool flush; //同花
	bool straight; //顺子
	bool four; //四张
	bool three; //三张
	int pair; // 对子
	// 0 表示不是 1 表示 1个对子 2 表示两个对子
	bool cardInHand[SUIT][RANK]; // 判断此牌是否已在手中
	int numRank[RANK]; // 每个点数的个数
	int numSuit[SUIT]; // 每个花色的个数
}CardType;

void initCardType(CardType* card); // 初始化
void readCard(CardType* card); // 读取输入
void analyseCard(CardType* card); // 分析手牌
void printResult(CardType* card); //打印结果

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

		bad_card = false; // 不要忘记重置坏牌的标记

		printf("Enter a card : ");

		// 判断点数
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

		// 检测输入是否多于两个字符
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

	// 同花是五张牌相同花色
	for (i = 0; i < SUIT; i++) {
		if (card->numSuit[i] == 5)
			card->flush = true;
	}

	// 顺子是五张连续的牌，中间不能隔断

	i = 0;
	// 找到数组种第一张存在的牌
	while (card->numRank[i] == 0)
		i++;
	count = 0;
	for (; i < RANK && card->numRank[i] != 0; i++) {
		count++;
	}
	// 顺子必须是五张
	if (count == CARD) {
		card->straight = true;
		return; // 顺子肯定不是对子
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