// torrent_main.cc
// 2016. 7. 28

#include "torrent.h"

int main() {
  TorrentClient utorrent;
  while(true) {
    string command;
    cin >> command;
    if(command == "add") {
      // use istream& operator>>(istream& is, Torrent& torrent);
      // make a new Torrent class and put it to utorrent;
      Torrent torrentFile;
      cin >> torrentFile;
      utorrent.addTorrent(torrentFile);
    }
    else if(command == "add_rate") {
      // use istream& operator>>(istream& is, RatedTorrent& ratedTorrent);
      // make a new RatedTorrent class and put it to utorrent;
      RatedTorrent ratedTorrentFile;
      cin >> ratedTorrentFile;
      utorrent.addRatedTorrent(ratedTorrentFile);
    }
    else if(command == "delete") {
      string name;
      cin >> name;
      utorrent.deleteTorrent(name);
    }
    else if(command == "print") {
      // print rated, then normal torrent;
      // use printTorrent();
      utorrent.printTorrent();
    }
    else if(command == "download") {
      // input second, then adjust currentSize_
      // downloading completed -> remove the file;
      int second;
      cin >> second;
      utorrent.downloadTorrent(second);
    }
    else if(command == "rate") {
      // get name and rating. move normal torrent to ratedtorrent;
      // if rating > 5, ignore the input;
      // use bool ratingTorrent();
      string name;
      int rating;
      cin >> name >> rating;
      if(!utorrent.ratingTorrent(name, rating)) {
        cout << "invalid operation" << endl;
      }
    }
    else {
      break;
    }
  }
  return 0;
}
