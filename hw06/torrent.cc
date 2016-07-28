// torrent.cc
// 2016. 7. 28

#include "torrent.h"

Torrent::Torrent() {
  seeder_ = 0;
  maxSize_ = 0;
  currentSize_ = 0;
}
Torrent::Torrent(const Torrent& torrent) {
  name_ = torrent.name();
  seeder_ = torrent.seeder();
  maxSize_ = torrent.maxSize();
  currentSize_ = torrent.currentSize();
}
Torrent::Torrent(const string& name, int maxSize, int seeder) {
  name_ = name;
  seeder_ = seeder;
  maxSize_ = maxSize;
  currentSize_ = 0;
}

string Torrent::name() const { return name_; }
int Torrent::seeder() const { return seeder_; }
int Torrent::maxSize() const { return maxSize_; }
int Torrent::currentSize() const { return currentSize_; }

int Torrent::download(int second) {
  currentSize_ += seeder_ * second;
  if(currentSize_ >= maxSize_)
    return -1;

  return currentSize_;
}
// end of class Torrent;



RatedTorrent::RatedTorrent() : Torrent() {
  rating_ = 0;
}
RatedTorrent::RatedTorrent(const Torrent& torrent) : Torrent(torrent) {
  rating_ = 0;
}
RatedTorrent::RatedTorrent(const string& name, int maxSize, int seeder,
                           int rating) : Torrent(name, maxSize, seeder) {
  rating_ = rating;
}

string RatedTorrent::name() const {
  string asterisk;
  for(int i = 0; i < rating_; i++)
    asterisk += "*";

  return Torrent::name() + "(" + asterisk + ")";
}
void RatedTorrent::setRate(int rating) {
  rating_ = rating;
}
int RatedTorrent::rating() const { return rating_; }
// end of class RatedTorrent;

TorrentClient::TorrentClient() {}

void TorrentClient::printTorrent() const {
  // print ratedTorrent first;
  for(auto it = ratedTorrents_.cbegin(); it != ratedTorrents_.cend(); it++) {
    cout << it->currentSize() << "/" << it->maxSize() << " " << it->name() <<
            endl;
  }
  // then, print torrent;
  for(auto it = torrents_.cbegin(); it != torrents_.cend(); it++) {
    cout << it->currentSize() << "/" << it->maxSize() << " " << it->name() <<
            endl;
  }
}

bool TorrentClient::ratingTorrent(const string& name, int rating) {
  if(rating > 5) return false;

  for(auto it = torrents_.begin(); it != torrents_.end(); it++) {
    // if torrent found, make a new ratedtorrent, then push it to ratedTorrents_
    // then remove it from torrents_;
    if(it->name() == name) {
      RatedTorrent rt(*it);
      rt.setRate(rating);
      ratedTorrents_.push_back(rt);
      torrents_.erase(it);
      return true;
    }
  }
  return false;
}

void TorrentClient::addTorrent(Torrent& torrent) {
  torrents_.push_back(torrent);
}
void TorrentClient::addRatedTorrent(RatedTorrent& ratedTorrent) {
  ratedTorrents_.push_back(ratedTorrent);
}
void TorrentClient::deleteTorrent(const string& name) {
  for(auto it = torrents_.begin(); it != torrents_.end(); it++) {
    if(it->name() == name) {
      torrents_.erase(it);
      return ;
    }
  }
  for(auto it = ratedTorrents_.begin(); it != ratedTorrents_.end(); it++) {
    if(it->Torrent::name() == name) {
      ratedTorrents_.erase(it);
      return ;
    }
  }
}

void TorrentClient::downloadTorrent(const int second) {
  for(auto it = torrents_.begin(); it != torrents_.end(); it++) {
    if(it->download(second) == -1) {
      torrents_.erase(it);
      it--;
    }
  }
  for(auto it = ratedTorrents_.begin(); it != ratedTorrents_.end(); it++) {
    if(it->download(second) == -1) {
      ratedTorrents_.erase(it);
      it--;
    }
  }
}

istream& operator>>(istream& is, Torrent& torrent) {
  string name;
  int size, seeder;

  is >> name >> size >> seeder;

  Torrent t(name, size, seeder);
  torrent = t;

  return is;
}
istream& operator>>(istream& is, RatedTorrent& ratedTorrent) {
  string name;
  int size, seeder, rating;

  is >> name >> size >> seeder >> rating;

  RatedTorrent rt(name, size, seeder, rating);
  ratedTorrent = rt;

  return is;
}
