
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

void Main()
{
	//ダイアログからテキストファイル選択
	auto _path = Dialog::OpenFile({ FileFilter::Text() });
	if (_path.has_value() != true)
		exit(true);

	//ファイルを開き、テキストファイルリーダーに格納
	TextReader _reader(_path.value());

	//1行ずつ文字列配列として_inputに格納
	Array<String> _inputs;
	while (auto line = _reader.readLine())
		_inputs.push_back(line.value_or(U"EOF"));

	//一番長い行の数を取得
	int _len = 0;
	for (auto& input : _inputs)
		if (input.size() > _len)
			_len = input.size();

	//一番長い行の文字数分の行を確保
	Array<String> _outputs;
	_outputs.resize(_len);

	//縦横変換
	for (int line = 0; line < _len; line++)
		for (int row = _inputs.size() - 1; row >= 0; row--)
		{
			_outputs[line].push_back(' ');
			if (_inputs[row].size() > line)
				_outputs[line].push_back(_inputs[row][line]);
			else
				_outputs[line].append(U"　");
		}

	for (int line = 0; line < _len; line++)
	{
		if (_outputs[line][0] == ' ')
			_outputs[line].pop_front();
	}

	//出力ファイルのパスを生成
	FilePath _outputPath = FileSystem::ParentPath(_path.value()) + FileSystem::BaseName(_path.value()) + U"_vertical" + U".txt";
	TextWriter _writer(_outputPath);

	//テキスト出力
	for(auto& output : _outputs)
	_writer.write(output + U"\n");

	/*
	//このループないとコンソールで動作チェックができない。落とし穴。
	while (System::Update())
	{

	}
	*/
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
