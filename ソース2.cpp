#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	//関数
	const int CARD = 3;
	const int CARD_NUMBER = 10;

	//変数
	int i, hit = 0;
	int playerCard[CARD];
	int enemyCard[CARD];
	int plyChoice[CARD];
	int emyChoice[CARD];

	bool trunFlag = true;
	bool judgementFlag = false;

	//乱数の初期化
	srand((unsigned int)time(NULL));

	//CARD分の配列にランダムな整数を設定
	for (i = 0; i < CARD; i++)
	{
		playerCard[i] = rand() % CARD_NUMBER;
		enemyCard[i] = rand() % CARD_NUMBER;
	}
	cout << "===================   Hit & Blow   ============================" << "\n";
	cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";
	cout << "あなたの配られてカードは," << "\n";

	//自身に配られたカードの表示
	for (i = 0; i < CARD; i++)
	{
		cout << i + 1 << "番目" << playerCard[i] << "\n";
	}

	cout << "===================   GAME STRAT   ============================" << "\n";

	//breakするまでループ
	while (true)
	{
		//trunFlagが「true」の場合実行
		if (trunFlag)
		{
			//hitの初期化
			hit = 0;
			cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";

			//CARD分の配列に答えだと思う整数を入力
			for (i = 0; i < CARD; i++)
			{
				//正しい整数が入力されるまでループ
				while (true)
				{
					cin >> plyChoice[i];
					if (0 > plyChoice[i] || 9 < plyChoice[i])
					{
						cout << "入力に誤りがあります。再度入力してください。\n";
					}
					else
					{
						break;
					}

				}
			}

			//「i」回目のそれぞれの数字を判定
			for (i = 0; i < CARD; i++)
			{
				//「i」回目のそれぞれの数字が同じだった場合実行
				if (plyChoice[i] == enemyCard[i])
				{
					cout << "Hit,";
					hit++;
				}
				//「i」回目のそれぞれの数字が異なった場合実行
				else
				{
					cout << "Blow,";
				}
			}
			cout << "\n";
			//「hit」カウントが3になった場合実行
			if (hit == 3)
			{
				cout << "3Hit!!\n";
				//judgementFlagを「true」に変更
				judgementFlag = true;
				break;
			}

			cout << "\n";
			//trunFlagを「false」に変更(playerとcpuのターンの切り替えのため)
			trunFlag = false;
		}
		//trunFlagが「false」の場合実行
		else
		{
			//hitの初期化
			hit = 0;

			//CARD分の配列にCPUの予想数を表示
			cout << "ENEMY TRUN \n";
			for (i = 0; i < CARD; i++)
			{
				//ランダムな予想数を生成
				emyChoice[i] = rand() % CARD_NUMBER;

				cout << i + 1 << "番目" << emyChoice[i] << "\n";
			}

			//「i」回目のそれぞれの数字を判定
			for (i = 0; i < CARD; i++)
			{
				//「i」回目のそれぞれの数字が同じだった場合実行
				if (emyChoice[i] == playerCard[i])
				{
					cout << "Hit,";
					hit++;
				}
				//「i」回目のそれぞれの数字が異なった場合実行
				else
				{
					cout << "Blow,";
				}
			}
			cout << "\n";
			//「hit」カウントが3になった場合実行
			if (hit == 3)
			{
				cout << "3Hit!!\n";
				break;
			}

			cout << "\n";
			//trunFlagを「true」に変更
			trunFlag = true;
		}


	}

	//judgementFlagが「true」だった場合実行
	if (judgementFlag)
	{
		cout << "PLAYER WINNER\n";
	}
	else
	{
		cout << "ENEMY WINNER\n";
	}

	return 0;
}