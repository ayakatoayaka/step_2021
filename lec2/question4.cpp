#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
class Cache{
    public:
        unordered_map<string, string> cache_map;
        queue<string> cache_queue;
        void push(string page_name,string url);
        void show();
        ll size;
};

void Cache::push(string page_name,string url){
    

    // queueのサイズがcacheのサイズよりも小さい　→　mapとqueueに追加
    // queueのサイズがcacheのサイズよりも大きい && cacheにkeyが存在している　→　cache_queueをtmp_queueに入れたい要素以外を入れ、cache_queueに移した後入れたい要素を入れる
    // queueのサイズがcacheのサイズよりも大きい && cacheにkeyが存在しない　→ queueをpopしmapからpopした要素をeraseして入れたい要素を入れる
    if(cache_queue.size()>=size){
            if(!cache_map.count(page_name)){                
                string page_name_erase=cache_queue.front();           
                cache_map.erase(page_name_erase);
                cache_queue.pop();
            }else{
                queue<string> tmp_queue;
                ll tmp_size=cache_queue.size();
                for(int i=0;i<tmp_size;i++){
                    if(cache_queue.front()!=page_name){
                        tmp_queue.push(cache_queue.front());
                    }
                    cache_queue.pop();
                }
                cache_queue=tmp_queue;
            }
            
            
        }   

    
    cache_map[page_name]=url;   
    cache_queue.push(page_name);
}


void Cache::show(){
    queue<string> tmp_queue;
    ll tmp_size=cache_queue.size();
    for(int i=0;i<tmp_size;i++){
        //cache_queueからpopしたものを一時的にtmp_queueに入れてcacheのtopを表示
        cout << "page_name:" << cache_queue.front() << ' ' << "url:" << cache_map[cache_queue.front()] << endl;
        tmp_queue.push(cache_queue.front());
        cache_queue.pop();
    }
    cache_queue=tmp_queue;
    
}

//引数にcacheのサイズを入力する
int main(int argc,char **argv) {
    if (argc != 2) {
    cout << "usage: " << argv[0] << endl;
    return -1;
    }
    ll cache_size = stoi(string(argv[1]));
    Cache cache1;
    cache1.size=cache_size;

    //Cacheを試すためのコード
    string s1="aa",s2 = "bb";
    
    cache1.push(s1,s2);
    cache1.push("twitter","https://twitter.com/home");
    cache1.push(s2,s1);
    
    cache1.show();
    cout << "-----------------------" << endl;

    cache1.push("nyan","nyanyanyan");
    cache1.show();


    cout << "-----------------------" << endl;

    cache1.push("nyan","nyanyanyan");
    cache1.show();
    cout << "-----------------------" << endl;
    cache1.push("twitter","https://twitter.com/home");
    cache1.show();

    cout << "-----------------------" << endl;
    cache1.push("nyan","nyanyanyan");
    cache1.show();



    cout << "-----------------------" << endl;
    cache1.push("bbb","nyanyanyan");
    cache1.show();



}