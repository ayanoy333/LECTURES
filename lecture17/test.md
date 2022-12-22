# 「処理概要ドキュメント」の記述方法について
## 方針
- VSCode に Markdown Preview Mermaid Supportをインストール
- 拡張子.mdのファイルを作成してマークダウンで記述する
- 処理詳細はかかない
- 例外は書かない
- 凡例以外は使わない
- レイアウトは気にしない
- 処理概要と処理フローを記述する
- mermaidのテーマは指定しない

:::mermaid
flowchart LR
    subgraph example [凡例]
        GenericProc[実装する処理]
        Common[[共通ルーチン系]]
        Tbl[(テーブル)]
        Cond{条件判定}
        StartEnd([開始/終了])
    end
:::
# ここから「処理概要ドキュメント」の記述例
## 処理概要
1. 会員情報取得
    1. 共通関数で要求電文の会員番号から会員テーブルの情報を取得する
2. 認証情報取得
   1. 共通関数で認証情報テーブルから会員番号の情報を取得する
3. 認証チェック
   1. 要求電文のパスワードをハッシュ化したものと2.認証情報で取得したハッシュ値を比較
   2. OKなら情報更新へ
   3. NGならエラー出力へ
4. 情報更新
   1. 会員テーブルの情報を要求電文で更新
5. 戻値設定
   1. 呼び出し元への戻り値を設定する
6. エラー出力
   1. 共通関数でエラーテーブルへ情報を出力する

## 処理フロー
:::mermaid
flowchart TB
    %% 全体処理をつないでいく
    subgraph 会員情報更新処理
        StartProc([開始]) --->
        GetKaiin[[1.会員情報取得]] --> 
        GetAuth[[2.認証情報取得]] --> AuthCheck
        %% OKパターン
        AuthCheck{3.認証チェック} --> |OK| UpdateInfo
        UpdateInfo[4.情報更新]-->
        SetReturnValue[5.戻値設定]-->
        EndProc([終了])
        %% NGパターン
        AuthCheck --> |NG| ErrOut
        ErrOut[[6.エラー出力]]
        ErrOut-->EndProc
    end
    
    %% テーブル関連の記述
    subgraph データベース
        KaiinTbl[(会員テーブル)] --> GetKaiin
        AuthTbl[(認証テーブル)] --> GetAuth
        UpdateInfo --> KaiinTbl
        ErrOut --> ErrTbl[(エラーテーブル)]
    end
:::