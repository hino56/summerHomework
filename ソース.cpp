#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//変数
	int answer = -1;
	int question;
	int count = 0;

	//乱数の初期化
	srand((unsigned int)time(nullptr));

	//ランダムな整数の生成
	question = rand() % 101;

	cout << "数字当てゲーム" << endl;
	cout << "0～100までの数字を当ててください。" << endl;

	//ランダムな生成された
	while (question != answer)
	{
		//試合カウントの増加
		count++;

		//入力数字の判定
		while (true)
		{
			cout << "0～100の数字を入力してください：" << endl;
			cin >> answer;

			//入力が範囲を超えた場合実行
			if (answer < 0 || answer > 100)
			{
				cout << "入力に誤りがあります。再入力してください。" << endl;
			}
			//入力が範囲値だった場合の終了判定
			else
			{
				break;
			}
		}

		//ランダムな整数のヒント
		if (question > answer)
		{
			cout << "もっと大きい数字です。" << endl;
		}
		else if (question < answer)
		{
			cout << "もっと小さい数字です。" << endl;
		}
	}

	cout << endl;
	cout << "おめでとうございます！正解です！" << endl;
	cout << "正解：" << answer << endl;
	cout << count << "回目で当てることができました。" << endl;

	return 0;
}