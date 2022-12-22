# 講義
- RENSHUフォルダは練習です
## mermaidもかけます
```mermaid
%%{init:{'theme':'base'}}%%
flowchart TD
    subgraph example [凡例]
        GenericProc[実装する処理]
        Common[[共通ルーチン系]]
        Tbl[(テーブル)]
        Cond{条件判定}
        StartEnd([開始/終了])
        Input[/入出力<画面 印刷など>/]
    end
```

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
```mermaid
%%{init:{'theme':'base'}}%%
flowchart TD
    %% 新規実装機能の色設定
    classDef newProc fill:#ffa23e

    subgraph 会員情報更新処理
        %% 全体処理をつないでいく
        StartProc([開始]) --->
        GetKaiin[[1.会員情報取得]] --> 
        GetAuth[[2.認証情報取得]] --> AuthCheck
        %% OKパターン
        AuthCheck{3.認証チェック} --> |OK| UpdateInfo
        UpdateInfo[4.情報更新]:::newProc -->
        SetReturnValue[5.戻値設定]:::newProc-->
        EndProc([終了])
        %% NGパターン
        AuthCheck --> |NG| ErrOut
        ErrOut[[6.エラー出力]]
        ErrOut-->EndProc
    end
    
    
    subgraph データベース
        %% テーブル関連の記述 コメント
        KaiinTbl[(会員テーブル)] --> GetKaiin
        AuthTbl[(認証テーブル)] --> GetAuth
        UpdateInfo --1--> KaiinTbl
        ErrOut --> ErrTbl[(エラーテーブル)]
    end
```
## DB 操作
<pre>
UPDATE member_info
SET num = inum, name = iname, ... 
WHERE num = inum;
</pre>