#4週目の課題

##実行方法
./実行ファイル名 使うpages.txt 使うlink.txt 始めるstring 終わりのstring


##関数の説明
make_graph(linkのファイル名,始点に終点を入れているmap)
:graphを作る

make_graph_name(pagesのファイル名,ノードとそのページ名のmap,始まりのstring)
:グラフのノードとページ名を対応させたmapを作り、始まりの文字列があるノードを返す

bfs(make_graphで作ったgraph,make_graph_nameで作ったmap,node入れるqueue,訪れたnodeを入れるset,訪れたnodeの一つ前のnodeを対応させるmap,終わりのstring)
:bfsで行きたいとこを探す、visitedというsetを使うことでループしてしまうことを防ぐ、行きたいところのnodeが見つかれば番号を返し、見つからなければ-1を返す

path_restore(訪れたnodeの一つ前のnodeを対応させるmap,make_graph_nameで作ったmap,関数bfsの返り値,始めのノード)
:経路復元

読みにくい文章で申し訳ないです。
