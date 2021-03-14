
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

void Main()
{
	//ダイアログからテキストファイル選択
	auto _path = Dialog::OpenFile({ FileFilter::Text() });
	
	//ファイルを開き、テキストファイルリーダーに格納
	TextReader _reader;
	if (_path.has_value())
		_reader.open(_path.value());

	//1行ずつ文字列配列として_inputに格納
	Array<String> _input;
	while (auto line = _reader.readLine())
		_input.push_back(line.value_or(U"EOF"));

	for (size_t i = 0; i < _input.size(); i++)
		Console(U"[" + Format(i) + U"]: " + _input[i]);

	//このループないとコンソールで動作チェックができない。落とし穴。
	while (System::Update())
	{

	}
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D ユーザコミュニティ Slack への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
