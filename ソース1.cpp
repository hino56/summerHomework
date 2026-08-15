#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//変数
	int player;
	int cpu;
	int result;
	int i;
	int win = 0;
	int lose = 0;
	int draw = 0;

	//ランダムな整数の初期化
	srand((unsigned int)time(nullptr));

	cout << "じゃんけんゲームを開始します。" << endl;

	//５回ループ
	for (i = 0; i < 5; i++)
	{
		cout << endl;
		cout << "-------- " << i + 1 << "回戦 --------" << endl;

		//入力数字の判定
		while (true)
		{
			cout << "0：グー　1：チョキ　2：パー" << endl;
			cout << "プレイヤーの手を入力してください：" << endl;

			cin >> player;

			//入力値が正常の場合ループ終了
			if (player >= 0 && player <= 2)
			{
				break;
			}

			cout << "入力に誤りがあります。再入力してください。" << endl;
		}

		//CPUのじゃんけんの手を生成
		cpu = rand() % 3;

		//選択された数字に対応する言葉(PLAYER)
		switch (player)
		{
		case 0:
			cout << "PLAYER：グー" << endl;
			break;

		case 1:
			cout << "PLAYER：チョキ" << endl;
			break;

		case 2:
			cout << "PLAYER：パー" << endl;
			break;
		}

		//選択された数字に対応する言葉(CPU)
		switch (cpu)
		{
		case 0:
			cout << "CPU：グー" << endl;
			break;

		case 1:
			cout << "CPU：チョキ" << endl;
			break;

		case 2:
			cout << "CPU：パー" << endl;
			break;
		}

		//じゃんけんの勝敗を判定するための計算
		result = player - cpu;

		//計算結果による勝敗の判定
		if (result == -1 || result == 2)
		{
			cout << "PLAYER WIN!" << endl;
			win++;
		}
		else if (result == 0)
		{
			cout << "DRAW" << endl;
			draw++;
		}
		else
		{
			cout << "CPU WIN!" << endl;
			lose++;
		}
	}

	//リザルト
	cout << endl;
	cout << "==============================" << endl;
	cout << "5回勝負終了！" << endl;
	cout << win << "勝 "
		<< draw << "分 "
		<< lose << "敗" << endl;
	cout << "==============================" << endl;

	return 0;
}